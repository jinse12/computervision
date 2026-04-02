# 과제 1
휴대폰 카메라로 사진을 촬영하여 저장한 후 imread 함수를 이용하여 Mat 객체에 저장하고  
영상의 **행의 수, 열의 수, 채널 수, type**을 화면에 출력하시오  
※ type은 기호상수로 표시할 것 (예: CV_8UC3 등)

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, endl 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main()
{
    // 컬러(BGR 3채널)로 이미지 읽기
    Mat img = imread("fish.jpg");

    // 이미지 로드 실패 체크
    if (img.empty()) {
        printf("Image load failed!");
        return -1;
    }

    // 행의 수, 열의 수, 채널 수 출력
    cout << "Rows (행의 수): "     << img.rows       << endl;
    cout << "Cols (열의 수): "     << img.cols       << endl;
    cout << "Channels (채널 수): " << img.channels() << endl;

    // type을 기호상수로 출력
    if (img.type() == CV_8UC1)
        cout << "Type: CV_8UC1 (grayscale image)" << endl;
    else if (img.type() == CV_8UC3)
        cout << "Type: CV_8UC3 (truecolor image)" << endl;
    else if (img.type() == CV_8UC4)
        cout << "Type: CV_8UC4 (BGRA image)" << endl;
    else if (img.type() == CV_16UC1)
        cout << "Type: CV_16UC1" << endl;
    else if (img.type() == CV_32FC1)
        cout << "Type: CV_32FC1" << endl;
    else if (img.type() == CV_32FC3)
        cout << "Type: CV_32FC3" << endl;
    else
        cout << "Type: Unknown (" << img.type() << ")" << endl;

    return 0;
}
```

---

## 개념

### Mat 주요 멤버
| 멤버 | 의미 |
|------|------|
| `img.rows` | 영상의 행의 수 (세로 픽셀 수, Height) |
| `img.cols` | 영상의 열의 수 (가로 픽셀 수, Width) |
| `img.channels()` | 채널 수 (흑백=1, 컬러=3) |
| `img.type()` | 픽셀 데이터 형식 (기호상수로 비교) |

### type 기호상수 의미
| 기호상수 | 비트 깊이 | 채널 수 | 설명 |
|----------|-----------|---------|------|
| `CV_8UC1` | 8비트 부호 없는 정수 | 1 | 흑백(Grayscale) 이미지 |
| `CV_8UC3` | 8비트 부호 없는 정수 | 3 | 컬러(BGR) 이미지 — 가장 일반적 |
| `CV_8UC4` | 8비트 부호 없는 정수 | 4 | BGRA (투명도 포함) 이미지 |
| `CV_32FC1` | 32비트 부동소수점 | 1 | 실수형 흑백 이미지 |
| `CV_32FC3` | 32비트 부동소수점 | 3 | 실수형 컬러 이미지 |

### imread 기본 동작
| 항목 | 설명 |
|------|------|
| 기본 플래그 | `IMREAD_COLOR` — 항상 BGR 3채널로 읽음 |
| 흑백으로 읽기 | `imread("fish.jpg", IMREAD_GRAYSCALE)` → CV_8UC1 |
| 컬러로 읽기 | `imread("fish.jpg")` 또는 `imread("fish.jpg", IMREAD_COLOR)` → CV_8UC3 |

---

## 출력 결과

<img width="404" height="103" alt="스크린샷 2026-04-02 205344" src="https://github.com/user-attachments/assets/abe39bad-e18a-41eb-a611-065b5c7a7927" />

---
