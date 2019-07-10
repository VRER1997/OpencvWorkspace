//
// Created by c1over on 2019-07-10.
//
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat srcImage = imread("1.jpg");
    imshow("[0]", srcImage);

    MatND dstHist;
    int dims = 1;
    float hranges[] = {0, 255};
    const float * ranges [] = {hranges};
    int size = 256;
    int channels = 0;

    calcHist(&srcImage, 1, &channels, Mat(), dstHist, dims, &size, ranges);

    int scale = 1;
    Mat dstImage(size * scale, size, CV_8U, Scalar(0));

    double minValue = 0, maxValue = 0;
    minMaxLoc(dstHist, &minValue, &maxValue, 0, 0);

    int hpt = saturate_cast<int>(0.9*size);
    for(int i = 0; i < 256; i++){
        float binValue = dstHist.at<float>(i);
        int realValue = saturate_cast<int>(binValue*hpt/maxValue);
        rectangle(dstImage, Point(i*scale, size-1), Point((i+1)*scale-1, size-realValue), Scalar(255));
    }
    imshow("[1]", dstImage);
    waitKey(0);
    return 0;
}

