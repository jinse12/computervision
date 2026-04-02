#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("fish.jpg");

	cout << "Rows (행의 수): " << img.rows << endl;
	cout << "Cols (열의 수): " << img.cols << endl;
	cout << "Channels (채널 수): " << img.channels() << endl;

	if (img.type() == CV_8UC1)
		cout << "Type: CV_8UC1 (grayscale image)" << endl;
	else if (img.type() == CV_8UC3)
		cout << "Type: CV_8UC3 (truecolor image)" << endl;
	else if (img.type() == CV_8UC4)
		cout << "Type: CV_8UC4 (BGRA image)" << endl;
	else if (img.type() == CV_16UC1)
		cout << "Type: CV_16UC1" << endl;
	else if (img.type() == CV_32FC1)
		cout << "Type: CV_32FC1" << endl;
	else if (img.type() == CV_32FC3)
		cout << "Type: CV_32FC3" << endl;
	else
		cout << "Type: Unknown (" << img.type() << ")" << endl;

	return 0;
}
