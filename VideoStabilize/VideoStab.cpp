

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

using namespace std;
using namespace cv;
using namespace cv::videostab;


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


        char str[256];
        sprintf(str, "imagest/%08d.jpg", k);
        imwrite(str, stabilizedFrame);
        k++;
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



int main(int argc, const char **argv)
{
    
     
    StabilizerBase *stabilizer;
    GaussianMotionFilter *motionFilter = 0;

    

   
    bool isTwoPass = 1;

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
    return 0;
}
