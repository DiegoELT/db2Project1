#include "RecordA.h"
#include "RandomFile.h"

int main(){
    RecordA record;
    record.setData();
    record.showData();
    RandomFile <RecordA> random("data");
    
}