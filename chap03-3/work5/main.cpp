#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일

using namespace cv;             // cv::Mat, cv::imshow 등을 쓸 때 cv::를 생략하기 위해 사용

int main() {
	// 400 x 400 크기의 1채널 검은색 이미지 생성
	Mat img(400, 400, CV_8UC1, Scalar(0));

	// gray: 현재 그레이 레벨(0~255)
	// step: 프로그램이 동작하면서 step이 가질수 있는 값은 +1 or -1 두가지.
	for (int gray = 0, step = 1; ; ) {
		// int형 gray를 Scalar로 감싸 uchar로 자동 변환 후 모든 픽셀에 대입
		imshow("GrayLevel", img = Scalar(gray));

		// 5msec 대기 / q 입력 시 종료
		if (waitKey(5) == 'q') break;

		// 그레이 레벨 증가
		gray += step;

		// 흰색 또는 검은색 도달 시 방향 반전
		if (gray == 255 || gray == 0) step = -step;

	}

	return 0;
}
