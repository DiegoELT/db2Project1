#include <iostream>
#include "Record.h"

class OffenseCodeRecord : public Record
{
private:
    char offenseCode [5];
    char description [50];
public:
    void setData(std::string csvLine){
        std::cout << "Offense: code "; std::cin >> offenseCode; std::cout << "\n";
        std::cout << "Offense: description "; std::cin >> description; std::cout << "\n";
    }
    void showData(){
        std::cout << offenseCode << std::endl;
        std::cout << description << std::endl;
    }
    char * getKey(){
        return offenseCode;
    }
};