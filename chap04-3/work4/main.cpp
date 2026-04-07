#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	if (src.empty()) return -1;

	circle(src, Point(300, 275), 119, Scalar(255, 0, 0), 2, LINE_AA);

	imshow("image", src);
	waitKey(0);
	return 0;
}
