#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat src, dst;
int bright = 0;
int mode = 0;
void onMouse(int event, int x, int y, int flags, void* username) {
	if (event == EVENT_LBUTTONDOWN) {
		if (mode == 0)bright += 10;
		else bright -= 10;
		dst = src + bright;
		imshow("dst", dst);
	}
}
void onTrackbar(int pos, void* userdata) {
	mode = pos;
}
int main() {
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	dst = src.clone();
	namedWindow("dst");
	setMouseCallback("dst", onMouse);
	createTrackbar("mode", "dst", &mode, 1, onTrackbar);
	imshow("dst", dst);
	waitKey();
}
