// OpenCV의 기본 헤더 포함
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;       // OpenCV의 네임스페이스 사용
using namespace std;      // 표준 C++ 라이브러리 네임스페이스 사용

int main() {
    // B, G, R 값을 저장할 변수 선언
    int b, g, r;

    // 사용자로부터 Blue 입력받기
    cout << "Blue값(0~255)을 입력하시오: ";
    cin >> b;

    // 사용자로부터 Green 입력받기
    cout << "Green값(0~255)을 입력하시오: ";
    cin >> g;

    // 사용자로부터 Red 입력받기
    cout << "Red값(0~255)을 입력하시오: ";
    cin >> r;

    // 입력값을 Vec3b 타입에 저장
    // Vec3b는 unsigned char(0~255) 3개를 저장하는 OpenCV의 벡터 클래스
    Vec3b color(b, g, r);

    // 결과 출력
    cout << "입력한 컬러값은 [" 
         << (int)color[0] << ", "    // Blue 값
         << (int)color[1] << ", "    // Green 값
         << (int)color[2] << "] 입니다." << endl;

    return 0;
}
