//
// Created by c1over on 2019-07-12.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xphoto/white_balance.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat inputImage = imread("3.jpg");
    Mat grayWBImage = Mat::zeros(inputImage.size(),inputImage.type());
    Mat simpleWBImage = Mat::zeros(inputImage.size(),inputImage.type());

    //灰度世界算法
    Ptr<xphoto::WhiteBalancer> grayWB = xphoto::createGrayworldWB();
    grayWB->balanceWhite(inputImage, grayWBImage);

    //完美反射算法
    Ptr<xphoto::WhiteBalancer> simpleWB = xphoto::createSimpleWB();
    simpleWB->balanceWhite(inputImage, simpleWBImage);

    imshow("inputImage",inputImage);
    imshow("grayWBImage",grayWBImage);
    imshow("simpleWBImage",simpleWBImage);
    waitKey();
    return 0;
}