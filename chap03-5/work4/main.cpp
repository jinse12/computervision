#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat img(400, 400, CV_8UC1, Scalar(255));
	for (int x = 0; x < img.cols; x++) {
		int y = (int)(1.0 / 400.0 * x * x);
		img.at<uchar>(y, x) = 0;
	}
	imshow("img", img);
	waitKey();
	return 0;
}
