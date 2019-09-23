#include "CrimeRecord.h"
#include "RandomFile.h"
#include "StaticHash.h"


int main(){

    //TODO: LINARES: PROBAR 
    RandomFile <CrimeRecord> randomFile("random");
    StaticHash <CrimeRecord> staticFile("static", 8);

    for (int i = 101; i < 200; i ++){
        CrimeRecord obj;
        obj.setLazy(i);
        randomFile.insertion(obj);
        staticFile.insertion(obj);
    }
    staticFile.scan();
    CrimeRecord test;
    test.setLazy(10);
    
    staticFile.search(test);

   /*
   - divide bucket into 2 buckets.
- update index values
- put each bucket in the index. 
- check if full in each indexfile and update. Continue
*/  


}
