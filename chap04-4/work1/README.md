# 과제 1

  Lenna 영상을 컬러 영상으로 읽은 후 화면에 출력하라
 - l(엘)을 누르면 얼굴 아래에 직선을 그려라
 - c를 누르면 얼굴주위에 원을 그려라
 - t를 누르면 문자열을 영상 상단에 출력하라
 - 기본 구조는 무한반복문으로 작성하고 q를 누르면 종료하는 코드를 작성하시오

---

## 코드

```cpp
#include <iostream>             // cout, cerr 등 입출력을 사용하기 위한 헤더 파일
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace std;            // std::cout, std::cerr 등을 쓸 때 std::를 생략하기 위해 사용
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용

int main() {
    Mat img = imread("lenna.bmp");  // lenna.bmp 컬러 영상 불러오기
    if (img.empty()) {              // 영상 로드 실패 시 종료
        cout << "영상을 불러올 수 없습니다." << endl;
        return -1;
    }

    namedWindow("image");   // 출력 창 생성
    imshow("image", img);   // 초기 영상 출력

    while (true) {
        int keycode = waitKey(0);   // 키 입력 대기 (0 = 무한 대기)

        if (keycode == 'l') {
            // 'l' 키: 흰색 가로선 그리기
            line(img,
                Point(100, 340),        // 시작점
                Point(400, 340),        // 끝점
                Scalar(255, 255, 255),  // 색상 BGR - 흰색
                2);                     // 두께
        }
        else if (keycode == 'c') {
            // 'c' 키: 빨간색 원 그리기
            circle(img,
                Point(256, 270),        // 중심점
                130,                    // 반지름
                Scalar(0, 0, 255),      // 색상 BGR - 빨간색
                2);                     // 두께
        }
        else if (keycode == 't') {
            // 't' 키: 노란색 텍스트 출력
            putText(img,
                "Hello, Lenna",         // 출력할 문자열
                Point(80, 70),          // 텍스트 시작 위치 (왼쪽 하단 기준)
                FONT_HERSHEY_SIMPLEX,   // 폰트 종류
                1.5,                    // 폰트 크기
                Scalar(0, 255, 255),    // 색상 BGR - 노란색
                2);                     // 두께
        }
        else if (keycode == 'q') {
            break;  // 'q' 키 누르면 프로그램 종료
        }

        imshow("image", img);   // 도형 추가 후 영상 갱신
    }
    return 0;
}
```

---

## 키 입력 동작

| 키 | 동작 |
|----|------|
| `l` | 흰색 가로선 그리기 `(100,340) → (400,340)` |
| `c` | 빨간색 원 그리기, 중심 `(256,270)`, 반지름 `130` |
| `t` | 노란색 텍스트 `"Hello, Lenna"` 출력 |
| `q` | 프로그램 종료 |

---

## 개념

### waitKey(0)
`waitKey(0)` 은 키 입력이 있을 때까지 **무한 대기**한다.  
반환값은 눌린 키의 ASCII 코드이다.

### line()
```cpp
line(img, pt1, pt2, color, thickness);
```
두 점을 잇는 직선을 그린다. `Scalar(255, 255, 255)` 는 BGR 기준 흰색이다.

### circle()
```cpp
circle(img, center, radius, color, thickness);
```
중심점과 반지름으로 원을 그린다. `thickness` 에 `-1` 을 주면 내부를 채운다.

### putText()
```cpp
putText(img, text, origin, fontFace, fontScale, color, thickness);
```
`origin` 은 텍스트의 **왼쪽 하단** 기준점이다.  
`FONT_HERSHEY_SIMPLEX` 는 OpenCV 기본 산세리프 폰트이다.

### ROI 응용 (부분행렬)
`img(Rect(x, y, width, height))` 로 관심영역을 참조하면  
전체 영상 좌표 대신 **ROI 내부 좌표 기준**으로 도형을 그릴 수 있어 좌표 계산이 단순해진다.

```cpp
Mat roi = img(Rect(0, 0, 200, 200));
circle(roi, Point(100, 100), 70, Scalar(255, 255, 255), 2);
// → 전체 img 기준으로는 (100, 100)에 원이 그려짐
```

---
# 실행 결과


https://github.com/user-attachments/assets/55b1e5e5-cd25-4767-b924-44f4e825ac0f

