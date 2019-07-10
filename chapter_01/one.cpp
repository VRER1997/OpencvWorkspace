#include <iostream>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat srcImage = imread("1.jpg");
    if(!srcImage.data)
        cout << "File do not load" << endl;
    else
        imshow("One Ya", srcImage);
    waitKey(0);
    return 0;;
}