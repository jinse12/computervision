#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;
using namespace std;

int main()
{
	int count = 0;
	bool running = false;

	while (true) {
		Mat img(300, 300, CV_8UC3, Scalar(255, 255, 255));
		putText(img, format("%d", count), Point(100, 200),
			FONT_HERSHEY_SCRIPT_SIMPLEX, 5, Scalar(0, 0, 0), 10, LINE_AA);

		imshow("Stopwatch", img);

		int key = waitKey(running ? 1000 : 0);
		if (key == 's' || key == 'S') running = true;
		else if (key == 't' || key == 'T') running = false;
		else if (key == 'r' || key == 'R') { count = 0; running = false; }
		else if (key == 'q' || key == 'Q') break;

		if (running) count++;
	}
	return 0;
}
