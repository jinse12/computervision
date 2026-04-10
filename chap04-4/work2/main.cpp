#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int cntMove = 0;
int cntLButtonDown = 0;
int cntLButtonUp = 0;
void onMouse(int event, int x, int y, int flags, void* userdata);

int main() {
	Mat img = imread("lenna.bmp");

	if (img.empty()) {
		cout << "영상을 불러올 수 없습니다." << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", onMouse);
	imshow("img", img);

	waitKey(0);
	return 0;
}

void onMouse(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_MOUSEMOVE) {
		cntMove++;
		cout << "EVENT_MOUSEMOVE:" << cntMove << endl;
	}
	else if (event == EVENT_LBUTTONDOWN) {
		cntLButtonDown++;
		cout << "EVENT_LBUTTONDOWN:" << cntLButtonDown << endl;
	}
	else if (event == EVENT_LBUTTONUP) {
		cntLButtonUp++;
		cout << "EVENT_LBUTTONUP:" << cntLButtonUp << endl;
	}
}
