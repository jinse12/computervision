# 과제 3
400x400 영상을 생성하고 다음처럼 도형을 그리시오.

---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::rectangle 등을 쓸 때 cv::를 생략하기 위해 사용

int main()
{
    // 400x400 흰색 영상 생성 (3채널, 픽셀값 255)
    Mat src(400, 400, CV_8UC3, Scalar(255, 255, 255));

    // 사각형 그리기 (100,100) ~ (300,300)
    rectangle(src, Point(100, 100), Point(300, 300), Scalar(0, 0, 0), 1, LINE_AA);

    // 내접원 그리기 (중심: 200,200 / 반지름: 100)
    circle(src, Point(200, 200), 100, Scalar(0, 0, 0), 1, LINE_AA);

    imshow("src", src);
    waitKey(0);
    return 0;
}
```
---
## 개념
### rectangle() — 사각형 그리기
`rectangle(img, pt1, pt2, color, thickness, lineType)` 으로 두 꼭짓점을 기준으로 사각형을 그린다.

| 인자 | 의미 |
|------|------|
| `pt1` | 좌상단 꼭짓점 |
| `pt2` | 우하단 꼭짓점 |
| `color` | 선 색상 (BGR) |
| `thickness` | 선 두께 (픽셀), `-1` 이면 채우기 |
| `lineType` | 선 스타일 (`LINE_8`, `LINE_AA` 등) |

### circle() — 원 그리기
`circle(img, center, radius, color, thickness, lineType)` 으로 원을 그린다.

| 인자 | 의미 |
|------|------|
| `center` | 원의 중심 좌표 |
| `radius` | 반지름 (픽셀) |
| `color` | 선 색상 (BGR) |
| `thickness` | 선 두께 (픽셀), `-1` 이면 채우기 |
| `lineType` | 선 스타일 (`LINE_8`, `LINE_AA` 등) |

### 내접원 좌표 계산
사각형이 `(100,100)` ~ `(300,300)` 이므로 중심은 `(200,200)`, 한 변의 길이는 200px이다.
반지름은 한 변의 절반인 `100` 으로 설정하면 사각형에 딱 맞는 내접원이 된다.

### Scalar(0, 0, 0) — 색상
OpenCV는 BGR 순서로 색상을 지정한다.
`Scalar(0, 0, 0)` 은 검정색, `Scalar(255, 255, 255)` 는 흰색이다.

---
## 실행 결과

<img width="493" height="530" alt="image" src="https://github.com/user-attachments/assets/5cb20106-d581-4ae4-8a3e-2747cf4a8ebf" />
