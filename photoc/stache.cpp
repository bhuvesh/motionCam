#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "datetime.h"


#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

IplImage* mask;

String face_cascade_name = "lbpcascade_frontalface.xml";
CascadeClassifier face_cascade;

/*
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}*/

Mat mous(Mat src)
{	 
	Mat frame = src.clone();
  vector<Rect> faces;
  Mat frame_gray;
  int i = 0;
  int c;

  cvtColor(frame, frame_gray, CV_BGR2GRAY);
  equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.3, 2, 0, Size(40,40 ));


  for(; i < faces.size(); i++) {
    //-- Scale and apply mustache mask for each face
    //cout<<"Hello\n";
    Mat faceROI = frame_gray(faces[i]);
    IplImage iplFrame = frame;
    int height = faces[i].height; // *4/3;
    int offset = faces[i].y; // - faces[i].height/4;
    if(offset < 0) offset = 0;
    IplImage *iplMask = cvCreateImage(cvSize(faces[i].width, height),mask->depth,mask->nChannels);
    cvSetImageROI(&iplFrame, cvRect(faces[i].x, offset,faces[i].width, height));
    cvResize(mask, iplMask, CV_INTER_LINEAR);
    cvSub(&iplFrame, iplMask, &iplFrame);
    cvResetImageROI(&iplFrame);
  }

return frame;

}
 



void stache_file(char* dest,char* mask_desti, int curr)
{	mask = 0;
    face_cascade.load(face_cascade_name) ;
    mask = cvLoadImage(mask_desti);
	Mat show=imread(dest);
	namedWindow( "stacheCam", CV_WINDOW_AUTOSIZE );
	mous(show).copyTo(show);	
	waitKey(5);
    imshow("stacheCam",show);
	waitKey(0);
    //waitKey(0);
	char filename[200];
 	sprintf(filename,"%s",dest);
    int i;
    for(i=0;i<strlen(filename);i++)
    {
        if (filename[i]=='.')
            break;
    }
    filename[i]='\0';
    char text[200];
    sprintf(text,"%d",curr);
    strcat(filename,"_mask");
    strcat(filename,text);
    strcat(filename,".jpg");

    imwrite(filename,show);
    cout << "Saved " << filename << endl;
    destroyWindow("stacheCam");

}

void stache_cam(char* mask_desti, int curr)
{	face_cascade.load(face_cascade_name) ;
    mask = 0;
    mask = cvLoadImage(mask_desti);
    //cout<<"mask : "<<mask_desti<<endl;
	Mat frame;
	
	
    char c;
	namedWindow("stacheCam",CV_WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open(0);
	while(1)
    {	cap>>frame;
    	mous(frame).copyTo(frame);
    	imshow("stacheCam",frame);
    	c=waitKey(5);
    	if(c=='s')
	    {	char filename[200];
            char filename2[200]="pimages/stache/";
            char filename3[200];
            sprintf(filename3,"%d_",curr);
            filename[0]='\0';
	    	const std::string s0=currentDateTime();
	        const char* s1;
	        s1 = s0.c_str();
	        sprintf(filename,"%s",s1);
	        filename[4]=filename[10]=filename[7]=filename[13]=filename[16]='_';
	        filename[19]='.';filename[20]='j';filename[21]='p';filename[22]='g';filename[23]='\0'; 
	        strcat(filename2,"mask");
	        strcat(filename2,filename3);
	        strcat(filename2,filename);
	        imwrite(filename2,frame);

	        cout << "Saved " << filename << endl;

    	}
    	else if(c==27)
    		{destroyWindow("stacheCam");break;}
    }
}


/*int main( int argc, char** argv )
{   
    // Load an image
        Mat src = imread( argv[1] );
        char a[200]="g3.png";

    if( !src.data ) //Check i image has been loaded
    { stache_cam(a,3); }
    else
    {
        stache_file(argv[1],a,3);
    }
}*/