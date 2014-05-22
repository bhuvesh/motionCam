#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;


Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edges";

void CannyThreshold()
{
	// Reduce noise 
	blur( src_gray, detected_edges, Size(3,3) );

	// Canny detector
	Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

	// Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);

	src.copyTo( dst, detected_edges);
	imshow( window_name, dst );
 }


int main( int argc, char** argv )
{
	// Load an image
	src = imread( argv[1] );

	if( !src.data ) //Check i image has been loaded
	{ return -1; }

	dst.create( src.size(), src.type() ); // Create a matrix same size as of the loaded image

	cvtColor( src, src_gray, CV_BGR2GRAY ); //Grayscale the image

	namedWindow( window_name, CV_WINDOW_AUTOSIZE );

	printf("\nEnter the value of canny threshold!:\n");
	scanf("%d",&lowThreshold);
	CannyThreshold();

	waitKey(0);

	return 0;
  }
