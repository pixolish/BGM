#include "BGM.hpp"
#include<opencv2/opencv.hpp>
#include<iostream>
#include<chrono>

using namespace cv;
using namespace std;


BGM::BGM()
{
  pBackSub = cv::createBackgroundSubtractorMOG2();

}

void BGM::model(cv::Mat roi)
{
cvtColor(roi,roi_gray, COLOR_BGR2GRAY);
pBackSub->apply(roi_gray,fgmask);
pBackSub->getBackgroundImage(bgmask);

}

bool BGM::capSample()
{
capture =false;
cv::absdiff(bgmask,roi_gray,diff);
threshold(roi_gray, thresh, 150, 255, THRESH_BINARY);
findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
if(contours.size()>10)
    capture=true;
return capture;

}
