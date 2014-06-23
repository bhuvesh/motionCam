#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "datetime.h"

using namespace cv;
using namespace std;
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
Mat sepia(Mat src)
{

	Mat image_copy = src.clone();
	Mat kern = (cv::Mat_<float>(4,4) <<  0.272, 0.534, 0.131, 0,
                                             0.349, 0.686, 0.168, 0,
                                             0.393, 0.769, 0.189, 0,
                                             0, 0, 0, 1);
	transform(src, image_copy, kern);

	return image_copy;
}


void sepia_file(char* dest)
{
	Mat show=imread(dest);
	namedWindow( "Sepia", CV_WINDOW_AUTOSIZE );
	sepia(show).copyTo(show);	
	waitKey(5);
	imshow("Sepia",show);
	waitKey(0);
	char filename[200];
 	sprintf(filename,"%s",dest);
    int i;
    for(i=0;i<strlen(filename);i++)
    {
        if (filename[i]=='.')
            break;
    }
    filename[i]='\0';
    strcat(filename,"_sepia.jpg");

    imwrite(filename,show);
    cout << "Saved " << filename << endl;
    destroyWindow("Sepia");

}

void sepia_cam()
{
	Mat frame;
	char filename[200];
	char filename2[200]="pimages/sepia/";
	char c;
	namedWindow("Sepia",CV_WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open(0);
	while(1)
    {	cap>>frame;
    	sepia(frame).copyTo(frame);
    	imshow("Sepia",frame);
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
	        imwrite(filename2,frame);
	        cout << "Saved " << filename << endl;

    	}
    	else if(c==27)
    		{destroyWindow("Sepia");break;}
    }
}
/*

int main( int argc, char** argv )
{
	// Load an image
	Mat src = imread( argv[1] );

	if( !src.data ) //Check i image has been loaded
	{ sepia_cam(); }
	else
	{
		sepia_file(argv[1]);
	}

}*/