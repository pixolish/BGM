#include "BGM.hpp"
#include<opencv2/opencv.hpp>
#include<iostream>
#include<stdio.h>

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
         counter++;
         capture >> frame;
         if (frame.empty())
                   break;
         //provide the roi
         roi=frame(Rect(25,30,350,400));
         // apply the roi into bgm construction
         bgm.model(roi);
         if((counter>100)&&(bgm.capSample()==true))
         {
             std::cout<<"capture the frame"<<bgm.capSample()<<std::endl;
             cv::imwrite("sample.jpg",roi);
         }

         imshow("Window",frame);
         waitKey(1);
}


return 0;
}
