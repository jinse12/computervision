# 과제
카메라로 촬영한 영상을 화면에 출력하라.
- 무한루프로 작성하고 q를 누르면 종료하라.
- 새로운 창을 출력하고 원본에 빨간색으로 십자선을 그린 후 출력하라.
- 원본과 처리결과를 저장하는 Mat 객체를 분리하여 저장하라.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cerr 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cerr 등을 쓸 때 std::를 생략하기 위해 사용

int main(void)
{
    // 0번 카메라(기본 웹캠) 열기
    VideoCapture cap(0);

    // 카메라 열기 실패 체크
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    Mat frame, dst;     // frame: 원본, dst: 처리결과 (Mat 객체 분리)

    while (true) {
        // 카메라에서 프레임 한 장 읽기
        cap >> frame;

        // 프레임이 비어있으면 종료
        if (frame.empty()) {
            cerr << "frame empty!" << endl;
            break;
        }

        // 원본을 dst에 복사 (원본 보존을 위해 clone 사용)
        dst = frame.clone();

        // 영상 중심 좌표 계산
        int cx = dst.cols / 2;  // 가로 중심
        int cy = dst.rows / 2;  // 세로 중심

        // 빨간색 가로선 그리기 (왼쪽 끝 → 오른쪽 끝)
        line(dst, Point(0, cy), Point(dst.cols, cy), Scalar(0, 0, 255), 2);

        // 빨간색 세로선 그리기 (위쪽 끝 → 아래쪽 끝)
        line(dst, Point(cx, 0), Point(cx, dst.rows), Scalar(0, 0, 255), 2);

        // 원본과 처리결과 영상 출력
        imshow("frame", frame);
        imshow("dst", dst);

        // q 누르면 종료
        if (waitKey(10) == 'q')
            break;
    }

    return 0;
}
```

---

## 개념

### Mat 객체 분리

원본 `frame` 에 직접 그리면 원본 영상이 훼손된다.
`dst = frame.clone()` 으로 원본을 복사한 뒤 `dst` 에만 그림을 그려
원본(`frame`)과 처리결과(`dst`)를 분리하여 관리한다.

| Mat 객체 | 역할 |
|----------|------|
| `frame` | 카메라에서 읽은 원본 영상 |
| `dst` | 원본을 복사한 후 십자선을 그린 처리결과 |

### clone vs 대입(=)

| 방법 | 설명 |
|------|------|
| `dst = frame` | 얕은 복사 — 같은 메모리를 공유하므로 dst를 수정하면 frame도 변경됨 |
| `dst = frame.clone()` | 깊은 복사 — 독립된 메모리에 복사하므로 dst를 수정해도 frame은 유지됨 |

### line 함수

```
line(img, pt1, pt2, color, thickness)
```

| 인자 | 설명 |
|------|------|
| `img` | 선을 그릴 Mat 객체 |
| `pt1` | 시작점 좌표 |
| `pt2` | 끝점 좌표 |
| `color` | 선 색상 — `Scalar(0, 0, 255)` 는 빨간색 (BGR) |
| `thickness` | 선 두께 (픽셀) |

### 십자선 좌표 계산

| 선 | 시작점 | 끝점 |
|----|--------|------|
| 가로선 | `(0, cy)` | `(cols, cy)` |
| 세로선 | `(cx, 0)` | `(cx, rows)` |

`cx = cols / 2`, `cy = rows / 2` 로 영상의 정중앙을 기준으로 그린다.

---
