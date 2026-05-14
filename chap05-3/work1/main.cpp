#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& img)
{
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
  const int histSize[] = { 256 };
	float graylevel[] = { 0, 256 };
	const float* ranges[] = { graylevel };

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;
}

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	imshow("src", src);

	cout << "영상의 전체 픽셀수 : " << src.rows * src.cols << endl;

	double minVal, maxVal;
	minMaxLoc(src, &minVal, &maxVal);
	cout << "영상에서 픽셀값의 최소값 : " << minVal << endl;
	cout << "영상에서 픽셀값의 최대값 : " << maxVal << endl;

	Mat hist = calcGrayHist(src);

	double histMax;
	Point maxLoc;
	minMaxLoc(hist, nullptr, &histMax, nullptr, &maxLoc);

  cout << "빈도수가 가장많은 픽셀값과 빈도수 : "
		<< maxLoc.y << ", " << (int)histMax << endl;

	cout << "픽셀값 80의 빈도수 : "
		<< (int)hist.at<float>(80, 0) << endl;

	waitKey();
	return 0;
}
