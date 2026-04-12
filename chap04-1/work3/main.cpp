#include <opencv2/opencv.hpp>
#include <iostream> 
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	int count = 0;

	while (true) {
		Mat frame;
		cap >> frame;

		imshow("img", frame);

		int key = waitKey(1);
		if (key == 'Q' || key == 'q') break;
		if (key == 's') {
			imwrite(format("frame%02d.jpg", count), frame);
			count++;
		}
	}
	return 0;
}
