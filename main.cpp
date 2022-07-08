#include "BGM.hpp"
#include<opencv2/opencv.hpp>
#include<iostream>
#include<stdio.h>
#include <chrono>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
Mat frame,roi;
   VideoCapture capture(atoi(argv[0]));
        if (!capture.isOpened()){
            //error in opening the video input
            cerr << "Unable to open: " << endl;
            return 0;
        }

BGM bgm;//

int counter=0;
while (true){
         auto now = std::chrono::system_clock::now();
         std::time_t end_time = std::chrono::system_clock::to_time_t(now);
 
         //std::cout << "Current Time and Date: " << std::ctime(&end_time) << std::endl;
         string time_stamp=std::ctime(&end_time);
         string imgfile=time_stamp+".jpg";
         counter++;
         capture >> frame;
         if (frame.empty())
                   break;
         //provide the roi
         roi=frame(Rect(25,30,400,400));
         // apply the roi into bgm construction
         bgm.model(roi);
         if((counter>500)&&(bgm.capSample()==true))
         {
             std::cout<<"capture the frame"<<bgm.capSample()<<std::endl;
             cv::imwrite(imgfile,roi);
         }

         imshow("Window",frame);
         imshow("BGM",bgm.bgmask);
         waitKey(1);
}


return 0;
}
