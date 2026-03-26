#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // 입출력(printf, cout 등)을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::imshow 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main()
{
    // Mat 객체에 영상 저장
    Mat img1 = imread("dog.bmp", IMREAD_COLOR);
    if (img1.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 깊은 복사로 원본 보존
    Mat img2 = img1.clone();

    // Rect(x, y, width, height)
    // x, y     : 얼굴 좌상단 좌표 (그림판 상태바에서 확인)
    // width    : x2 - x1
    // height   : y2 - y1
    Rect faceROI(104, 46, 70, 70); // ← 실제 측정값으로 수정

    // 얼굴 ROI 영역을 파란색(BGR: 255, 0, 0)으로 채우기
    img2(faceROI) = Scalar(255, 0, 0);

    // 원본과 수정본 출력
    imshow("Original", img1);
    imshow("Blue", img2);

    waitKey();
    return 0;
}
