#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

int main(void)
{
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	VideoWriter outputVideo("output.mp4", fourcc, 30, Size(w, h));

	if (!outputVideo.isOpened()) {
		cout << "File open failed!" << endl;
		return -1;
	}

	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		outputVideo << frame;
		imshow("Camera Recording", frame);

		int key = waitKey(33);
		if (key == 'q' || key == 'Q') {
			cout << "녹화 종료." << endl;
			break;
		}
	}
}
/*
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0);
	int fourcc = VideoWriter::fourcc('X', 'V', 'I', 'D');
	VideoWriter outputvideo("output.mp4", fourcc, 30, Size(640, 480));

	while (true) {
		Mat frame;
		cap >> frame;

		outputvideo << frame;
		imshow("fr", frame);

		int key = waitKey(33);
		if (key == 'q' || key == 'Q') break;
	}
}
*/
