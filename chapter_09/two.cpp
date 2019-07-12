#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

int main( ){
    Mat srcImage_base, hsvImage_base;
    Mat srcImage_test1, hsvImage_test1;
    Mat srcImage_test2, hsvImage_test2;
    Mat hsvImage_halfDown;

    srcImage_base = imread( "2.jpg",1 );
    srcImage_test1 = imread( "3.jpg", 1 );
    srcImage_test2 = imread( "4.jpg", 1 );
    imshow("[0]", srcImage_base);
    imshow("[1]",srcImage_test1);
    imshow("[2]",srcImage_test2);

    cvtColor( srcImage_base, hsvImage_base,  COLOR_BGR2HSV );
    cvtColor( srcImage_test1, hsvImage_test1, COLOR_BGR2HSV );
    cvtColor( srcImage_test2, hsvImage_test2, COLOR_BGR2HSV );

    hsvImage_halfDown = hsvImage_base( Range( hsvImage_base.rows/2, hsvImage_base.rows - 1 ), Range( 0, hsvImage_base.cols - 1 ) );

    int h_bins = 50; int s_bins = 60;
    int histSize[] = { h_bins, s_bins };
    float h_ranges[] = { 0, 256 };
    float s_ranges[] = { 0, 180 };
    const float* ranges[] = { h_ranges, s_ranges };
    int channels[] = { 0, 1 };

    MatND baseHist;
    MatND halfDownHist;
    MatND testHist1;
    MatND testHist2;

    calcHist( &hsvImage_base, 1, channels, Mat(), baseHist, 2, histSize, ranges, true, false );
    normalize( baseHist, baseHist, 0, 1, NORM_MINMAX, -1, Mat() );

    calcHist( &hsvImage_halfDown, 1, channels, Mat(), halfDownHist, 2, histSize, ranges, true, false );
    normalize( halfDownHist, halfDownHist, 0, 1, NORM_MINMAX, -1, Mat() );

    calcHist( &hsvImage_test1, 1, channels, Mat(), testHist1, 2, histSize, ranges, true, false );
    normalize( testHist1, testHist1, 0, 1, NORM_MINMAX, -1, Mat() );

    calcHist( &hsvImage_test2, 1, channels, Mat(), testHist2, 2, histSize, ranges, true, false );
    normalize( testHist2, testHist2, 0, 1, NORM_MINMAX, -1, Mat() );


    for( int i = 0; i < 4; i++ ){
        int compare_method = i;
        double base_base = compareHist( baseHist, baseHist, compare_method );
        double base_half = compareHist( baseHist, halfDownHist, compare_method );
        double base_test1 = compareHist( baseHist, testHist1, compare_method );
        double base_test2 = compareHist( baseHist, testHist2, compare_method );
        printf( " method [%d] : \n\n base_base %f, base_half %f,base_test1 %f, base_test2 %f -----------\n",
                i, base_base, base_half , base_test1, base_test2 );
    }
    waitKey(0);
    return 0;
}