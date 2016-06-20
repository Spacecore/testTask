#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    string fileName;

    cout<<"Enter path to the pic"<<endl<<"Path:";
    cin>>fileName;

    Mat input;
    input = imread(fileName.c_str(), IMREAD_COLOR);
    if(input.empty()) {cout<<"Could not open or found the image"<<endl; return -1;}

    namedWindow("inputWindow", WINDOW_AUTOSIZE);
    imshow("inputWindow", input);

    waitKey(0);
    return 0;
}

