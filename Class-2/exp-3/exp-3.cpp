#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
int main(){
    cv::Mat src = imread("../sun.jpg");
    if(src.data == NULL){
        std::cout << "Open Failed !" << std::endl;
        exit(0);
    }
    int height = src.rows;
    int width = src.cols * src.channels();
    float histgram[256] = {0};
    for(int i = 0; i < height; ++i){
        uchar *data = src.ptr<uchar>(i);
        for(int j = 0; j < width ; ++j){
            histgram[data[j]]++;
        }
    }
    cv::Mat histgram_mat(256, 256, CV_8UC1, Scalar(255));
    for(int i = 0; i<256; i++){
        Point pt1, pt2;
        pt1.x = i;
        pt1.y = 256;
        pt2.x = i;
        pt2.y = 256 - (histgram[i]/256);
        line(histgram_mat, pt1, pt2, CV_RGB(255,0,0), 2, 8, 0);
    }
    imshow("histgram", histgram_mat);
    imshow("src", src);
    waitKey(0);
    return 0;
}