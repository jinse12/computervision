#include "opencv2/opencv.hpp"  
//openCV의 모든 주요 모듈을 한 번에 포함하는 헤더
#include <iostream>            
//표준 입출력을 사용하기 위해 필요
using namespace cv;
//openCV 네임스페이스 (Mat, imread, imshow 같은 것들)
using namespace std;
//std::cout, std::endl, std::cerr을 그냥 cout, endl, cerr로 사용 가능하게 함

int main()
{
	Size2f s1, s2;                //두개의 사각형 크기를 저장할 변수 선언
	//Size2f : float 타입의 width, height를 가지는 OpenCV 클래스

	//사용자에게 첫번째 사각형의 크기 입력 요청
	cout << "첫번째 사각형의 폭, 높이 입력: ";
	cin >> s1.width >> s1.height; //width와 height를 순서대로 입력받음

	//사용자에게 두번째 사각형의 크기 입력 요청
	cout << "두번째 사각형의 폭, 높이 입력: ";
	cin >> s2.width >> s2.height; //동일하게 width와 height 입력받음

	//입력받은 값을 확인하기 위해 출력
	cout << "s1: [" << s1.width << " x " << s1.height << "]" << endl;
	cout << "s2: [" << s2.width << " x " << s2.height << "]" << endl;

	//각 사각형의 면적 계산
	float area1 = s1.width * s1.height;
	float area2 = s2.width * s2.height;

	//계산된 면적 출력
	cout << "s1의 면적: " << area1 << endl;
	cout << "s2의 면적: " << area2 << endl;

	return 0;
}
