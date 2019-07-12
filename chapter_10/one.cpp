//
// Created by c1over on 2019-07-12.
//

#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat srcImage = imread("1.jpg", 0);
    imshow("[0]", srcImage);

    Mat corner;
    cornerHarris(srcImage, corner, 2, 3, 0.01);

    Mat harrisCorner;
    threshold(corner, harrisCorner, 0.00001, 255, THRESH_BINARY);
    imshow("[1]", harrisCorner);

    waitKey(0);
    return 0;
}
