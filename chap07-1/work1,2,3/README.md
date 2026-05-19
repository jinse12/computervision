# 실습과제 1, 2, 3

코드 7-1에서 필터를 각각 다른 마스크로 바꾼 후 결과를 출력하라.

## 코드

```cpp
#include <iostream>            // 표준 입출력 헤더
#include <opencv2/opencv.hpp>  // OpenCV 헤더
using namespace std;           // std:: 생략
using namespace cv;            // cv:: 생략

int main(void)
{
    // rose.bmp를 그레이스케일로 로드
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

    // 실습과제 1 - 평균 필터 마스크 생성 (모든 원소 1/9)
    // 1/9.f : float형 나눗셈 (1/9는 정수 나눗셈으로 0이 되므로 .f 필요)
    float data1[] = { 1/9.f, 1/9.f, 1/9.f,
                      1/9.f, 1/9.f, 1/9.f,
                      1/9.f, 1/9.f, 1/9.f };
    Mat mask1(3, 3, CV_32FC1, data1); // 3x3 크기의 float형 마스크 생성
    Mat dst1;
    filter2D(src, dst1, -1, mask1, Point(-1, -1), 0); // delta=0 : 추가로 더할 값 없음

    // 실습과제 2 - 샤프닝 필터 마스크 생성 (중앙 9, 나머지 -1)
    // 모든 원소의 합 = 9 + (-1x8) = 1
    float data2[] = { -1, -1, -1,
                      -1,  9, -1,
                      -1, -1, -1 };
    Mat mask2(3, 3, CV_32FC1, data2); // 3x3 크기의 float형 마스크 생성
    Mat dst2;
    filter2D(src, dst2, -1, mask2, Point(-1, -1), 0); // delta=0 : 추가로 더할 값 없음

    // 실습과제 3 - Sobel 에지 검출 마스크 생성
    // 왼쪽 열 음수(-1,-2,-1), 가운데 열 0, 오른쪽 열 양수(1,2,1)
    float data3[] = { -1,  0,  1,
                      -2,  0,  2,
                      -1,  0,  1 };
    Mat mask3(3, 3, CV_32FC1, data3); // 3x3 크기의 float형 마스크 생성
    Mat dst3_0, dst3_128;
    filter2D(src, dst3_0,   -1, mask3, Point(-1, -1), 0);   // delta=0   : 음수값이 포화연산으로 0이 됨
    filter2D(src, dst3_128, -1, mask3, Point(-1, -1), 128); // delta=128 : 결과값에 128을 더해 양쪽 경계 표현

    imshow("원본",              src);      // 원본 영상 출력
    imshow("과제1",             dst1);     // 평균 필터 결과 출력
    imshow("과제2",             dst2);     // 샤프닝 필터 결과 출력
    imshow("과제3 - delta=0",   dst3_0);   // Sobel 에지 검출 결과 출력 (delta=0)
    imshow("과제3 - delta=128", dst3_128); // Sobel 에지 검출 결과 출력 (delta=128)

    waitKey(); // 키 입력 대기
    return 0;  // 프로그램 정상 종료
}
```

## 실습과제 1 — 평균 필터 (블러링)

```cpp
float data1[] = { 1/9.f, 1/9.f, 1/9.f,
                  1/9.f, 1/9.f, 1/9.f,
                  1/9.f, 1/9.f, 1/9.f };
```

3×3 영역의 9개 픽셀 평균값으로 현재 픽셀을 교체합니다. 평균을 내면 주변 픽셀값과의 차이가 줄어들어 영상이 부드럽게(블러링) 보입니다. delta = 0이므로 결과값에 추가로 더하는 값은 없습니다.

## 실습과제 2 — 샤프닝 필터

```cpp
float data2[] = { -1, -1, -1,
                  -1,  9, -1,
                  -1, -1, -1 };
```

마스크 원소의 합이 1이므로 평탄한 영역은 원본값이 유지되고, 경계 부분은 중앙값(9)이 주변값(-1)과의 차이를 강조하여 영상의 윤곽선이 뚜렷하게 표현됩니다. delta = 0이므로 결과값에 추가로 더하는 값은 없습니다.

## 실습과제 3 — Sobel 에지 검출

```cpp
float data3[] = { -1,  0,  1,
                  -2,  0,  2,
                  -1,  0,  1 };
```

왼쪽 열은 음수, 오른쪽 열은 양수로 구성되어 가로 방향 경계를 검출합니다. delta = 0이면 음수값이 포화연산으로 사라져 한쪽 경계만 표현되고, delta = 128을 더하면 음수 경계는 어두운 회색, 평탄한 영역은 중간 회색(128), 양수 경계는 밝은 색으로 양쪽 경계가 모두 표현됩니다.

## 실행 결과

<img width="1797" height="845" alt="image" src="https://github.com/user-attachments/assets/a453c3be-7148-4e70-a11e-047eb9fd184f" />
