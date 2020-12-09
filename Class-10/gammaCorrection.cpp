#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void GammaCorrection(Mat& src, Mat& dst, float fGamma)
{
    CV_Assert(src.data);

    // accept only char type matrices
    CV_Assert(src.depth() != sizeof(uchar));

    // build look up table
    unsigned char lut[256];
    for( int i = 0; i < 256; i++ )
    {
        lut[i] = saturate_cast<uchar>(pow((float)(i/255.0), fGamma) * 255.0f);
    }

    dst = src.clone();
    const int channels = dst.channels();
    switch(channels)
    {
        case 1:
        {

            MatIterator_<uchar> it, end;
            for( it = dst.begin<uchar>(), end = dst.end<uchar>(); it != end; it++ )
                //*it = pow((float)(((*it))/255.0), fGamma) * 255.0;
                *it = lut[(*it)];

            break;
        }
        case 3:
        {

            MatIterator_<Vec3b> it, end;
            for( it = dst.begin<Vec3b>(), end = dst.end<Vec3b>(); it != end; it++ )
            {
                //(*it)[0] = pow((float)(((*it)[0])/255.0), fGamma) * 255.0;
                //(*it)[1] = pow((float)(((*it)[1])/255.0), fGamma) * 255.0;
                //(*it)[2] = pow((float)(((*it)[2])/255.0), fGamma) * 255.0;
                (*it)[0] = lut[((*it)[0])];
                (*it)[1] = lut[((*it)[1])];
                (*it)[2] = lut[((*it)[2])];
            }

            break;

        }
    }
}

int main()
{
    //开始计时
    double start = static_cast<double>(cvGetTickCount());
    Mat src = imread("../histgram2.jpg");
    Mat dst;
    CV_Assert(src.data);
    GammaCorrection(src, dst, 0.5);
    imshow("gammaCorrection", dst);
    //结束计时
    double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
    //显示时间
    cout << "processing time:" << time / 1000 << "ms" << endl;

    //等待键盘响应，按任意键结束程序
    waitKey(0);
    return 0;
}
