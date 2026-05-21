# 실습과제 4
lenna 영상을 그레이로 변환하여 출력하고 마우스 이벤트를 이용하여
마우스로 드래깅한 영역만 샤프닝 필터링을 수행하는 프로그램을 작성하시오.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, endl 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Point 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

// 전역 변수 선언 (콜백 함수에서 접근하기 위해 전역으로 선언)
Mat src, dst;
Point ptStart, ptEnd;
bool isDragging = false;

// 샤프닝 마스크
float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };
Mat mask = Mat(3, 3, CV_32F, weights);

// 마우스 콜백 함수
void on_mouse(int event, int x, int y, int, void*)
{
    // 마우스 왼쪽 버튼을 누를 때: 드래그 시작점 저장
    if (event == EVENT_LBUTTONDOWN) {
        ptStart = Point(x, y);
        isDragging = true;
    }
    // 마우스 왼쪽 버튼을 뗄 때: 드래그 종료, 샤프닝 적용
    else if (event == EVENT_LBUTTONUP && isDragging) {
        ptEnd = Point(x, y);
        isDragging = false;

        // 드래그 영역을 Rect로 변환 (영상 범위를 벗어나지 않도록 & 연산자 사용)
        Rect rect = Rect(ptStart, ptEnd) & Rect(0, 0, src.cols, src.rows);

        if (rect.width > 0 && rect.height > 0) {
            // 드래그 영역만 샤프닝 필터 적용
            Mat roi = dst(rect);
            filter2D(roi, roi, -1, mask);
            imshow("dst", dst);
        }
    }
}

int main(void)
{
    // 그레이스케일로 영상 불러오기
    src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 이미지 로드 실패 체크
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

    // dst에 원본 복사 (드래그할 때마다 누적 적용)
    src.copyTo(dst);

    // 창 생성 및 마우스 콜백 등록
    namedWindow("dst");
    setMouseCallback("dst", on_mouse);

    imshow("dst", dst);
    waitKey();
    return 0;
}
```

---

## 개념

### 샤프닝 마스크
| 위치 | 값 | 의미 |
|------|----|------|
| 중심 | 9 | 현재 픽셀에 높은 가중치 |
| 주변 8개 | -1 | 주변 픽셀을 빼서 차이를 강조 |
| 원소 합 | 1 | 평탄한 영역은 변화 없음 |

### 마우스 이벤트
| 이벤트 | 의미 |
|--------|------|
| `EVENT_LBUTTONDOWN` | 마우스 왼쪽 버튼을 누를 때 → 시작점 저장 |
| `EVENT_LBUTTONUP` | 마우스 왼쪽 버튼을 뗄 때 → 종료점 저장 후 샤프닝 적용 |

### ROI 처리
| 코드 | 의미 |
|------|------|
| `Rect(ptStart, ptEnd)` | 드래그 시작점과 끝점으로 사각형 영역 생성 |
| `& Rect(0, 0, src.cols, src.rows)` | 영상 범위를 벗어나지 않도록 교집합 처리 |
| `dst(rect)` | dst에서 rect 영역만 ROI로 추출 |
| `filter2D(roi, roi, -1, mask)` | ROI 영역에만 샤프닝 필터 적용 |

---

## 출력 결과

https://github.com/user-attachments/assets/c22942e6-c389-4bfa-b597-5070e424ec37
