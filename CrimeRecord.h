#include <iostream>
#include "Record.h"
#include <istream>

class CrimeRecord : public Record {
private:
    char incidentNumber [10];
    char offenseCode [5];
    char district [4];
    int reportingArea;
    char shooting;
    int year;
    int month;
    char dayOfWeek [10];
    int hour;
    char ucrPart [20];
    char street [20];
public:
    void setData(std::string csvLine) {
        std::cout << csvLine << std::endl;
        std::istream *stream1;
        stream1 = &csvLine;
        std::string token;
        std::getline(stream1, token, ',');
        std::cout << token;

        std::cout << "Enter: id "; std::cin >> incidentNumber; std::cout << "\n";
        std::cout << "Enter: offense "; std::cin >> offenseCode; std::cout << "\n";
        std::cout << "Enter: district "; std::cin >> district; std::cout << "\n";
        std::cout << "Enter: Area "; std::cin >> reportingArea; std::cout << "\n";
        std::cout << "Enter: shooting "; std::cin >> shooting; std::cout << "\n";
        std::cout << "Enter: year "; std::cin >> year; std::cout << "\n";
        std::cout << "Enter: month "; std::cin >> month; std::cout << "\n";
        std::cout << "Enter: day "; std::cin >> dayOfWeek; std::cout << "\n";
        std::cout << "Enter: hour "; std::cin >> hour; std::cout << "\n";
        std::cout << "Enter: part "; std::cin >> ucrPart; std::cout << "\n";
        std::cout << "Enter: street"; std::cin >> street; std::cout << "\n";
    }
    void showData() {
        std::cout << incidentNumber << std::endl;
        std::cout << offenseCode << std::endl;
        std::cout << district << std::endl;
        std::cout << reportingArea << std::endl;
        std::cout << shooting << std::endl;
        std::cout << year << std::endl;
        std::cout << month << std::endl;
        std::cout << dayOfWeek << std::endl;
        std::cout << hour << std::endl;
        std::cout << ucrPart << std::endl;
        std::cout << street << std::endl;
    }
    char * getKey(){
        return incidentNumber;
    }
};