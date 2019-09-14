#include <string>
#include <map>
#include <fstream>
#include <iostream>


template <class T>
class RandomFile {
private:
    std::string fileName;
    std::string indexName;
    std::map <char *, long> index;
public:
    RandomFile(std::string name);
    ~RandomFile();
    void search(T record);
    void insertion(T record);
    void readIndex();
    void writeIndex();
    void scan();
};

template <class T>
RandomFile<T>::RandomFile(std::string name){
    fileName = name;
    indexName = fileName + "_ind";
    readIndex();
}

template <class T>
RandomFile<T>::~RandomFile(){
    writeIndex();
}

template <class T>
void RandomFile<T>::search(T record){
    T foundRecord;
    char * key = record.getKey();
    auto it = index.find(key);
    
    if(it == index.end()) {
        std::cout << "Not found" << std::endl;
    } else {
        long pos = index[key];
        std::ifstream inFile;
        inFile.open(fileName, std::ios::in | std::ios::binary);
        inFile.seekg(pos-sizeof(foundRecord));
        inFile.read((char *) &foundRecord, sizeof(foundRecord));
        foundRecord.showData();
        inFile.close();
    }
    
}

template <class T>
void RandomFile<T>::insertion(T record){
    std::ofstream outFile;
    outFile.open(fileName, std::ios::binary | std::ios::app);
    outFile.write((char *) &record, sizeof(record));
    long pos = outFile.tellp();
    outFile.close();
    index[record.getKey()] = pos;
}

template <class T>
void RandomFile<T>::writeIndex(){
    std::ofstream outFile;
    outFile.open(indexName, std::ios::out | std::ios::binary);
    for (auto& pair : index) {
        outFile.write((char *) &pair.second, sizeof(pair.second));
        outFile.write((char *) &pair.first, sizeof(pair.first));
    }
    outFile.close();
}

template <class T>
void RandomFile<T>::readIndex(){
    std::ifstream inFile;
    inFile.open(indexName, std::ios::in | std::ios::binary);
    char * key;
    long pos;
    while (inFile.read((char *) &pos, sizeof(pos))){
        inFile.read((char *) &key, sizeof(key));
        index[key] = pos;
    }
    inFile.close();
}

template <class T>
void RandomFile<T>::scan(){
    std::ifstream inFile;
    inFile.open(fileName, std::ios::binary);
    T record;
    while (inFile.read((char *) &record, sizeof(record))){
        record.showData();
    }
    inFile.close();
}
