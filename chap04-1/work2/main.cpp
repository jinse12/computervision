#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	while (true) {
		Mat frame;
		cap >> frame;
		Mat bright;
		bright = frame+Scalar(100,100,100);
		imshow("origin", frame);
		imshow("bright", bright);
		if (waitKey(1) == 'q')break;
	}
	return 0;
}
