#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat src = imread("lenna.bmp");
	if (src.empty()) return -1;

	int w = src.cols;
	int h = src.rows;

	// 세로선 3개
	line(src, Point(w / 4, 0), Point(w / 4, h), Scalar(255, 0, 0), 1, LINE_AA);
	line(src, Point(w / 2, 0), Point(w / 2, h), Scalar(255, 0, 0), 1, LINE_AA);
	line(src, Point(w * 3 / 4, 0), Point(w * 3 / 4, h), Scalar(255, 0, 0), 1, LINE_AA);

	// 가로선 3개
	line(src, Point(0, h / 4), Point(w, h / 4), Scalar(255, 0, 0), 1, LINE_AA);
	line(src, Point(0, h / 2), Point(w, h / 2), Scalar(255, 0, 0), 1, LINE_AA);
	line(src, Point(0, h * 3 / 4), Point(w, h * 3 / 4), Scalar(255, 0, 0), 1, LINE_AA);

	imshow("src", src);
	waitKey(0);
	return 0;
}
