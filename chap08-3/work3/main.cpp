#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

int main(void)
{
    Mat src = imread("lenna.bmp");
    Point2f cp(src.cols / 2.f, src.rows / 2.f);
    int angle = 0;

    while (true) {
        Mat M = getRotationMatrix2D(cp, angle, 1);
        Mat dst;
        warpAffine(src, dst, M, Size());

        imshow("src", src);
        imshow("dst", dst);

        int key = waitKey();
        if (key == 'q') break;
        else if (key == 'r') angle -= 10;   // 시계방향 10도
        else if (key == 'b') angle += 10;   // 반시계방향 10도
    }
    return 0;
}
