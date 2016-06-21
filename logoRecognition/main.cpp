#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "dataExample.h"
#include <vector>
#include <fstream>

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
    imshow("input window", exampleVault->at(i)->getPic());

    return 0;
}

void readFromFile(vector<dataExample*> *arr, string aPathToFile) {
    ifstream from(stringToChar(aPathToFile),ios_base::in);
    while(from.eof() == false) {
       char buff1[100];
       char buff2[100];
       for(int i=0; i<2; i++){
           if(i%2==0){from.getline(buff1,100);}
           else{from.getline(buff2,100);}
       }
       dataExample* tempExample = new dataExample(charToString(buff1),charToString(buff2));
       arr->push_back(tempExample);
    }
}

string charToString(char *aWord) {
    using namespace std;

    string s(aWord);

    return s;
}

char* stringToChar(string aString) {
    using namespace std;

    char* s;

    s = new char[aString.length() + 1];
    strcpy(s, aString.c_str());

    return s;
}

void conturFoundes() {
    IplImage* image;
    IplImage* gray;
    IplImage* bin;
    IplImage* dst;

    image = cvLoadImage("C:/Prog/reposit/testTask/logoRecognition/DataSet/8.jpg",1);
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
