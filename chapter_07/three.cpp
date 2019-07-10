//
// Created by c1over on 2019-07-07.
//

#include <vector>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    Mat srcImage = imread("3.jpg");
    Mat tempImage, dstImage;

    Canny(srcImage, tempImage, 50, 200);
    cvtColor(tempImage, dstImage, COLOR_GRAY2BGR);

    vector<Vec2f> lines;
    HoughLines(tempImage, lines, 1, CV_PI/180, 150);

    for(size_t i = 0; i < lines.size(); i++){
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*a);
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*a);

        line(dstImage, pt1, pt2, Scalar(55, 100, 195), 1, LINE_AA);
    }

    imshow("[0]", srcImage);
    imshow("[1]", tempImage);
    imshow("[2]", dstImage);

    waitKey(0);
    return 0;
}

