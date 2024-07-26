#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/home/leejieun/kdta_ROS2_Leezizon/opencv/dataFolder/";

int main()
{
    Mat img = imread(folder + "candies.png");

    int lowerhue = 40;
    int upperhue = 80;
    int lowerStation = 50;

    Mat src, dst;
    cvtColor(img,src,COLOR_RGB2HSV);
    namedWindow("dst");
    createTrackbar("lower hue","dst",&lowerhue,179);
    createTrackbar("upper hue","dst",&upperhue,179);
    createTrackbar("lower sturation","dst",&lowerStation,255);

    while(true){
        inRange(src,Scalar(lowerhue,lowerStation,0),Scalar(upperhue,255,255),dst);
        imshow("dst", dst);
        if(waitKey(33) == 27){
            break;
        }
    }
    
    waitKey(0);

    return 0;
}