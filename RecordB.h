#include "Record.h"
#include <iostream>
class RecordB : Record {

private:
    int notKey;
public:
    void setData() {
        std::cin >> key;
        std::cin >> notKey;
    }
    void showData() {
        std::cout << key << std::endl;
        std::cout << notKey << std::endl;
    };
    void write(){
        std::cout << "not implemented yet";
    }
    void read(){
        std::cout << "not implemented yet";
    }
};