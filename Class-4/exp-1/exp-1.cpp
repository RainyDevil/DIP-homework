#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
void open(Mat& src, Mat& dst)
{
    Size mat_size = Size(5,5);
    Mat kernel = getStructuringElement(MORPH_RECT, mat_size);
    Mat erode_mat;
    erode(src, erode_mat, kernel);
    dilate(erode_mat, dst, kernel);
}
void close(Mat& src, Mat& dst)
{
    Size mat_size = Size(5,5);
    Mat kernel = getStructuringElement(MORPH_RECT, mat_size);
    Mat dilate_mat;
    erode(src, dilate_mat, kernel);
    dilate(dilate_mat, dst, kernel);
}
int main(){
    Mat src_mat;
    Mat gry_mat;
    src_mat = imread("../Coin.jpg");
    if(!src_mat.data){
        std::cout << "Open Failed!" << std::endl;
        exit(0);
    }
    cvtColor(src_mat, gry_mat, CV_BGR2GRAY);
    Mat bin_mat;
    threshold(gry_mat, bin_mat, 82, 255, 0);
    Mat erode_mat ;
    Size mat_size = Size(5,5);
    Mat kernel = getStructuringElement(MORPH_RECT, mat_size);
    erode(bin_mat, erode_mat, kernel);
    Mat dilate_mat;
    dilate(bin_mat, dilate_mat, kernel);
    Mat open_mat, closed_mat;
    open(bin_mat, open_mat);
    close(bin_mat, closed_mat);
    imshow("binMat", bin_mat);
    imshow("腐蚀", erode_mat);
    imshow("膨胀", dilate_mat);
    imshow("Open", open_mat);
    imshow("Close", closed_mat);
    waitKey(0);
}