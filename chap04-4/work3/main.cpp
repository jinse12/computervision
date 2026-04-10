#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img;
void onMouse(int event, int x, int y, int flags, void* userdata);

int main() {
	img = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (img.empty()) {
		cout << "영상을 불러올 수 없습니다." << endl;
		return -1;
	}

	namedWindow("gray");
	setMouseCallback("gray", onMouse);
	imshow("gray", img);
	waitKey(0);
	return 0;
}

void onMouse(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		int pixel = img.at<uchar>(y, x);
		cout << "좌표: (" << x << "," << y << "), 화소값: " << pixel << endl;
	}
}
