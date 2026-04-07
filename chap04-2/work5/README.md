# 과제 5
카메라로 촬영한 영상을 사용자가 원하는 시간 동안만 동영상을 저장하는 프로그램을 작성하라.
  - 원하는 시점에서 s키를 누르면 동영상 파일로 저장을 시작하고 e키를 누르면 저장을 종료하고 프로그램을 종료하는 코드를 작성하라.
  - 프로젝트 폴더에 생성된 파일을 재생하여 결과를 확인할 것.
---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용

int main(void)
{
    // 기본 카메라(인덱스 0) 열기
    VideoCapture cap(0);
    if (!cap.isOpened()) return -1;     // 카메라 열기 실패 시 종료

    // 카메라 해상도 및 코덱 설정
    int w      = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h      = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');   // DIVX 코덱 사용

    VideoWriter outputVideo;    // 선언만 하고 s키 누를 때 열기
    bool recording = false;     // 녹화 중 여부 플래그

    Mat frame;
    while (true) {
        cap >> frame;           // 카메라에서 프레임 한 장 읽기
        if (frame.empty()) break;

        int key = waitKey(33);  // 약 30fps 간격으로 키 입력 대기

        // s/S 키: 녹화 시작 (아직 녹화 중이 아닐 때만)
        if ((key == 's' || key == 'S') && !recording) {
            outputVideo.open("output.mp4", fourcc, 30, Size(w, h));
            recording = outputVideo.isOpened(); // 열기 성공 시 true
        }
        // e/E 키: 녹화 종료 및 프로그램 종료
        if (key == 'e' || key == 'E') break;

        if (recording) {
            outputVideo << frame;                               // 프레임 저장
            putText(frame, "REC", Point(10, 30),
                    FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2); // 빨간 REC 표시
        }
        imshow("Camera Recording", frame);  // 카메라 영상 출력
    }
    return 0;
}
```
---
## 개념
### VideoCapture(0) — 카메라 열기
`VideoCapture cap(0)` 은 시스템의 기본 카메라(인덱스 0)를 열어 프레임을 읽어온다.
파일 경로 대신 정수 인덱스를 전달하는 것이 동영상 파일과의 차이점이다.

### VideoWriter 지연 초기화
프로그램 시작 시 바로 열지 않고 선언만 해두었다가 `s` 키 입력 시점에 `open()` 으로 열어
사용자가 원하는 시간부터만 녹화를 시작할 수 있다.
`recording = outputVideo.isOpened()` 로 열기 성공 여부를 플래그에 바로 대입한다.

### fourcc — DIVX 코덱
| 코덱 | fourcc 코드 | 사용 확장자 |
|------|-------------|------------|
| `DIVX` | `'D','I','V','X'` | .avi / .mp4 |
| `XVID` | `'X','V','I','D'` | .avi |
| `mp4v` | `'m','p','4','v'` | .mp4 |
| `MJPG` | `'M','J','P','G'` | .avi |

코덱과 파일 확장자는 반드시 일치시켜야 정상적으로 저장된다.

### waitKey(33) — 키 입력 및 fps 제어
`waitKey(33)` 은 33ms 대기하며 키 입력을 받는다.
33ms ≈ 1000ms / 30fps 이므로 약 30fps의 재생 속도를 유지한다.

### putText() — REC 표시
녹화 중임을 사용자에게 알리기 위해 `putText()` 로 화면 좌상단에 빨간색 `REC` 문자를 표시했다.

---
## 실행 결과

https://github.com/user-attachments/assets/742797d4-bad2-4285-9fa9-f76f3b0e4c70

