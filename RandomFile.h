#include "FileOrganization.h"

template <class T>
class RandomFile : private FileOrganization {
private: 

public:
    RandomFile(std::string fileName){
        super(fileName);
    }

    ~RandomFile(){
        
    }

    void Insertion(T record){
        
    }

    void Search(T record){

    }


};