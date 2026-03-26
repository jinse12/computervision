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

    // 그림판으로 측정한 얼굴 영역 ROI
    Rect faceROI(115, 73, 48, 10);

    // 얼굴 영역을 얕은 복사로 참조
    Mat faceRef = img1(faceROI);

    // 얼굴 원본을 깊은 복사로 따로 저장
    Mat faceBackup;
    faceRef.copyTo(faceBackup); // 깊은 복사로 원본 얼굴 보존

    while (true)
    {
        // 얕은 복사 참조를 통해 얼굴 영역을 파란색으로 변경
        faceRef = Scalar(255, 0, 0);

        // 변경된 img1 출력
        imshow("dog", img1);

        // 1초 대기(q 누르면 종료)
        if (waitKey(1000) == 'q') break;

        // 깊은 복사본으로 얼굴 영역 복구
        // faceRef(img1의 얼굴 영역)에 원본 데이터 복사
        faceBackup.copyTo(faceRef);

        // 복구된 img1 출력
        imshow("dog", img1);

        // 1초 대기 (q 누르면 종료)
        if (waitKey(1000) == 'q') break;
    }

    return 0;
}
