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
                        Point2f(150, 150),
                        Point2f(150, 300),
                        Point2f(350, 300),
                        Point2f(350, 150)
    };
    Point2f dst_pt[] = {
                        Point2f(200, 150),
                        Point2f(200, 300),
                        Point2f(340, 270),
                        Point2f(340, 180)
    };

    Mat perspect_matrix = getPerspectiveTransform(src_pt, dst_pt);
    Mat dst_mat;
    warpPerspective(src_mat, dst_mat, perspect_matrix, src_mat.size());
    imshow("src", src_mat);
    imshow("dst", dst_mat);
    waitKey(0);
    return 0;
}