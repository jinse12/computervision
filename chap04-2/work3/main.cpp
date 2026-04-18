#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	VideoCapture cap("stopwatch.avi");
	if (!cap.isOpened()) return -1;

	int fps = (int)cap.get(CAP_PROP_FPS);
	int width = (int)cap.get(CAP_PROP_FRAME_WIDTH);
	int height = (int)cap.get(CAP_PROP_FRAME_HEIGHT);

	VideoWriter out("output.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'),
		fps, Size(width, height));

	Mat frame, cross;
	while (true) {
		cap >> frame;
		if (frame.empty()) { cap.set(CAP_PROP_POS_FRAMES, 0); continue; }

		frame.copyTo(cross);
		line(cross, Point(width / 2, 0), Point(width / 2, height), Scalar(0, 0, 255), 2);
		line(cross, Point(0, height / 2), Point(width, height / 2), Scalar(0, 0, 255), 2);

		out << cross;
		imshow("frame", frame);
		imshow("cross", cross);

		char key = waitKey(1000 / fps);
		if (key == 'q' || key == 'Q') break;
	}
	return 0;
}
/*
#include <opencv2/opencv.hpp>
#include <iostream> 
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap("stopwatch.avi");

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	VideoWriter outputvideo("output.avi", fourcc, 30, Size(640, 480));
	while (true) {
		Mat frame;
		cap >> frame;
		int h = frame.rows;
		int w = frame.cols;

		Mat cross = frame.clone();
		line(cross, Point(w / 2, 0), Point(w / 2, h), Scalar(0, 0, 255));
		line(cross, Point(0, h / 2), Point(w, h / 2), Scalar(0, 0, 255));
		imshow("fr", frame);
		imshow("cr", cross);
		outputvideo << cross;
		
		int key = waitKey(33);
		if (key == 'q' || key == 'Q')break;
	}
}
*/

/*
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap("stopwatch.avi");
	while (true) {
		Mat frame;
		cap >> frame;
		if (frame.empty())break;
		int w = frame.cols;
		int h = frame.rows;
		Mat cross = frame.clone();
		line(cross, Point(w / 2, 0), Point(w / 2, h), { 0,0,255 }, 1);
		line(cross, Point(0, h / 2), Point(w, h / 2), { 0,0,255 }, 1);

		imshow("origin", frame);
		imshow("cross", cross);
		if (waitKey(30) == 'q')break;
	}
	return 0;
}
*/
