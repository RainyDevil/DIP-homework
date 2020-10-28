#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
//
// Created by cyk on 2020/9/28.
//

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
int main(){
    VideoCapture cap;
    cap.open(0);
    if(!cap.isOpened()){
        std::cout << "Open Failed !" << std::endl;
        return -1;
    }
    double fps = cap.get(CAP_PROP_FPS);
    std::cout << "fps = " << fps << std::endl;
    while(1){
        cv::Mat frame;
        if(!(cap.read(frame))){
            std::cout << "Read Failed !" << std::endl;
            return -1;
        }
        else {
            cv::Mat dst;
            Size mat_size = Size(5, 5);
            blur(frame, dst, mat_size);
            imshow("frame", dst);
        }
        waitKey(30);
    }
    return 0;
}