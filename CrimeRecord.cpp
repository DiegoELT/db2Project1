#include "CrimeRecord.h"

using namespace std;

CrimeRecord::CrimeRecord();

CrimeRecord::CrimeRecord(CrimeData _information){
  this -> information = _information;  
}

void CrimeRecord::setCrime(){
  CrimeData newInformation; 
  cout << "Incident Number: "; cin >> newInformation.incidentNumber;
  cout << "Offense Code: "; cin >> newInformation.offenseCode;
  cout << "District: "; cin >> newInformation.district;
  cout << "Reporting Area: "; cin >> newInformation.reportingArea;
  cout << "Shooting: "; cin >> newInformation.shooting;
  cout << "Year: "; cin >> newInformation.year;
  cout << "Month: "; cin >> newInformation.month;
  cout << "Day of Week: "; cin >> newInformation.dayOfWeek;
  cout << "Hour: "; cin >> newInformation.hour;
  cout << "UCR Part: "; cin >> newInformation.ucrPart;
  cout << "Street: "; cin >> newInformation.street;
  information = newInformation;
}

string CrimeRecord::getKey(){
  return information.incidentNumber;
}

void CrimeRecord::showData(){
  cout << "Incident Number: " << information.incidentNumber << "\n";  
  cout << "Offense Code: " << information.offenseCode << "\n";  
  cout << "District: " << information.district << "\n";  
  cout << "Reporting Area: " << information.reportingArea << "\n";  
  cout << "Shooting: " << information.shooting << "\n";  
  cout << "Year: " << information.year << "\n";  
  cout << "Month: " << information.month << "\n";  
  cout << "Day of Week: " << information.dayOfWeek << "\n";  
  cout << "Hour: " << information.hour << "\n";  
  cout << "UCR Part: " << information.ucrPart << "\n";  

