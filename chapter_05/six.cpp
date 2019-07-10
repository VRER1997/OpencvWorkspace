//
// Created by c1over on 2019-07-06.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace cv;

int main(){
    FileStorage fs("test.yaml", FileStorage::READ);

    int frameCount = (int)fs["frameCount"];
    string date;
    fs["calibrationDate"] >> date;

    Mat cameraMat, distCoef;
    fs["cameraMatrix"] >> cameraMat;
    fs["distCoeffs"] >> distCoef;

    cout << "frameCount : " << frameCount << endl
         << "calibrationDate" << date << endl
         << "cameraMatrix" << cameraMat << endl
         << "distCoeffs" << distCoef << endl;

    FileNode features = fs["features"];
    FileNodeIterator it = features.begin(), it_end = features.end();
    int idx = 0;
    vector<uchar> lbpval;

    for(; it != it_end; it++, idx++){
        cout << "feature #" << idx << " : " << endl;
        cout << "x = " << (int)(*it)["x"] << ", y = " << (int)(*it)["y"] << ", lbp: (";

        (*it)["lbp"] >> lbpval;
        for(int i = 0; i < (int)lbpval.size(); i++){
            cout << " " << (int)lbpval[i];
        }
        cout << ")" << endl;
    }

    fs.release();

    getchar();

    return 0;
}