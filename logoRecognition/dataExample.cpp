#include "dataExample.h"

using namespace std;
using namespace cv;

dataExample::dataExample(string aPath, string aName)
{
    pic_ = imread(aPath.c_str(), IMREAD_COLOR);
    name_ = aName;
}

Mat dataExample::getPic() {
    return pic_;
}

string dataExample::getName() {
    return name_;
}

