
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

    }

    void writeIndex(){

    }



    void Insertion(T record){

    }

    void Search(T record){

    }


};