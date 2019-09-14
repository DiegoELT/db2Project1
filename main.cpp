#include "CrimeRecord.h"
#include "RandomFile.h"

int main(){
    CrimeRecord recordA;
    RandomFile <CrimeRecord> randomA("data");
    randomA.insertion(recordA);
    randomA.scan();
    std::cout << "Data. " << std::endl;
    randomA.search(recordA);


}