# 과제 2
Lenna 영상에 화면을 4등분하는 가로, 세로선을 그리시오.
  - 반드시 line함수를 이용할 것.
  - 라인 스타일 수정 가능함.
---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::line 등을 쓸 때 cv::를 생략하기 위해 사용

int main()
{
    Mat src = imread("lenna.bmp");  // Lenna 영상 읽기
    if (src.empty()) return -1;     // 파일 열기 실패 시 종료

    int w = src.cols;   // 영상 가로 크기
    int h = src.rows;   // 영상 세로 크기

    // 세로선 3개 (가로 방향 4등분)
    line(src, Point(w/4,   0), Point(w/4,   h), Scalar(255, 0, 0), 1, LINE_AA);
    line(src, Point(w/2,   0), Point(w/2,   h), Scalar(255, 0, 0), 1, LINE_AA);
    line(src, Point(w*3/4, 0), Point(w*3/4, h), Scalar(255, 0, 0), 1, LINE_AA);

    // 가로선 3개 (세로 방향 4등분)
    line(src, Point(0, h/4  ), Point(w, h/4  ), Scalar(255, 0, 0), 1, LINE_AA);
    line(src, Point(0, h/2  ), Point(w, h/2  ), Scalar(255, 0, 0), 1, LINE_AA);
    line(src, Point(0, h*3/4), Point(w, h*3/4), Scalar(255, 0, 0), 1, LINE_AA);

    imshow("src", src);
    waitKey(0);
    return 0;
}
```
---
## 개념
### imread() — 영상 읽기
`imread("lenna.bmp")` 로 영상 파일을 읽어 Mat 객체로 반환한다.
`src.empty()` 로 파일 읽기 실패 여부를 확인한다.

### cols / rows — 영상 크기
`src.cols` 는 영상의 가로(width), `src.rows` 는 세로(height) 픽셀 수를 반환한다.
하드코딩 없이 영상 크기에 맞게 4등분 좌표를 계산할 수 있다.

### line() — 직선 그리기
`line(img, pt1, pt2, color, thickness, lineType)` 으로 두 점을 잇는 직선을 그린다.

| 인자 | 의미 |
|------|------|
| `img` | 그릴 대상 영상 |
| `pt1`, `pt2` | 시작점, 끝점 |
| `color` | 선 색상 (BGR) |
| `thickness` | 선 두께 (픽셀) |
| `lineType` | 선 스타일 (`LINE_4`, `LINE_8`, `LINE_AA`) |

### LINE_AA — 안티앨리어싱
선을 부드럽게 그려주는 옵션으로 경계 픽셀에 중간 색상값을 섞어 계단 현상을 줄인다.

| 옵션 | 설명 |
|------|------|
| `LINE_4` | 4방향 연결, 가장 단순 |
| `LINE_8` | 8방향 연결, 기본값 |
| `LINE_AA` | 안티앨리어싱, 가장 부드러움 |

수직/수평선은 차이가 거의 없으나 사선이나 곡선에서 효과가 두드러진다.

---

## 실행 결과

<img width="632" height="674" alt="image" src="https://github.com/user-attachments/assets/6218138f-ebd0-4070-9c5c-87e81ec67635" />
