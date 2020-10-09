#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
int main(){
    Mat src_mat;
    Mat gry_mat;
    src_mat = imread("../sun.jpg");
    if(!src_mat.data){
        std::cout << "Open Failed!" << std::endl;
        exit(0);
    }
    cvtColor(src_mat, gry_mat, CV_BGR2GRAY);
    Mat bin_mat;
    threshold(gry_mat, bin_mat, 100,255, THRESH_OTSU);
    Mat adapt_mat;
    adaptiveThreshold(gry_mat, adapt_mat, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 10);
    imshow("src_mat", src_mat);
    imshow("bin_mat", bin_mat);
    imshow("adapt_mat", adapt_mat);
    waitKey(0);
}