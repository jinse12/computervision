# 과제 2
카메라로 촬영한 컬러 영상의 R, G, B 값을 모두 100만큼 증가시킨 후  
원본 영상과 결과 영상을 모두 출력하라.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, cerr 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Scalar 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::cerr 등을 쓸 때 std::를 생략하기 위해 사용

int main(void)
{
    // 0번 카메라(기본 웹캠) 열기
    VideoCapture cap(0);

    // 카메라 열기 실패 체크
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    // 카메라 프레임 크기 출력
    cout << "Frame width: "  << cvRound(cap.get(CAP_PROP_FRAME_WIDTH))  << endl;
    cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

    Mat frame, bright;

    while (true) {
        // 카메라에서 프레임 한 장 읽기
        cap >> frame;

        // 프레임이 비어있으면 종료
        if (frame.empty()) {
            cerr << "frame empty!" << endl;
            break;
        }

        // R, G, B 모든 채널에 100 더하기 (포화 연산 자동 적용)
        bright = frame + Scalar(100, 100, 100);

        // 원본과 밝기 증가 영상 출력
        imshow("frame", frame);
        imshow("bright", bright);

        // ESC 키(27) 누르면 종료
        if (waitKey(10) == 27)
            break;
    }

    return 0;
}
```

---

## 개념

### VideoCapture

카메라 또는 동영상 파일로부터 영상을 읽어오는 OpenCV 클래스이다.

`VideoCapture cap(0)` 은 시스템의 0번 카메라(기본 웹캠)를 연다.
`cap.isOpened()` 로 카메라가 정상적으로 열렸는지 확인한다.
`cap >> frame` 으로 카메라에서 프레임을 한 장씩 읽어온다.

### CAP_PROP_FRAME_WIDTH / HEIGHT

`cap.get()` 함수에 전달하는 속성 상수로, 카메라의 프레임 가로/세로 크기를 반환한다.
`cvRound()` 를 사용하여 반환된 실수값을 정수로 반올림하여 출력한다.

### Scalar(100, 100, 100)

BGR 3채널 모두에 동일하게 100을 더하는 연산이다.
OpenCV의 `+` 연산은 포화(Saturation) 처리를 자동으로 수행하므로
255를 초과하는 값은 자동으로 255로 클램핑된다.

### waitKey(10)

10ms 동안 키 입력을 대기하며, 반환값이 27(ESC 키)이면 루프를 종료한다.
카메라 영상처럼 실시간으로 프레임을 갱신할 때 반드시 필요하다.

---

## 실행 결과


---
