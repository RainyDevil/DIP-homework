#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main(){
    std::cout << "hello opencv" << std::endl;
    Mat src_image = imread("timg.jpeg");
    Mat shallowMat = src_image;
    Mat deepMat;
    src_image.copyTo(deepMat);
    uchar threshold = 100;
    int height = src_image.rows;
    int width = src_image.cols * src_image.channels();
    for(int i = 0; i < height; i++){
        uchar *data = src_image.ptr<uchar>(i);
        for(int j = 0 ; j < width; j++) {
            if(data[j] > threshold) data[j] = 255;
            else data[j] = 0;
            // data[j] = data[j] / 3;
        }
    }
    imshow("src_image", src_image);
    imshow("image1", image1);
    imshow("image2", image2);
    waitKey(0);
    return 0;
}

