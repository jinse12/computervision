// OpenCV의 기본 헤더 포함
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;   // OpenCV 네임스페이스 사용
using namespace std;  // 표준 C++ 네임스페이스 사용

int main() {
    // B, G, R 값을 저장할 정수형 변수 선언
    int b, g, r;

    // 사용자로부터 Blue 값 입력받기
    cout << "Blue값(0~255)을 입력하시오: ";
    cin >> b;

    // 사용자로부터 Green 값 입력받기
    cout << "Green값(0~255)을 입력하시오: ";
    cin >> g;

    // 사용자로부터 Red 값 입력받기
    cout << "Red값(0~255)을 입력하시오: ";
    cin >> r;

    // 입력받은 값을 Scalar 객체에 저장
    // Scalar의 구성: Scalar(blue, green, red)
    Scalar color(b, g, r);

    //결과 출력
    cout << "입력한 컬러값은 ["
        << (int)color[0] << ", "
        << (int)color[1] << ", "
        << (int)color[2] << ", "
        << (int)color[3] << "] 입니다." << endl;


    return 0;
}
