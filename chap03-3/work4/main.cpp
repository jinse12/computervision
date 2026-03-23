#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // 입출력(printf, cout 등)을 사용하기 위한 헤더 파일

using namespace cv;             // cv::Mat, cv::imshow 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용


int main()
{
    // Mat 타입 배열로 이미지 3개 선언
    Mat imgs[3];
    imgs[0] = Mat(300, 400, CV_8UC3, Scalar(255, 0, 0));  // Blue
    imgs[1] = Mat(300, 400, CV_8UC3, Scalar(0, 255, 0));  // Green
    imgs[2] = Mat(300, 400, CV_8UC3, Scalar(0, 0, 255));  // Red

    // 현재 표시할 이미지의 배열 인덱스 (0=Blue, 1=Green, 2=Red)
    int index = 0;

    while (true)
    {
        // index번째 이미지를 "Window" 창에 표시
        imshow("Window", imgs[index]);

        // 다음 이미지로 순환
        index = (index + 1) % 3;

        // 1초 대기, q 누르면 반복문 종료
        if (waitKey(1000) == 'q') break;
    }

    return 0;
}
