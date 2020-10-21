#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
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
    Mat labels, stats, centroids;
    connectedComponentsWithStats(erode_mat, labels, stats, centroids);
    int height = stats.rows;
    for(int i = 0; i < height; ++i)
    {
        int *data = stats.ptr<int>(i);
        rectangle(erode_mat, Point(data[0], data[1]),
                Point(data[0]+data[2], data[1]+data[3]),
                Scalar(255, 0, 0));
    }
    std::cout << height << std::endl;
    imshow("binMat", bin_mat);
    imshow("腐蚀标记", erode_mat);
    waitKey(0);
}