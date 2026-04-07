# 과제
600X200 컬러영상을 만들고 Red, Green, Blue로 배경을 만들고 각 도형을 그리시오.
  - 3장 부분행렬(관심영역)을 응용해볼 것.
  - 3개의 관심영역을 만들어 처리하면 좌표 계산이 쉬움.
---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Rect 등을 쓸 때 cv::를 생략하기 위해 사용

int main()
{
    Mat img(200, 600, CV_8UC3);  // 600x200 컬러 영상 생성

    // 3개의 ROI(관심영역) 설정
    Mat roi1 = img(Rect(0,   0, 200, 200));  // 왼쪽  - 파란 배경
    Mat roi2 = img(Rect(200, 0, 200, 200));  // 가운데 - 초록 배경
    Mat roi3 = img(Rect(400, 0, 200, 200));  // 오른쪽 - 빨간 배경

    // 각 ROI 배경색 채우기
    roi1 = Scalar(255, 0, 0);    // Blue
    roi2 = Scalar(0, 255, 0);    // Green
    roi3 = Scalar(0, 0, 255);    // Red

    // ROI1: 흰색 사각형 (roi 내부 좌표 기준)
    rectangle(roi1, Point(30, 30), Point(170, 170), Scalar(255, 255, 255), 8, LINE_AA);

    // ROI2: 흰색 원
    circle(roi2, Point(100, 100), 70, Scalar(255, 255, 255), 8, LINE_AA);

    // ROI3: 흰색 X (대각선 2개)
    line(roi3, Point(30, 30),  Point(170, 170), Scalar(255, 255, 255), 8, LINE_AA);
    line(roi3, Point(170, 30), Point(30, 170),  Scalar(255, 255, 255), 8, LINE_AA);

    imshow("img", img);
    waitKey(0);
    return 0;
}
```
---
## 개념
### ROI(관심영역) — Rect
`img(Rect(x, y, width, height))` 로 영상의 특정 영역을 잘라 Mat으로 참조한다.
ROI는 얕은 복사이므로 roi에 그리면 원본 img에 바로 반영된다.
600x200 영상을 200씩 3등분하여 각각 독립적으로 처리할 수 있다.

| ROI | x 시작 | 배경색 | 도형 |
|-----|--------|--------|------|
| roi1 | 0 | Blue `(255,0,0)` | 사각형 |
| roi2 | 200 | Green `(0,255,0)` | 원 |
| roi3 | 400 | Red `(0,0,255)` | X |

### ROI 내부 좌표 기준
도형을 그릴 때 좌표는 **ROI 내부 기준(0,0 시작)** 으로 계산한다.
전체 img 기준이 아니므로 좌표 계산이 단순해진다.

### rectangle() / circle() / line()
| 함수 | 용도 |
|------|------|
| `rectangle(img, pt1, pt2, color, thickness, lineType)` | 사각형 |
| `circle(img, center, radius, color, thickness, lineType)` | 원 |
| `line(img, pt1, pt2, color, thickness, lineType)` | 직선 |

`thickness` 에 `-1` 을 전달하면 도형 내부를 채운다.
`Scalar(255, 255, 255)` 는 BGR 기준 흰색이다.

---
## 실행 결과

<img width="748" height="280" alt="스크린샷 2026-04-07 145652" src="https://github.com/user-attachments/assets/d060faac-828d-413d-a2dc-120f91abb9a1" />
