#include "CrimeRecord.h"

CrimeRecord::CrimeRecord() { }

CrimeRecord::CrimeRecord(CrimeData information){
  m_Information = information;  
}

void CrimeRecord::setCrime(){
  CrimeData newInformation; 
  std::cout << "Incident Number: "; 
  std::cin >> newInformation.incidentNumber;
  std::cout << "Offense Code: ";
  std::cin >> newInformation.offenseCode;
  std::cout << "District: ";
  std::cin >> newInformation.district;
  std::cout << "Reporting Area: ";
  std::cin >> newInformation.reportingArea;
  std::cout << "Shooting: ";
  std::cin >> newInformation.shooting;
  std::cout << "Year: ";
  std::cin >> newInformation.year;
  std::cout << "Month: ";
  std::cin >> newInformation.month;
  std::cout << "Day of Week: ";
  std::cin >> newInformation.dayOfWeek;
  std::cout << "Hour: ";
  std::cin >> newInformation.hour;
  std::cout << "UCR Part: ";
  std::cin >> newInformation.ucrPart;
  std::cout << "Street: ";
  std::cin >> newInformation.street;
  m_Information = newInformation;
}

std::string CrimeRecord::getKey() {
  return m_Information.incidentNumber;
}

void CrimeRecord::showData() {
  std::cout << "Incident Number: " << m_Information.incidentNumber << "\n";
  std::cout << "Offense Code: " << m_Information.offenseCode << "\n";
  std::cout << "District: " << m_Information.district << "\n";
  std::cout << "Reporting Area: " << m_Information.reportingArea << "\n";
  std::cout << "Shooting: " << m_Information.shooting << "\n";
  std::cout << "Year: " << m_Information.year << "\n";
  std::cout << "Month: " << m_Information.month << "\n";
  std::cout << "Day of Week: " << m_Information.dayOfWeek << "\n";
  std::cout << "Hour: " << m_Information.hour << "\n";
  std::cout << "UCR Part: " << m_Information.ucrPart << "\n";
  std::cout << "Street: " << m_Information.street << "\n";
}

void CrimeRecord::readFromFile(std::ifstream& inCrimes){
  std::string auxWord;
  std::getline(inCrimes, m_Information.incidentNumber, ',');
  std::getline(inCrimes, auxWord, ','); m_Information.offenseCode = std::stoi(auxWord);
  std::getline(inCrimes, m_Information.district, ',');
  std::getline(inCrimes, auxWord, ','); m_Information.reportingArea = std::stoi(auxWord);
  std::getline(inCrimes, auxWord, ','); m_Information.shooting = auxWord[0];
  std::getline(inCrimes, auxWord, ','); m_Information.year = std::stoi(auxWord);
  std::getline(inCrimes, auxWord, ','); m_Information.month = std::stoi(auxWord);
  std::getline(inCrimes, m_Information.dayOfWeek, ',');
  std::getline(inCrimes, auxWord, ','); m_Information.hour = std::stoi(auxWord);
  std::getline(inCrimes, m_Information.ucrPart, ',');
  std::getline(inCrimes, m_Information.street, '\n');
}

