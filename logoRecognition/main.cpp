#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include "service.h"
#include "dataExample.h"

using namespace std;
using namespace cv;

int main()
{
    vector<dataExample*>* exampleVault;
    vector<dataExample*>* datasetVault;
    exampleVault = new vector<dataExample*>;
    datasetVault = new vector<dataExample*>;

    Service::getResourse()->readFromFile(exampleVault,"C:/Prog/reposit/testTask/logoRecognition/exampleDataPath.txt");
    Service::getResourse()->readFromFile(datasetVault,"C:/Prog/reposit/testTask/logoRecognition/dataPath.txt");
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

