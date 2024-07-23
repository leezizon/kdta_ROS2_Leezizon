#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

std::string folder = "/home/leejieun/kdta_ROS2_Leezizon/opencv/first/";

int main(){
    std::cout <<"hello, world"<<std::endl;
    cv::Mat img;
    img = cv::imread(folder+"lena512.bmp");
    cv::imshow("image",img);

    cv::waitKey(0);
    
    return 0; 
}