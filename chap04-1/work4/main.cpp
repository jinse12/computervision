#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}

	Mat frame, dst;

	while (true) {
		cap >> frame;

		if (frame.empty()) {
			cerr << "frame empty!" << endl;
			break;
		}

		dst = frame.clone();

		int cx = dst.cols / 2;
		int cy = dst.rows / 2;

		line(dst, Point(0, cy), Point(dst.cols, cy), Scalar(0, 0, 255), 2);
		line(dst, Point(cx, 0), Point(cx, dst.rows), Scalar(0, 0, 255), 2);

		imshow("frame", frame);
		imshow("dst", dst);

		if (waitKey(10) == 'q')
			break;
	}

	return 0;
}
