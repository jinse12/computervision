#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Point2f pt1, pt2;

	cout << "첫번째 점의 x, y 좌표를 입력: ";
	cin >> pt1.x >> pt1.y;

	cout << "두번째 점의 x, y 좌표를 입력: ";
	cin >> pt2.x >> pt2.y;

	cout << "pt1: [" << pt1.x << ", " << pt1.y << "]" << endl;
	cout << "pt2: [" << pt2.x << ", " << pt2.y << "]" << endl;

	float distance = norm(pt1 - pt2);

	cout << "두 점 사이의 거리: " << distance << endl;

	return 0;
}
