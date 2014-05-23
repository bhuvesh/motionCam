#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

Mat src, src_gray;
Mat detected_edges, detected_harris, detected_harris_norm, detected_harris_norm_scaled;

int thresh=190;



void Harris()
{
	blur( src_gray, src_gray, Size(3,3) ); //noise reduction

	cornerHarris(src_gray, detected_harris, 5, 5 , 0.09); //CornerHarris

	normalize( detected_harris, detected_harris_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );  //Normalisation and Scaling
    convertScaleAbs( detected_harris_norm, detected_harris_norm_scaled );



    for( int j = 0; j < detected_harris_norm.rows ; j++ ) //Drawing circles arounf the corners
    { for( int i = 0; i < detected_harris_norm.cols; i++ )
    {
        if( (int) detected_harris_norm.at<float>(j,i) > thresh )
        {
           circle( detected_harris_norm_scaled, Point( i, j ), 5,  Scalar(0), 2, 8, 0 );
        }
    }
    }

    imshow( "CornerHarris", detected_harris_norm_scaled );

}
int main( int argc, char** argv )
{
	// Load an image
	src = imread( argv[1] );

	if( !src.data ) //Check if image has been loaded
	{ return -1; }


	cvtColor( src, src_gray, CV_BGR2GRAY ); //Grayscale the image
	
	detected_harris = Mat::zeros( src.size(), CV_32FC1 );

	namedWindow( "CornerHarris", CV_WINDOW_AUTOSIZE );

	printf("\nEnter the CornerHarris threshold (Should be about 190 - 250) : \n");
	scanf("%d",&thresh);
	
	Harris();

	waitKey(0);

	return 0;
  }
