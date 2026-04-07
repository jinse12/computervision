#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));

	Point cur(250, 250);

	while (true) {
		imshow("src", img);

		int key = waitKey(0);
		Point next = cur;

		if (key == 'l' || key == 'L') next.x -= 50;
		else if (key == 'r' || key == 'R') next.x += 50;
		else if (key == 'u' || key == 'U') next.y -= 50;
		else if (key == 'd' || key == 'D') next.y += 50;
		else if (key == 'q' || key == 'Q') break;

		line(img, cur, next, Scalar(0, 0, 0), 1, LINE_AA);
		cur = next;
	}
	return 0;
}
