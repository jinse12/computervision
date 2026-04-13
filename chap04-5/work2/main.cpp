#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flags, void* userdata);
void on_trackbar(int pos, void* userdata);

Mat img;
int track_pos = 0;
Point pt1, pt2;
bool drawing = false;

int main() {
	img = Mat(500, 500, CV_8UC3, Scalar(255, 255, 255));

	namedWindow("img");
	setMouseCallback("img", on_mouse);
	createTrackbar("level", "img", 0, 3, on_trackbar);

	while (true) {
		imshow("img", img);
		if (waitKey(1) == 'q') break;
	}
	return 0;
}

void on_trackbar(int pos, void* userdata) {
	track_pos = pos;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
	switch (event) {
	case EVENT_LBUTTONDOWN:
		drawing = true;
		pt1 = Point(x, y);
		break;

	case EVENT_LBUTTONUP:
		drawing = false;
		pt2 = Point(x, y);
		switch (track_pos) {
		case 0: rectangle(img, pt1, pt2, Scalar(255, 0, 0), 2); break;
		case 1: rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2); break;
		case 2: rectangle(img, pt1, pt2, Scalar(0, 0, 255), 2); break;
		case 3: rectangle(img, pt1, pt2, Scalar(255, 255, 255), -1); break;
		}
		break;
	}
}
