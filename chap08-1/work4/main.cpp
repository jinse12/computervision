#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
	VideoCapture cap(0);
	if (!cap.isOpened()) { cerr << "Camera open failed!" << endl; return -1; }

	double scale = 1.0;

	Mat frame, dst;
	while (true)
	{
		cap >> frame;
		if (frame.empty()) break;

		Point2f srcPts[3], dstPts[3];
		srcPts[0] = Point2f(0, 0);
		srcPts[1] = Point2f(frame.cols - 1, 0);
		srcPts[2] = Point2f(frame.cols - 1, frame.rows - 1);

		dstPts[0] = Point2f(0, 0);
		dstPts[1] = Point2f((frame.cols - 1) * scale, 0);
		dstPts[2] = Point2f((frame.cols - 1) * scale, (frame.rows - 1) * scale);

		Mat M = getAffineTransform(srcPts, dstPts);
		warpAffine(frame, dst, M, Size(frame.cols, frame.rows));

		imshow("dst", dst);

		int key = waitKey(1);
		if (key == 'a') scale = 2.0;
		else if (key == 'b') scale = 0.5;
		else if (key == 'c') scale = 1.0;
		else if (key == 'q') break;
	}

	return 0;
}
