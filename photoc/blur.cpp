#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "datetime.h"

using namespace cv;
using namespace std;

Mat src_blur,show_blur;


Mat blurit(Mat src,int ksize)
{

	Mat image_copy;
	
	blur(src,image_copy,Size(ksize,ksize));

	return image_copy;
}


static void onTrackbar_blur(int thres, void* )
{	   

    blurit(src_blur,thres+3).copyTo(show_blur);	    
    imshow("Blur", show_blur);
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
void blurit_file(char* dest)
{	int thres=50;
	src_blur=imread(dest);
	namedWindow( "Blur", CV_WINDOW_AUTOSIZE );
	blurit(src_blur,thres+3).copyTo(show_blur);
	imshow("Blur",show_blur);

    createTrackbar("Kernel", "Blur", &thres, 100, onTrackbar_blur);

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
		    strcat(filename,"_blur.jpg");

		    imwrite(filename,show_blur);
		    cout << "Saved " << filename << endl;
		}
	}

	destroyWindow("Blur");

}

void blurit_cam()
{
	int thres=50;

	namedWindow( "Blur", CV_WINDOW_AUTOSIZE );
	
    createTrackbar("Kernel", "Blur", &thres, 100, onTrackbar_blur);

	char filename[200];
	char filename2[200]="pimages/blurit/";
	char c;
	VideoCapture cap;
	cap.open(0);
	while(1)
    {	cap>>src_blur;
    	blurit(src_blur,thres+3).copyTo(show_blur);
    	imshow("Blur",show_blur);
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
	        imwrite(filename2,show_blur);
	        cout << "Saved " << filename << endl;

    	}
    	else if(c==27)
    		{destroyWindow("Blur");break;}
    }
}

/*

int main( int argc, char** argv )
{
	Mat src = imread( argv[1] );

	if( !src.data ) //Check i image has been loaded
	{ blurit_cam(); }
	else
	{
		blurit_file(argv[1]);
	}

}
*/