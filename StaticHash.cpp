#include "StaticHash.h" 

#define hashingValue 50

bool fileExists(std::string name){
  std::ifstream file(name);
  return file.good();
}

int hashRecord(CrimeRecord crime){
  std::string crimeCode = (crime.getKey()).substr(1,9);
  return stoi(crimeCode) % hashingValue;
}

IndexFile::IndexFile(std::string _fileName){
  fileName = _fileName;
  if (fileExists(fileName)){
    std::ifstream indexArchive;
    indexArchive.open(fileName, std::ios::binary);

    size_t sizeToRead;
    indexArchive.read((char*) &sizeToRead, sizeof(size_t));
    indexArchive.read((char*) &index.saveMap, sizeToRead);
    indexArchive.read((char*) &sizeToRead, sizeof(size_t));
    indexArchive.read((char*) &index.nextItemMap, sizeToRead);
  } //If the file exists, read the index from there. 
}

void IndexFile::writeInBucket(CrimeRecord crime){
  int elementHash = hashRecord(crime);
  std::map<int, std::string>::const_iterator it = index.saveMap.find(elementHash); //Find if certain hash is already on the map 
  
  if (it == index.saveMap.end()){ //If it is the first element with that hash
    std::cout << "It is the first element with this hash. \n"; 
    
    std::string _fileName = "staticHashFiles/" + std::to_string(elementHash) + ".bin";
    std::string _nextFileName = ""; 

    StaticBucket bucketToInsert(_fileName, _nextFileName);
    bucketToInsert.addItem(crime); 

    index.saveMap[elementHash] = _fileName;
    index.nextItemMap[_fileName] = _nextFileName; 
    std::ofstream writeIndex;
    writeIndex.open(fileName, std::ios::out | std::ios::binary);
    
    size_t sizeToWrite = sizeof(index.saveMap);
    size_t sizeToWrite2 = sizeof(index.nextItemMap);

    writeIndex.write((char *) &sizeToWrite, sizeof(size_t));
    writeIndex.write((char *) &index.saveMap, sizeToWrite);
    writeIndex.write((char *) &sizeToWrite2, sizeof(size_t));
    writeIndex.write((char *) &index.nextItemMap, sizeToWrite2);
  }
  
  std::cout << "Hash has been attempted succesfully. \n";
}

StaticBucket::StaticBucket(std::string _fileName, std::string _nextFileName){
  fileName = _fileName; 
  nextFileName = _nextFileName;
  
  std::cout << "Created a bucket with the name " << fileName << "\n";
}

void StaticBucket::addItem(CrimeRecord crime){
  std::ofstream fileToInsert;
  fileToInsert.open(fileName, std::ios::app | std::ios::binary);
  
  std::cout << "Added item in bucket. \n";
}
