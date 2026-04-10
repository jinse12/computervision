#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void on_mouse(int event, int x, int y, int flags, void* userdata);

Mat img;

int main(void) {
	img = Mat(200, 400, CV_8UC3, Scalar(255, 255, 255));

	namedWindow("src");
	setMouseCallback("src", on_mouse);
	imshow("src", img);

	waitKey();
	return 0;
}
void on_mouse(int event, int x, int y, int flags, void* userdata) {
	switch (event) {
	case EVENT_LBUTTONDOWN:
		img = Mat(200, 400, CV_8UC3, Scalar(0, 0, 255));
		imshow("src", img);
		break;
	case EVENT_RBUTTONDOWN:
		img = Mat(200, 400, CV_8UC3, Scalar(255, 0, 0));
		imshow("src", img);
		break;
	}
}
