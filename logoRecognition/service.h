#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <cstring>
#include <vector>
#include <dataExample.h>

class Service
{
private:
    static Service* resourse_;
    Service();
public:
    static Service* getResourse();
    char* stringToChar(std::string aString);
    std::string charToString(char *aWord);
    void readFromFile(std::vector<dataExample*> *arr, std::string aPathToFile);
};

#endif // SERVICE_H
