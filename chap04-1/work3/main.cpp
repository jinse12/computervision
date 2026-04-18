#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	int count = 0;
	while (true) {
		Mat frame;
		cap >> frame;
		imshow("origin", frame);
		int key = waitKey(1);
		if (key == 's') imwrite(format("frame%02d.jpg", count++), frame);
		if (key == 'q')break;
	}
	return 0;
}
