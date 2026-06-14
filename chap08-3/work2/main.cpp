#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("lenna.bmp");
    Point2f cp(src.cols / 2.f, src.rows / 2.f);

    while (true) {
        cout << "회전각도를 입력하시오: ";
        int angle;
        cin >> angle;

        Mat M = getRotationMatrix2D(cp, angle, 1);
        Mat dst;
        warpAffine(src, dst, M, Size());

        imshow("src", src);
        imshow("dst", dst);

        int key = waitKey();
        if (key == 'q') break;
    }
    return 0;
}
