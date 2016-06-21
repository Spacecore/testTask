#ifndef DATAEXEMPLE_H
#define DATAEXEMPLE_H
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

class dataExample
{
private:
    std::string name_;
    IplImage* pic_;
public:
    IplImage* getPic();
    std::string getName();
    dataExample(std::string aPath, std::string aName);
};

#endif // DATAEXEMPLE_H
