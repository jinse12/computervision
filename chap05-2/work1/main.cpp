#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return-1; }

	float s = 2.f;
	Mat dst(src.rows, src.cols, src.type());
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = saturate_cast<uchar>(s * src.at<uchar>(j, i));
		}
	}
	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	return 0;
}
