//
// Created by c1over on 2019-07-05.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
using namespace cv;
using namespace std;

void ChannelBlending(){
    Mat srcImage = imread("dota_jugg.jpg");
    Mat logoImage = imread("dota_logo.jpg", 0);

    vector<Mat> channels;
    split(srcImage, channels);

    Mat imageBuluChannel = channels.at(0);
    Mat ROI = imageBuluChannel(Rect(500, 250, logoImage.cols, logoImage.rows));
    addWeighted(ROI, 1.0, logoImage, 0.5, 0, ROI);

    merge(channels, srcImage);

    imshow("Result", srcImage);
}

int main(){
    ChannelBlending();
    waitKey(0);
    return 0;
}