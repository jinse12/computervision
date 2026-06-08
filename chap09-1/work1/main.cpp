#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("vertical.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

	Mat mx = Mat_<float>({ 1, 3 }, { -1, 0, 1 });
	Mat my = Mat_<float>({ 3, 1 }, { -1, 0, 1 });

	Mat dx, dy;
	filter2D(src, dx, -1, mx);
	filter2D(src, dy, -1, my);

	imshow("src", src);
	imshow("dx", dx);
	imshow("dy", dy);

	waitKey();
	return 0;
}
