#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <fstream>
#include "service.h"
#include "dataExample.h"

using namespace std;
using namespace cv;

void readFromFile(vector<dataExample*>* arr, string aPathToFile);
string charToString(char *aWord);
char* stringToChar(string aString);
void conturFoundes();

int main()
{
    vector<dataExample*>* exampleVault;
    exampleVault = new vector<dataExample*>;

    readFromFile(exampleVault,"C:/Prog/reposit/testTask/logoRecognition/exampleDataPath.txt");
    for(int i=0; i<exampleVault->size(); i++) {
        cout<<exampleVault->at(i)->getName()<<endl;
    }

    namedWindow("input window", WINDOW_AUTOSIZE);
    cvShowImage("input window", exampleVault->at(1)->getPic());

    cvWaitKey(0);
    return 0;
}

void readFromFile(vector<dataExample*> *arr, string aPathToFile) {
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


void conturFoundes() {
    IplImage* image;
    IplImage* gray;
    IplImage* bin;
    IplImage* dst;

    image = cvLoadImage("C:/Prog/reposit/testTask/logoRecognition/DataSet/100.jpg",1);
    gray = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U,1);
    bin = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U,1);
    dst = cvCloneImage(image);
    cvNamedWindow("original",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("binary",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("contur",CV_WINDOW_AUTOSIZE);
    cvCvtColor(image, gray, CV_RGB2GRAY);
    cvInRangeS(gray, cvScalar(40), cvScalar(150), bin);
    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contours=0;
    int contoursCont = cvFindContours( bin, storage,&contours,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
    for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next){
        cvDrawContours(dst, seq0, CV_RGB(255,216,0), CV_RGB(0,0,250), 0, 1, 8);
    }
    cvShowImage("original",image);
    cvShowImage("binary", bin);
    cvShowImage("contours", dst);
    cvWaitKey(0);

}
