#include "service.h"


Service* Service::resourse_;

Service* Service::getResourse() {
    if (Service::resourse_ == 0) {
        Service::resourse_ = new Service();
    }
    return Service::resourse_;
}

Service::Service()
{

}

std::string Service::charToString(char *aWord) {
    using namespace std;

    string s(aWord);

    return s;
}

char* Service::stringToChar(std::string aString) {
    using namespace std;

    char* s;

    s = new char[aString.length() + 1];
    strcpy(s, aString.c_str());

    return s;
}
