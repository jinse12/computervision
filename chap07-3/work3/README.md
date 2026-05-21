# 실습과제 3
filter2D 함수를 이용하여 가우시안 필터를 구현하시오.
GaussianBlur 함수에서 ksize를 5x5로 설정했을 때와 결과를 비교하시오.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, endl 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Size 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main(void)
{
    // 그레이스케일로 영상 불러오기
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    // 이미지 로드 실패 체크
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
    imshow("src", src);

    // 5x5 가우시안 커널 원소값 배열 (1/273 배율)
    float data[25] = {
         1,  4,  7,  4,  1,
         4, 16, 26, 16,  4,
         7, 26, 41, 26,  7,
         4, 16, 26, 16,  4,
         1,  4,  7,  4,  1
    };

    // 배열을 5x5 float 행렬로 변환 후 원소 합(273)으로 나눠 정규화
    Mat kernel = Mat(5, 5, CV_32F, data) / 273.0f;

    // filter2D로 가우시안 필터 적용
    Mat dst_filter2D;
    filter2D(src, dst_filter2D, -1, kernel);
    putText(dst_filter2D, "filter2D Gaussian 5x5", Point(10, 30),
            FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
    imshow("filter2D", dst_filter2D);

    // GaussianBlur 함수로 비교 (ksize=5x5, sigma=0이면 ksize로부터 자동 계산)
    Mat dst_gaussian;
    GaussianBlur(src, dst_gaussian, Size(5, 5), 0);
    putText(dst_gaussian, "GaussianBlur 5x5", Point(10, 30),
            FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
    imshow("GaussianBlur", dst_gaussian);

    waitKey();
    return 0;
}
```

---

## 개념

### 커널 생성 방법
| 코드 | 의미 |
|------|------|
| `Mat(5, 5, CV_32F, data)` | 배열을 5×5 float 행렬로 변환 |
| `/ 273.0f` | 원소 합(273)으로 나눠 커널 합이 1이 되도록 정규화 |
| 커널 합 = 1 | 필터링 후에도 평균 밝기 유지 |

### 가우시안 커널 구조
| 위치 | 값 | 의미 |
|------|----|------|
| 중심 (2,2) | 41 | 가장 높은 가중치 |
| 중심에서 멀어질수록 | 26 → 16 → 7 → 4 → 1 | 가중치 감소 |

### filter2D vs GaussianBlur
| | 설명 |
|--|------|
| `filter2D()` | 커널을 직접 만들어 전달, σ ≈ 1.0 기준 커널 사용 |
| `GaussianBlur(Size(5,5), 0)` | 내부적으로 σ ≈ 1.1 기준 커널 자동 생성 |

두 결과는 육안으로 유사하지만 표준편차 기준이 다소 달라 픽셀 단위에서 미세한 차이가 발생할 수 있습니다.

---

## 출력 결과

<img width="1783" height="427" alt="image" src="https://github.com/user-attachments/assets/2f666072-6b61-43ce-a77f-028e3b4f039b" />
