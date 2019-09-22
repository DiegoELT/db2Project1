#include "CrimeRecord.h"
#include <map>

bool fileExists(std::string name);
int hashRecord(CrimeRecord crime);

struct IndexMap{
  std::map<int, std::string> saveMap; //Index that reads hash to buckets
  std::map<std::string, std::string> nextItemMap; //Saves the next file for each bucket.
};

class IndexFile{
  public:
    IndexFile(std::string _fileName); 
    void writeInBucket(CrimeRecord crime); 

  private:
    std::string fileName;
    IndexMap index; 
};

class StaticBucket{
  public: 
    StaticBucket(std::string _fileName, std::string _nextFileName);
    void addItem(CrimeRecord crime);

  private:
    std::string fileName;
    std::string nextFileName; 
};
