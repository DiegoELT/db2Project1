#include <string>
#include <fstream>

template <class T>

class FileOrganization {
protected: 
    std::string fileName;

public:
    FileOrganization(std::string fileName){
        this->fileName = fileName;
    }
    ~FileOrganization(){

    }
    virtual void Insertion(T record) = 0;
    
    virtual void Search(T record) = 0;

    void Scan(int n){
        std::fstream inFile;
        inFile.open(this->fileName, ios::in | ios::binary);
        T record;
        if (inFile.is_open()) {
            while (record.read(inFile) && n) {
                record.showData();
                n--;
            }
            inFile.close();
        } else cout << "Could not open the file.\n";
    }

    void Scan(){
        std::fstream inFile;
        inFile.open(this->fileName, ios::in | ios::binary);
        T record;
        if (inFile.is_open()) {
            while (record.read(inFile)) {
                record.showData();
            }
            inFile.close();
        } else cout << "Could not open the file.\n";
    }


};