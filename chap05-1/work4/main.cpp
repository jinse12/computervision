#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat src, dst;
void onMouse(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)) {
		if (x > 0 && x < src.cols - 1 &&
			y>0 && y < src.rows - 1) {
			dst.at<uchar>(y, x) = saturate_cast<uchar>(dst.at<uchar>(y, x) + 100);
			dst.at<uchar>(y - 1, x) = saturate_cast<uchar>(dst.at<uchar>(y - 1, x) + 100);
			dst.at<uchar>(y + 1, x) = saturate_cast<uchar>(dst.at<uchar>(y + 1, x) + 100);
			dst.at<uchar>(y, x - 1) = saturate_cast<uchar>(dst.at<uchar>(y, x - 1) + 100);
			dst.at<uchar>(y, x + 1) = saturate_cast<uchar>(dst.at<uchar>(y, x + 1) + 100);
		}
		imshow("dst", dst);
	}
}
int main() {
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	dst = src.clone();
	namedWindow("dst");
	setMouseCallback("dst", onMouse);
	imshow("dst", dst);
	waitKey();
}
