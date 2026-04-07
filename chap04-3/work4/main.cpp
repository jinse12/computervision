#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat src = imread("lenna.bmp", IMREAD_COLOR);    // 컬러 영상으로 읽기
	if (src.empty()) return -1;

	// 얼굴 주위에 파란색 원 그리기 (그림판으로 좌표 확인)
	// 중심: (300, 275), 반지름: 119
	circle(src, Point(300, 275), 119, Scalar(255, 0, 0), 2, LINE_AA);

	imshow("image", src);
	waitKey(0);
	return 0;
}
