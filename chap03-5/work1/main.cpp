#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.bmp");

	if (src.empty()) {
		printf("Image load failed!");
		return -1;
	}

	Vec3b pixel;

	pixel = src.at<Vec3b>(50, 50);
	cout << "좌표( 50, 50)의 화소값(B,G,R) : " << pixel << endl;

	pixel = src.at<Vec3b>(100, 100);
	cout << "좌표(100,100)의 화소값(B,G,R) : " << pixel << endl;

	pixel = src.at<Vec3b>(150, 150);
	cout << "좌표(150,150)의 화소값(B,G,R) : " << pixel << endl;

	return 0;
}
