#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "everything.h"

#define sqr(a) (a)*(a)

using namespace cv;
using namespace std;

Mat src;
int textflag, curr, currw=0, choice, sflag;
char inp[1000], inpmask[1000];
string s;

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

void something(int choice,int curr, char* de);
void something(int choice,int curr, char* de)
{
  if(curr==14)
  {
    switch(choice)
    {
      case 1:
      cout<<"motionCam karenge.\n";
      break;


      case 2:
      cout<<"motionCam karenge.\n";
      break;

      case 3:
      laplace_cam();
      break;

      case 4:
      sepia_cam();
      break;

      case 5:
      poster_cam();
      break;

      case 6:
      negative_cam();
      break;

      case 7:
      blurit_cam();
      break;

      case 8:
      cannye_cam();
      break;

      case 9:
      grayscale_cam();
      break;

      case 10:
      bifi_cam();
      break;      

    }
  }
  if(curr==15)
  {
    switch(choice)
    {
      case 1:
      cout<<"motionCam karenge.\n";
      break;


      case 2:
      cout<<"motionCam karenge.\n";
      break;

      case 3:
      laplace_file(de);
      break;

      case 4:
      sepia_file(de);
      break;

      case 5:
      poster_file(de);
      break;

      case 6:
      negative_file(de);
      break;

      case 7:
      blurit_file(de);
      break;

      case 8:
      cannye_file(de);
      break;

      case 9:
      grayscale_file(de);
      break;

      case 10:
      bifi_file(de);
      break;      

    }
  }
}



void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{

	 if ( event == EVENT_MOUSEMOVE )
     {
          //cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

          if (currw==0)
          {
              if (x>40&&x<380&&y>90&&y<305)
            {
              if (curr!=1)
              
              {
                src = imread("img/home/motion.jpg");
                curr=1;
                //cout<<curr<<endl;
              }

            } 
            else if (x>40&&x<380&&y>340&&y<555)
            {
              if (curr!=2)
              
              {
                src = imread("img/home/stache.jpg");
                curr=2;
                //cout<<curr<<endl;
              }

            }

            else if (x>410&&x<560&&y>90&&y<180)
            {
              if (curr!=3)
              
              {
                src = imread("img/home/laplace.jpg");
                curr=3;
                //cout<<curr<<endl;
              }

            } 


            else if (x>410&&x<560&&y>215&&y<305)
            {
              if (curr!=4)
              
              {
                src = imread("img/home/sepia.jpg");
                curr=4;
                //cout<<curr<<endl;
              }

            }


            else if (x>410&&x<560&&y>340&&y<430)
            {
              if (curr!=5)
              
              {
                src = imread("img/home/poster.jpg");
                curr=5;
                //cout<<curr<<endl;
              }

            }


            else if (x>410&&x<560&&y>465&&y<555)
            {
              if (curr!=6)
              
              {
                src = imread("img/home/invert.jpg");
                curr=6;
                //cout<<curr<<endl;
              }

            }


            else if (x>600&&x<750&&y>90&&y<180)
            {
              if (curr!=7)
              
              {
                src = imread("img/home/blur.jpg");
                curr=7;
                //cout<<curr<<endl;
              }

            }


            else if (x>600&&x<750&&y>215&&y<305)
            {
              if (curr!=8)
              
              {
                src = imread("img/home/canny.jpg");
                curr=8;
                //cout<<curr<<endl;
              }

            }


            else if (x>600&&x<750&&y>340&&y<430)
            {
              if (curr!=9)
              
              {
                src = imread("img/home/gray.jpg");
                curr=9;
                //cout<<curr<<endl;
              }

            }


            else if (x>600&&x<750&&y>465&&y<555)
            {
              if (curr!=10)
              
              {
                src = imread("img/home/bifi.jpg");
                curr=10;
                //cout<<curr<<endl;
              }

            }     


            
            else
            {
              if(curr)
              {
              
              src = imread("img/home/backgr.jpg");
              curr=0;
              //cout<<curr<<endl; 
              }
              
            }
          }

          else if(currw==1)
          {
            if (sqr(x-184) + sqr(y-300) <= sqr(104))
            {
              if(curr!=14)
              {
                //cout<<"HI\n";
                src = imread("img/choice/choose1.jpg");
                curr=14;
                //cout<<curr<<endl;
              }

            }

            else if (sqr(x- 579) + sqr(y-300) <= sqr(104))
            {
              if(curr!=15)
              {
                src = imread("img/choice/choose2.jpg");
                curr=15;
                //cout<<curr<<endl;
              }

            }

             else if (x>318&&x<485&&y>485&&y<580)
            {
              if (curr!=16)
              
              {
                src = imread("img/choice/choose3.jpg");
                curr=16;
                //cout<<curr<<endl;
              }

            }  

           

            else if (x>389&&x<786&&y>437&&y<465)
            {
              if (curr!=17)
              
              {
                
                curr=17;
                //cout<<curr<<endl;
              }

            }

            else if (curr!=13)
            {
                src = imread("img/choice/choose.jpg");
                curr=13;
                //cout<<"bye\n";
            }


            putText(src, s , Point(400, 455) , 3  , 0.5 , Scalar(130,162,234), 1.5);
          }

          else if(currw==2)
          {
            if (x>27&&x<127&&y>130&&y<261)
            {
              if(curr!=19)
              {
                src = imread("img/mous/st1.jpg");
                //cout<<"Hello\n";
                curr=19;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s1.png");
              }

            }

            else if (x>152&&x<252&&y>130&&y<261)
            {
              if(curr!=20)
              {
                src = imread("img/mous/st2.jpg");
                curr=20;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s2.png");
              }

            }

            else if (x>277&&x<377&&y>130&&y<261)
            {
              if(curr!=21)
              {
                src = imread("img/mous/st3.jpg");
                curr=21;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s3.png");
              }

            }

            else if (x>402&&x<502&&y>130&&y<261)
            {
              if(curr!=22)
              {
                src = imread("img/mous/st4.jpg");
                curr=22;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s4.png");
              }

            }

            else if (x>527&&x<627&&y>130&&y<261)
            {
              if(curr!=23)
              {
                src = imread("img/mous/st5.jpg");
                curr=25;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s5.png");
              }

            }

            else if (x>652&&x<752&&y>130&&y<261)
            {
              if(curr!=24)
              {
                src = imread("img/mous/st6.jpg");
                curr=24;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s6.png");
              }

            }


            else if (x>27&&x<127&&y>310&&y<441)
            {
              if(curr!=25)
              {
                src = imread("img/mous/st7.jpg");
                curr=25;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s7.png");
              }

            }

            

            else if (x>152&&x<252&&y>310&&y<441)
            {
              if(curr!=26)
              {
                src = imread("img/mous/st8.jpg");
                curr=26;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s8.png");
              }

            }

            else if (x>277&&x<377&&y>310&&y<441)
            {
              if(curr!=27)
              {
                src = imread("img/mous/st9.jpg");
                curr=27;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s9.png");
              }

            }



            else if (x>402&&x<502&&y>310&&y<441)
            {
              if(curr!=28)
              {
                src = imread("img/mous/st10.jpg");
                curr=28;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s10.png");
              }

            }

            else if (x>27&&x<127&&y>310&&y<441)
            {
              if(curr!=25)
              {
                src = imread("img/mous/st7.jpg");
                curr=25;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s7.png");
              }

            }



            else if (x>527&&x<627&&y>310&&y<441)
            {
              if(curr!=29)
              {
                src = imread("img/mous/st11.jpg");
                curr=29;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s11.png");
              }

            }



            else if (x>652&&x<752&&y>310&&y<441)
            {
              if(curr!=30)
              {
                src = imread("img/mous/st12.jpg");
                curr=30;
                inpmask[0]='\0';
                strcat(inpmask,"img/mask/s12.png");
              }

            }



            else if (x>280&&x<500&&y>490&&y<540)
            {
              if(curr!=31)
              {
                src = imread("img/mous/stback.jpg");
                curr=31;
                
              }

            }

            else if(curr!=18)
            {

              curr=18;
              src = imread("img/mous/stbg.jpg");

            }


          }


          

     }

      if  ( event == EVENT_LBUTTONDOWN )
     {
 		     if(curr>=1&&curr<=12&&currw==0)
        {
        	
           src = imread("img/choice/choose.jpg");

           currw = 1;

           choice=curr;

         }

         if (currw==1)
         {

            if (curr==17)
            {
              textflag=1;
            }

            else
              textflag=0;

            if (curr==16)
            {
              currw=0;
               src = imread("img/home/backgr.jpg");
              curr=0;


            }
            else if (curr==14||curr==15)
            {

              if (choice<=10 && choice>2)
              {
                Mat test;
                test = imread (inp);
                if (curr==14)
                  {something(choice,curr,inp);}

                else if (curr==15)
                {
                   if( !test.data ) //Check i image has been loaded
                     {src = imread("img/choice/chooseerr.jpg"); }
                    else
                      {something(choice,curr,inp);cout<<"hi\n";imshow("photoCENTER", src);}
                }
               
              }

              else if(choice==2)
              {
                if (curr==14)
                {
                  currw=2;
                src = imread("img/mous/stbg.jpg");
                sflag=curr;

                }

                else if(curr==15)
                {
                  Mat test;
                test = imread (inp);
                if( !test.data ) //Check i image has been loaded
                     {src = imread("img/choice/chooseerr.jpg"); }
                   else
                   {
                    currw=2;
                src = imread("img/mous/stbg.jpg");
                sflag=curr;
                   }

                }
                

              }

              else if(choice == 1)
              {
                if (curr==15)
                {
                  string arg = inp;
                  VideoCapture cap(arg);

                  if (!cap.isOpened()) 
                  { 
                   src = imread("img/choice/chooseerr.jpg");
                  }
                  else 
                    motionCam_file(inp);
                }
                else if(curr==14)
                {
                  motionCam_cam();
                }

              }
              //destroyAllWindows();
              
            }



         }

         else if(currw==2)
         {

          if (curr>=19&&curr<=30)
          {
            if(sflag==14)
            {
              //cout<<inpmask<<endl;
              stache_cam(inpmask,curr-18);

            }
            else if(sflag==15)
            {
              stache_file(inp,inpmask,curr-18);
            }
          }
          else if (curr==31)
          {
            currw=1;
            src = imread("img/choice/choose.jpg");


          }

         }
     }
}




int main( int argc, char** argv )
{
	textflag=0;
	// Load an image

  src = imread("img/home.jpg");
    imshow("photoCENTER",src);

  waitKey(3000);



	src = imread("img/home/backgr.jpg");

	if( !src.data ) //Check i image has been loaded
	{ return -1; }

	

	namedWindow( "photoCENTER", CV_WINDOW_AUTOSIZE );
	imshow("photoCENTER",src);

	setMouseCallback("photoCENTER", CallBackFunc, NULL);
	int c=0;
	
	inp[0]='\0';
	int end=0;

	while(c!='q'||textflag==1)
	{
		imshow("photoCENTER", src);
		c = waitKey(5);
		//if(c!=-1) cerr<<c;
		if(textflag&&c!=-1)
		{
			src = imread("img/choice/choose.jpg");

			if(c==8)
			{
				if(end)
				{

				end--;
				inp[end]='\0';	
				}
			}
			else if(c==13)
			{
				textflag=0;
			}
			else
			{
				inp[end]=c;
				end++;
				inp[end]='\0';
			}
			s= string(inp);
			putText(src, s ,Point(400, 455)  , 3  , 0.5 , Scalar(130,162,234), 1.5);
			//cout<<inp<<endl;
		}
	}





	waitKey(0);

}
