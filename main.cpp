#include "StaticHash.h" 
#include <fstream> 

int main(){
  std::ifstream inCrime;
  inCrime.open("tables/crime.csv", std::ios::in);

  std::cout << "Opened File. \n";
  
  std::string word;
  std::getline(inCrime, word);

  CrimeRecord testCrime;

  testCrime.readFromFile(inCrime);
  testCrime.readFromFile(inCrime);
  testCrime.showData();

  //IndexFile index;
  std::cout << hashRecord(testCrime) << "\n";

  IndexFile testIndex("testFile.bin");
  testIndex.writeInBucket(testCrime);
}
