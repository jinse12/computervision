#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat src, dst;
Point startPt;
void onMouse(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		startPt = Point(x, y);
	}
	else if (event == EVENT_LBUTTONUP) {
		Point endPt(x, y);
		int x1 = min(startPt.x, endPt.x);
		int y1 = min(startPt.y, endPt.y);
		int x2 = max(startPt.x, endPt.x);
		int y2 = max(startPt.y, endPt.y);
		Rect roi(x1, y1, x2 - x1, y2 - y1);
		Mat roiRegion = dst(roi);
		GaussianBlur(roiRegion,roiRegion,Size(),5.0);
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
