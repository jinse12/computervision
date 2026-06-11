#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
Mat calcGrayHist(const Mat& img){
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
	double maxVal;
	minMaxLoc(hist, 0, &maxVal);
	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / maxVal)), Scalar(0));
	}
	return imgHist;
}
int main() {
	Mat src = imread("crayfish.jpg", IMREAD_GRAYSCALE);
	double gmin, gmax;
	minMaxLoc(src, &gmin, &gmax);
	Mat dst = (src - gmin) * 255 / (gmax - gmin);
	imshow("src", src);
	imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
	imshow("dst", dst);
	imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));
	waitKey();
	return 0;
}
