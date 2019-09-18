#ifndef RECORD_H
#define RECORD_H
#include <string>
class Record {
    public:
    virtual void setData(std::string csvLine) = 0;
    virtual void showData() = 0;
    virtual char * getKey() = 0;
};

#endif