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

std::string readString(std::fstream &stream) {
    int tam;
    stream.read((char *) &tam, sizeof(tam));
    char *buffer = new char[tam + 1];
    stream.read(buffer, tam);
    buffer[tam] = '\0';
    std::string result = buffer;
    delete buffer;
    return result;
}

void writeString(std::fstream &stream, std::string str) {
    int len = str.size();
    stream.write((char *) &len, sizeof(len));
    stream.write(str.c_str(), len);
}