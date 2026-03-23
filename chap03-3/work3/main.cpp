#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // 입출력(printf, cout 등)을 사용하기 위한 헤더 파일

using namespace cv;             // cv::Mat, cv::imshow 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main() {
	int b, g, r;

	// B G R 순서로 각 채널 값 입력받기
	cout << "B값을 입력하라: ";
	cin >> b;
	cout << "G값을 입력하라: ";
	cin >> g;
	cout << "R값을 입력하라: ";
	cin >> r;

	// 400x300 크기의 흰색(255,255,255) 초기 이미지 생성
	// CV_8UC3: 8비트 unsigned 3채널
	Mat img(300, 400, CV_8UC3, Scalar(255, 255, 255));

	// setTo()로 이미지 전체 픽셀을 입력받은 BGR 색으로 변경
	img.setTo(Scalar(b, g, r));

	// 윈도우에 이미지 출력
	imshow("Image", img);

	// 키 입력 대기
	waitKey(0);

	return 0;
}
