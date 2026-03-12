#include "opencv2/opencv.hpp"  
//openCV의 모든 주요 모듈을 한 번에 포함하는 헤더
#include <iostream>            
//표준 입출력을 사용하기 위해 필요
using namespace cv;
//openCV 네임스페이스 (Mat, imread, imshow 같은 것들)
using namespace std;
// std::cout, std::endl, std::cerr을 그냥 cout, endl, cerr로 사용 가능하게 함

int main()
{
	//openCV 버전 출력
	cout << "Hello OpenCV " << CV_VERSION << endl;
	Mat img;
	//Mat은 openCV의 가장 기본적인 이미지 객체

	//이미지 파일 읽기
	//lenna.bmp 파일을 그레이스케일 모드로 읽음
	img = imread("lenna.bmp", IMREAD_GRAYSCALE);

	//이미지 로드에 실패했는지 확인 (파일이 없거나 경로가 잘못됐는지
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		//cerr : 표준 에러 출력
		return -1;  //비정상 종료
	}

	//창 이름 "image"로 창을 만들고 img를 화면에 띄움
	imshow("image", img);

	Mat bright;
	//밝기 조절된 이미지를 저장할 새로운 Mat 객체

	//밝기 전체를 100만큼 증가
	bright = img + 100;

	//밝기 조절된 결과 화면에 띄우기
	imshow("bright image", bright);

	//현재 밝기 조절된 이미지를 파일로 저장
	//현재 디렉토리에 "bright.jpg" 이름으로 jpg 저장
	imwrite("bright.jpg", bright);
	waitKey();
	//키보드 입력을 기다림 (아무 키나 누를 때까지 프로그램 멈춤)
	//괄호 안에 숫자를 넣으면 그 시간만큼만 기다림

	return 0;
}
