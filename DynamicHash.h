#include "FileOrganization.h"

struct IndexInfo {
    std::string fullName;
    std::string name;
    int localDepth;

    void setName(){
        name = "";
        int len = fullName.length();
        for (int i = 0; i < localDepth; i++) name = fullName[len-1-i] + name;
        std::cout << name << std::endl;

    }

    void setFullName(int n, int d) {
        fullName = "0";
        for (int i = 1; i < d; i++) fullName = fullName + "0";
        for(int i=0; n>0; i++)    
        {    
            if (n%2 == 0) fullName[d-1-i] = '0'; else fullName[d-1-i] = '1';    
            n= n/2;  
        }  
    }
};


template<class T>
class DynamicHash : public FileOrganization <T>{
private:
    std::string fileName;
    std::string indexName;
    std::map <int, IndexInfo> index;
    int depth;
    int binaryDepth;
    int maxBucketSize = B;
    int currentTopFileIndex;
public:
    DynamicHash(std::string name, int d);
    ~DynamicHash();
    void search(T record);
    void insertion(T record);
    int hashInt(char * key);
    void readIndex();
    void writeIndex();
    void scan();
    void initIndex();
    void insertionLinked(T record);
    int getBinaryDepth();
    std::string hash(char * key); 
};



template <typename T>
DynamicHash<T>::DynamicHash(std::string name, int d){
    fileName = name;
    indexName = "dynamicHash/" + fileName + "_ind";
    depth = d;
    binaryDepth = getBinaryDepth();
    maxBucketSize = B;
    initIndex();
    readIndex();
    //for (auto f : index) {std::cout << f.first << " " << f.second.fullName << " " << f.second.name << std::endl;}
}

template <typename T>
int DynamicHash<T>::getBinaryDepth(){
    int counter = 0;
    for (int i = 1; i < depth; i=i*2) counter++;
    return counter;

}
template <typename T>
void DynamicHash<T>::initIndex(){
    for (int i = 0; i < depth; i++) {
        IndexInfo indexInfo;
        indexInfo.setFullName(i, binaryDepth);
        indexInfo.localDepth = 1;
        indexInfo.setName();
        index[i] = indexInfo;
    }
}

template <typename T>
DynamicHash<T>::~DynamicHash(){
    writeIndex();
}

template <typename T>
void DynamicHash<T>::search(T record){

    char * key = record.getKey();
    int current = hashInt(key);

    if (index[current].localDepth == binaryDepth) {
        Bucket bucket;
        std::string indexFileName = indexName + index[current].fullName;
        std::ifstream inFile;
        inFile.open(indexFileName, std::ios::binary);
        inFile.read((char *) &bucket, sizeof(bucket));
        inFile.close();
        int next = bucket.next;
        int n;

        while (current != next) {
            n = bucket.size;
            for (int i = 0; i < n; i++) {
                if (bucket.key[i] == key) {
                    std::cout << "Pos: " << bucket.pos[i] << std::endl;
                    return ;
                }
            }
            indexFileName = indexName + std::to_string(next);
            
            inFile.open(indexFileName, std::ios::binary);
            inFile.read((char *) &bucket, sizeof(bucket));
            inFile.close();
            current = next;
            next = bucket.next;
            
        }

        n = bucket.size;
        for (int i = 0; i < n; i++) {
            if (bucket.key[i] == key) {
                std::cout << "Pos: " << bucket.pos[i] << std::endl;
                return ;
            }
        }
    } else {
        Bucket bucket;
        std::string indexFileName = indexName + index[current].name;
        std::ifstream inFile;
        inFile.open(indexFileName, std::ios::binary);
        inFile.read((char *) &bucket, sizeof(bucket));
        inFile.close();
        int n = bucket.size;
        for (int i = 0; i < n; i++) {
            if (bucket.key[i] == key) {
                std::cout << "Pos: " << bucket.pos[i] << std::endl;
                return ;
            }
        }
    }
    
    
    std::cout << "Not found..." << std::endl;
    return ;
    
}

template <typename T>
void DynamicHash<T>::insertion(T record){
    char * key = record.getKey();
    int current = hashInt(key); IndexInfo indexPtr = index[current];
    if (indexPtr.localDepth == binaryDepth) insertionLinked(record);
    
    else {
        std::ofstream outFile;
        outFile.open(fileName, std::ios::binary | std::ios::app);
        outFile.write((char *) &record, sizeof(record));
        long pos = outFile.tellp();
        outFile.close();
        std::string currentName = index[current].name; 
        std::string currentFileBucket = indexName + currentName;
        std::cout << currentFileBucket << std::endl;

        int next; std::string nextFileBucket;
        int bucketSize;

        Bucket bucket;
        bucket.next  = hashInt(key);
        bucket.size = 0;

        std::ifstream inFile;
        inFile.open(currentFileBucket, std::ios::binary);
        inFile.read((char *) &bucket, sizeof(bucket));
        inFile.close();

        next = bucket.next;
        bucketSize = bucket.size;
        int counter = 0;
        std::cout << bucketSize << std::endl;
        std::cout << maxBucketSize << std::endl;
        if (bucketSize == maxBucketSize) {
            std::cout << "YEET" << std::endl;
            for (auto &f : index) {
                if (f.second.name == currentName) {
                    int newBucketIndex = f.first;
                    f.second.localDepth ++; 
                    f.second.setName();
                    std::cout << newBucketIndex << std::endl;
                }
            }
            for (int i = 0; i < bucketSize; i++) {
                char* reasignKey = bucket.key[i];
                long reasignPos = bucket.pos[i];
                int current = hashInt(reasignKey);

                std::string reasign = index[current].name;
                std::string reasignIndex = indexName + reasign;
                std::cout << "YEET " << reasignIndex << std::endl;
                Bucket obj;
                obj.size = 0;
                obj.next =  current;
                std::ifstream inFile;
                inFile.open(reasignIndex, std::ios::binary);
                inFile.read((char *) &obj, sizeof(obj));
                inFile.close();

                int size = ++obj.size;
                obj.key[size-1] = reasignKey; 
                obj.pos[size-1] = reasignPos;
                
                std::ofstream outFile;
                outFile.open(reasignIndex, std::ios::binary | std::ios::trunc);
                outFile.write((char *) &obj, sizeof(obj));
                outFile.close();
                insertion(record);
            }            
        } else {
            std::ofstream outFile;
            outFile.open(currentFileBucket, std::ios::out | std::ios::trunc);
            int size = ++bucket.size;
            bucket.key[size-1] = key;
            bucket.pos[size-1] = pos;
            if (size == maxBucketSize && index[hashInt(key)].localDepth == binaryDepth) {
                bucket.next = ++currentTopFileIndex;
            }
            outFile.write((char *) &bucket, sizeof(bucket));
            outFile.close(); 
        }
    }

}

template <typename T>
void DynamicHash<T>::insertionLinked(T record){

    std::ofstream outFile;
    outFile.open(fileName, std::ios::binary | std::ios::app);
    outFile.write((char *) &record, sizeof(record));
    long pos = outFile.tellp();
    outFile.close();

    char * key = record.getKey();

    int current = hashInt(key); std::string currentFileBucket = indexName + index[current].fullName;
    int next; std::string nextFileBucket;
    int bucketSize;

    Bucket bucket;
    bucket.next  = hashInt(key);
    bucket.size = 0;

    std::ifstream inFile;
    inFile.open(currentFileBucket, std::ios::binary);
    inFile.read((char *) &bucket, sizeof(bucket));
    inFile.close();

    next = bucket.next;
    bucketSize = bucket.size;

    while(current != next) {
        current = next;
        nextFileBucket = indexName + std::to_string(next);
        inFile.open(nextFileBucket, std::ios::binary);
        inFile.read((char *) &bucket, sizeof(bucket));
        bucketSize = bucket.size;
        next = bucket.next;
        inFile.close();
    }
    
    currentFileBucket = indexName + std::to_string(current);

    if (bucketSize < maxBucketSize)
    {
        inFile.open(currentFileBucket, std::ios::binary);
        inFile.read((char *) &bucket, sizeof(bucket));
        inFile.close();

        bucket.key[bucketSize] = key;
        bucket.pos[bucketSize] = pos;
        bucket.size = bucketSize + 1;
        bucket.next = current;

        std::ofstream outIndexFile;
        outIndexFile.open(currentFileBucket, std::ios::binary | std::ios::trunc);
        outIndexFile.write((char *) &bucket, sizeof(bucket));
        outIndexFile.close();   
    
    } else {
        currentTopFileIndex ++;
        inFile.open(currentFileBucket, std::ios::binary);
        inFile.read((char *) &bucket, sizeof(bucket));
        inFile.close();

        bucket.next = currentTopFileIndex;
        std::ofstream outIndexFile;
        outIndexFile.open(currentFileBucket, std::ios::binary | std::ios::trunc);
        outIndexFile.write((char *) &bucket, sizeof(bucket));
        outIndexFile.close();

        std::string newFileBucket = indexName + std::to_string(currentTopFileIndex);
        std::ofstream newIndexFile;
        Bucket newBucket;
        newIndexFile.open(newFileBucket, std::ios::binary);
        newBucket.next = currentTopFileIndex;
        newBucket.size = 0;
        newIndexFile.write((char *) &newBucket, sizeof(newBucket));
        newIndexFile.close();

    }
}

template <typename T>
void DynamicHash<T>::writeIndex(){
    std::ofstream outFile;
    outFile.open(indexName, std::ios::out | std::ios::binary);
    for (auto& pair : index) {
        outFile.write((char *) &pair.first, sizeof(pair.first));
        outFile.write((char *) &pair.second, sizeof(pair.second));
    }
    outFile.close();
    std::ofstream metaData;
    metaData.open("dynamicHash/hashMetaData", std::ios::binary | std::ios::trunc);
    metaData.write((char *) &currentTopFileIndex, sizeof(currentTopFileIndex));
    metaData.close();
}

template <typename T>
void DynamicHash<T>::readIndex(){
    std::ifstream inFile;
    inFile.open(indexName, std::ios::in | std::ios::binary);
    int key;
    IndexInfo value;
    while (inFile.read((char *) &key, sizeof(key))){
        inFile.read((char *) &value, sizeof(value));
        index[key] = value;
    }
    inFile.close();
    currentTopFileIndex  = depth - 1;
    std::ifstream metaData;
    metaData.open("dynamicHash/hashMetaData", std::ios::binary);
    metaData.read((char *) &currentTopFileIndex, sizeof(currentTopFileIndex));
    metaData.close();
}

template <typename T>
void DynamicHash<T>::scan(){
    
    std::ifstream inFile;
    inFile.open(fileName, std::ios::binary);
    T record;
    while (inFile.read((char *) &record, sizeof(record))){
        record.showData();
    }
    inFile.close();
}

template <typename T>
std::string DynamicHash<T>::hash(char * key) {
    std::string s(key);
    int k = stoi(s);
    return std::to_string(k%depth);
}

template <typename T>
int DynamicHash<T>::hashInt(char * key) {
    std::string s(key);
    int k = stoi(s);
    return k%depth;
}