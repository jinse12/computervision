#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	Mat frame;
	while (true) {
	cap >> frame;
	Mat cross = frame.clone();
	int h = cross.rows;
	int w = cross.cols;
		line(cross, Point(w / 2, 0), Point(w / 2, h), { 0,0,255 }, 1);
		line(cross, Point(0, h / 2), Point(w, h / 2), { 0,0,255 }, 1);
		imshow("origin", frame);
		imshow("cross", cross);
		if (waitKey(1) == 'q')break;
	}
	return 0;
}
