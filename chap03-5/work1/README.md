# 과제 1
lenna.bmp 영상에서 좌표 (50,50), (100,100), (150,150)에서 픽셀값(B,G,R)을 출력하시오  

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, endl 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Vec3b 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main() {
    // 컬러(BGR 3채널)로 이미지 읽기
    Mat src = imread("lenna.bmp");

    // 이미지 로드 실패 체크
    if (src.empty()) {
        printf("Image load failed!");
        return -1;
    }

    // Vec3b 변수 한 번만 선언 (이후 대입으로 재사용)
    Vec3b pixel;

    // 좌표(50, 50)의 화소값 출력 → at<Vec3b>(행, 열) = at<Vec3b>(y, x)
    pixel = src.at<Vec3b>(50, 50);
    cout << "좌표( 50, 50)의 화소값(B,G,R) : " << pixel << endl;

    // 좌표(100, 100)의 화소값 출력
    pixel = src.at<Vec3b>(100, 100);
    cout << "좌표(100,100)의 화소값(B,G,R) : " << pixel << endl;

    // 좌표(150, 150)의 화소값 출력
    pixel = src.at<Vec3b>(150, 150);
    cout << "좌표(150,150)의 화소값(B,G,R) : " << pixel << endl;

    return 0;
}
```

---

## 개념

### x, y 좌표와 row, col 관계
| 용어 | 의미 | at() 인자 순서 |
|------|------|--------------|
| x | 가로 위치 (열, col) | 두 번째 인자 |
| y | 세로 위치 (행, row) | 첫 번째 인자 |

### Vec3b 란?
| 코드 | 의미 |
|------|------|
| `Vec3b` | 3개의 uchar 값을 묶은 OpenCV 자료형 |
| `pixel[0]` | B (파랑) 성분 |
| `pixel[1]` | G (초록) 성분 |
| `pixel[2]` | R (빨강) 성분 |

### 변수 선언 vs 대입
| | 설명 |
|--|------|
| `Vec3b pixel` | 메모리 공간을 한 번만 생성 |
| `pixel = src.at<Vec3b>(...)` | 같은 공간에 값을 덮어씌워 재사용 |

---

## 출력 결과

<img width="667" height="73" alt="image" src="https://github.com/user-attachments/assets/065db9e3-d8da-4fb8-8acf-27e22860deb3" />

---
