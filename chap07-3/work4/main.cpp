#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat src, dst;
Point ptStart, ptEnd;
bool isDragging = false;

float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };
Mat mask = Mat(3, 3, CV_32F, weights);

void on_mouse(int event, int x, int y, int, void*)
{
	if (event == EVENT_LBUTTONDOWN) {
		ptStart = Point(x, y);
		isDragging = true;
	}
	else if (event == EVENT_LBUTTONUP && isDragging) {
		ptEnd = Point(x, y);
		isDragging = false;

		Rect rect = Rect(ptStart, ptEnd) & Rect(0, 0, src.cols, src.rows);

		if (rect.width > 0 && rect.height > 0) {
			Mat roi = dst(rect);
			filter2D(roi, roi, -1, mask);
			imshow("dst", dst);
		}
	}
}

int main(void)
{
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	src.copyTo(dst);

	namedWindow("dst");
	setMouseCallback("dst", on_mouse);
	imshow("dst", dst);
	waitKey();
	return 0;
}

//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace cv;
//using namespace std;
//Mat src, dst;
//Point startPt;
//void onMouse(int event, int x, int y, int flags, void* userdata) {
//	if (event == EVENT_LBUTTONDOWN) {
//		startPt = Point(x, y);
//	}
//	else if (event == EVENT_LBUTTONUP) {
//		Point endPt(x, y);
//		int x1 = min(startPt.x, endPt.x);
//		int y1 = min(startPt.y, endPt.y);
//		int x2 = max(startPt.x, endPt.x);
//		int y2 = max(startPt.y, endPt.y);
//		Rect roi(x1, y1, x2 - x1, y2 - y1);
//		Mat roiRegion = dst(roi);
//		float data[] = { -1,-1,-1,-1,9,-1,-1,-1,-1 };
//		Mat kernel(3, 3, CV_32FC1, data);
//		filter2D(roiRegion, roiRegion, -1, kernel);
//		imshow("dst", dst);
//
//	}
//}
//int main() {
//	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
//	dst = src.clone();
//	namedWindow("dst");
//	setMouseCallback("dst", onMouse);
//	imshow("dst", dst);
//	waitKey();
//	return 0;
//
//}
