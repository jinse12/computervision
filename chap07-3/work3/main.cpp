#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat src, blurred;
int alpha = 0;

void on_trackbar(int, void*)
{
	Mat dst = (1 + alpha) * src - alpha * blurred;
	imshow("dst", dst);
}

int main(void)
{
	src = imread("rose.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	imshow("src", src);

	blur(src, blurred, Size(3, 3));

	namedWindow("dst");
	createTrackbar("alpha", "dst", &alpha, 50, on_trackbar);
	on_trackbar(0, 0);

	waitKey();
	return 0;
}
