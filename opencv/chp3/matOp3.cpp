#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

String folder = "/home/leejieun/kdta_ROS2_Leezizon/opencv/dataFolder/";

int main(){
    Mat img1 = imread(folder+"lena512.bmp"); 
    Rect rc(220, 120, 200, 200);
    Mat img2 = img1(rc);
    Mat img3 = img1(rc).clone();

    img2 = ~img2;
    img2.setTo(Scalar(0, 225, 225));
    
    imshow("img1",img1);
    imshow("img2",img2);
    imshow("img3",img3);
    waitKey(0);

    return 0;
}