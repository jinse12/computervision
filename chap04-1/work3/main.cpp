#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}

	Mat frame;
	int cnt = 0;

	while (true) {
		cap >> frame;

		if (frame.empty()) {
			cerr << "frame empty!" << endl;
			break;
		}

		imshow("frame", frame);

		int key = waitKey(10);

		if (key == 'q' || key == 'Q')
			break;

		if (key == 's') {
			String filename = format("frame%02d.jpg", cnt);
			imwrite(filename, frame);
			cout << filename << " saved." << endl;
			cnt++;
		}
	}

	return 0;
}
