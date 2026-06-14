#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat src;
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
Mat getGrayHistImage(const Mat& hist) {
	double histmax;
	minMaxLoc(hist, 0, &histmax);
	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 255; i++) {
		int y1 = 100 - cvRound(hist.at<float>(i, 0) * 100 / histmax);
		int y2 = 100 - cvRound(hist.at<float>(i+1, 0) * 100 / histmax);
		line(imgHist, Point(i, y1), Point(i+1, y2), Scalar(0));

	}
	return imgHist;
}
int main() {
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	imshow("src", src);
	Mat hist = calcGrayHist(src);
	Mat histImg = getGrayHistImage(hist);
	imshow("histimg", histImg);
	waitKey();
	return 0;
}
