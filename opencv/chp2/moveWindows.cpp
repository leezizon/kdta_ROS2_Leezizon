#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

std::string folder = "/home/leejieun/kdta_ROS2_Leezizon/opencv/dataFolder/";

int main(){
    Mat img;
    img = imread(folder+"lena512.bmp");
    imshow("lena",img);

    while(waitKey(0) != -1){
        cout << "aaa" << endl;
        moveWindow("lena",50,0);
    }

    waitKey(0);
    
    return 0; 
}