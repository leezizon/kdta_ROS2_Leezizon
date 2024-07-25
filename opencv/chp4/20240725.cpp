#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/leejieun/kdta_ROS2_Leezizon/opencv/dataFolder/";


void onMouse(int event, int x, int y, int flags, void *data);
FileStorage fs;
struct Mydata
{
    Point pt;
    Mat img;
    Mat back = imread(folder + "lena512.bmp");
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    vector<Vec3b> mouseBGR;
    bool flag = false;
};

int main()
{
    Mydata mydata;
    namedWindow("img");
    setMouseCallback("img", onMouse, (void *)&mydata);

    int keycode = waitKey(0);
    if (keycode == 27)
    {
        fs.open(folder + "mouseBGRPoint.json", FileStorage::WRITE);
        fs << "mouseBGR" << mydata.mouseBGR;
        fs.release();
    }
    destroyAllWindows();
    return 0;
}


void onMouse(int event, int x, int y, int flags, void *data)
{
    Mydata *ptr = (Mydata *)data;
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
    if (x >= 0 && x < ptr->img.cols && y >= 0 && y < ptr->img.rows) {
        cout << "mouse left button down" << x << y << endl;
        Vec3b bgr = ptr->img.at<Vec3b>(x, y);
        ptr->mouseBGR.push_back(ptr->back.at<Vec3b>(x, y));
        cout << "B" << static_cast<int>(bgr[0]) << endl;
        cout << "R" << static_cast<int>(bgr[1]) << endl;
        cout << "G" << static_cast<int>(bgr[2]) << endl;
    }
        break;
    case EVENT_LBUTTONUP:
        cout << "mouse left button up" << x << y << endl;
        break;
    case EVENT_MOUSEMOVE:
        ptr->pt = Point(x, y);
        ptr->back.copyTo(ptr->img);
        rectangle(ptr->img, Point(ptr->pt.x, ptr->pt.y), Point(ptr->pt.x+10, ptr->pt.y+10), ptr->blue, 2);
        imshow("img", ptr->img);
    }
}