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
int main() {
    Mat src_mat = imread("../trans.jpg");
    if(src_mat.empty()) return 1;
    float angle = -10.0, scale = 1.0;
    Point2f center(src_mat.cols*0.5, src_mat.rows*0.5);
    Mat affine_matrix = getRotationMatrix2D(center, angle, scale);
    Mat dst_mat;
    warpAffine(src_mat, dst_mat, affine_matrix, src_mat.size());
    imshow("src", src_mat);
    imshow("dst", dst_mat);
    waitKey(0);
    return 0;
}
