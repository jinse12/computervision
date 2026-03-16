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
	Point2f pt1, pt2; //두 점을 저장할 변수를 실수형 타입으로 만든다

	//안내 메시지로 입력받은 값을 pt1.x, pt1.y에 저장
	cout << "첫번째 점의 x, y 좌표를 입력: ";
	cin >> pt1.x >> pt1.y;
	//아래도 동일하다
	cout << "두번째 점의 x, y 좌표를 입력: ";
	cin >> pt2.x >> pt2.y;
	//화면에 좌표 출력
	cout << "pt1: " << pt1 << endl;
	cout << "pt2: " << pt2 << endl;
	//두 점의 차이 벡터를 만들고 벡터의 거리를 norm으로 구하고 실수형 distance에 대입
	float distance = norm(pt1 - pt2);
	//두 점 사이의 거리 메시지를 화면에 출력한다.
	cout << "두 점 사이의 거리: " << distance << endl;

	return 0;
}
