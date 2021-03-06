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


void templateMatch(IplImage* src, IplImage* templ, string templName,string outputName);

int main()
{
    vector<dataExample*>* exampleVault;
    vector<dataExample*>* datasetVault;
    exampleVault = new vector<dataExample*>;
    datasetVault = new vector<dataExample*>;

    Service::getResourse()->readFromFile(exampleVault,"exampleDataPath.txt");
    Service::getResourse()->readFromFile(datasetVault,"dataPath.txt");
    cout<<"for start search enter index of logo"<<endl;
    for(int i=0; i<exampleVault->size()-1; i++){
        cout<<i<<" for "<<exampleVault->at(i)->getName()<<endl;
    }
    char buff[3];
    cin>>buff;
    int index = 0;
    if(atoi(buff) < 19){index = atoi(buff);}
    for(int i=0; i<datasetVault->size()-1;i++){
        try{
            templateMatch(datasetVault->at(i)->getPic(),exampleVault->at(index)->getPic(),exampleVault->at(index)->getName(),
                          datasetVault->at(i)->getName());
        } catch(...) {
             continue;
        }
    }
    system("pause");
    return 0;
}

void templateMatch(IplImage* src, IplImage* templ, string templName, string outputName) {
    IplImage* original=0, *find = 0;
    original = cvCloneImage(src);
    if((templ->width>=src->width) ||(templ->height>=src->height)) {
        find = cvCreateImage(cvSize(original->width/2.5,original->height/2.5), templ->depth,templ->nChannels);
        cvResize(templ, find,CV_INTER_LINEAR);
    } else {
        find = cvCloneImage(templ);
    }

    IplImage *res = cvCreateImage(cvSize(src->width-find->width+1,src->height-find->height+1),IPL_DEPTH_32F,1);
    cvMatchTemplate(original, find, res, CV_TM_SQDIFF);

    double minVal, maxVal;
    CvPoint minLoc, maxLoc;
    cvMinMaxLoc(res,&minVal, &maxVal, &minLoc, &maxLoc,0);
    cvNormalize(res,res,1,0,CV_MINMAX);
    cvRectangle(original, cvPoint(minLoc.x, minLoc.y), cvPoint(minLoc.x+find->width-1,minLoc.y+find->height-1), CV_RGB(255, 0, 0), 1, 8);
    string path = "Rezult/"+templName+outputName+".jpg";
    cvSaveImage(Service::getResourse()->stringToChar(path),original);
    cvReleaseImage(&res);
    cvReleaseImage(&find);
    cvReleaseImage(&original);
}
