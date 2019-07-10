//
// Created by c1over on 2019-07-08.
//
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat srcImage, dstImage;
    srcImage = imread("7.jpg");

    cvtColor(srcImage, srcImage, COLOR_BGR2GRAY);

    equalizeHist(srcImage, dstImage);

    imshow("[0]", srcImage);
    imshow("[1]", dstImage);

    waitKey(0);
    return 0;
}