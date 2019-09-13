#include <iostream>
#include <string>

struct CrimeData {
  std::string incidentNumber;
  int offenseCode;
  std::string district;
  int reportingArea;
  char shooting;
  int year;
  int month;
  std::string dayOfWeek;
  int hour;
  std::string ucrPart;
  std::string street; 
};

class CrimeRecord{
  public:
	CrimeRecord();
	CrimeRecord(CrimeData information);
	void setCrime();
	std::string getKey();
	void showData();

  private:  
	CrimeData m_Information;
};
