#include "opencv2/opencv.hpp"
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
    FileStorage fs;

    fs.open(folder + "mydata.json", FileStorage::READ);
    if (!fs.isOpened())
    {
        cerr << "file open failed" << endl;
        return 1;
    }

    String name = "lee";

    fs["name"] >> name;
    fs["mat1"] >> img;
    
    fs.release();

    cout << name << endl;
    
    imshow("img",img);
    waitKey(0);

    return 0;
}