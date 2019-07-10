//
// Created by c1over on 2019-07-04.
//

#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    VideoCapture capture("1.avi");
    Mat frame;
    while (1){

        capture >> frame;

        if(frame.empty())
            break;

        imshow("Reading Video", frame);
        waitKey(30);
    }
    return 0;
}
