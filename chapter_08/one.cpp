//
// Created by c1over on 2019-07-10.
//
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

int main(){
    Mat srcImage = imread("1.jpg", 0);
    imshow("[0]", srcImage);

    Mat dstImage = Mat::zeros(srcImage.size(), srcImage.type());

    srcImage = srcImage > 119;
    imshow("[1]", srcImage);

    vector< vector< Point > > contours;
    vector<Vec4i> hierarchy;

    findContours(srcImage, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

    int index = 0;
    for(; index >= 0; index = hierarchy[index][0]){
        Scalar color( random()&255, rand()&255, rand()&255);
        drawContours(dstImage, contours, index, color, FILLED, 8, hierarchy);
    }
    imshow("[2]", dstImage);

    waitKey(0);
    return 0;
}
