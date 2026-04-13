# 과제 4
Lenna 영상을 컬러 영상으로 화면에 출력하고 마우스로 클릭하는 화면 좌표와 해당 좌표의 화소값(B,G,R)을 출력하는 프로그램을 작성하시오.

## 코드
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flags, void* userdata);
// 마우스 이벤트 발생 시 호출될 콜백 함수 선언

Mat img; // lenna.bmp를 저장할 이미지 (전역변수로 선언하여 on_mouse에서 공유)

int main(void) {
    img = imread("lenna.bmp"); // lenna.bmp 이미지 파일을 읽어 img에 저장

    // 이미지 로드 실패 시 에러 메시지 출력 후 종료
    if (img.empty()) {
        cerr << "영상을 불러올 수 없습니다" << endl;
        return -1;
    }

    namedWindow("img"); // "img" 이름의 윈도우 생성

    // 마우스 이벤트 발생 시 on_mouse 콜백 함수 등록
    setMouseCallback("img", on_mouse);

    imshow("img", img); // 이미지 화면에 표시
    waitKey();          // 키 입력 대기 (프로그램 유지)
    return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_LBUTTONDOWN) { // 왼쪽 버튼 클릭 시에만 동작

        // img.at<Vec3b>(y, x) : (y, x) 좌표의 픽셀값을 Vec3b 타입으로 읽기
        // 주의: Mat의 좌표 순서는 (행, 열) -> (y, x) 순서
        Vec3b pixel = img.at<Vec3b>(y, x);

        // pixel[0]: B값, pixel[1]: G값, pixel[2]: R값
        // (int) 캐스팅: uchar(0~255)를 정수로 변환하여 숫자로 출력
        cout << "좌표: (" << x << "," << y << "), "
             << "화소값(B,G,R): ("
             << (int)pixel[0] << ","  // Blue
             << (int)pixel[1] << ","  // Green
             << (int)pixel[2] << ")"  // Red
             << endl;
    }
}
```

---

## 개념

### 전역변수
```cpp
Mat img;
```
`main`과 `on_mouse` 양쪽에서 같은 `img`를 참조해야 하므로 전역변수로 선언한다.

### Vec3b
```cpp
Vec3b pixel = img.at<Vec3b>(y, x);
```
3채널 컬러 영상의 픽셀값을 저장하는 타입이다.
`uchar` 3개를 묶은 벡터로 BGR 순서로 저장된다.

| 인덱스 | 채널 | 값 범위 |
|--------|------|---------|
| `pixel[0]` | Blue | 0 ~ 255 |
| `pixel[1]` | Green | 0 ~ 255 |
| `pixel[2]` | Red | 0 ~ 255 |

### at<>() 좌표 순서
```cpp
img.at<Vec3b>(y, x)
// Mat은 (행, 열) 순서 -> (y, x) 순서로 접근
// 화면 좌표 (x, y)와 반대임에 주의
```

| 표현 | 순서 |
|------|------|
| 화면 좌표 | (x, y) -> (가로, 세로) |
| Mat.at<> | (y, x) -> (행, 열) |

### (int) 캐스팅
```cpp
(int)pixel[0]
```
`Vec3b`의 각 원소는 `uchar` 타입이다.
`uchar`를 그대로 `cout`으로 출력하면 문자로 출력되므로
`(int)`로 캐스팅하여 숫자로 출력한다.

| 타입 | cout 출력 결과 |
|------|---------------|
| `uchar` | 문자 (예: `%`) |
| `(int)uchar` | 숫자 (예: `37`) |

### cerr
```cpp
cerr << "영상을 불러올 수 없습니다" << endl;
```
`cout`은 표준 출력, `cerr`는 표준 에러 출력이다.

### 실행 결과

https://github.com/user-attachments/assets/272ab221-9f0f-4bb3-b001-dd1da02c9dcb
