#include <iostream>
#include <string>

using namespace std;

struct CrimeData{
  string incidentNumber;
  int offenseCode;
  string district;
  int reportingArea;
  char shooting;
  int year;
  int month;
  string dayOfWeek;
  int hour;
  string ucrPart;
  string street; 
};

class CrimeRecord{
private:  
  CrimeData information;

public:
  CrimeRecord();
  CrimeRecord(CrimeData _information);
  void setCrime();
  string getKey();
  void showData();
};
