//
// Created by Lenovo on 2023/10/16.
//
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include <iostream>
#include <iomanip>
#ifndef OPENCVTEST_OPENCVCAPTUREPICTURES_H
#define OPENCVTEST_OPENCVCAPTUREPICTURES_H


class OpenCVCapturePictures {
private:
    std::string saveImgPath;
public:
    explicit OpenCVCapturePictures(const std::string path);
    void capturePicturesAndSaveImage();
    ~OpenCVCapturePictures() = default;
};


#endif //OPENCVTEST_OPENCVCAPTUREPICTURES_H
