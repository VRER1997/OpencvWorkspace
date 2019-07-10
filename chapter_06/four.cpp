//
// Created by c1over on 2019-07-06.
//

#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src = imread("4.jpg");
    imshow("[0]", src);

    Rect ccomp;
    floodFill(src, Point(50, 300), Scalar(155, 255, 55), &ccomp, Scalar(20, 20, 20), Scalar(20, 20, 20));
    imshow("[1]", src);

    waitKey(0);
    return 0;
}