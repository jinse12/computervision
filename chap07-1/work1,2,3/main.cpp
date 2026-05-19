#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(void)
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

	// 실습과제 1
	float data1[] = { 1 / 9.f, 1 / 9.f, 1 / 9.f,
					  1 / 9.f, 1 / 9.f, 1 / 9.f,
					  1 / 9.f, 1 / 9.f, 1 / 9.f };
	Mat mask1(3, 3, CV_32FC1, data1);
	Mat dst1;
	filter2D(src, dst1, -1, mask1, Point(-1, -1), 0);

	// 실습과제 2
	float data2[] = { -1, -1, -1,
					  -1,  9, -1,
					  -1, -1, -1 };
	Mat mask2(3, 3, CV_32FC1, data2);
	Mat dst2;
	filter2D(src, dst2, -1, mask2, Point(-1, -1), 0);

	// 실습과제 3
	float data3[] = { -1,  0,  1,
					  -2,  0,  2,
					  -1,  0,  1 };
	Mat mask3(3, 3, CV_32FC1, data3);
	Mat dst3_0, dst3_128;
	filter2D(src, dst3_0, -1, mask3, Point(-1, -1), 0);
	filter2D(src, dst3_128, -1, mask3, Point(-1, -1), 128);

	imshow("원본", src);
	imshow("과제1", dst1);
	imshow("과제2", dst2);
	imshow("과제3 - delta=0", dst3_0);
	imshow("과제3 - delta=128", dst3_128);

	waitKey();
	return 0;
}
