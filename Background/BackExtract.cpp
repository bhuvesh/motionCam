/*
This is a prototype for background extraction.
It uses the class BackgroundSubtractorMOG2 which is a Gussian Mixture based 
background/foreground segmentation algorithm.

The program will take a video or webcam feed and detect the moving object and
would create a background image without the objects. The background will be saved
in the same directory as a jpg file with the same name as the video file.  If webcam
is used as the video feed, the file will be saved with the name as current date and time.

To test this program, pass the executable with the argument of a video file name
if you want to use a video, or pass the argument 0 if you want to use the webcam.

Press ESC to quit.
*/


#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;


const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}


int main( int argc, char** argv )
{

    
    bool update_bg_model = true;
    int flag=0;

    string arg = argv[1];
    VideoCapture cap(arg); //try to open string, this will attempt to open it as a video file
    if (!cap.isOpened()) //if this fails, try to open as a video camera, using the default webcam.
        {cap.open(0);flag=1;}

    
    BackgroundSubtractorMOG2 bg;//(100, 3, 0.3, 5);
    bg.set ("nmixtures", 3);
    vector < std::vector < cv::Point > >contours;

    namedWindow ("Frame");
    namedWindow ("Background");

    Mat frame, fgmask, fgimg, backgroundImage;

    
    while(1)
    {
        cap >> frame;
        if (frame.empty())
            break;
        bg.operator()(frame, fgimg);
        bg.getBackgroundImage (backgroundImage);
        erode (fgimg, fgimg, cv::Mat ());
        dilate (fgimg, fgimg, cv::Mat ());

        findContours (fgimg, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
        drawContours (frame, contours, -1, cv::Scalar (0, 0, 255), 2);

        imshow ("Frame", frame);
        imshow ("Background", backgroundImage);


        char k = (char)waitKey(30);
        if( k == 27 ) break;  //Exit when Escape is pressed

    }

                       
    char filename[200];
    if(flag==0) //Saving the background of video feed
    {
        sprintf(filename,"%s",argv[1]);
        int i;
        for(i=0;i<strlen(filename);i++)
        {
            if (filename[i]=='.')
                break;
        }
        filename[i+1]='\0';
        strcat(filename,"jpg");

        imwrite(filename,backgroundImage);
        cout << "Saved " << filename << endl;
    }

    else  //Saving the background of webcam feed
    {
        
        const std::string s0=currentDateTime();
        const char* s1;
        s1 = s0.c_str();
        sprintf(filename,"%s",s1);
        filename[4]=filename[10]=filename[7]=filename[13]=filename[16]='_';
        filename[19]='.';filename[20]='j';filename[21]='p';filename[22]='g';filename[23]='\0'; 
       
        imwrite(filename,backgroundImage);
        cout << "Saved " << filename << endl;
    }




    
    

    return 0;
}
