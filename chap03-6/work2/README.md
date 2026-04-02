# 과제 2
행렬연산을 이용하여 아래 수식에서 행렬 X를 구하는 프로그램을 작성하시오.  
행렬 X를 화면에 출력하라.  
역행렬 B⁻¹ 은 Mat::inv 함수를 사용할 것

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, endl 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main()
{
    // 행렬 A 정의
    Mat A = (Mat_<double>(2, 2) << 1, 3, -4, 2);

    // 행렬 B 정의
    Mat B = (Mat_<double>(2, 2) << 2, 3, 0, 5);

    // 행렬 C 정의
    Mat C = (Mat_<double>(2, 2) << -2, -2, -2, -3);

    // X = 3*A + B^(-1) + 10*C - 5
    // B.inv() : B의 역행렬 계산
    // 스칼라 -5 는 OpenCV가 각 원소에 자동으로 적용
    Mat X = 3 * A + B.inv() + 10 * C - 5;

    cout << "X = " << endl << X << endl;

    return 0;
}
```

---

## 개념

### Mat\_<double> 초기화
| 코드 | 설명 |
|------|------|
| `Mat_<double>(2, 2)` | 2×2 실수형(64bit) 행렬 선언 |
| `CV_64F` (double) 사용 이유 | 역행렬 계산 시 소수점이 발생하므로 실수형 필수 |

### 주요 연산
| 코드 | 설명 |
|------|------|
| `3 * A` | 스칼라 × 행렬 — 모든 원소에 3을 곱함 |
| `B.inv()` | B의 역행렬 B⁻¹ 계산 (`Mat::inv` 함수) |
| `10 * C` | 스칼라 × 행렬 — 모든 원소에 10을 곱함 |
| `- 5` | 스칼라 빼기 — OpenCV가 각 원소에서 5를 자동으로 뺌 |

### 스칼라 연산 자동 처리
OpenCV의 `Mat` 연산에서 스칼라 값은 별도로 단위행렬로 변환하지 않아도  
각 원소에 자동으로 적용되므로 `- 5` 그대로 사용 가능하다.

---

## 출력 결과

<img width="186" height="80" alt="image" src="https://github.com/user-attachments/assets/2268ac75-f8fe-4361-9e19-b2c6b0aac018" />

---
