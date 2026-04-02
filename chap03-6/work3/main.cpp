#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("lenna.bmp");

	if (img.empty()) {
		printf("Image load failed!");
		return -1;
	}

	int delta;
	cout << "밝기변화량을 입력: ";
	cin >> delta;

	imshow("img", img);

	Mat bright = img + Scalar(delta, delta, delta);
	imshow("bright", bright);

	waitKey();
	return 0;
}
