#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("tekapo.bmp");
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

	Point2f srcPts[3], dstPts[3];
	srcPts[0] = Point2f(0, 0);
	srcPts[1] = Point2f(src.cols - 1, 0);
	srcPts[2] = Point2f(src.cols - 1, src.rows - 1);

	dstPts[0] = Point2f(0, 0);
	dstPts[1] = Point2f((src.cols - 1) / 2.f, 0);
	dstPts[2] = Point2f((src.cols - 1) / 2.f, (src.rows - 1) / 2.f);

	Mat M = getAffineTransform(srcPts, dstPts);

	Mat dst;
	warpAffine(src, dst, M, Size());
	vector<Point2f> centerPt = { Point2f(src.cols / 2.f, src.rows / 2.f) };
	vector<Point2f> transformedPt;

	transform(centerPt, transformedPt, M);
	cout << "원본 중앙점: " << centerPt[0] << endl;
	cout << "변환된 중앙점: " << transformedPt[0] << endl;

	circle(src, centerPt[0], 5, Scalar(0, 0, 255), -1);
	circle(dst, transformedPt[0], 5, Scalar(0, 0, 255), -1);

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	return 0;
}
