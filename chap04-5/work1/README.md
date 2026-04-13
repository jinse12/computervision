# 과제 1
트랙바의 위치를 콘솔창에 출력하고 트랙바를 움직일때마다 트랙바의 위치값을 반지름으로 하는 원을 그리시오. 트랙바 위치의 최대값은 100으로 설정하라.

---

## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, cerr 등 입출력을 사용하기 위한 헤더 파일
using namespace std;            // std::cout, std::cerr 등을 쓸 때 std::를 생략하기 위해 사용
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용

void on_trackbar(int pos, void* userdata); // 트랙바 이동 시 호출될 콜백 함수 선언

Mat img; // imread로 불러온 이미지를 저장할 전역변수
         // 전역변수로 선언하여 on_trackbar 콜백 함수에서 공유

int main() {
    img = imread("lenna.bmp"); // lenna.bmp 이미지 파일을 읽어 img에 저장

    namedWindow("Lenna"); // "Lenna" 이름의 윈도우 생성

    // 트랙바 생성
    // "Trackbar"  : 트랙바 이름 (윈도우에 표시되는 레이블)
    // "Lenna"     : 부착할 윈도우 이름
    // 0           : value 포인터 없음 (따로 저장할 변수 지정 안 함)
    // 100         : 트랙바 최대값 (0~100)
    // on_trackbar : 트랙바 이동 시 자동으로 호출될 콜백 함수 포인터
    createTrackbar("Trackbar", "Lenna", 0, 100, on_trackbar);

    // while 루프로 imshow를 반복 실행하여 img 변경사항을 화면에 계속 갱신
    // on_trackbar에서 img에 직접 원을 그리므로 루프가 돌 때마다 누적된 img가 표시됨
    while (true) {
        imshow("Lenna", img);
        if (waitKey(1) == 'q') break; // q 입력 시 종료
    }
    return 0;
}

void on_trackbar(int pos, void* userdata) {
    cout << "트랙바 위치: " << pos << endl; // 트랙바 현재 위치값을 콘솔에 출력

    Point center(img.cols / 2, img.rows / 2); // 이미지 중앙 좌표 계산
                                               // cols: 이미지 너비, rows: 이미지 높이

    // img에 직접 원을 그림
    // center        : 원의 중심 (이미지 중앙)
    // pos           : 원의 반지름 (트랙바 위치값)
    // Scalar(0,255,0): BGR 기준 초록색
    // 2             : 선 두께
    // LINE_AA       : 계단 현상 없이 부드러운 선 (안티앨리어싱)
    circle(img, center, pos, Scalar(0, 255, 0), 2, LINE_AA);
}
```

---

## 개념

### 전역변수
콜백 함수 간 데이터를 공유하기 위해 전역변수로 선언한다.

| 변수 | 역할 |
|------|------|
| `Mat img` | 원을 그릴 이미지 (main과 on_trackbar에서 공유) |

### createTrackbar
```cpp
createTrackbar("Trackbar", "Lenna", 0, 100, on_trackbar);
//              이름        윈도우  초기값 최대값 콜백함수
```
- 3번째 인자 `0` -> value 포인터 없음 (저장할 변수 지정 안 함)
- 콜백 함수 이름 자체가 함수의 주소(포인터)이므로 `on_trackbar`를 전달
- 트랙바 이동 시 OpenCV가 `on_trackbar(pos, userdata)`를 자동으로 호출

### 콜백 함수 (함수 포인터)
함수도 메모리에 저장되므로 주소(포인터)가 존재한다.
`on_trackbar`를 전달한다는 것은 트랙바 이동 시 OpenCV가 해당 주소로 찾아가 자동 호출하는 것을 의미한다. 이를 **콜백**이라 한다.

### img 직접 사용
`img`에 직접 `circle`을 그리므로 트랙바를 움직일수록 원이 누적된다.
clone을 사용하면 매번 원본에서 복사하므로 누적되지 않는다.

| 방식 | 동작 |
|------|------|
| `img` 직접 사용 | 원이 누적됨 |
| `img.clone()` 사용 | 매번 원본에서 새로 그림 (누적 없음) |

### circle()
```cpp
circle(img, center, radius, color, thickness, lineType);
```

---
### 실행 화면

<img width="847" height="726" alt="work1" src="https://github.com/user-attachments/assets/9d0e705e-ab98-4513-a7fa-fef4843a052b" />
