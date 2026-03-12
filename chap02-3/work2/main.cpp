#include <opencv2/opencv.hpp> //openCV의 모든 주요 모듈을 한 번에 포함하는 헤더
using namespace cv;//openCV 네임스페이스

int main()
{
	//이미지 파일 이름 배열
	const char* files[3] = { "lion.jpg", "panda.jpg", "pig.jpg" };
	//3장의 이미지를 저장할 Mat 배열
	Mat imgs[3];

	//이미지들 미리 읽어오기
	for (int i = 0; i < 3; i++) {
		imgs[i] = imread(files[i]); //imread : 파일에서 이미지를 읽어 Mat 객체로 변환, flag는 기본으로 컬러 이미지로 지정됨
		if (imgs[i].empty()) return -1;   //파일이 없거나 경로가 잘못되면 비정상 종료됨
	}

	int idx = 0;   // 현재 보여줄 이미지 인덱스

	while (true)
	{
		imshow("Slide", imgs[idx]);       //현재 인덱스에 해당하는 이미지를 창에 표시
		idx = (idx + 1) % 3;              //다음 이미지로 이동

		//1초 대기 + 키 입력 체크
		if (waitKey(1000) >= 0) break;    //아무 키나 누르면 종료
	}

	return 0;
}
