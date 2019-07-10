//
// Created by c1over on 2019-07-06.
//
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat image = imread("1.jpg");

    imshow("[0]", image);

    Mat out;

    boxFilter(image, out, -1, Size(5,5));
    imshow("[1]", out);

    blur(image, out, Size(7,7));
    imshow("[2]", out);

    GaussianBlur(image, out, Size(3,3), 0, 0);
    imshow("[3]", out);

    medianBlur(image, out, 7);
    imshow("[4]", out);

    bilateralFilter(image, out, 25, 25*2, 25/2);
    imshow("[5]", out);

    waitKey(0);
    return 0;
}
