#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat src(400, 400, CV_8UC3, Scalar(255, 255, 255));
  // 사각형 네 변
	line(src, Point(100, 100), Point(300, 100), Scalar(0, 0, 0), 1);
	line(src, Point(100, 300), Point(300, 300), Scalar(0, 0, 0), 1);
	line(src, Point(100, 100), Point(100, 300), Scalar(0, 0, 0), 1);
	line(src, Point(300, 100), Point(300, 300), Scalar(0, 0, 0), 1);
  // 대각선 X
	line(src, Point(100, 100), Point(300, 300), Scalar(0, 0, 0), 1);
	line(src, Point(300, 100), Point(100, 300), Scalar(0, 0, 0), 1);

	imshow("src", src);
	waitKey(0);
	return 0;
}
