//
// Created by c1over on 2019-07-12.
//
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

#define WINDOW_NAME "[1]"

Mat g_srcImage, g_grayImage;
int g_maxCornerNumber = 3;
int g_maxTrackbarNumber = 500;
RNG g_rng(12345);

void on_GoodFeaturesToTrack(int, void*){
    if(g_maxCornerNumber <= 1){
        g_maxCornerNumber = 1;
    }

    vector<Point2f> corners;
    double qualityLevel = 0.01;
    double minDistance = 10;
    int blockSize = 3;
    double k = 0.04;
    Mat copy = g_srcImage.clone();
    goodFeaturesToTrack(g_grayImage, corners, g_maxCornerNumber, qualityLevel, minDistance, Mat(), blockSize,false, k);

    cout << "corner.size = " << corners.size() << endl;

    int r = 4;
    for(unsigned int i = 0; i < corners.size(); i++){
        circle(copy, corners[i], r, Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));
    }

    imshow("[1]", copy);
}

int main(){

    g_srcImage = imread("2.jpg");
    cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
    namedWindow(WINDOW_NAME);
    createTrackbar("corner number:", WINDOW_NAME, &g_maxCornerNumber, g_maxTrackbarNumber, on_GoodFeaturesToTrack);
    imshow(WINDOW_NAME, g_srcImage);
    on_GoodFeaturesToTrack(0, 0);
    waitKey(0);
    return 0;
}

