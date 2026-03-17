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
	String str; //파일 이름을 저장할 문자열 변수

	//i를 1부터 15까지 홀수로 증가
	for (int i = 1; i <= 15; i += 2)
	{
		//format: i 값을 숫자로 넣어서 예쁘게 만드는 함수
		str = format("실행결과%d.bmp", i);

		//생성된 파일 이름 출력
		cout << str << endl;
	}
	return 0;
}
