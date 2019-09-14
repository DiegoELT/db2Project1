#include "CrimeRecord.h"
#include "OffenseCodeRecord.h"
#include "RandomFile.h"

int main(){
    CrimeRecord recordA;
    recordA.setData();
    RandomFile <CrimeRecord> randomA("data");
    randomA.insertion(recordA);
    randomA.scan();
    std::cout << "Data. " << std::endl;
    randomA.search(recordA);
    std::cout << "\n";
    OffenseCodeRecord recordB;
    recordB.setData();
    RandomFile <OffenseCodeRecord> randomB("data2");
    randomB.insertion(recordB);
    randomB.scan();
    std::cout << "Data. " << std::endl;
    randomB.search(recordB);

}