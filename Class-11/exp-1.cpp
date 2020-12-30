#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int kMeansDemo()
{
    const int MAX_CLUSTERS = 5;
    Scalar colorTab[] =
            {
                    Scalar(0, 0, 255),
                    Scalar(0,255,0),
                    Scalar(255,100,100),
                    Scalar(255,0,255),
                    Scalar(0,255,255)
            };

    Mat img(500, 500, CV_8UC3);
    RNG rng(12345);

    for (;;)
    {
        int k, clusterCount = rng.uniform(2, MAX_CLUSTERS + 1);
        int i, sampleCount = rng.uniform(1, 1001);
        Mat points(sampleCount, 1, CV_32FC2), labels;

        clusterCount = MIN(clusterCount, sampleCount);
        std::vector<Point2f> centers;

        /* generate random sample from multigaussian distribution */
        for (k = 0; k < clusterCount; k++)
        {
            Point center;
            center.x = rng.uniform(0, img.cols);
            center.y = rng.uniform(0, img.rows);
            Mat pointChunk = points.rowRange(k*sampleCount / clusterCount,
                                             k == clusterCount - 1 ? sampleCount :
                                             (k + 1)*sampleCount / clusterCount);
            rng.fill(pointChunk, RNG::NORMAL, Scalar(center.x, center.y), Scalar(img.cols*0.05, img.rows*0.05));
        }

        randShuffle(points, 1, &rng);

        double compactness = kmeans(points,	MAX_CLUSTERS,labels,
                TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 1.0),
                3, KMEANS_PP_CENTERS, centers);

        img = Scalar::all(0);

        for (i = 0; i < sampleCount; i++)
        {
            int clusterIdx = labels.at<int>(i);
            Point ipt = points.at<Point2f>(i);
            circle(img, ipt, 2, colorTab[clusterIdx], FILLED, LINE_AA);
        }
        for (i = 0; i < (int)centers.size(); ++i)
        {
            Point2f c = centers[i];
            circle(img, c, 40, colorTab[i], 1, LINE_AA);
        }
        cout << "Compactness: " << compactness << endl;

        imshow("clusters", img);

        char key = (char)waitKey();
        if (key == 27 || key == 'q' || key == 'Q') // 'ESC'
            break;
    }

    return 0;
}

int main()
{
    //开始计时13
    double start = static_cast<double>(cvGetTickCount());
    Mat src = imread("../histgram2.jpg");
    Mat dst;
    CV_Assert(src.data);
    kMeansDemo();
    imshow("gammaCorrection", dst);
    //结束计时
    double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
    //显示时间
    cout << "processing time:" << time / 1000 << "ms" << endl;

    //等待键盘响应，按任意键结束程序
    waitKey(0);
    return 0;
}
