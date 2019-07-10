//
// Created by c1over on 2019-07-07.
//
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

#define WINDOW_NAME "[Window]"

Mat g_srcImage, g_dstImage, g_tempImage;

int main(){

    g_srcImage = imread("5.jpg");

    namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
    imshow(WINDOW_NAME, g_srcImage);

    g_tempImage = g_srcImage;
    g_dstImage = g_tempImage;

    int key = 0;

    while(1){
        key = waitKey(9);

        switch(key){
            case 27 :
                return 0;
                break;
            case 'q':
                return 0;
                break;
            case 'a':
                pyrUp(g_tempImage, g_dstImage, Size(g_tempImage.cols*2, g_tempImage.rows*2));
                printf("A   pyrUP()");
                break;
            case 'w':
                resize(g_tempImage, g_dstImage, Size(g_tempImage.cols*2, g_tempImage.rows*2));
                printf("W   Size()");
                break;
            case 'd':
                pyrDown(g_tempImage, g_dstImage, Size(g_tempImage.cols/2, g_tempImage.rows/2));
                printf("D   pyrDown()");
                break;
            case 's':
                resize(g_tempImage, g_dstImage, Size(g_tempImage.cols/2, g_tempImage.rows/2));
                printf("S pyrDown()");
                break;
        }
        imshow(WINDOW_NAME, g_dstImage);

        g_tempImage = g_dstImage;
    }
}