# 과제 4
Lenna 영상을 컬러 영상으로 읽은 후 화면에 출력하고 얼굴주위에 파란색 원을 그리시오.
  - 필요한 좌표값은 그림판 프로그램을 이용하여 구하시오.
---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::circle 등을 쓸 때 cv::를 생략하기 위해 사용

int main()
{
    // 컬러 영상으로 읽기
    Mat src = imread("lenna.bmp", IMREAD_COLOR);
    if (src.empty()) return -1;

    // 얼굴 주위에 파란색 원 그리기 (그림판으로 좌표 확인)
    // 중심: (245, 200), 반지름: 165
    circle(src, Point(245, 200), 165, Scalar(255, 0, 0), 2, LINE_AA);

    imshow("image", src);
    waitKey(0);
    return 0;
}
```
---
## 개념
### IMREAD_COLOR — 컬러 영상으로 읽기
`imread("lenna.bmp", IMREAD_COLOR)` 는 영상을 BGR 3채널 컬러로 읽어온다.

| 플래그 | 의미 |
|--------|------|
| `IMREAD_COLOR` | BGR 3채널 컬러로 읽기 (기본값) |
| `IMREAD_GRAYSCALE` | 그레이스케일 1채널로 읽기 |
| `IMREAD_UNCHANGED` | 원본 채널 그대로 읽기 |

### circle() — 원 그리기
`circle(img, center, radius, color, thickness, lineType)` 으로 원을 그린다.

| 인자 | 의미 |
|------|------|
| `center` | 원의 중심 좌표 |
| `radius` | 반지름 (픽셀) |
| `color` | 선 색상 (BGR) |
| `thickness` | 선 두께, `-1` 이면 채우기 |
| `lineType` | 선 스타일 (`LINE_8`, `LINE_AA` 등) |

### 그림판으로 좌표 구하기
원의 가장자리(얼굴 테두리)까지 마우스를 이동해 좌표 확인
반지름 = 가장자리 x좌표 - 중심 x좌표

---
## 실행 결과

<img width="631" height="666" alt="스크린샷 2026-04-07 144907" src="https://github.com/user-attachments/assets/d1c173e3-8744-448b-80d7-5929c6cf7d3e" />

