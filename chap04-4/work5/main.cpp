#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void event_handler(int event, int x, int y, int flags, void* userdata);

Mat img;

int main(void)
{
	img = imread("lenna.bmp");
	if (img.empty()) {
		cerr << "영상을 불러올 수 없습니다" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", event_handler);

	int key;
	while (true) {
		imshow("img", img);
		key = waitKey(10);
		if (key == 'q') break;
	}
	return 0;
}

void event_handler(int event, int x, int y, int flags, void* userdata)
{
	static Point ptOld;

	switch (event) {
	case EVENT_LBUTTONDOWN:
		ptOld = Point(x, y);
		cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
		break;

	case EVENT_LBUTTONUP:
		cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;
		{
			Rect r1(ptOld, Point(x, y));
			Mat drag = img(r1);

			namedWindow("drag");
			imshow("drag", drag);
		}
		break;
	}
}
