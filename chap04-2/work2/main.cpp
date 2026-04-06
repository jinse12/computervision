#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
	VideoCapture cap("stopwatch.avi");
	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return -1;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(CAP_PROP_FPS);

	int fourcc = VideoWriter::fourcc('m', 'p', '4', 'v');
	VideoWriter original("original.mp4", fourcc, fps, Size(w, h));
	VideoWriter bright("bright.mp4", fourcc, fps, Size(w, h));

	if (!original.isOpened() || !bright.isOpened()) {
		cerr << "VideoWriter open failed!" << endl;
		return -1;
	}
	
	Mat frame, brighten;

	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		brighten = frame + Scalar(100, 100, 100);

		original << frame;
		bright << brighten;

		imshow("original", frame);
		imshow("bright", brighten);

		int key = waitKey(30);
		if (key == 'q' || key == 'Q') {
			cout << "종료합니다." << endl;
			break;
		}
	}
	return 0;
}
