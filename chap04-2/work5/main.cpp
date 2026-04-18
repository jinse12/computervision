#include <opencv2/opencv.hpp>
using namespace cv;

int main(void)
{
	VideoCapture cap(0);
	if (!cap.isOpened()) return -1;

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');

	VideoWriter outputVideo;
	bool recording = false;

	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		int key = waitKey(33);
		if ((key == 's' || key == 'S') && !recording) {
			outputVideo.open("output.mp4", fourcc, 30, Size(w, h));
			recording = outputVideo.isOpened();
		}
		if (key == 'e' || key == 'E') break;

		if (recording) {
			outputVideo << frame;
			putText(frame, "REC", Point(10, 30),
				FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
		}
		imshow("Camera Recording", frame);
	}
	return 0;
}

/*
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap("stopwatch.avi");
	Mat frame;
	cap >> frame;

	int fourcc = VideoWriter::fourcc('m', 'p', '4', 'v');
	VideoWriter writer;

	while (true) {
		cap >> frame;
		if (frame.empty()) break;
		imshow("origin", frame);
		int key= waitKey(33);
		if (key == 's') writer.open("gwage.mp4", fourcc, 30, Size(frame.cols, frame.rows));
		if (writer.isOpened()) writer << frame;
		if (key == 'e')break;
	}
	return 0;
}
*/
