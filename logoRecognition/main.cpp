#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include "service.h"
#include "dataExample.h"
#include <stdio.h>

using namespace std;
using namespace cv;

void testMatch(IplImage* original, IplImage* templ);

int main()
{
    vector<dataExample*>* exampleVault;
    vector<dataExample*>* datasetVault;
    exampleVault = new vector<dataExample*>;
    datasetVault = new vector<dataExample*>;

    Service::getResourse()->readFromFile(exampleVault,"C:/Prog/reposit/testTask/logoRecognition/exampleDataPath.txt");
    Service::getResourse()->readFromFile(datasetVault,"C:/Prog/reposit/testTask/logoRecognition/dataPath.txt");
    /*for(int i=0; i<datasetVault->size()-1;i++){
        testMatch(exampleVault->at(6)->getPic(),datasetVault->at(i)->getPic());
    }*/
    for(int i=0; i<exampleVault->size(); i++) {
        cout<<exampleVault->at(i)->getName()<<endl;
    }
    for(int i=0; i<datasetVault->size(); i++) {
        cout<<datasetVault->at(i)->getName()<<endl;
    }

    namedWindow("example window", WINDOW_FREERATIO);
    namedWindow("dataset window", WINDOW_FREERATIO);
    int i=0;
    int j=0;
    while(true) {
        char c = cvWaitKey(0);
        if(c == 13){
            break;
        }
        if(c == 97){
            i--;
            if(i<0){i=exampleVault->size()-1;}
        }
        if(c == 100) {
            i++;
            if(i>exampleVault->size()-1){i=0;}
        }
        if(c == 37) {
            j--;
            if(j<0){j=datasetVault->size()-1;}
        }
        if(c == 39) {
            j++;
            if(j>datasetVault->size()-1){j=0;}
        }
        cvShowImage("example window", exampleVault->at(i)->getBin());
        cvShowImage("dataset window", datasetVault->at(j)->getBin());
    }


    cvWaitKey(0);
    return 0;
}

void testMatch(IplImage* original, IplImage* templ) {

    IplImage *src=0, *dst=0;

    src=cvCloneImage(original);

    IplImage* binI = cvCreateImage( cvGetSize(src), 8, 1);
    IplImage* binT = cvCreateImage( cvGetSize(templ), 8, 1);

    IplImage* rgb = cvCreateImage(cvGetSize(original), 8, 3);
    cvConvertImage(src, rgb, CV_GRAY2BGR);
    IplImage* rgbT = cvCreateImage(cvGetSize(templ), 8, 3);
    cvConvertImage(templ, rgbT, CV_GRAY2BGR);

    cvCanny(src, binI, 50, 200);
    cvCanny(templ, binT, 50, 200);

    cvNamedWindow( "cannyI", 1 );
    cvShowImage( "cannyI", binI);

    cvNamedWindow( "cannyT", 1 );
    cvShowImage( "cannyT", binT);

    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contoursI=0, *contoursT=0;

    int contoursCont = cvFindContours( binI, storage, &contoursI, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

    CvFont font;
    cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 1.0, 1.0);
    char buf[128];
    int counter=0;

    if(contoursI!=0){
            for(CvSeq* seq0 = contoursI;seq0!=0;seq0 = seq0->h_next){
                    cvDrawContours(rgb, seq0, CV_RGB(255,216,0), CV_RGB(0,0,250), 0, 1, 8);
            }
    }
    cvNamedWindow( "cont", 1 );
    cvShowImage( "cont", rgb );

    cvConvertImage(src, rgb, CV_GRAY2BGR);

    cvFindContours( binT, storage, &contoursT, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

    CvSeq* seqT=0;
    double perimT = 0;

    if(contoursT!=0){
            for(CvSeq* seq0 = contoursT;seq0!=0;seq0 = seq0->h_next){
                    double perim = cvContourPerimeter(seq0);
                    if(perim>perimT){
                            perimT = perim;
                            seqT = seq0;
                    }
                    cvDrawContours(rgbT, seq0, CV_RGB(255,216,0), CV_RGB(0,0,250), 0, 1, 8); // рисуем контур
            }
    }
    cvDrawContours(rgbT, seqT, CV_RGB(52,201,36), CV_RGB(36,201,197), 0, 2, 8); // рисуем контур
    cvNamedWindow( "contT", 1 );
    cvShowImage( "contT", rgbT );


    CvSeq* seqM=0;
    double matchM=1000;
    counter=0;
    if(contoursI!=0){
            for(CvSeq* seq0 = contoursI;seq0!=0;seq0 = seq0->h_next){
                    double match0 = cvMatchShapes(seq0, seqT, CV_CONTOURS_MATCH_I3);
                    if(match0<matchM){
                            matchM = match0;
                            seqM = seq0;
                    }
                    printf("[i] %d match: %.2f\n", ++counter, match0);
            }
    }
    cvDrawContours(rgb, seqM, CV_RGB(52,201,36), CV_RGB(36,201,197), 0, 2, 8); // рисуем контур

    cvNamedWindow( "find", 1 );
    cvShowImage( "find", rgb );

    cvWaitKey(0);

    cvReleaseMemStorage(&storage);

    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    cvReleaseImage(&rgb);
    cvReleaseImage(&rgbT);
    cvReleaseImage(&binI);
    cvReleaseImage(&binT);

    cvDestroyAllWindows();
}
