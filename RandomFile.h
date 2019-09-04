#include "FileOrganization.h"
#include <map>


template <class T>
class RandomFile : private FileOrganization {
private: 
    string indexName;
    std::map<string, long> index;

public:
    RandomFile(std::string fileName){
        super(fileName);
        this->indexName = fileName + "_ind";
        readIndex();
    }

    ~RandomFile(){
        writeIndex();
    }

    void readIndex(){
        std::fstream inFile;
        inFile.open(this->indexName, std::ios::in | std::ios::binary);
        std::string key;
        long position;
        if (inFile.is_open()){
            inFile.read((char *) &position, sizeof(position));
            key = readString(inFile);
            index[key] = position;
        }
        inFile.close();
    }

    void writeIndex(){
        std::fstream outFile;
        outFile.open(this->indexName, std::ios::out | std::ios::binary);
        if (outFile.is_open()){
            for (auto &entry : index){
                outFile.write((char *) &entry.second, sizeof(entry.second));
                writeString(outFile, entry.first);
            }
            outFile.close();
        }
    }



    void Insertion(T record){

    }

    void Search(T record){

    }


};