#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
    imshow("src", src);

    float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };
    Mat mask = Mat(3, 3, CV_32F, weights);
    Mat dst = src.clone();

    for (int i = 1; i <= 5; i++) {
        filter2D(dst, dst, -1, mask);

        String desc = format("Sharpen: %d times", i);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
                Scalar(255), 1, LINE_AA);
        imshow("dst", dst);
        waitKey();
    }
    return 0;
}
