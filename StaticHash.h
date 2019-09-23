#include "FileOrganization.h"
#define B 10
struct Bucket {
    int next;
    int size;
    char *key [B];
    long pos [B];
};


template<class T>
class StaticHash : public FileOrganization <T>{
private:
    std::string fileName;
    std::string indexName;
    std::map <std::string, int> index;
    int depth;
    int maxBucketSize = B;
    int currentTopFileIndex;
public:
    StaticHash(std::string name, int d);
    ~StaticHash();
    void search(T record);
    void insertion(T record);
    int hashInt(char * key);
    void readIndex();
    void writeIndex();
    void scan();
    std::string hash(char * key); 
};



template <typename T>
StaticHash<T>::StaticHash(std::string name, int d){
    fileName = name;
    indexName = "staticHash/" + fileName + "_ind";
    depth = d;
    maxBucketSize = B;
    readIndex();
}

template <typename T>
StaticHash<T>::~StaticHash(){
    writeIndex();
}

template <typename T>
void StaticHash<T>::search(T record){

    char * key = record.getKey();
    int current = hashInt(key);
    
    Bucket bucket;

    std::string indexFileName = indexName + std::to_string(current);
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
    std::cout << "Not found..." << std::endl;
    return ;
    
}

template <typename T>
void StaticHash<T>::insertion(T record){
    std::ofstream outFile;
    outFile.open(fileName, std::ios::binary | std::ios::app);
    outFile.write((char *) &record, sizeof(record));
    long pos = outFile.tellp();
    outFile.close();

    char * key = record.getKey();

    int current = hashInt(key); std::string currentFileBucket = indexName + hash(key);
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
    std::cout << next << std::endl;
    std::cout << bucketSize << std::endl;

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
void StaticHash<T>::writeIndex(){
    std::ofstream outFile;
    outFile.open(indexName, std::ios::out | std::ios::binary);
    for (auto& pair : index) {
        outFile.write((char *) &pair.second, sizeof(pair.second));
        outFile.write((char *) &pair.first, sizeof(pair.first));
    }
    outFile.close();
    std::ofstream metaData;
    metaData.open("staticHash/hashMetaData", std::ios::binary | std::ios::trunc);
    metaData.write((char *) &currentTopFileIndex, sizeof(currentTopFileIndex));
    metaData.close();
}

template <typename T>
void StaticHash<T>::readIndex(){
    std::ifstream inFile;
    inFile.open(indexName, std::ios::in | std::ios::binary);
    char * key;
    int size;
    while (inFile.read((char *) &size, sizeof(size))){
        inFile.read((char *) &key, sizeof(key));
        index[key] = size;
    }
    inFile.close();
    currentTopFileIndex  = depth - 1;
    std::ifstream metaData;
    metaData.open("staticHash/hashMetaData", std::ios::binary);
    metaData.read((char *) &currentTopFileIndex, sizeof(currentTopFileIndex));
    metaData.close();
}

template <typename T>
void StaticHash<T>::scan(){
    
    std::ifstream inFile;
    inFile.open(fileName, std::ios::binary);
    T record;
    while (inFile.read((char *) &record, sizeof(record))){
        record.showData();
    }
    inFile.close();
}

template <typename T>
std::string StaticHash<T>::hash(char * key) {
    std::string s(key);
    int k = stoi(s);
    return std::to_string(k%depth);
}

template <typename T>
int StaticHash<T>::hashInt(char * key) {
    std::string s(key);
    int k = stoi(s);
    return k%depth;
}