//
// Created by c1over on 2019-07-04.
//

#include <opencv2/opencv.hpp>
using namespace cv;

int main(){

    Mat girl = imread("girl.jpg");
    namedWindow("[1]");
    imshow("[1]", girl);

    Mat image = imread("dota.jpg", 199);
    Mat logo = imread("dota_logo.jpg");

    namedWindow("[2]");
    imshow("[2]", image);

    namedWindow("[3]");
    imshow("[3]", logo);

    Mat imageROI = image(Rect(800, 350, logo.cols, logo.rows));
    addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

    namedWindow("[4]");
    imshow("[4]", image);

    imwrite("generate.jpg", image);

    waitKey(0);
    return 0;
}