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

int main()
{
    vector<dataExample*>* exampleVault;
    exampleVault = new vector<dataExample*>;

    readFromFile(exampleVault,"C:/Prog/reposit/testTask/logoRecognition/dataPath.txt");
    for(int i=0; i<exampleVault->size(); i++) {
        cout<<exampleVault->at(i)->getName()<<endl;
    }


    namedWindow("input window", WINDOW_AUTOSIZE);
    imshow("input window", exampleVault->at(10)->getPic());

    waitKey(0);
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
