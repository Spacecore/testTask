#include "dataExample.h"
#include "service.h"

using namespace std;
using namespace cv;

char* stringToChar1(string aString);

dataExample::dataExample(string aPath, string aName)
{
    pic_ = cvLoadImage(Service::getResourse()->stringToChar(aPath),1);
    name_ = aName;
    bin_ = cvCreateImage(cvGetSize(pic_), IPL_DEPTH_8U,1);
    gray_ = cvCreateImage(cvGetSize(pic_), IPL_DEPTH_8U,1);
    withCont_=cvCloneImage(pic_);
    cvCvtColor(pic_, gray_, CV_RGB2GRAY);
    cvInRangeS(gray_, cvScalar(40), cvScalar(150), bin_);
    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contours=0;
    int contoursCont = cvFindContours( bin_, storage,&contours,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
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

