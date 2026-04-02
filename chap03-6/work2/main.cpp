#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat A = (Mat_<double>(2, 2) << 1, 3, -4, 2);
	Mat B = (Mat_<double>(2, 2) << 2, 3, 0, 5);
	Mat C = (Mat_<double>(2, 2) << -2, -2, -2, -3);

	Mat X = 3 * A + B.inv() + 10 * C - 5;

	cout << "X = " << endl << X << endl;

	return 0;
}
