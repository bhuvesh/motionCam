/*
This is a prototype for achieving our goal of getting rid of the moving object.
It uses a basic average model, which assigns the average value of a pixel in all the frames to
the destination image.

The program will take a video feed. The output image will be saved
in the same directory as a jpg file with the same name as the video file. 

To test this program, pass the executable with the argument of a video file name.

*/





#include "opencv2/core/core.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>

#include <iostream>
#include <vector>

#define DEBUG if(0)

using namespace std;
using namespace cv;



int main( int argc, char** argv )
{

    
    bool update_bg_model = true;

    string arg = argv[1];
    VideoCapture cap(arg); //try to open string, this will attempt to open it as a video file
    if (!cap.isOpened()) 
	{
		cout<<"Error in opening the video\n";
		return 0;
	}

	int max_frames = cap.get(CV_CAP_PROP_FRAME_COUNT);
	namedWindow("OurVector",CV_WINDOW_KEEPRATIO);
	vector <Mat> frames;
	Mat framesarr[50];
 	Mat cur;
 	for(int i=0;i<max_frames;i++)
 	{
 		
 		frames.push_back(Mat());
 		cap >> cur;
 		cur.copyTo(frames.back());
 		imshow("OurVector",frames[i]);
 		waitKey(30);
 	}

 

 	

 	DEBUG for (int i=0;i<max_frames;i++)
 	{
 		imshow("OurVector",frames[i]);
 		waitKey(30);
 	}

 	Mat dst;

 	dst.create( cur.size(), cur.type() );

 	dst = Scalar::all(0);

 	int sum0,sum1,sum2;
	for(int i=0;i<cur.rows;i++)
	{	for(int j=0;j<cur.cols;j++)
		 
		{	
			sum0=0,sum2=0,sum1=0;

			for (int k=0;k<frames.size();k++)
			{	sum0+=frames[k].at<Vec3b>(i,j)[0];
				sum1+=frames[k].at<Vec3b>(i,j)[1];
				sum2+=frames[k].at<Vec3b>(i,j)[2];
			}


			dst.at<Vec3b>(i,j)[0]=sum0/frames.size();

			dst.at<Vec3b>(i,j)[1]=sum1/frames.size();

			dst.at<Vec3b>(i,j)[2]=sum2/frames.size();

		}
		
	}

	namedWindow("FinalImage",CV_WINDOW_KEEPRATIO);

	imshow("FinalImage",dst);
	waitKey(0);

	char filename[200];

	sprintf(filename,"%s",argv[1]);
        int i;
        for(i=0;i<strlen(filename);i++)
        {
            if (filename[i]=='.')
                break;
        }
        filename[i+1]='\0';
        strcat(filename,"jpg");

        imwrite(filename,dst);
        cout << "Saved " << filename << endl;

	return 0;


    
}
