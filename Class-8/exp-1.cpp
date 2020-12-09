#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void imgcorrect()
{
    //读取图片
    cv::Mat  src = imread("../trans.jpg");

    //定义图片容器
    cv::Mat  gry_Mat;
    Mat correct_Mat;
    cvtColor(src,gry_Mat,COLOR_BGR2GRAY);

    //找4个点，通过仿射变换矫正位置
    int height = src.rows;
    int width = src.cols;
    Point2f pst_1[4];

    //找左上角的点
    for (int j = 0;j < width;j++)
    {
        if (gry_Mat.at<uchar>(0, j) < 250)
        {
            pst_1[0] = Point2f(j, 0);
            j = width;
        }
    }

    //找右下角的点
    for (int j = width-1;j >0;j--)
    {
        if (gry_Mat.at<uchar>(height - 1, j) <250)
            pst_1[1] = Point2f(static_cast<float>(j), static_cast<float>(height - 1)), j = 0;
    }


    //找左下角的点
    for (int i = height-1;i >0;i--)
    {
        if (gry_Mat.at<uchar>(i, 0) <250)
            pst_1[2] = Point2f(0, static_cast<float>(i)), i = 0;
    }

    //找右上角的点
    for (int i = 0;i < height;i++)
    {
        if (gry_Mat.at<uchar>(i, width - 1) < 250)
            pst_1[3] = Point2f(static_cast<float>(width - 1), static_cast<float>(i)), i = height;
    }


    //变换后的4个点
    Point2f pst_2[4]{ Point2f(0,0),Point2f(static_cast<float>(width - 1),static_cast<float>(height - 1)),Point2f(0,static_cast<float>(height - 1)),Point2f(static_cast<float>(width - 1),0) };

    //计算投影变换矩阵
    const Mat Matrix = cv::getPerspectiveTransform(pst_1, pst_2);

    //进行投影变换
    cv::warpPerspective(src, correct_Mat, Matrix, src.size());


    imshow("src", src);
    imshow("correct_Mat", correct_Mat);
    waitKey(0);

}
int main()
{
    //开始计时
    double start = static_cast<double>(cvGetTickCount());

    //处理函数
    //canny_extracrtion();
    //warpaffine();
    imgcorrect();

    //结束计时
    double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
    //显示时间
    cout << "processing time:" << time / 1000 << "ms" << endl;

    //等待键盘响应，按任意键结束程序
    system("pause");
    return 0;
}
