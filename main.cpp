#include "CrimeRecord.h"
#include "RandomFile.h"
#include "StaticHash.h"
#include "DynamicHash.h"
#include <chrono>

#include <thread>
#include <random>
#include <mutex>

#define TESTS 1


std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(1, 2000);

std::mutex fileLock;

template<typename FileOrganization>
void transactionExecute(FileOrganization* file) {
	CrimeRecord tmp;
	tmp.setLazy(dist(mt));
    std::lock_guard<std::mutex> guard(fileLock);
	file->insertion(tmp);
}


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


    std::thread t1(&transactionExecute<StaticHash<CrimeRecord>>, &staticFile);
    std::thread t2(&transactionExecute<StaticHash<CrimeRecord>>, &staticFile);
	t1.join();
	t2.join();

    //randomFile.scan();

}
