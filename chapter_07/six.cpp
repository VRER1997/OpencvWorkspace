//
// Created by c1over on 2019-07-08.
//
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

#define WINDOW_NAME1 "[0]"
#define WINDOW_NAME2 "[1]"
#define WINDOW_NAME3 "[2]"

int main(){
    Point2f srcTriangle[3], dstTriangle[3];

    Mat rotMat(2, 3, CV_32FC1);
    Mat warpMat(2, 3, CV_32FC1);
    Mat srcImage, dstImage_wrap, dstImage_warp_rotate;

    srcImage = imread("6.jpg");
    dstImage_wrap = Mat::zeros(srcImage.size(), srcImage.type());

    srcTriangle[0] = Point2f( 0,0 );
    srcTriangle[1] = Point2f( static_cast<float>(srcImage.cols - 1), 0 );
    srcTriangle[2] = Point2f( 0, static_cast<float>(srcImage.rows - 1 ));

    dstTriangle[0] = Point2f( static_cast<float>(srcImage.cols*0.0), static_cast<float>(srcImage.rows*0.33));
    dstTriangle[1] = Point2f( static_cast<float>(srcImage.cols*0.65), static_cast<float>(srcImage.rows*0.35));
    dstTriangle[2] = Point2f( static_cast<float>(srcImage.cols*0.15), static_cast<float>(srcImage.rows*0.6));

    warpMat = getAffineTransform(srcTriangle, dstTriangle);

    warpAffine(srcImage, dstImage_wrap, warpMat, dstImage_wrap.size());

    Point center = Point(dstImage_wrap.cols/2, dstImage_wrap.rows/2);
    double angle = -30.0;
    double scale = 0.8;

    rotMat = getRotationMatrix2D(center, angle, scale);

    warpAffine(dstImage_wrap, dstImage_warp_rotate, rotMat, dstImage_wrap.size());

    imshow(WINDOW_NAME1, srcImage);
    imshow(WINDOW_NAME2, dstImage_wrap);
    imshow(WINDOW_NAME3, dstImage_warp_rotate);

    waitKey(0);
    return 0;
}
