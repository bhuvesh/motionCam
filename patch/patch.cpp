#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace cv;
using namespace std;


int x,y, delx, dely;

int main() 
{
	namedWindow("Logopogo",1);
	Mat img = imread("image.jpg");
	Mat img2 = imread("logo.png");
	if ( img.empty() )//|| img2.empty()) 
	{	cout<<"\nImages not found";
		return -1;
	}

	cout<<"\nEnter x, y";
	cin>>x>>y;
	Mat roi = img( Rect(Point(x,y),img2.size()) );
	Mat img2_bw;
	cvtColor(img2,img2_bw,CV_RGB2GRAY);
	Mat mask=roi;
	threshold(img2_bw, mask, 10 , 255 ,THRESH_BINARY);
	
	int i,j;
	for( i=0;i<roi.rows;i++)
	{	for(j=0;j<roi.cols;j++)
		{	if( mask.at<uchar>(i,j)!=0)
			{	img.at<Vec3b>(i+y,j+x)[0]=img2.at<Vec3b>(i,j)[0];
				img.at<Vec3b>(i+y,j+x)[1]=img2.at<Vec3b>(i,j)[1];
				img.at<Vec3b>(i+y,j+x)[2]=img2.at<Vec3b>(i,j)[2];
			}
		}
		cout<<"\n";
	}

	
	//rectangle(img, Rect(Point(x,y),img2.size()), Scalar(100,0,0));
	
	imshow("Logopogo",img);
	waitKey(0);
	return 0; 
}
