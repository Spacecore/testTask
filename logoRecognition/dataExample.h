#ifndef DATAEXEMPLE_H
#define DATAEXEMPLE_H
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

class dataExemple
{
private:
    std::string name_;
    cv::Mat pic_;
public:
    cv::Mat getPic();
    std::string getName();
    dataExemple(std::string aPath, std::string aName);
};

#endif // DATAEXEMPLE_H
