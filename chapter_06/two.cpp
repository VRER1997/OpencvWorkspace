//
// Created by c1over on 2019-07-06.
//
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat image = imread("2.jpg");
    imshow("[0]", image);

    Mat element, out;

    element = getStructuringElement(MORPH_RECT, Size(15, 15));
    dilate(image, out, element);
    imshow("[1]", out);

    erode(image, out, element);
    imshow("[2]", out);

    waitKey(0);
    return 0;
}

