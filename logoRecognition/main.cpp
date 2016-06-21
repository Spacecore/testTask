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
void conturFoundes();

int main()
{
    vector<dataExample*>* exampleVault;
    exampleVault = new vector<dataExample*>;

    readFromFile(exampleVault,"C:/Prog/reposit/testTask/logoRecognition/exampleDataPath.txt");
    for(int i=0; i<exampleVault->size(); i++) {
        cout<<exampleVault->at(i)->getName()<<endl;
    }
    cout<<exampleVault->at(7)->getName()<<endl;
    namedWindow("input window", WINDOW_AUTOSIZE);
    cvShowImage("input window", exampleVault->at(7)->getBin());

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
