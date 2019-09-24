#include "CrimeRecord.h"
#include "RandomFile.h"
#include "StaticHash.h"
#include "DynamicHash.h"



int main(){

    //TODO: LINARES: PROBAR 
    RandomFile <CrimeRecord> randomFile("random");
    StaticHash <CrimeRecord> staticFile("static", 8);
    DynamicHash <CrimeRecord> dynamicFile("dynamic", 8);


    for (int i = 0; i < 100; i ++){
        CrimeRecord obj;
        obj.setLazy(i);
        std::cout << i << std::endl;
        //randomFile.insertion(obj);
        //staticFile.insertion(obj);
        dynamicFile.insertion(obj);
    }
    staticFile.scan();

    CrimeRecord test;
    test.setLazy(10);
 
    dynamicFile.search(test);


}
