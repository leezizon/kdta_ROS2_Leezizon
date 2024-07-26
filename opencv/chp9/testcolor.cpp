#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 흰 배경에 빨강, 초록, 파랑 원을 그린 이미지 생성
    Mat img = Mat::zeros(400, 600, CV_8UC3);
    img = Scalar(255, 255, 255); // 흰색 배경
    circle(img, Point(150, 200), 50, Scalar(0, 0, 255), -1); // 빨강 원
    circle(img, Point(300, 200), 50, Scalar(0, 255, 0), -1); // 초록 원
    circle(img, Point(450, 200), 50, Scalar(255, 0, 0), -1); // 파랑 원

    // 각 색상 채널을 분리
    vector<Mat> channels;
    split(img, channels);

    // 이진화를 위해 임계값 설정
    int threshold_value = 128;
    Mat binary_red, binary_green, binary_blue;
    
    threshold(channels[2], binary_red, threshold_value, 255, THRESH_BINARY); // 빨강 채널 이진화
    threshold(channels[1], binary_green, threshold_value, 255, THRESH_BINARY); // 초록 채널 이진화
    threshold(channels[0], binary_blue, threshold_value, 255, THRESH_BINARY); // 파랑 채널 이진화

    // Contours를 찾습니다.
    vector<vector<Point>> contours_red, contours_green, contours_blue;
    vector<Vec4i> hierarchy;
    
    findContours(binary_red, contours_red, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    findContours(binary_green, contours_green, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    findContours(binary_blue, contours_blue, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // Contours를 그립니다.
    Mat dst = Mat::zeros(img.size(), CV_8UC3);
    
    // for (size_t i = 0; i < contours_red.size(); i++) {
    //     Scalar color = Scalar(0, 0, 255);  // 빨강색으로 Contours를 그립니다.
    //     drawContours(dst, contours_red, static_cast<int>(i), color, 2, LINE_8, hierarchy, 0);
    // }

    for (size_t i = 0; i < contours_green.size(); i++) {
        Scalar color = Scalar(0, 255, 0);  // 초록색으로 Contours를 그립니다.
        drawContours(dst, contours_green, static_cast<int>(i), color, 2, LINE_8, hierarchy, 0);
    }

    // for (size_t i = 0; i < contours_blue.size(); i++) {
    //     Scalar color = Scalar(255, 0, 0);  // 파랑색으로 Contours를 그립니다.
    //     drawContours(dst, contours_blue, static_cast<int>(i), color, 2, LINE_8, hierarchy, 0);
    // }

    // 원본 이미지와 Contours를 그린 이미지를 출력합니다.
    imshow("green", binary_green);
    
    imshow("Original Image", img);
    imshow("Contours", dst);
    waitKey(0);

    return 0;
}