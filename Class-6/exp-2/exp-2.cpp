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
    if(src_mat.empty()) return -1;
    Point2f src_pt[] = {
                        Point2f(200, 200),
                        Point2f(250, 200),
                        Point2f(200, 100)
    };
    Point2f dst_pt[] = {
                        Point2f(300, 100),
                        Point2f(300, 50),
                        Point2f(200, 100)
    };

    Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
    Mat dst_mat;
    warpAffine(src_mat, dst_mat, affine_matrix, src_mat.size());
    imshow("src", src_mat);
    imshow("dst", dst_mat);
    waitKey(0);
    return 0;
}