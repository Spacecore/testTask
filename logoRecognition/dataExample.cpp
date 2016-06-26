#include "dataExample.h"
#include "service.h"

using namespace std;
using namespace cv;

char* stringToChar1(string aString);

dataExample::dataExample(string aPath, string aName)
{
    pic_ = cvLoadImage(Service::getResourse()->stringToChar(aPath),1);
    float kernel[9];
    kernel[0] = -0.1;
    kernel[1] = -0.1;
    kernel[2] = -0.1;
    kernel[3]=-0.1;
    kernel[4]=2;
    kernel[5]=-0.1;
    kernel[6]=-0.1;
    kernel[7]=-0.1;
    kernel[8]=-0.1;
    CvMat kernel_matrix=cvMat(3,3,CV_32FC1,kernel);
    cvFilter2D(pic_,pic_,&kernel_matrix, cvPoint(-1,1));
    name_ = aName;
}

IplImage* dataExample::getPic() {
    return pic_;
}

string dataExample::getName() {
    return name_;
}

