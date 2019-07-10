//
// Created by c1over on 2019-07-08.
//

#include <vector>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    Mat srcImage = imread("4.jpg");
    Mat midImage;

    imshow("[0]", srcImage);

    cvtColor(srcImage, midImage, COLOR_BGR2GRAY);
    GaussianBlur(midImage, midImage, Size(3,3), 2, 2);

    vector<Vec3f> circles;
    HoughCircles(midImage, circles, HOUGH_GRADIENT, 1.5, 10, 200);

    for(int i = 0; i < circles.size(); i++){
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
        circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
    }

    imshow("[1]", srcImage);
    waitKey(0);
    return 0;


}