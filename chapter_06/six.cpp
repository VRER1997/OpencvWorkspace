//
// Created by c1over on 2019-07-07.
//
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

#define WINDOW_NAME "[Program]"

int g_nThresholdValue = 100, g_nThresholdType = 3;
Mat g_srcImage, g_grayImage, g_dstImage;

void on_Threshold(int ,void*);
int main(){
    g_srcImage = imread("6.jpg");
    cvtColor(g_srcImage, g_grayImage, COLOR_RGB2GRAY);

    namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
    createTrackbar("Mode", WINDOW_NAME, &g_nThresholdType, 4, on_Threshold);
    createTrackbar("Value", WINDOW_NAME, &g_nThresholdValue, 255, on_Threshold);

    on_Threshold(0, 0);

    while(char(waitKey(20)) != 27) {}

    return 0;
}
void on_Threshold(int, void*){
    threshold(g_grayImage, g_dstImage, g_nThresholdValue, 255, g_nThresholdType);
    imshow(WINDOW_NAME, g_dstImage);
}
