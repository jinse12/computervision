#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void on_mouse(int event, int x, int y, int flags, void* userdata);

Mat img;

int main(void) {
	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "영상을 불러올 수 없습니다" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", on_mouse);
	imshow("img", img);

	waitKey();
	return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		Vec3b pixel = img.at<Vec3b>(y, x);
		cout << "좌표: (" << x << "," << y << "), "
			<< "화소값(B,G,R): ("
			<< (int)pixel[0] << ","
			<< (int)pixel[1] << ","
			<< (int)pixel[2] << ")"
			<< endl;
	}
}
