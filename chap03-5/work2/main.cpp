#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (img.empty()) {
		printf("Image load failed!");
		return -1;
	}
	for (int i = 0; i < img.rows; i++) {
		img.at<uchar>(i, img.cols / 4) = 255;
		img.at<uchar>(i, img.cols / 2) = 255;
		img.at<uchar>(i, img.cols * 3 / 4) = 255;
	}
	for (int i = 0; i < img.cols; i++) {
		img.at<uchar>(img.rows / 4, i) = 255;
		img.at<uchar>(img.rows / 2, i) = 255;
		img.at<uchar>(img.rows * 3 / 4, i) = 255;
	}

	imshow("Line", img);
	waitKey();
	return 0;
}
