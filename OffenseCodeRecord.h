#include <iostream>
#include "Record.h"

class OffenseCodeRecord : private Record <int> {
private:
    int offenseCode;
    char description [50];
public:
    void setData(){
        std::cout << "Offense: code "; std::cin >> offenseCode; std::cout << "\n";
        std::cout << "Offense: description "; std::cin >> description; std::cout << "\n";
    }
    void showData(){
        std::cout << offenseCode << std::endl;
        std::cout << description << std::endl;
    }
    int getKey(){
        return offenseCode;
    }
};