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
	//사각형 만들기
	//x=10, y=10에서 시작해서 가로 20, 세로 20 크기
	Rect r1(10, 10, 20, 20);

	//확인하고 싶은 점 만들기
	//이 점은 사각형 안에 있음
	Point p1(15, 15);

	//점이 사각형 안에 있는지 확인
	//contains 안에 있으면 true, 없으면 false 반환
	if (r1.contains(p1))
	{
		cout << "점 p1(" << p1.x << ", " << p1.y << ")은 ";
		cout << "사각형 r1 안에 있습니다." << endl;
	}
	else
	{
		cout << "점 p1(" << p1.x << ", " << p1.y << ")은 ";
		cout << "사각형 r1 밖에 있습니다." << endl;
	}

	return 0;
}
