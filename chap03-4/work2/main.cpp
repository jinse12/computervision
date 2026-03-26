#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // 입출력(printf, cout 등)을 사용하기 위한 헤더 파일

using namespace cv;             // cv::Mat, cv::imshow 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main() {
    // img1 객체 생성
    // Mat_<int> 템플릿으로 데이터 타입을 정수형으로
    Mat img1 = (Mat_<int>(3, 5) <<
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15);

    // 관심 영역 객체 생성
    // Rect(x, y, width, height)
    // x=2: 3번째 열부터, y=1: 2번째 행부터
    // width=3: 열 3개(3,4,5번째), height=2: 행 2개(2,3번째)
    Rect roi(2, 1, 3, 2);

    // img2 객체 생성: img1에서 roi 영역의 부분행렬을 복사하여 저장
    // clone()으로 독립적인 메모리를 갖는 새로운 Mat 객체 생성
    Mat img2 = img1(roi).clone();

    // img1 출력
    cout << "img1" << endl;
    cout << img1 << endl;

    // img2 출력
    cout << "img2" << endl;
    cout << img2 << endl;

    return 0;
}
