# 실습과제 1
코드7-2에서 filter2D 함수를 이용하여 평균값 필터(blur)를 구현하시오.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);  // 그레이스케일로 영상 불러오기
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }  // 오류 검사
    imshow("src", src);  // 원본 영상 출력

    Mat dst;
    for (int ksize = 3; ksize <= 7; ksize += 2) {  // 3, 5, 7 순서로 반복
        Mat kernel = Mat::ones(Size(ksize, ksize), CV_32F)  // 모든 원소가 1인 커널 생성
                     / (float)(ksize * ksize);              // ksize² 로 나눠 합이 1이 되도록 정규화
        filter2D(src, dst, -1, kernel);  // 커널을 src에 적용하여 dst에 저장

        String desc = format("Mean: %dx%d", ksize, ksize);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
                Scalar(255), 1, LINE_AA);  // 커널 크기를 영상 위에 표시
        imshow("dst", dst);
        waitKey();
    }
    return 0;
}
```

---

## 개념

### blur() vs filter2D()
| | 설명 |
|--|------|
| `blur()` | 내부적으로 평균값 커널을 자동 생성하여 적용 |
| `filter2D()` | 커널을 직접 만들어 전달하면 동일한 결과를 얻을 수 있음 |

### 커널 생성 방법
| 코드 | 의미 |
|------|------|
| `Mat::ones(Size(ksize, ksize), CV_32F)` | 모든 원소가 1인 ksize×ksize 행렬 생성 |
| `/ (float)(ksize * ksize)` | 전체 원소 수로 나눠 각 원소를 1/9, 1/25, 1/49로 만듦 |
| 커널 원소 합 = 1 | 필터링 후에도 평균 밝기 유지 |

### filter2D() 인자
| 인자 | 의미 |
|------|------|
| `src` | 입력 영상 |
| `dst` | 출력 영상 |
| `-1` | 출력 깊이를 입력과 동일하게 설정 |
| `kernel` | 적용할 커널 행렬 |

### 커널 크기와 블러 효과
| 커널 크기 | 평균 내는 픽셀 수 | 효과 |
|----------|----------------|------|
| 3×3 | 9개 | 약한 블러 |
| 5×5 | 25개 | 중간 블러 |
| 7×7 | 49개 | 강한 블러 |

---

## 출력 결과

https://github.com/user-attachments/assets/87c58b1d-53da-44f5-bed1-4142cc9e9b58
