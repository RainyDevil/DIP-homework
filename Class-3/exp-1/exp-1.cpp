#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace cv;
int main(){
  VideoCapture cap(0);
  double scale = 0.5;

  double min_H = 0;
  double max_H = 20;

  double min_S = 43;
  double max_S = 255;

  double min_V = 55;
  double max_V = 255;

  while(1){
      Mat frame;
      Mat hsv_mat;
      Mat detect_mat;
      cap >> frame;
      Size mat_size = Size(frame.cols * scale, frame.rows * scale);
      Mat resize_mat = Mat(mat_size, frame.type());
      resize(frame, resize_mat, mat_size, INTER_LINEAR);
      cvtColor(resize_mat, hsv_mat, COLOR_BGR2HSV);
      resize_mat.copyTo(detect_mat);
      inRange(hsv_mat, Scalar(min_H, min_S, min_V), Scalar(max_H, max_S, max_V), detect_mat);
      imshow("in the range ", detect_mat);
      imshow("frame", frame);
      waitKey(30);
  }
}