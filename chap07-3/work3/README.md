# 실습과제 3
실습과제 2번에서 α값을 트랙바를 이용하여 입력받아서 필터링을 수행하라.
α값을 0에서 50까지 변화하도록 하라.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, endl 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Size 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

// 전역 변수 선언 (콜백 함수에서 접근하기 위해 전역으로 선언)
Mat src, blurred;
int alpha = 0;

// 트랙바 콜백 함수: 트랙바를 움직일 때마다 호출됨
void on_trackbar(int, void*)
{
    // 언샤프 마스크 필터 적용: dst = src + alpha * (src - blurred)
    Mat dst = (1 + alpha) * src - alpha * blurred;
    imshow("dst", dst);
}

int main(void)
{
    // 그레이스케일로 영상 불러오기
    src = imread("rose.bmp", IMREAD_GRAYSCALE);

    // 이미지 로드 실패 체크
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
    imshow("src", src);

    // 평균값 필터로 블러 영상 생성 (한 번만 수행)
    blur(src, blurred, Size(3, 3));

    // dst 창 생성 후 트랙바 추가 (범위: 0~50, 초기값: 0)
    namedWindow("dst");
    createTrackbar("alpha", "dst", &alpha, 50, on_trackbar);

    // 초기 결과 영상 출력
    on_trackbar(0, 0);

    waitKey();
    return 0;
}
```

---

## 개념

### 트랙바 관련 함수
| 코드 | 의미 |
|------|------|
| `namedWindow("dst")` | 트랙바를 붙일 창을 미리 생성 |
| `createTrackbar("alpha", "dst", &alpha, 50, on_trackbar)` | 0~50 범위의 트랙바 생성, 변경 시 on_trackbar 호출 |
| `on_trackbar(0, 0)` | 프로그램 시작 시 초기 결과 영상 출력 |

### 실습과제 2와의 차이점
| | 실습과제 2 | 실습과제 3 |
|--|-----------|-----------|
| alpha 입력 방식 | for문으로 10~50 순서 반복 | 트랙바로 실시간 입력 |
| blur() 호출 위치 | for문 안에서 매번 호출 | main에서 한 번만 호출 |
| 결과 확인 방법 | 키 입력마다 다음 결과 출력 | 트랙바 조절 시 즉시 갱신 |

### 전역 변수를 사용하는 이유
콜백 함수 `on_trackbar()`는 매개변수로 `int`와 `void*`만 받을 수 있으므로,
`src`, `blurred`, `alpha`를 전역 변수로 선언해야 콜백 함수 내에서 접근할 수 있습니다.

---

## 출력 결과

https://github.com/user-attachments/assets/8d7a1f62-a2f6-4df2-a06e-3ffccc7e5702
