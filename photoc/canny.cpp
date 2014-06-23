#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "datetime.h"

using namespace cv;
using namespace std;


Mat src_canny,show_canny;


Mat cannye(Mat src, int lowThreshold,int ksize=3)
{	int ratio = 3;
	Mat detected_edges, dst, src_gray;
	cvtColor( src, src_gray, CV_BGR2GRAY );

	// Reduce noise 
	blur( src_gray, detected_edges, Size(ksize,ksize) );

	// Canny detector
	Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, ksize );


	// Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);

	//bitwise_not(detected_edges, detected_edges);

	src.copyTo( dst, detected_edges);
	
	//return detected_edges;
	return dst;

}

static void onTrackbar_canny(int thres, void* )
{	   

    cannye(src_canny,thres).copyTo(show_canny);	    
    imshow("Canny", show_canny);
}	

/*
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
*/

void cannye_file(char* dest)
{	int thres=50;
	src_canny=imread(dest);
	namedWindow( "Canny", CV_WINDOW_AUTOSIZE );
	cannye(src_canny,thres).copyTo(show_canny);
	imshow("Canny",show_canny);

    createTrackbar("Canny threshold", "Canny", &thres, 60, onTrackbar_canny);

	 int c=0;
    while(c!=27)
    {
	c=waitKey(5);
	if(c=='s')
		{	char filename[200];
		 	sprintf(filename,"%s",dest);
		    int i;
		    for(i=0;i<strlen(filename);i++)
		    {
		        if (filename[i]=='.')
		            break;
		    }
		    filename[i]='\0';
		    strcat(filename,"_canny.jpg");

		    imwrite(filename,show_canny);
		    cout << "Saved " << filename << endl;
		}
	}

	destroyWindow("Canny");
}

void cannye_cam()
{
	int thres=50;
	
	namedWindow("Canny",CV_WINDOW_AUTOSIZE);



    createTrackbar("Canny threshold", "Canny", &thres, 60, onTrackbar_canny);

	char filename[200];
	char filename2[200]="pimages/cannye/";
	char c;
	VideoCapture cap;
	cap.open(0);
	while(1)
    {	cap>>src_canny;
    	cannye(src_canny,thres).copyTo(show_canny);
    	imshow("Canny",show_canny);
    	c=waitKey(5);
    	if(c=='s')
	    {	
	    	const std::string s0=currentDateTime();
	        const char* s1;
	        s1 = s0.c_str();
	        sprintf(filename,"%s",s1);
	        filename[4]=filename[10]=filename[7]=filename[13]=filename[16]='_';
	        filename[19]='.';filename[20]='j';filename[21]='p';filename[22]='g';filename[23]='\0'; 
	        strcat(filename2,filename);	       
	        imwrite(filename2,show_canny);
	        cout << "Saved " << filename << endl;

    	}
    	else if(c==27)
    		{destroyWindow("Canny");break;}
    }
}
/*

int main( int argc, char** argv )
{
// Load an image
	Mat src = imread( argv[1] );

	if( !src.data ) //Check i image has been loaded
	{ cannye_cam(); }
	else
	{
		cannye_file(argv[1]);
	}
}
*/


