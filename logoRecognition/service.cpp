#include "service.h"
#include <fstream>


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

void Service::readFromFile(std::vector<dataExample*> *arr, std::string aPathToFile) {
    using namespace std;
    using namespace cv;

    ifstream from(Service::getResourse()->stringToChar(aPathToFile),ios_base::in);
    while(from.eof() == false) {
       char buff1[100];
       char buff2[100];
       for(int i=0; i<2; i++){
           if(i%2==0){from.getline(buff1,100);}
           else{from.getline(buff2,100);}
       }
       dataExample* tempExample = new dataExample(Service::getResourse()->charToString(buff1),Service::getResourse()->charToString(buff2));
       arr->push_back(tempExample);
    }
}
