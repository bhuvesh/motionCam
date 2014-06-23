#include "opencv2/core/core.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>

#include <iostream>
#include <vector>
#include <math.h>
#include "datetime.h"


#define sqr(a) (a)*(a)
#define ERR 0.7
#define DEBUG if(1)

using namespace std;
using namespace cv;
/*
const std::string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}*/

void motionCam_file(char* dest)
{



    string arg = string(dest);
    VideoCapture cap(arg);     

	int max_frames = cap.get(CV_CAP_PROP_FRAME_COUNT);
	namedWindow("motionCam",CV_WINDOW_KEEPRATIO);
	vector <Mat> frames;
	
 	Mat cur;
 	for(int i=0;i<max_frames;i++)
 	{
 		
 		frames.push_back(Mat());
 		cap >> cur;
 		cur.copyTo(frames.back());
 		imshow("motionCam",frames[i]);
 		waitKey(50);
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

	char filename[200];

	sprintf(filename,"%s",dest);
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

	waitKey(0);
	destroyWindow("FinalImage");
	destroyWindow("motionCam");


} 


void motionCam_cam()
{	
	int max_frames=50;
	int count=0;
	int started=0;
	vector <Mat> frames;
	Mat cur;
	char filename[200];
	char filename2[200]="pimages/motion/";
	char c;
	namedWindow("motionCam",CV_WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open(0);
	int once=0;
	while(1)
    {	cap>>cur;
    	
    	c=waitKey(5);
    	if(c=='s')
	    {	started=1; 

	    	putText(cur, "RECORDING STARTS" , Point(20, 40) , 2  , 1 , Scalar(130,162,234), 2);
	    	imshow("motionCam",cur);
	    	waitKey(200);
	    	continue;
    	}
    	imshow("motionCam",cur);

    	if(started==1 && count<max_frames && once==0)
    	{	
    		frames.push_back(Mat());
	 		cap >> cur;
	 		cur.copyTo(frames.back());
	 		count++;	 		

    	}
    	else if(started==1 && once==0)
	{		
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

			char filename[200];
			const std::string s0=currentDateTime();
	        const char* s1;
	        s1 = s0.c_str();
	        sprintf(filename,"%s",s1);
	        filename[4]=filename[10]=filename[7]=filename[13]=filename[16]='_';
	        filename[19]='.';filename[20]='j';filename[21]='p';filename[22]='g';filename[23]='\0'; 
	        strcat(filename2,filename);	       
	        imwrite(filename2,dst);
	        cout << "Saved " << filename << endl;
	        waitKey(0);
	        //started=0;
			once=1;
    	}
    	if(started&&once)
    		{destroyWindow("FinalImage");destroyWindow("motionCam");break;}
    	else if(c==27)
    		{destroyWindow("FinalImage");destroyWindow("motionCam");break;}
    }
}


/*int main( int argc, char** argv )
{
	string arg = argv[1];
    VideoCapture cap(arg); //try to open string, this will attempt to open it as a video file
    if (!cap.isOpened()) 
	{	
		motionCam_cam();

	}
	else
	{
		motionCam_file(argv[1]);
	}
}*/