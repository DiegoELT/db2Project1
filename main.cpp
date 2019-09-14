#include "CrimeRecord.h"
#include "OffenseCodeRecord.h"
#include "RandomFile.h"

int main(){
    /*
    Header con funciones para pasar de CSV a un array de objetos record.
    Por que funcion y no clase? No vas a hacer ningún cambio de estado, así que no es necesario tenerlo en clase.
    funcion (fileName, ptrAlArray)
    getline ',' y llenar elemento por elemento.
    for para insertar
    liberar espacio en la memoria
    seguir con el siguiente csv



    */
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