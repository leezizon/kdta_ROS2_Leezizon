#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
String folder = "/home/leejieun/kdta_ROS2_Leezizon/opencv/dataFolder/";

int main()
{
    Mat src = imread(folder + "rose.bmp", IMREAD_GRAYSCALE);
    vector<Mat> dsts;

    for (int ksize = 3; ksize <= 19; ksize += 2)
    {

    }

    int i = 3;
    for (auto dst : dsts)
    {
        imshow("dst" + to_string(i), dst);
        i += 2;
    }

    return 0;
}