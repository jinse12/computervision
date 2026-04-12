#include <opencv2/opencv.hpp>
#include <iostream> 
using namespace std;
using namespace cv;

int main() {
	Mat img = imread("lenna.bmp");

	int x, y, width, height, pixel;

	cout << "관심영역의 좌측상단좌표(x, y): ";
	cin >> x >> y;
	cout << "관심영역의 폭,높이(width, height): ";
	cin >> width >> height;
	cout << "픽셀변화량: ";
	cin >> pixel;

	img(Rect(x, y, width, height)) += Scalar(pixel, pixel, pixel);

	imshow("img", img);
	waitKey(0);

	return 0;
}
