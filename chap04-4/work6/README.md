# 과제 6
크기가 400 X 200, 배경색이 백색인 컬러영상을 생성하고 마우스 왼쪽버튼을 누르면 배경색이 Red가 되고 마우스 오른쪽 버튼을 누르면 배경색이 Blue가 되도록 프로그램을 작성하시오.

---

## 코드
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void on_mouse(int event, int x, int y, int flags, void* userdata);
// 마우스 이벤트 발생 시 호출될 콜백 함수 전방 선언

Mat img; // 배경색을 변경할 이미지 (전역변수로 선언하여 on_mouse에서 공유)

int main(void) {
    // 400x200 크기의 3채널 컬러 영상을 흰색으로 초기화
    img = Mat(200, 400, CV_8UC3, Scalar(255, 255, 255));

    namedWindow("src"); // "src" 이름의 윈도우 생성

    // 마우스 이벤트 발생 시 on_mouse 콜백 함수 등록
    setMouseCallback("src", on_mouse);

    imshow("src", img); // 초기 흰색 이미지 표시
    waitKey();          // 키 입력 대기 (프로그램 유지)
    return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
    switch (event) {
    case EVENT_LBUTTONDOWN: // 왼쪽 버튼 클릭 시
        // img를 빨간색(BGR: 0, 0, 255)으로 초기화
        img = Mat(200, 400, CV_8UC3, Scalar(0, 0, 255));
        imshow("src", img); // 변경된 img 화면에 표시
        break;

    case EVENT_RBUTTONDOWN: // 오른쪽 버튼 클릭 시
        // img를 파란색(BGR: 255, 0, 0)으로 초기화
        img = Mat(200, 400, CV_8UC3, Scalar(255, 0, 0));
        imshow("src", img); // 변경된 img 화면에 표시
        break;
    }
}
```

---

## 개념

### 전역변수
```cpp
Mat img;
```
`main`과 `on_mouse` 양쪽에서 같은 `img`를 수정해야 하므로 전역변수로 선언한다.

### setMouseCallback
```cpp
setMouseCallback("src", on_mouse);
// "src"     : 이벤트를 등록할 윈도우 이름
// on_mouse  : 마우스 이벤트 발생 시 자동으로 호출될 콜백 함수 포인터
```
마우스 이벤트가 발생할 때마다 OpenCV가 `on_mouse`를 자동으로 호출한다.

### 마우스 이벤트 종류
| 이벤트 | 설명 |
|--------|------|
| `EVENT_LBUTTONDOWN` | 왼쪽 버튼 클릭 |
| `EVENT_RBUTTONDOWN` | 오른쪽 버튼 클릭 |
| `EVENT_MOUSEMOVE` | 마우스 이동 |

### BGR 색상
OpenCV는 RGB가 아닌 BGR 순서로 색상을 표현한다.

| 색상 | Scalar (BGR) |
|------|-------------|
| 흰색 | `Scalar(255, 255, 255)` |
| 빨간색 | `Scalar(0, 0, 255)` |
| 파란색 | `Scalar(255, 0, 0)` |

### imshow 위치
이 코드는 이벤트가 발생할 때만 화면을 갱신하면 되므로
`while` 루프 없이 `on_mouse` 안에서 직접 `imshow`를 호출한다.
클릭할 때만 색이 바뀌므로 루프로 계속 갱신할 필요가 없다.

### 실행 결과

https://github.com/user-attachments/assets/faa0be06-7a0e-4783-9149-fea21f288f6e
