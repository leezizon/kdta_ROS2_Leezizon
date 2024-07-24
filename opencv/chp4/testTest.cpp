#include "opencv2/opencv.hpp"
#include <opencv2/freetype.hpp>
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/home/leejieun/kdta_ROS2_Leezizon/opencv/dataFolder/";

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255));

    Ptr<freetype::FreeType2> ft2 = freetype::createFreeType2();
    ft2 ->loadFontData(folder+"spl.ttf",0);
    String text = " 한글 지 원 ";
    int font_height = 60;
    Size textSize = ft2->getTextSize(text,font_height,-1,0);

    putText(img,"adasdasdsdasda",Point(20,50),FONT_HERSHEY_SCRIPT_SIMPLEX,1,green);
    putText(img,"안써짐",Point(20,100),FONT_HERSHEY_SCRIPT_SIMPLEX,1,green);

    ft2->putText(img,text,Point(20,200),font_height,green,-1,LINE_AA,true);

    imshow("img", img);
    waitKey(0);

    return 0;
}