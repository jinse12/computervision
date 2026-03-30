#include <opencv2/opencv.hpp>
using namespace cv;
int main() {

	Mat img = imread("lenna.bmp");

	if (img.empty()) {
		printf("Image load failed!");
		return -1;
	}

	for (int i = 0; i < img.rows; i++) {
		img.at<Vec3b>(i, img.cols / 4) = Vec3b(255, 255, 255);
		img.at<Vec3b>(i, img.cols / 2) = Vec3b(255, 255, 255);
		img.at<Vec3b>(i, img.cols *3 / 4) = Vec3b(255, 255, 255);
	}
	for (int i = 0; i < img.cols; i++) {
		img.at<Vec3b>(img.rows / 4, i) = Vec3b(255, 255, 255);
		img.at<Vec3b>(img.rows / 2,i) = Vec3b(255, 255, 255);
		img.at<Vec3b>(img.rows *3 / 4,i) = Vec3b(255, 255, 255);
	}
	imshow("img", img);
	waitKey();
	return 0;
}
