#ifndef BGM_HPP
#define BGM_HPP
#include <iostream>
#include <sstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

class BGM
{
public:
    BGM();
    void model(cv::Mat roi);
    bool capSample();
private:
    cv::Ptr<cv::BackgroundSubtractor> pBackSub;
    cv::Mat roi,fgmask,bgmask,diff,roi_gray,thresh;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i>hierarchy;
    bool capture;
};

#endif // BGM_HPP
