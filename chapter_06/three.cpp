//
// Created by c1over on 2019-07-06.
//
#include <opencv2/opencv.hpp>
using namespace cv;

Mat g_srcImage, g_dstImage, element;
int g_nTrackbarNumber = 0;
int g_nStructElementSize = 3;

void Process();
void on_TrackbarNumberChange(int, void*);
void on_ElementSizeChange(int, void*);

int main(){
    g_srcImage = imread("3.jpg");
    imshow("[0]", g_srcImage);

    namedWindow("[1]");
    element = getStructuringElement(MORPH_RECT, Size(2*g_nStructElementSize+1,2*g_nStructElementSize+1),
                Point(g_nStructElementSize, g_nStructElementSize));
    erode(g_srcImage, g_dstImage, element);
    imshow("[1]", g_dstImage);

    createTrackbar("erode/dilate:", "[1]", &g_nTrackbarNumber, 1, on_TrackbarNumberChange);
    createTrackbar("Size:", "[1]", &g_nStructElementSize, 21, on_ElementSizeChange);

    while (char(waitKey(1)) != 'q') {}

    return 0;
}

void Process(){
    if(g_nTrackbarNumber){
        //dilate(g_srcImage, g_dstImage, element);
        morphologyEx(g_srcImage, g_dstImage, MORPH_DILATE, element);
    } else {
        //erode(g_srcImage, g_dstImage, element);
        morphologyEx(g_srcImage, g_dstImage, MORPH_ERODE, element);
    }
    imshow("[1]", g_dstImage);
}

void on_TrackbarNumberChange(int, void *){
    Process();
}

void on_ElementSizeChange(int, void*){
    Process();
}