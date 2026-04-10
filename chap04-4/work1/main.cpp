#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat img = imread("lenna.bmp");

	if (img.empty()) {
		cout << "영상을 불러올 수 없습니다." << endl;
		return -1;
	}

	namedWindow("image");
	imshow("image", img);

	while (true) {
		int keycode = waitKey(0);

		if (keycode == 'l') {
			line(img,
				Point(100, 340),
				Point(400, 340),
				Scalar(255, 255, 255), 2);
		}
		else if (keycode == 'c') {
			circle(img,
				Point(256, 270),
				130,
				Scalar(0, 0, 255), 2);
		}
		else if (keycode == 't') {
			putText(img,
				"Hello, Lenna",
				Point(80, 70),
				FONT_HERSHEY_SIMPLEX,
				1.5,
				Scalar(0, 255, 255), 2);
		}
		else if (keycode == 'q') {
			break;
		}
		imshow("image", img);
	}
	return 0;
}
