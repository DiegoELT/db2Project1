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
    void stringToArray(std::string field_s, char * field_a, int size) {
        for (int i = 0; i < size; i++) {
            if (i < sizeof(field_s)) field_a[i] = field_s[i];
            else field_a[i] = ' ';
        }
        field_a[size-1] = '\0';
    }
    void setLazy(int i){
        std::string id = std::to_string(i);
        stringToArray(id, incidentNumber, sizeof(incidentNumber));
        stringToArray(std::to_string(i%1000), offenseCode, sizeof(offenseCode));
        stringToArray(std::to_string(i%100), district, sizeof(district));
        reportingArea = i%50;
        shooting = i%10 == 0 ? 'Y' : 'N';
        year = 2000 + i%20;
        month = i%12 + 1;
        stringToArray("Thursday", dayOfWeek, sizeof(dayOfWeek));
        hour = i%25;
        stringToArray("NULL", ucrPart, sizeof(ucrPart));
        stringToArray("Street " + std::to_string(i%400), street, sizeof(street)); 
    }
    
    void setData() {
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

    ~CrimeRecord(){

    }
};