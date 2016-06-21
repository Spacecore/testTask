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
    bin_ = cvCreateImage(cvGetSize(pic_), IPL_DEPTH_8U,1);
    gray_ = cvCreateImage(cvGetSize(pic_), IPL_DEPTH_8U,1);
    withCont_=cvCloneImage(pic_);
    cvCvtColor(pic_, gray_, CV_RGB2GRAY);
    cvInRangeS(gray_, cvScalar(40), cvScalar(150), bin_);
    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contours=0;
    int contoursCont = cvFindContours( bin_, storage,&contours,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_CODE,cvPoint(0,0));
    for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next){
        cvDrawContours(withCont_, seq0, CV_RGB(255,216,0), CV_RGB(0,0,250), 0, 1, 8);
    }
}

IplImage* dataExample::getPic() {
    return pic_;
}

string dataExample::getName() {
    return name_;
}

IplImage* dataExample::getBin() {
    return bin_;
}

IplImage* dataExample::getGray() {
    return gray_;
}

IplImage* dataExample::getPicWithCon() {
    return withCont_;
}

