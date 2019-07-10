//
// Created by c1over on 2019-07-04.
//

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(){
    Mat srcImage = imread("2.jpg");
    imshow("[Origin]:", srcImage);

    Mat element = getStructuringElement(MORPH_RECT, Size(15,15));
    Mat desImage;
    erode(srcImage, desImage, element);

    imshow("[Afeter]:", desImage);
    waitKey(0);
    return 0;
}