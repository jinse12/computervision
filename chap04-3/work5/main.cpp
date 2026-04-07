#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img(200, 600, CV_8UC3);

	Mat roi1 = img(Rect(0, 0, 200, 200));
	Mat roi2 = img(Rect(200, 0, 200, 200));
	Mat roi3 = img(Rect(400, 0, 200, 200));

	roi1 = Scalar(255, 0, 0);
	roi2 = Scalar(0, 255, 0);
	roi3 = Scalar(0, 0, 255);

	rectangle(roi1, Point(30, 30), Point(170, 170), Scalar(255, 255, 255), 8, LINE_AA);

	circle(roi2, Point(100, 100), 70, Scalar(255, 255, 255), 8, LINE_AA);

	line(roi3, Point(30, 30), Point(170, 170), Scalar(255, 255, 255), 8, LINE_AA);
	line(roi3, Point(170, 30), Point(30, 170), Scalar(255, 255, 255), 8, LINE_AA);

	imshow("img", img);
	waitKey(0);
	return 0;
}
