#include "opencv2/opencv.hpp"  
//openCV의 모든 주요 모듈을 한 번에 포함하는 헤더
#include <iostream>            
//표준 입출력을 사용하기 위해 필요
using namespace cv;
//openCV 네임스페이스 (Mat, imread, imshow 같은 것들)
using namespace std;
//std::cout, std::endl, std::cerr을 그냥 cout, endl, cerr로 사용 가능하게 함

int main() {
	int x, y, w, h, px, py;         //필요한 모든 변수 선언

	cout << "사각형의 좌측 상단의 좌표를 입력하시오(x, y): ";
	//사용자가 입력한 x, y 값을 변수에 저장
	cin >> x >> y;

	cout << "사각형의 폭, 높이를 입력하시오(width, height): ";
	//사용자가 입력한 width, height 값을 변수에 저장
	cin >> w >> h;

	cout << "점 P의 좌표를 입력하시오: ";
	//사용자가 입력한 점의 x, y 좌표를 변수에 저장
	cin >> px >> py;

	//Point 객체를 바로 만들어서 Rect 객체도 바로 생성하면서
	//inside() 함수로 여부 판단
	if (Point(px, py).inside(Rect(x, y, w, h)))
		cout << "점 P는 사각형 안에 있다." << endl;
	else
		cout << "점 P는 사각형 밖에 있다." << endl;

	return 0;
}
