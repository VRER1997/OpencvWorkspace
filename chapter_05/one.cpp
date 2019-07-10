//
// Created by c1over on 2019-07-05.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void colorReduce(Mat& inputImage, Mat& outputImage, int div){
    outputImage = inputImage.clone();
    int rows = outputImage.rows;
    int cols = outputImage.cols * outputImage.channels();

    for(int i = 0; i < rows; i++){
        uchar* data = outputImage.ptr<uchar>(i);
        for(int j = 0; j < cols; j++){
            data[j] = data[j] / div * div + div / 2;
        }
    }
}

int main(){
    Mat srcImage = imread("1.jpg");
    imshow("[Origin]:", srcImage);

    Mat dstImage;
    dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());

    double time0 = static_cast<double>(getTickCount());

    colorReduce(srcImage, dstImage, 32);

    time0 = ((double)getTickCount() - time0) / getTickFrequency();
    cout << time0 << "second" << endl;

    imshow("Result", dstImage);
    waitKey(0);
    return 0;
}