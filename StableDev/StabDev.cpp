

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "opencv2/core/core.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/videostab/videostab.hpp"


#define DEBUG if(0)
#define sqr(a) (a)*(a)
#define ERR 0.7


using namespace std;
using namespace cv;
using namespace cv::videostab;

vector <Mat> frames;

Ptr<IFrameSource> stabilizedFrames;
string saveMotionsPath;
double outputFps;
string outputPath;
bool quietMode;

void run();
void saveMotionsIfNecessary();
void printHelp();

class GlobalMotionReader : public IGlobalMotionEstimator
{
public:
    GlobalMotionReader(string path)
    {
        ifstream f(path.c_str());
        if (!f.is_open())
            throw runtime_error("can't open motions file: " + path);
        int size = 0; f >> size;
        motions_.resize(size);
        for (int i = 0; i < size; ++i)
        {
            Mat_<float> M(3, 3);
            for (int l = 0; l < 3; ++l)
                for (int s = 0; s < 3; ++s)
                    f >> M(l,s);
            motions_[i] = M;
        }
        pos_ = 0;
    }

    virtual Mat estimate(const Mat &/*frame0*/, const Mat &/*frame1*/)
    {
        if (pos_ >= motions_.size())
        {
            stringstream text;
            text << "can't load motion between frames " << pos_ << " and " << pos_+1;
            throw runtime_error(text.str());
        }
        return motions_[pos_++];
    }

private:
    vector<Mat> motions_;
    size_t pos_;
};

void run()
{
   // VideoWriter writer;
    Mat stabilizedFrame;
    int k=0;
    while (!(stabilizedFrame = stabilizedFrames->nextFrame()).empty())
    {
        if (!saveMotionsPath.empty())
            saveMotionsIfNecessary();
        /*if (!outputPath.empty())
        {
            if (!writer.isOpened())
                writer.open(outputPath, CV_FOURCC('X','V','I','D'), outputFps, stabilizedFrame.size());
            writer << stabilizedFrame;
        }*/
        if (!quietMode)
        {
            imshow("stabilizedFrame", stabilizedFrame);
            char key = static_cast<char>(waitKey(3));
            if (key == 27)
                break;
        }

        frames.push_back(Mat());
        stabilizedFrame.copyTo(frames.back());
        //char str[256];
        //sprintf(str, "imagest/%08d.jpg", k);
        //imwrite(str, stabilizedFrame);
        //k++;
    }

    cout << "\nfinished\n";
}


void saveMotionsIfNecessary()
{
    static bool areMotionsSaved = false;
    if (!areMotionsSaved)
    {
        IFrameSource *frameSource = static_cast<IFrameSource*>(stabilizedFrames);
        TwoPassStabilizer *twoPassStabilizer = dynamic_cast<TwoPassStabilizer*>(frameSource);
        if (twoPassStabilizer)
        {
            ofstream f(saveMotionsPath.c_str());
            const vector<Mat> &motions = twoPassStabilizer->motions();
            f << motions.size() << endl;
            for (size_t i = 0; i < motions.size(); ++i)
            {
                Mat_<float> M = motions[i];
                for (int l = 0, k = 0; l < 3; ++l)
                    for (int s = 0; s < 3; ++s, ++k)
                        f << M(l,s) << " ";
                f << endl;
            }
        }
        areMotionsSaved = true;
        cout << "motions are saved";
    }
}


void errormodel(const char **argv)
{
    Mat dst;
    namedWindow("FinalImage",CV_WINDOW_KEEPRATIO);

    dst.create( frames[0].size(), frames[0].type() );
    int count=0;
    dst = Scalar::all(0);
    double avg0,avg1,avg2,sum0,sum1,sum2,sdev0,sdev1,sdev2;
    for(int i=0;i<dst.rows;i++)

    {   imshow("FinalImage",dst);
        waitKey(1);
        for(int j=0;j<dst.cols;j++)
         
        {   
            
            sum0=0,sum2=0,sum1=0;
            avg0=0;avg1=0;avg2=0;
            sdev0=0;sdev1=0;sdev2=0;

            for (int k=0;k<frames.size();k++)
            {   avg0+=frames[k].at<Vec3b>(i,j)[0];
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



}



int main(int argc, const char **argv)
{
    
     
    StabilizerBase *stabilizer;
    GaussianMotionFilter *motionFilter = 0;

    

   
    bool isTwoPass = 0;

    if (isTwoPass)
    {
        TwoPassStabilizer *twoPassStabilizer = new TwoPassStabilizer();
        
        stabilizer = twoPassStabilizer;
    }
    else
    {
        OnePassStabilizer *onePassStabilizer= new OnePassStabilizer();
        if (motionFilter)
            onePassStabilizer->setMotionFilter(motionFilter);
        stabilizer = onePassStabilizer;
    }

    string inputPath = argv[1];
    if (inputPath.empty())
        throw runtime_error("specify video file path");

    VideoFileSource *frameSource = new VideoFileSource(inputPath);
    outputFps = frameSource->fps();
    stabilizer->setFrameSource(frameSource);
    cout << "frame count: " << frameSource->frameCount() << endl;

 
    stabilizer->setLog(new LogToStdout());
    

    stabilizedFrames = dynamic_cast<IFrameSource*>(stabilizer);

    run();
   
    
    stabilizedFrames.release();

    errormodel(argv);

    frames.clear();





    return 0;
}
