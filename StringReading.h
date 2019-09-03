#include <fstream>
#include <string>
using namespace std;


string readString(fstream &stream) {
    int tam;
    stream.read((char *) &tam, sizeof(tam));
    char *buffer = new char[tam + 1];
    stream.read(buffer, tam);
    buffer[tam] = '\0';
    string result = buffer;
    delete buffer;
    return result;
}

void writeString(fstream &stream, string str) {
    int len = str.size();
    stream.write((char *) &len, sizeof(len));
    stream.write(str.c_str(), len);
}