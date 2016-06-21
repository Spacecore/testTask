#include "dataExample.h"
#include "service.h"

using namespace std;
using namespace cv;

char* stringToChar1(string aString);

dataExample::dataExample(string aPath, string aName)
{
    pic_ = cvLoadImage(Service::getResourse()->stringToChar(aPath),1);
    name_ = aName;
}

IplImage* dataExample::getPic() {
    return pic_;
}

string dataExample::getName() {
    return name_;
}

