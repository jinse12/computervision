# 과제 3
행렬 연산을 이용하여 영상의 밝기를 수정하는 프로그램을 작성하시오.  

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, cin 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Scalar 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::cin 등을 쓸 때 std::를 생략하기 위해 사용

int main()
{
    // 컬러(BGR 3채널)로 이미지 읽기
    Mat img = imread("lenna.bmp");

    // 이미지 로드 실패 체크
    if (img.empty()) {
        printf("Image load failed!");
        return -1;
    }

    // 밝기 변화량 입력받기
    int delta;
    cout << "밝기변화량을 입력: ";
    cin >> delta;

    // 원본 영상 출력
    imshow("img", img);

    // 행렬 + Scalar 연산으로 밝기 조정
    Mat bright = img + Scalar(delta, delta, delta);
    imshow("bright", bright);

    waitKey();
    return 0;
}
```

---

## 개념

### Scalar 란?
| 코드 | 설명 |
|------|------|
| `Scalar(b, g, r)` | BGR 3채널 각각에 적용할 값을 지정 |
| `Scalar(delta, delta, delta)` | 모든 채널에 동일한 delta 적용 -> 전체 밝기 변화 |
| `Scalar(100, 0, 0)` | B 채널에만 적용 -> Blue 값만 변화 |

### 행렬 + Scalar 연산
| 연산 | 설명 |
|------|------|
| `img + Scalar(delta, delta, delta)` | 모든 픽셀의 B, G, R 각각에 delta를 더함 |
| `img - Scalar(delta, delta, delta)` | 모든 픽셀의 B, G, R 각각에서 delta를 뺌 |
| `img + delta` | `Scalar(delta, delta, delta)` 와 동일한 결과 |

---

## 출력 결과

<img width="1006" height="700" alt="스크린샷 2026-04-02 211832" src="https://github.com/user-attachments/assets/79befc5f-88a4-488d-96e4-9ab9986d381f" />

---
