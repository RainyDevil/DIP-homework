#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace cv;
const String win_name("binary_mat");
void threshold_change(int th, void * data);
int main(){
    Mat src_mat;
    Mat gry_mat;
    int lowTh = 30;
    int maxTh = 255;
    src_mat = imread("../sun.jpg");
    if(!src_mat.data){
        std::cout << "Open Failed!" << std::endl;
        exit(0);
    }
    cvtColor(src_mat, gry_mat, CV_BGR2GRAY);
    imshow(win_name, gry_mat);
    createTrackbar("threshold", win_name, &lowTh, maxTh, threshold_change, &gry_mat);
    waitKey(0);
}
void threshold_change(int th, void * data)
{
    Mat src_mat = *(Mat *)data;
    Mat dst_mat;
    threshold(src_mat, dst_mat, th, 255, 0);
    imshow(win_name, dst_mat);
}