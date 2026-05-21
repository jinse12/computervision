# 실습과제 2
- 평균값 필터의 마스크 사이즈가 3×3, 10×10, 30×30일 때 함수의 실행시간을 비교하시오.  
- 실행 시간 차이가 없으면 마스크 사이즈를 더 증가시켜보라  
- 실행 시간 측정 방법 1: C++ 라이브러리 함수 이용  
- 실행 시간 측정 방법 2 : 교재 184 페이지 TickMeter 클래스 이용  
---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, endl 등 입출력을 사용하기 위한 헤더 파일
#include <chrono>               // 실행시간 측정을 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Size 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main(void)
{
    // 그레이스케일로 영상 불러오기
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    // 이미지 로드 실패 체크
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

    // 비교할 마스크 크기 배열
    int ksizes[] = { 3, 10, 30 };

    // 마스크 크기 3개를 순서대로 반복
    for (int i = 0; i < 3; i++) {
        int ksize = ksizes[i];
        Mat dst;

        // 시작 시간 저장
        auto startTime = std::chrono::steady_clock::now();

        // 평균값 필터 적용
        blur(src, dst, Size(ksize, ksize));

        // 종료 시간 저장
        auto endTime = std::chrono::steady_clock::now();

        // 실행시간 계산 및 출력 (ms 단위)
        float totalTime = std::chrono::duration<float, std::milli>(endTime - startTime).count();
        cout << ksize << "x" << ksize << " 실행시간: " << totalTime << " ms" << endl;
    }
    return 0;
}
```

---

## 개념

### 실행시간 측정 방법
| 코드 | 의미 |
|------|------|
| `steady_clock::now()` | 현재 시간 저장 |
| `duration<float, milli>` | 두 시간의 차이를 ms 단위로 변환 |
| `.count()` | 시간 값을 float으로 반환 |

### 마스크 크기와 실행시간 관계
| 마스크 크기 | 연산 픽셀 수 | 실행시간 |
|------------|------------|---------|
| 3×3 | 9개 | 가장 짧음 |
| 10×10 | 100개 | 중간 |
| 30×30 | 900개 | 가장 김 |

마스크 크기가 커질수록 평균 내는 픽셀 수가 늘어나므로 연산량이 증가하여 실행시간이 길어집니다.

---

## 출력 결과

<img width="320" height="78" alt="image" src="https://github.com/user-attachments/assets/7ef05683-2067-499d-8cfb-e4e2552314a2" />
