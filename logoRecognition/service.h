#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <cstring>

class Service
{
private:
    static Service* resourse_;
    Service();
public:
    static Service* getResourse();
    char* stringToChar(std::string aString);
    std::string charToString(char *aWord);
};

#endif // SERVICE_H
