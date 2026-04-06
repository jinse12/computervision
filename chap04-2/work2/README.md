# 과제 2
코드 4-3의 동영상(stopwatch.avi)을 R, G, B값 모두 100만큼 증가시킨 후 원본과 결과 영상을 모두 출력하라.
  - 원본 영상과 처리 후 영상을 분리하여 저장할 것.
  - 무한루프로 작성하고 q or Q를 누르면 종료하도록 할 것.
---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, cerr 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::cerr 등을 쓸 때 std::를 생략하기 위해 사용

int main(void)
{
    // 동영상 파일 열기
    VideoCapture cap("stopwatch.avi");

    if (!cap.isOpened()) {
        cerr << "Video open failed!" << endl;
        return -1;
    }

    // cap.get()으로 동영상 속성값을 읽어오고 소수점을 반올림해 정수로 변환
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);

    // mp4 파일에 맞는 코덱 지정
    int fourcc = VideoWriter::fourcc('m', 'p', '4', 'v');

    // 원본과 밝기 증가 영상을 저장할 VideoWriter 설정
    VideoWriter original("original.mp4", fourcc, fps, Size(w, h));
    VideoWriter bright("bright.mp4", fourcc, fps, Size(w, h));

    if (!original.isOpened() || !bright.isOpened()) {
        cerr << "VideoWriter open failed!" << endl;
        return -1;
    }

    Mat frame, brighten;

    while (true) {
        cap >> frame;                               // 동영상에서 프레임 한 장 읽기
        if (frame.empty()) break;                   // 프레임을 못 읽으면 (영상 끝) 종료

        brighten = frame + Scalar(100, 100, 100);   // B, G, R 모든 채널에 100 더하기

        original << frame;                          // 원본 프레임을 original.mp4에 저장
        bright << brighten;                         // 밝기 증가 프레임을 bright.mp4에 저장

        imshow("original", frame);                  // 원본 영상 출력
        imshow("bright", brighten);                 // 밝기 증가 영상 출력

        int key = waitKey(30);
        if (key == 'q' || key == 'Q') {
            cout << "종료합니다." << endl;
            break;
        }
    }

    return 0;
}
```

---

## 개념

### VideoCapture — 동영상 파일 읽기

`VideoCapture cap("stopwatch.avi")` 는 카메라가 아닌 동영상 파일을 열어 프레임을 읽어온다.
`cap >> frame` 으로 매 루프마다 프레임을 순서대로 읽으며, 파일 끝에 도달하면 빈 프레임을 반환한다.

### CAP_PROP_FPS

`cap.get(CAP_PROP_FPS)` 는 원본 동영상의 초당 프레임 수(fps)를 속성값으로 읽어온다.
VideoWriter 생성 시 동일한 fps를 전달해야 저장된 영상의 재생 속도가 원본과 동일하게 유지된다.

### fourcc — mp4 코덱

| 코덱 | fourcc 코드 | 사용 확장자 |
|------|-------------|------------|
| `mp4v` | `'m','p','4','v'` | .mp4 |
| `DIVX` | `'D','I','V','X'` | .avi |
| `XVID` | `'X','V','I','D'` | .avi |
| `MJPG` | `'M','J','P','G'` | .avi |

코덱과 파일 확장자는 반드시 일치시켜야 정상적으로 저장된다.

### VideoWriter 두 개 사용

원본(`original.mp4`)과 밝기 증가본(`bright.mp4`)을 동시에 저장하기 위해
VideoWriter 객체를 두 개 선언하여 각각 프레임을 기록한다.

### Scalar(100, 100, 100)

BGR 3채널 모두에 100을 더해 영상 전체를 밝게 만든다.
OpenCV의 `+` 연산은 포화(Saturation) 처리를 자동으로 수행하므로
255를 초과하는 값은 자동으로 255로 클램핑된다.

---

## 실행 결과

https://github.com/user-attachments/assets/88d136b6-e705-404c-a936-82a9e7d27a87

---
