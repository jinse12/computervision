#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	imshow("src", src);

	for (int alpha = 10; alpha <= 50; alpha += 10) {
		Mat blurred;
		blur(src, blurred, Size(3, 3));

		Mat dst = (1 + alpha) * src - alpha * blurred;

		String desc = format("alpha: %d", alpha);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
			Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey();
	}
	return 0;
}
