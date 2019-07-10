#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

Mat g_srcImage, g_srcGrayImage,g_dstImage;

Mat g_cannyDetectedEdges;
int g_cannyLowThreshold=1;//TrackBarλ�ò���

Mat g_sobelGradient_X, g_sobelGradient_Y;
Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
int g_sobelKernelSize=1;//TrackBarλ�ò���

Mat g_scharrGradient_X, g_scharrGradient_Y;
Mat g_scharrAbsGradient_X, g_scharrAbsGradient_Y;


static void on_Canny(int, void*);
static void on_Sobel(int, void*);
void Scharr( );

int main( int argc, char** argv )
{
    namedWindow("[0]");
    imshow("[0]", g_srcImage);

    g_dstImage.create( g_srcImage.size(), g_srcImage.type() );

    cvtColor( g_srcImage, g_srcGrayImage, COLOR_BGR2GRAY );

    namedWindow( "[1 canny]", WINDOW_AUTOSIZE );
    namedWindow( "[2 sobel]", WINDOW_AUTOSIZE );

    createTrackbar( "value", "[1 canny]", &g_cannyLowThreshold, 120, on_Canny );
    createTrackbar( "value", "[2 sobel]", &g_sobelKernelSize, 3, on_Sobel );

    on_Canny(0, 0);
    on_Sobel(0, 0);

    Scharr( );

    while((char(waitKey(1)) != 'q')) {}

    return 0;
}

void on_Canny(int, void*)
{
    blur( g_srcGrayImage, g_cannyDetectedEdges, Size(3,3) );

    Canny( g_cannyDetectedEdges, g_cannyDetectedEdges, g_cannyLowThreshold, g_cannyLowThreshold*3, 3 );
    g_dstImage = Scalar::all(0);

    g_srcImage.copyTo( g_dstImage, g_cannyDetectedEdges);

    imshow( "[1 canny]", g_dstImage );
}

void on_Sobel(int, void*)
{
    Sobel( g_srcImage, g_sobelGradient_X, CV_16S, 1, 0, (2*g_sobelKernelSize+1), 1, 1, BORDER_DEFAULT );
    convertScaleAbs( g_sobelGradient_X, g_sobelAbsGradient_X );//�������ֵ���������ת����8λ

    Sobel( g_srcImage, g_sobelGradient_Y, CV_16S, 0, 1, (2*g_sobelKernelSize+1), 1, 1, BORDER_DEFAULT );
    convertScaleAbs( g_sobelGradient_Y, g_sobelAbsGradient_Y );//�������ֵ���������ת����8λ

    addWeighted( g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, g_dstImage );

    imshow("[2 sobel]", g_dstImage);

}


void Scharr( )
{
    Scharr( g_srcImage, g_scharrGradient_X, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT );
    convertScaleAbs( g_scharrGradient_X, g_scharrAbsGradient_X );//�������ֵ���������ת����8λ

    Scharr( g_srcImage, g_scharrGradient_Y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT );
    convertScaleAbs( g_scharrGradient_Y, g_scharrAbsGradient_Y );//�������ֵ���������ת����8λ

    addWeighted( g_scharrAbsGradient_X, 0.5, g_scharrAbsGradient_Y, 0.5, 0, g_dstImage );

    imshow("[3 scharr]", g_dstImage);
}
