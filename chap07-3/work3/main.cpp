#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
using namespace cv;
using namespace std;
int main(void)
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	imshow("src", src);

	float data[25] = {
		 1,  4,  7,  4,  1,
		 4, 16, 26, 16,  4,
		 7, 26, 41, 26,  7,
		 4, 16, 26, 16,  4,
		 1,  4,  7,  4,  1
	};

	Mat kernel = Mat(5, 5, CV_32F, data) / 273.0f;

	Mat dst_filter2D;
	filter2D(src, dst_filter2D, -1, kernel);
	putText(dst_filter2D, "filter2D Gaussian 5x5", Point(10, 30),
		FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
	imshow("filter2D", dst_filter2D);

	Mat dst_gaussian;
	GaussianBlur(src, dst_gaussian, Size(5, 5), 0);
	putText(dst_gaussian, "GaussianBlur 5x5", Point(10, 30),
		FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
	imshow("GaussianBlur", dst_gaussian);

	waitKey();
	return 0;
}
namespace chap07_3 {
	void solution() {

	}
}
