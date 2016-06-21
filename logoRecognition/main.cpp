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
    cout<<exampleVault->at(7)->getName()<<endl;
    namedWindow("input window", WINDOW_AUTOSIZE);
    cvShowImage("input window", exampleVault->at(7)->getBin());

    cvWaitKey(0);
    return 0;
}

