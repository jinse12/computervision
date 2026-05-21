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
