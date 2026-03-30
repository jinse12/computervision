# 과제 5
Lenna 영상을 컬러 영상으로 읽은 후 화면에 출력하고 가로, 세로선을 3개씩 그려 16등분하시오  
반드시 원소 참조함수 Mat::at()를 사용할 것. 😲

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::imshow 등을 쓸 때 cv::를 생략하기 위해 사용

int main() {
    // 컬러(BGR 3채널)로 이미지 읽기
    Mat img = imread("lenna.bmp");

    // 이미지 로드 실패 체크
    if (img.empty()) {
        printf("Image load failed!");
        return -1;
    }

    // 세로선 3개: i는 행(row)을 위에서 아래로 반복, 열(col)은 고정
    for (int i = 0; i < img.rows; i++) {
        img.at<Vec3b>(i, img.cols / 4)     = Vec3b(255, 255, 255);  // 1/4 지점 열 고정
        img.at<Vec3b>(i, img.cols / 2)     = Vec3b(255, 255, 255);  // 2/4 지점 열 고정
        img.at<Vec3b>(i, img.cols * 3 / 4) = Vec3b(255, 255, 255);  // 3/4 지점 열 고정
    }

    // 가로선 3개: i는 열(col)을 왼쪽에서 오른쪽으로 반복, 행(row)은 고정
    for (int i = 0; i < img.cols; i++) {
        img.at<Vec3b>(img.rows / 4,     i) = Vec3b(255, 255, 255);  // 1/4 지점 행 고정
        img.at<Vec3b>(img.rows / 2,     i) = Vec3b(255, 255, 255);  // 2/4 지점 행 고정
        img.at<Vec3b>(img.rows * 3 / 4, i) = Vec3b(255, 255, 255);  // 3/4 지점 행 고정
    }

    // "img" 창에 결과 이미지 출력
    imshow("img", img);

    // 키 입력이 있을 때까지 대기
    waitKey();

    return 0;
}
```

---

## 개념

### 세로선 vs 가로선 원리
| 선 종류 | for문 반복 | at() 고정 인자 |
|---------|-----------|--------------|
| 세로선 | `i < img.rows` (행 반복) | col 고정 (1/4, 2/4, 3/4) |
| 가로선 | `i < img.cols` (열 반복) | row 고정 (1/4, 2/4, 3/4) |

---

## 결과 이미지

<img width="633" height="671" alt="image" src="https://github.com/user-attachments/assets/ca6e1ad4-4760-478c-82b9-d4d26eeaf8fd" />

---
