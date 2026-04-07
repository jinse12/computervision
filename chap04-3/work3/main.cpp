#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    Mat src(400, 400, CV_8UC3, Scalar(255, 255, 255));

  rectangle(src, Point(100, 100), Point(300, 300), Scalar(0, 0, 0), 1, LINE_AA);

    circle(src, Point(200, 200), 100, Scalar(0, 0, 0), 1, LINE_AA);

    imshow("src", src);
    waitKey(0);
    return 0;
}
