//
// Created by c1over on 2019-07-04.
//

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

int main(){
    Mat srcImage = imread("4.jpg");
    imshow("[Origin]:", srcImage);

    Mat edge, grayImage;
    //灰度化
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
    //降噪
    blur(grayImage, edge, Size(3,3));
    Canny(edge, edge, 3, 9, 3);
    imshow("[After]:", edge);

    waitKey(0);
    return 0;
}
