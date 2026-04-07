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
