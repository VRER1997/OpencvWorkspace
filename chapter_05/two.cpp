//
// Created by c1over on 2019-07-05.
//

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void ROI_AddImage(){
    Mat srcImage = imread("dota_pa.jpg");
    Mat logoImage = imread("dota_logo.jpg");

    Mat imageROI = srcImage(Rect(200, 250, logoImage.cols, logoImage.rows));
    Mat mask = imread("dota_logo.jpg", 0);
    logoImage.copyTo(imageROI, mask);

    imshow("[Result]:", srcImage);
}

void LinearBlending(){
    double alphaValue = 0.5;
    double betaValue = 1.0 - alphaValue;

    Mat srcImage1, srcImage2, dstImage;

    srcImage1 = imread("mogu.jpg");
    srcImage2 = imread("rain.jpg");

    addWeighted(srcImage1, alphaValue, srcImage2, betaValue, 0.0, dstImage);

    imshow("[2]", srcImage1);
    imshow("[22]", dstImage);
}

void ROI_LinearBlending(){
    Mat srcImage = imread("dota_pa.jpg");
    Mat logoImage = imread("dota_logo.jpg");

    Mat imageROI = srcImage(Rect(200, 250, logoImage.cols, logoImage.rows));
    //Mat mask = imread("dota_logo.jpg", 0);
    //logoImage.copyTo(imageROI, mask);

    addWeighted(imageROI, 0.5, logoImage, 0.3, 0.0, imageROI);
    imshow("[Result]:", srcImage);
}

int main(){

    //ROI_AddImage();
    //LinearBlending();
    ROI_LinearBlending();

    waitKey(0);
    return 0;
}
