//
// Created by cyk on 2020/9/28.
//
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
int main(){
    std::cout << "通道分离" << std::endl;
    Mat src_image = imread("timg.jpeg");
    std::vector<cv::Mat> channels;
    cv::split(src_image, channels);
    cv::Mat B = channels.at(0);
    cv::Mat G = channels.at(1);
    cv::Mat R = channels.at(2);
    imshow("原始", src_image);
    imshow("B", B);
    imshow("G", G);
    imshow("R", G);
    waitKey(0);
    return 0;
}

