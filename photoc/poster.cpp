#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "datetime.h"

using namespace cv;
using namespace std;


Mat src_poster,show_poster;
int thres_poster,thres2_poster;



Mat poster(Mat src, double sp, double sr)
{	sp=sp/10;
	sr=sr/10;
	int ratio = 3;
	Mat dst;
	pyrMeanShiftFiltering(src, dst, sp,sr);
	return dst;

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
static void onTrackbar_poster(int thres_poster, void* )
{	   

    poster(src_poster,thres_poster,thres2_poster).copyTo(show_poster);	    
    imshow("Poster", show_poster);
}
static void onTrackbar_poster2(int thres2_poster, void* )
{	   

    poster(src_poster,thres_poster,thres2_poster).copyTo(show_poster);	    
    imshow("Poster", show_poster);
}

void poster_file(char* dest)
{	thres_poster=100;
	thres2_poster=500;
	src_poster=imread(dest);
	namedWindow( "Poster", CV_WINDOW_AUTOSIZE );
	poster(src_poster,thres_poster,thres2_poster).copyTo(show_poster);
	imshow("Poster",show_poster);

    createTrackbar("Range", "Poster", &thres_poster, 100, onTrackbar_poster);
    createTrackbar("Width", "Poster", &thres2_poster, 1000, onTrackbar_poster2);

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
		    strcat(filename,"_poster.jpg");

		    imwrite(filename,show_poster);
		    cout << "Saved " << filename << endl;
		}
	}

	destroyWindow("Poster");
}

void poster_cam()
{
	thres_poster=100;
	thres2_poster=65;

	namedWindow("Poster",CV_WINDOW_AUTOSIZE);
    createTrackbar("Range", "Poster", &thres_poster, 100, onTrackbar_poster);
    createTrackbar("Width", "Poster", &thres2_poster, 1000, onTrackbar_poster2);

	char filename[200];
	char filename2[200]="pimages/poster/";
	char c;
	VideoCapture cap;
	cap.open(0);
	while(1)
    {	cap>>src_poster;
    	poster(src_poster,thres_poster,thres2_poster).copyTo(show_poster);
    	imshow("Poster",show_poster);
    	c=waitKey(20);
    	if(c=='s')
	    {	
	    	const std::string s0=currentDateTime();
	        const char* s1;
	        s1 = s0.c_str();
	        sprintf(filename,"%s",s1);
	        filename[4]=filename[10]=filename[7]=filename[13]=filename[16]='_';
	        filename[19]='.';filename[20]='j';filename[21]='p';filename[22]='g';filename[23]='\0'; 
	        strcat(filename2,filename);	       
	        imwrite(filename2,show_poster);
	        cout << "Saved " << filename << endl;

    	}
    	else if(c==27)
    		{destroyWindow("Poster");break;}
    }
}

/*
int main( int argc, char** argv )
{
	// Load an image
	Mat src = imread( argv[1] );

	if( !src.data ) //Check i image has been loaded
	{ poster_cam(); }
	else
	{
		poster_file(argv[1]);
	}

}
*/