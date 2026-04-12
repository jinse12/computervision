#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	int idx = 0;

	while (true) {
		Mat img(200, 600, CV_8UC3, Scalar(255, 255, 255));

		if (idx == 0) img(Rect(0, 0, 200, 200)) = Scalar(0, 0, 255);
		else if (idx == 1) img(Rect(200, 0, 200, 200)) = Scalar(0, 0, 255);
		else if (idx == 2) img(Rect(400, 0, 200, 200)) = Scalar(0, 0, 255);

		imshow("img", img);

		if (waitKey(1000) == 'q') break;

		idx = (idx + 1) % 3;
	}
	return 0;
}
