#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	const int W = 500, H = 500;
	const int GRID = 5;
	const int CELL = W / GRID;

	int cx = GRID / 2, cy = GRID / 2;

	while (true) {
		Mat img(H, W, CV_8UC3, Scalar(255, 255, 255));
		
		for (int i = 0; i <= GRID; i++) {
			line(img, Point(i * CELL, 0), Point(i * CELL, H), Scalar(0, 0, 0), 1);
			line(img, Point(0, i * CELL), Point(W, i * CELL), Scalar(0, 0, 0), 1);
		}

		rectangle(img, Point(cx * CELL, cy * CELL),
			Point((cx + 1) * CELL, (cy + 1) * CELL),
			Scalar(255, 0, 0), -1);

		imshow("src", img);

		int key = waitKey(0);
		if (key == 'l' || key == 'L') { if (cx > 0)        cx--; }
		else if (key == 'r' || key == 'R') { if (cx < GRID - 1)   cx++; }
		else if (key == 'u' || key == 'U') { if (cy > 0)        cy--; }
		else if (key == 'd' || key == 'D') { if (cy < GRID - 1)   cy++; }
		else if (key == 'q' || key == 'Q') break;
	}
	return 0;
}
