#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat mycalcGrayHist(const Mat& img)
{
	CV_Assert(img.type() == CV_8UC1);

	Mat hist = Mat::zeros(256, 1, CV_32FC1);

	for (int j = 0; j < img.rows; j++)
		for (int i = 0; i < img.cols; i++)
			hist.at<float>(img.at<uchar>(j, i), 0)++;
	
	return hist;
}

Mat getGrayHistImage(const Mat& hist)
{
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist,
			Point(i, 100),
			Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)),
			Scalar(0));
	}
	return imgHist;
}

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	imshow("입력 영상", src);

	Mat hist = mycalcGrayHist(src);
	Mat hist_img = getGrayHistImage(hist);

	imshow("srcHist", hist_img);

	waitKey();
	return 0;
}
