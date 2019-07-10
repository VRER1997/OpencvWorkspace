//
// Created by c1over on 2019-07-07.
//
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src = imread("1.jpg");
    Mat src1 = src.clone();
    imshow("[0]:", src);

    Mat dst, edge, gray;

    dst.create(src.size(), src.type());
    cvtColor(src, gray, COLOR_BGR2GRAY);
    blur(gray, edge, Size(3,3));
    Canny(edge, edge, 3, 9, 3);

    dst = Scalar::all(0);
    src1.copyTo(dst, edge);

    imshow("[1]", dst);
    waitKey(0);
    return 0;
}
