#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
Mat calcGrayHist(const Mat& img) {
	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0,256 };
	const float* ranges[] = { graylevel };
	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
	return hist;
}
Mat mygetGrayHistImage(const Mat& hist) {
	double histMax;
	minMaxLoc(hist, 0, &histMax);
	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 255; i++) {
		int y1 = 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax);
		int y2 = 100 - cvRound(hist.at<float>(i + 1, 0) * 100 / histMax);
		line(imgHist, Point(i, y1), Point(i + 1, y2), Scalar(0));
	}
	return imgHist;
}
int main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	imshow("입력영상", src);
	Mat hist = calcGrayHist(src);
	Mat histimg = mygetGrayHistImage(hist);
	imshow("srchist", histimg);
	waitKey();
	return;
}
