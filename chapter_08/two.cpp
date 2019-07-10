//
// Created by c1over on 2019-07-10.
//
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

#define WINDOW_NAME "[0]"
#define WINDOW_NAME1 "[1]"

Mat g_srcImage, g_grayImage;
int g_nThresh = 80, g_nThresh_max = 255;
RNG g_rng(12345);
Mat g_cannyMat_output;
vector<vector<Point> > g_vContours;
vector<Vec4i> g_vHierarchy;

void on_ThreshChange(int, void*);

int main(){
   g_srcImage = imread("2.jpg");

   cvtColor(g_srcImage, g_grayImage, COLOR_BGR2GRAY);
   blur(g_grayImage, g_grayImage, Size(3, 3));

   namedWindow(WINDOW_NAME);
   imshow(WINDOW_NAME, g_srcImage);

   createTrackbar("canny threshold", WINDOW_NAME, &g_nThresh, g_nThresh_max, on_ThreshChange);
   on_ThreshChange(0, 0);

   waitKey(0);
   return 0;
}

void on_ThreshChange(int, void*){

    Canny(g_grayImage, g_cannyMat_output, g_nThresh, g_nThresh*2, 3);

    findContours(g_cannyMat_output, g_vContours, g_vHierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE, Point(0,0));
    Mat drawing = Mat::zeros(g_cannyMat_output.size(), CV_8UC3);

    for(int i = 0; i < g_vContours.size(); i++){
        Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));
        drawContours(drawing, g_vContours, i, color, 2, 8, g_vHierarchy, 0, Point());
    }

    imshow(WINDOW_NAME1, drawing);
}
