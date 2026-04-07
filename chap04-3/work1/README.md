# 과제 1
400x400 영상을 생성하고 line함수를 이용하여 직선을 그리시오.

---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::line 등을 쓸 때 cv::를 생략하기 위해 사용

int main()
{
    // 400x400 흰색 영상 생성 (3채널, 픽셀값 255)
    Mat src(400, 400, CV_8UC3, Scalar(255, 255, 255));

    // 사각형 네 변 그리기 (100,100) ~ (300,300)
    line(src, Point(100, 100), Point(300, 100), Scalar(0, 0, 0), 1); // 위
    line(src, Point(100, 300), Point(300, 300), Scalar(0, 0, 0), 1); // 아래
    line(src, Point(100, 100), Point(100, 300), Scalar(0, 0, 0), 1); // 왼쪽
    line(src, Point(300, 100), Point(300, 300), Scalar(0, 0, 0), 1); // 오른쪽

    // 대각선 X 그리기
    line(src, Point(100, 100), Point(300, 300), Scalar(0, 0, 0), 1); // 좌상 -> 우하
    line(src, Point(300, 100), Point(100, 300), Scalar(0, 0, 0), 1); // 우상 -> 좌하

    imshow("src", src);
    waitKey(0);
    return 0;
}
```
---
## 개념
### Mat 생성 — 빈 영상 만들기
`Mat src(400, 400, CV_8UC3, Scalar(255, 255, 255))` 로 400×400 흰색 영상을 생성한다.

| 인자 | 의미 |
|------|------|
| `400, 400` | 행(height), 열(width) |
| `CV_8UC3` | 8비트 unsigned, 3채널(BGR) |
| `Scalar(255, 255, 255)` | 모든 픽셀을 흰색으로 초기화 |

### line() — 직선 그리기
`line(img, pt1, pt2, color, thickness)` 으로 두 점을 잇는 직선을 그린다.

| 인자 | 의미 |
|------|------|
| `img` | 그릴 대상 영상 |
| `pt1`, `pt2` | 시작점, 끝점 |
| `color` | 선 색상 (BGR) |
| `thickness` | 선 두께 (픽셀) |

### Point — 좌표 지정
`Point(x, y)` 로 픽셀 좌표를 지정한다.
좌상단이 `(0, 0)` 이고 오른쪽/아래쪽으로 갈수록 값이 커진다.

### Scalar(0, 0, 0) — 색상
OpenCV는 BGR 순서로 색상을 지정한다.
`Scalar(0, 0, 0)` 은 검정색, `Scalar(0, 0, 255)` 는 빨간색이다.

---
## 실행 결과

<img width="494" height="532" alt="스크린샷 2026-04-07 140116" src="https://github.com/user-attachments/assets/6178d130-f88c-4e65-adba-73a453fb88a2" />
