# 실습과제 1
예제의 샤프닝 필터를 1~5회 반복 적용한 결과를 각각 출력하고 결과를 설명하라.
주의: 샤프닝 적용한 결과영상을 다시 샤프닝하라는 의미임.

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

    // 샤프닝 마스크 생성
    float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };
    Mat mask = Mat(3, 3, CV_32F, weights);

    // 반복 적용을 위해 dst에 원본 복사
    Mat dst = src.clone();

    // 샤프닝을 1~5회 누적 반복 적용
    for (int i = 1; i <= 5; i++) {
        // 이전 결과영상(dst)에 샤프닝 재적용
        filter2D(dst, dst, -1, mask);

        // 반복 횟수를 영상 위에 표시
        String desc = format("Sharpen: %d times", i);
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

### 반복 적용 방식
| 코드 | 의미 |
|------|------|
| `Mat dst = src.clone()` | 원본을 복사하여 반복 적용의 시작점으로 사용 |
| `filter2D(dst, dst, -1, mask)` | 입력과 출력을 동일하게 설정하여 결과에 누적 적용 |

### 반복 횟수와 결과 변화
| 반복 횟수 | 효과 |
|----------|------|
| 1회 | 엣지가 약간 강조됨 |
| 2회 | 엣지가 더욱 뚜렷해짐 |
| 3회 | 엣지 과강조, 노이즈 증가 |
| 4회 | 영상이 많이 왜곡됨 |
| 5회 | 엣지가 과도하게 강조되어 원본과 크게 달라짐 |


---

## 출력 결과
https://github.com/user-attachments/assets/0862280a-3c38-4d1c-9d4d-e19d7013509e
