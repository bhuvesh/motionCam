#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "datetime.h"
using namespace cv;
using namespace std;


Mat src_laplace,show_laplace;

Mat laplace(Mat src2,int kernel_size)
{
	Mat dst;
	kernel_size=2*kernel_size +1;
  int scale = 2;
  int delta = 0;
  int ddepth = CV_16S;

	Mat src_gray;
	Mat src = src2.clone();
	GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );

	cvtColor( src, src_gray, CV_RGB2GRAY );
	

	Mat abs_dst;

  Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( dst, abs_dst );
 // bitwise_not(abs_dst,abs_dst);

	return abs_dst;
}


static void onTrackbar_laplace(int thres, void* )
{	   

    laplace(src_laplace,thres).copyTo(show_laplace);	    
    imshow("Laplace", show_laplace);
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
void laplace_file(char* dest)
{	int thres=1;
	src_laplace=imread(dest);
	namedWindow( "Laplace", CV_WINDOW_AUTOSIZE );
	laplace(src_laplace,thres).copyTo(show_laplace);
	imshow("Laplace",show_laplace);

    createTrackbar("Kernel", "Laplace", &thres, 2, onTrackbar_laplace);
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
		    strcat(filename,"_laplace.jpg");

		    imwrite(filename,show_laplace);
		    cout << "Saved " << filename << endl;
		}
	}

	destroyWindow("Laplace");

}

void laplace_cam()
{
	int thres=1;
	
	namedWindow("Laplace",CV_WINDOW_AUTOSIZE);



    createTrackbar("Kernel", "Laplace", &thres, 2, onTrackbar_laplace);

	char filename[200];
	char filename2[200]="pimages/laplace/";
	char c;
	VideoCapture cap;
	cap.open(0);
	while(1)
    {	cap>>src_laplace;
    	laplace(src_laplace,thres).copyTo(show_laplace);
    	imshow("Laplace",show_laplace);
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
	        imwrite(filename2,show_laplace);
	        cout << "Saved " << filename << endl;

    	}
    	else if(c==27)
    		{destroyWindow("Laplace");break;}
    }
}
/*
int main( int argc, char** argv )
{
	Mat src = imread( argv[1] );

	if( !src.data ) //Check i image has been loaded
	{ laplace_cam(); }
	else
	{
		laplace_file(argv[1]);
	}


}
*/