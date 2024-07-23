#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

std::string folder = "/home/leejieun/kdta_ROS2_Leezizon/opencv/dataFolder/";

int main(){
    Mat img;
    img = imread(folder+"lena512.bmp");
    namedWindow("lenna");
    imshow("lena",img);
    int key = waitKey(0);
    cout << key << endl;
    Size size;
    size.height = 100;
    size.width = 100;
    resizeWindow("lena",size);
    waitKey(0);
    
    return 0; 
}