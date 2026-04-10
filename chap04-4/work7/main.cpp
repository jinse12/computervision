#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void event_handler(int event, int x, int y, int flags, void* userdata);

Mat img;

int main(void)
{
	img = Mat(300, 500, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(0, 0, 200, 100), Scalar(0, 0, 0), 2);
	rectangle(img, Rect(0, 100, 200, 100), Scalar(0, 0, 0), 2);
	rectangle(img, Rect(0, 200, 200, 100), Scalar(0, 0, 0), 2);

	putText(img, "Red", Point(70, 60), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
	putText(img, "Green", Point(55, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
	putText(img, "Blue", Point(65, 260), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);

	namedWindow("Menu");
	setMouseCallback("Menu", event_handler);

	int key;
	while (true) {
		imshow("Menu", img);
		key = waitKey(10);
		if (key == 'q') break;
	}
	return 0;
}

void event_handler(int event, int x, int y, int flags, void* userdata)
{
	if (event != EVENT_LBUTTONDOWN) return;

	img = Mat(300, 500, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(0, 0, 200, 100), Scalar(0, 0, 0), 2);
	rectangle(img, Rect(0, 100, 200, 100), Scalar(0, 0, 0), 2);
	rectangle(img, Rect(0, 200, 200, 100), Scalar(0, 0, 0), 2);
	putText(img, "Red", Point(70, 60), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
	putText(img, "Green", Point(55, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
	putText(img, "Blue", Point(65, 260), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);

	if (x >= 0 && x < 200 && y >= 0 && y < 100) {
		rectangle(img, Rect(0, 0, 200, 100), Scalar(0, 0, 0), -1);
		putText(img, "Red", Point(70, 60), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
		putText(img, "Red pressed.", Point(220, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
	}
	else if (x >= 0 && x < 200 && y >= 100 && y < 200) {
		rectangle(img, Rect(0, 100, 200, 100), Scalar(0, 0, 0), -1);
		putText(img, "Green", Point(55, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
		putText(img, "Green pressed.", Point(220, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
	}
	else if (x >= 0 && x < 200 && y >= 200 && y < 300) {
		rectangle(img, Rect(0, 200, 200, 100), Scalar(0, 0, 0), -1);
		putText(img, "Blue", Point(65, 260), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
		putText(img, "Blue pressed.", Point(220, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
	}
}
