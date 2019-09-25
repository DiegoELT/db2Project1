#include "CrimeRecord.h"
#include "RandomFile.h"
#include "StaticHash.h"
#include "DynamicHash.h"
#include <chrono>
#define TESTS 1


int main(){

    //RandomFile <CrimeRecord> randomFile("random");
    StaticHash <CrimeRecord> staticFile("static", 8);
    //DynamicHash <CrimeRecord> dynamicFile("dynamic", 8);

    for (int i = 0; i < TESTS; i ++){
        CrimeRecord obj;
        obj.setLazy(i);
        //std::cout << i << std::endl;
        //randomFile.insertion(obj);
        staticFile.insertion(obj);
        //dynamicFile.insertion(obj);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < TESTS; i ++){
        CrimeRecord obj;
        obj.setLazy(i);
        //std::cout << i << std::endl;
        //randomFile.search(obj);
        staticFile.search(obj);
        //dynamicFile.search(obj);
    }
    
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    //randomFile.scan();

}
