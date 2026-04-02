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
	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	Mat frame, bright;

	while (true) {
		cap >> frame;
		if (frame.empty()) {
			cerr << "frame empty!" << endl;
			break;
		}
		bright = frame + Scalar(100, 100, 100);

		imshow("frame", frame);
		imshow("bright", bright);

		if (waitKey(10) == 27)
			break;
	}

	return 0;
}
