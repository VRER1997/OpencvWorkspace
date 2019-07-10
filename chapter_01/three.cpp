//
// Created by c1over on 2019-07-04.
//

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(){
    Mat srcImage = imread("3.jpg");
    imshow("[Origin]:", srcImage);

    Mat desImage;
    blur(srcImage, desImage, Size(7,7));
    imshow("[After]:", desImage);

    waitKey(0);
    return 0;
}
