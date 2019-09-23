#include "CrimeRecord.h"
#include "RandomFile.h"

#define D 4
#define HASH 8
std::map<std::string, int> index;
int currentTopIndex = 7;

struct Bucket {
    int next;
    int size;
    long pos[D];
    int key[D];
};

void createIndex();
void insert(int i);
int main(){
    /*
    RandomFile <CrimeRecord> randomFile("random");
    for (int i = 0; i < 10000; i ++){
        CrimeRecord obj;
        obj.setLazy(i);
        randomFile.insertion(obj);
    }
    randomFile.scan();
    */

    //CHEQUEA EL TAMAÑO DEL ARRAY SIZEOF
    //ESCRIBE CADA VEZ QUE CREAS ALGO!!!!!!!!

    createIndex();
    for (auto f : index) std::cout << f.first << std::endl;

    insert(9);
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    insert(14);
    insert(15);

    

}

void createIndex() {

    std::string file_index_name = "staticHash/index_";
    std::fstream createFile;
    
    for (int i = 0; i < HASH; i++) {
        Bucket bucket;
        index[file_index_name + std::to_string(i)] = 1;
        bucket.size = 0;
        bucket.next = i;
        bucket.key[0] = 0;
        bucket.key[1] = 0;
        bucket.key[2] = 0;
        bucket.key[3] = 0;
        bucket.pos[0] = 0;
        bucket.pos[1] = 0;
        bucket.pos[2] = 0;
        bucket.pos[3] = 0;

        createFile.open(file_index_name + std::to_string(i), std::ios::in | std::ios::binary);
        createFile.seekg(0);
        createFile.write((char *) &bucket, sizeof(bucket));
        createFile.close();
    }
}

void insertion(int record){
    std::ofstream outFile;
    std::string index_file_name = "staticHash/index_" + std::to_string(i % HASH);
    outFile.open(index_file_name, std::ios::binary | std::ios::app);
    outFile.write((char *) &record, sizeof(record));
    long pos = outFile.tellp();
    outFile.close();
    index[record.getKey()] = pos;
}

void insert(int i){
    std::fstream outFile;
    outFile.open("hash", std::ios::in | std::ios::binary | std::ios::app);
    outFile.write((char *) &i, sizeof(int));
    long pos = outFile.tellp();
    outFile.close();
         
    std::string index_file_name = "staticHash/index_" + std::to_string(i % HASH);
    int sizeOfList = index[index_file_name];

    std::fstream indexFile;
    Bucket bucket;
    int next = i % HASH;
    for (int i = 0; i < sizeOfList; i++) {
        index_file_name = "staticHash/index_" + std::to_string(next);
        indexFile.open(index_file_name, std::ios::binary);
        indexFile.seekg(0);
        indexFile.read((char *) &bucket, sizeof(bucket));
        next = bucket.next;
        indexFile.close();
    }
    std::cout << next << std::endl;

    index_file_name = "staticHash/index_" + std::to_string(next);

    /*
    std::cout << index_file_name << std::endl;
    
    indexFile.open(index_file_name, std::ios::binary);

    indexFile.read((char *) &bucket, sizeof(bucket));

    std::cout << std::endl;
    std::cout << bucket.size << std::endl;
    bucket.key[bucket.size - 1] = i;
    bucket.pos[bucket.size - 1] = pos;

    std::cout << bucket.size << std::endl;
    bucket.size++;
    std::cout << bucket.size << std::endl;

    if (bucket.size == D) {
        currentTopIndex++;
        bucket.next = currentTopIndex;
        index[index_file_name]++;
        std::cout << index[index_file_name] << std::endl;
        index_file_name = "staticHash/index_" + std::to_string(currentTopIndex);
        std::fstream newIndexFile;
        Bucket newBucket;
        newBucket.next = currentTopIndex;
        newIndexFile.open(index_file_name, std::ios::in | std::ios::binary | std::ios::app);
        newIndexFile.write((char *) &newBucket, sizeof(newBucket));
        newIndexFile.close();
    }

    indexFile.write((char *) &bucket, sizeof(bucket));
    indexFile.close();
    */
}