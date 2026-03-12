#include <opencv2/opencv.hpp> //openCV의 모든 주요 모듈을 한 번에 포함하는 헤더
using namespace cv;//openCV 네임스페이스

int main() {
	Mat nums[10]; //0~9까지 숫자 이미지를 저장할 배열
	for (int i = 0; i < 10; i++) {
		//파일에서 이미지를 읽어 Mat 객체로 변환, flag는 기본으로 컬러 이미지로 지정됨
		nums[i] = imread(std::to_string(i) + ".bmp"); //imread 함수는 파일 경로를 문자열로 받기 때문에 정수 i를 문자열로 변환
		if (nums[i].empty()) return -1;   //파일이 없거나 경로가 잘못되면 비정상 종료됨
	}

	int idx = 0; //숫자 이미지의 인덱스
	while (true) {
		imshow("Counter", nums[idx]); //현재 인덱스에 해당하는 숫자 이미지를 화면에 출력
		idx = (idx + 1) % 10; //0~9를 순환
		//1초 대기 + 키 입력 체크
		if (waitKey(1000) >= 0) break;    //아무 키나 누르면 종료
	}
	return 0;
}
