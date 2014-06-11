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
#include <math.h>

#define DEBUG if(0)
#define sqr(a) (a)*(a)
#define ERR 0.7

using namespace std;
using namespace cv;



int main( int argc, char** argv )
{



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
 	namedWindow("FinalImage",CV_WINDOW_KEEPRATIO);

 	dst.create( cur.size(), cur.type() );
 	int count=0;
 	dst = Scalar::all(0);
    double avg0,avg1,avg2,sum0,sum1,sum2,sdev0,sdev1,sdev2;
	for(int i=0;i<cur.rows;i++)

	{	imshow("FinalImage",dst);
		waitKey(1);
		for(int j=0;j<cur.cols;j++)
		 
		{	
			
			sum0=0,sum2=0,sum1=0;
			avg0=0;avg1=0;avg2=0;
			sdev0=0;sdev1=0;sdev2=0;

			for (int k=0;k<frames.size();k++)
			{	avg0+=frames[k].at<Vec3b>(i,j)[0];
				avg1+=frames[k].at<Vec3b>(i,j)[1];
				avg2+=frames[k].at<Vec3b>(i,j)[2];
				sum0+=sqr(frames[k].at<Vec3b>(i,j)[0]);
				sum1+=sqr(frames[k].at<Vec3b>(i,j)[1]);
				sum2+=sqr(frames[k].at<Vec3b>(i,j)[2]);
			}

			avg0=avg0/frames.size();
			avg1=avg1/frames.size();
			avg2=avg2/frames.size();

			sum0=sum0/frames.size();
			sum1=sum1/frames.size();
			sum2=sum2/frames.size();

			sdev0 = sqrt( sum0 - sqr(avg0));
			sdev1 = sqrt( sum1 - sqr(avg1));
			sdev2 = sqrt( sum2 - sqr(avg2));


			count = 0;
			sum0=0,sum2=0,sum1=0;

			
			for (int k=0;k<frames.size();k++)
			{
				if ( (fabs(frames[k].at<Vec3b>(i,j)[0] - avg0) < sdev0*ERR) && (fabs(frames[k].at<Vec3b>(i,j)[1] - avg1) < sdev1*ERR) && (fabs(frames[k].at<Vec3b>(i,j)[2] - avg2) < sdev2*ERR))
				{
					count++;
					sum0+=frames[k].at<Vec3b>(i,j)[0];
					sum1+=frames[k].at<Vec3b>(i,j)[1];
					sum2+=frames[k].at<Vec3b>(i,j)[2];
				}

			}
			if (count)
			{
				dst.at<Vec3b>(i,j)[0]=sum0/count;

				dst.at<Vec3b>(i,j)[1]=sum1/count;

				dst.at<Vec3b>(i,j)[2]=sum2/count;
			}
			else
			{

				dst.at<Vec3b>(i,j)[0]=avg0;

				dst.at<Vec3b>(i,j)[1]=avg1;

				dst.at<Vec3b>(i,j)[2]=avg2;

			}

			//printf("(%d,%d)  B: %lf  G: %lf  R: %lf\n",i,j,sdev0,sdev1,sdev2);
			//if ((i+j)%400 == 0)printf("(%d,%d) : %d\n",i,j,count);
			
			
			

		}
		
	}



			
	

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
