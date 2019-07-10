//
// Created by c1over on 2019-07-10.
//
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

#define WINDOW_NAME "[0]"
#define WINDOW_NAME1 "[1]"

Mat g_srcImage, g_grayImage;
int g_nThresh = 50, g_maxThresh = 255;
RNG g_rng(12345);
Mat srcImage_copy = g_srcImage.clone();
Mat g_thresholdImage_output;
vector<vector<Point> > g_vContours;
vector<Vec4i> g_vHierarchy;

void on_ThresholdChange(int, void*);

int main(){

    g_srcImage = imread("3.jpg");
    cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
    blur(g_grayImage, g_grayImage, Size(3, 3));

    namedWindow(WINDOW_NAME);
    imshow(WINDOW_NAME, g_grayImage);

    createTrackbar("Value:", WINDOW_NAME, &g_nThresh, g_maxThresh, on_ThresholdChange);
    on_ThresholdChange(0, 0);

    waitKey(0);
    return 0;
}

void on_ThresholdChange(int, void*){
    threshold(g_grayImage, g_thresholdImage_output, g_nThresh, 255, THRESH_BINARY);
    findContours(g_thresholdImage_output, g_vContours, g_vHierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE, Point(0,0));

    vector<vector<Point> >hull(g_vContours.size());
    for(unsigned int i = 0; i < g_vContours.size(); i++){
        convexHull(Mat(g_vContours[i]), hull[i], false);
    }

    Mat drawing = Mat::zeros(g_thresholdImage_output.size(), CV_8UC3);
    for(unsigned int i = 0; i < g_vContours.size(); i++){
        Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));
        drawContours(drawing, g_vContours, i, color, 2, 8, g_vHierarchy, 0, Point());
        drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
    }

    imshow(WINDOW_NAME1, drawing);
}
