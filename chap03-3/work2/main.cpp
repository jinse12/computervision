#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // 입출력(printf, cout 등)을 사용하기 위한 헤더 파일

using namespace cv;             // cv::Mat, cv::imshow 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main()
{
    // 400 x 300 크기의 3채널 이미지 3개를 만든다.
    // CV_8UC3 : unsigned char 타입, 3채널(B, G, R)
    // Scalar(B, G, R) 순서로 색을 지정한다.

    // Mat 클래스 타입의 변수 선언

    // 파란색 이미지 (Blue = 255, Green = 0, Red = 0)
    Mat blueImg(300, 400, CV_8UC3, Scalar(255, 0, 0));

    // 초록색 이미지 (Blue = 0, Green = 255, Red = 0)
    Mat greenImg(300, 400, CV_8UC3, Scalar(0, 255, 0));

    // 빨간색 이미지 (Blue = 0, Green = 0, Red = 255)
    Mat redImg(300, 400, CV_8UC3, Scalar(0, 0, 255));

    // 만들어진 이미지를 각각 다른 창 이름으로 화면에 보여준다.
    imshow("Blue Window", blueImg);    // 파란색 화면
    imshow("Green Window", greenImg);  // 초록색 화면
    imshow("Red Window", redImg);      // 빨간색 화면

    // 키보드에서 아무 키나 입력될 때까지 대기
    waitKey(0);

    return 0;
}
