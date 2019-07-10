//
// Created by c1over on 2019-07-05.
//

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int g_nConstrastValue;
int g_nBrightValue;
Mat g_srcImage, g_dstImage;

static void on_ContrastAndBright(int, void*);

int main(){
    g_srcImage = imread("4.jpg");
    g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

    g_nConstrastValue = 80;
    g_nBrightValue = 80;

    namedWindow("[2]", 1);

    createTrackbar("ConstrastValue: ", "[2]", &g_nConstrastValue, 300, on_ContrastAndBright);
    createTrackbar("BrightValue: ", "[2]", &g_nBrightValue, 200, on_ContrastAndBright);

    on_ContrastAndBright(g_nConstrastValue, 0);
    on_ContrastAndBright(g_nBrightValue, 0);

    while(char(waitKey(1)) != 'q') {}
    return 0;
}

static void on_ContrastAndBright(int, void*){
    namedWindow("[1]", 1);
    for(int y = 0; y < g_srcImage.rows; y++){
        for(int x = 0; x < g_srcImage.cols; x++){
            for(int c = 0; c < 3; c++) {
                g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(
                        (g_nConstrastValue * 0.01) * (g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
            }
        }
    }
    imshow("[1]", g_srcImage);
    imshow("[2]", g_dstImage);
}