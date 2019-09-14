
#include <iostream>

class RecordA{
private:
    int key;
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