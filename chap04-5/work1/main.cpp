#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void on_trackbar(int pos, void* userdata);

Mat img;
int main() {
	img = imread("lenna.bmp");

	namedWindow("Lenna");
	createTrackbar("Trackbar", "Lenna", 0, 100, on_trackbar);
	while (true) {
		imshow("Lenna", img);
		if (waitKey(1) == 'q')break;
	}
		return 0;
}
	void on_trackbar(int pos, void* userdata) {
	cout << "트랙바 위치: " << pos << endl;
	Point center(img.cols / 2, img.rows / 2);
	circle(img, center, pos, Scalar(0, 255, 0), 2, LINE_AA);
}
