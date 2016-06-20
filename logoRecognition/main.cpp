#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "dataExample.h"
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    dataExample example("C:/Prog/reposit/testTask/logoRecognition/twitter.jpg", "twitter");

    cout<<example.getName()<<endl;
    namedWindow("inputWindow", WINDOW_AUTOSIZE);
    imshow("inputWindow", example.getPic());

    waitKey(0);
    return 0;
}

