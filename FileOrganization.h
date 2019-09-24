#ifndef FILEORGANIZATION_H
#define FILEORGANIZATION_H
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#define B 10
struct Bucket {
    int next;
    int size;
    char *key [B];
    long pos [B];
};

template <class T>
class FileOrganization {
    public:
    virtual void readIndex() = 0;
    virtual void writeIndex() = 0;
    virtual void scan() = 0;
    virtual void insertion(T record) = 0;
    virtual void search(T record) = 0;
};

#endif