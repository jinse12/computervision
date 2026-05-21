# 실습과제 2
코드 7-4에서 가우시안 필터 대신에 평균값 필터를 사용하고 α값을 10, 20, 30, 40, 50까지 증가시키면서 필터링 결과가 어떻게 변화하는지 설명하라.

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

    // alpha를 10, 20, 30, 40, 50 순서로 반복
    for (int alpha = 10; alpha <= 50; alpha += 10) {
        Mat blurred;

        // 평균값 필터로 블러 영상 생성
        blur(src, blurred, Size(3, 3));

        // 언샤프 마스크 필터 적용: dst = src + alpha * (src - blurred)
        Mat dst = (1 + alpha) * src - alpha * blurred;

        // alpha 값을 영상 위에 표시
        String desc = format("alpha: %d", alpha);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
                Scalar(255), 1, LINE_AA);
        imshow("dst", dst);
        waitKey();
    }
    return 0;
}
```

---

## 개념

### 언샤프 마스크 필터 수식
```
dst = (1 + alpha) * src - alpha * blurred
    = src + alpha * (src - blurred)
```

| 항 | 의미 |
|----|------|
| `blurred` | 평균값 필터로 엣지가 뭉개진 영상 |
| `src - blurred` | 원본에서 뭉개진 부분을 뺀 엣지 정보 |
| `alpha * (src - blurred)` | 엣지 정보를 alpha배 강조 |
| `src + ...` | 원본에 강조된 엣지를 더해 날카롭게 만듦 |

### alpha 값과 결과 변화
| alpha | 효과 |
|-------|------|
| 10 | 엣지가 미세하게 강조됨 |
| 20 | 조금 더 날카로워짐 |
| 30 | 엣지가 뚜렷해짐 |
| 40 | 엣지가 강하게 강조됨 |
| 50 | 엣지가 과도하게 강조됨 |

### GaussianBlur vs blur()
| | 설명 |
|--|------|
| `GaussianBlur()` | 중심 픽셀에 높은 가중치를 줘서 자연스러운 블러 |
| `blur()` | 주변 픽셀을 단순 평균내는 블러 |

---

## 출력 결과

https://github.com/user-attachments/assets/0b012d06-565e-42f5-9db8-f80664bfb592
