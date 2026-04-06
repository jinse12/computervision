# 과제 4
카메라로 촬영한 영상을 동영상 파일로 저장하는 프로그램을 작성하라.
- Q 또는 q를 누르면 녹화를 종료하라.
- 프로젝트 폴더에 생성된 파일을 재생하여 결과를 확인할 것.

---

## 코드

```cpp
#include <iostream>             // cout, cerr 등 입출력을 사용하기 위한 헤더 파일
using namespace std;            // std::cout, std::cerr 등을 쓸 때 std::를 생략하기 위해 사용
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용

int main(void)
{
    // 0번 카메라 열기
    VideoCapture cap(0);
    // 오류 검사
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    // 카메라 속성값을 읽어오고 소수점을 반올림해 정수로 변환
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));

    // 동영상 압축 방식(코덱) 지정 및 VideoWriter(저장할 동영상 파일) 설정
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo("output.mp4", fourcc, 30, Size(w, h));

    if (!outputVideo.isOpened()) {
        cout << "File open failed!" << endl;
        return -1;
    }

    Mat frame;

    while (true) {
        cap >> frame;           // 카메라에서 현재 프레임을 읽고 frame에 저장

        if (frame.empty())      // 프레임을 못 읽으면 반복문 탈출
            break;

        outputVideo << frame;   // 읽은 프레임을 동영상 파일에 기록. 매 루프마다 반복되면서 동영상이 쌓임

        imshow("Camera Recording", frame);  // 화면에 프레임을 실시간으로 보여줌

        // Q 또는 q 키를 누르면 종료
        int key = waitKey(33);  // 33ms 동안 키 입력을 기다림
        if (key == 'q' || key == 'Q') {
            cout << "녹화 종료." << endl;
            break;
        }
    }
}
```

---

## 개념

### VideoWriter

카메라 또는 Mat 객체의 프레임을 동영상 파일로 저장하는 OpenCV 클래스이다.
`outputVideo.isOpened()` 로 파일이 정상적으로 열렸는지 확인한다.
`outputVideo << frame` 으로 매 루프마다 프레임을 파일에 누적하여 동영상을 만든다.

### fourcc (Four Character Code)

동영상 압축 방식(코덱)을 4개의 문자로 지정하는 코드이다.
`VideoWriter::fourcc('D', 'I', 'V', 'X')` 는 DIVX 코덱을 사용한다는 의미이다.

| 코덱 | fourcc 코드 | 설명 |
|------|-------------|------|
| DIVX | `'D','I','V','X'` | MPEG-4 기반, .avi 파일에 주로 사용 |
| XVID | `'X','V','I','D'` | DIVX와 유사한 오픈소스 코덱 |
| MP4V | `'M','P','4','V'` | MPEG-4, .mp4 파일에 사용 |
| MJPG | `'M','J','P','G'` | Motion JPEG 코덱 |

### VideoWriter 생성자 인자

```
VideoWriter("파일명", fourcc, fps, Size(width, height))
```

| 인자 | 설명 |
|------|------|
| `"output.mp4"` | 저장할 파일명 |
| `fourcc` | 코덱 지정 |
| `30` | 초당 프레임 수 (fps) |
| `Size(w, h)` | 프레임 해상도 (카메라 해상도와 일치시켜야 함) |

### waitKey(33)

33ms 동안 키 입력을 대기한다.
1000ms ÷ 33ms ≈ 30fps 로, 카메라 영상의 재생 속도와 맞추기 위해 33을 사용한다.

---

## 실행 결과



---
