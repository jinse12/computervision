# 과제 3
코드 4-3의 동영상(stopwatch.avi)을 아래 그림처럼 라인을 그린 후 원본과 결과영상을 모두 출력하라.
  - 출력영상은 동영상파일로(output.avi) 저장하라 -> 동영상을 재생하여 결과 확인할 것
  - 원본 영상과 처리 후 영상을 분리하여 저장할 것.
  - 무한루프로 작성하고 q or Q를 누르면 종료하도록 할 것.
---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용

int main()
{
    // 동영상 파일 열기
    VideoCapture cap("stopwatch.avi");
    if (!cap.isOpened()) return -1;     // 파일 열기 실패 시 프로그램 종료

    // 동영상 속성 읽기 (프레임 크기, FPS)
    int fps    = (int)cap.get(CAP_PROP_FPS);
    int width  = (int)cap.get(CAP_PROP_FRAME_WIDTH);
    int height = (int)cap.get(CAP_PROP_FRAME_HEIGHT);

    // 결과 영상을 저장할 VideoWriter 설정 (XVID 코덱, .avi)
    VideoWriter out("output.avi", VideoWriter::fourcc('X','V','I','D'),
                    fps, Size(width, height));

    Mat frame, cross;
    while (true) {
        cap >> frame;                                   // 동영상에서 프레임 한 장 읽기
        if (frame.empty()) {                            // 영상 끝에 도달하면
            cap.set(CAP_PROP_POS_FRAMES, 0);            // 처음으로 되감아 무한 반복
            continue;
        }

        frame.copyTo(cross);    // 깊은 복사: cross는 frame과 독립된 데이터를 가짐

        // 십자선 그리기 (중앙 기준, 빨간색, 두께 2)
        line(cross, Point(width/2, 0),    Point(width/2, height), Scalar(0,0,255), 2); // 수직선
        line(cross, Point(0, height/2),   Point(width, height/2), Scalar(0,0,255), 2); // 수평선

        out << cross;               // 처리된 프레임을 output.avi에 저장
        imshow("frame", frame);     // 원본 영상 창 출력
        imshow("cross", cross);     // 십자선 적용 영상 창 출력

        // fps 기반 대기, q/Q 입력 시 종료
        char key = waitKey(1000 / fps);
        if (key == 'q' || key == 'Q') break;
    }
    return 0;
}
```
---
## 개념
### VideoCapture — 동영상 파일 읽기
`VideoCapture cap("stopwatch.avi")` 는 동영상 파일을 열어 프레임을 순서대로 읽어온다.
`cap >> frame` 으로 매 루프마다 프레임을 한 장씩 읽으며, 파일 끝에 도달하면 빈 프레임을 반환한다.
`cap.set(CAP_PROP_POS_FRAMES, 0)` 으로 재생 위치를 처음으로 되돌려 무한 반복을 구현한다.

### CAP_PROP_FPS
`cap.get(CAP_PROP_FPS)` 는 원본 동영상의 초당 프레임 수(fps)를 읽어온다.
`waitKey(1000 / fps)` 에 전달하여 원본과 동일한 재생 속도를 유지하고,
VideoWriter 생성 시에도 동일한 fps를 전달해야 저장된 영상의 속도가 맞다.

### fourcc — XVID 코덱
| 코덱 | fourcc 코드 | 사용 확장자 |
|------|-------------|------------|
| `XVID` | `'X','V','I','D'` | .avi |
| `mp4v` | `'m','p','4','v'` | .mp4 |
| `DIVX` | `'D','I','V','X'` | .avi |
| `MJPG` | `'M','J','P','G'` | .avi |

코덱과 파일 확장자는 반드시 일치시켜야 정상적으로 저장된다.

### copyTo — 깊은 복사
`frame.copyTo(cross)` 는 frame의 픽셀 데이터를 cross에 독립적으로 복사한다.
`=` 연산자(얕은 복사)와 달리 cross에 선을 그려도 frame 데이터에 영향을 주지 않으므로
원본 창(`frame`)과 처리 창(`cross`)을 분리하여 출력할 수 있다.

### line() — 십자선 그리기
`line(img, pt1, pt2, color, thickness)` 으로 두 점을 잇는 직선을 그린다.
중앙 좌표 `(width/2, height/2)` 를 기준으로 수직선과 수평선을 각각 그려 십자선을 완성한다.
`Scalar(0, 0, 255)` 는 BGR 기준 빨간색이다.

---
## 실행 결과
---

https://github.com/user-attachments/assets/8f72ff6e-5a1a-4a90-b245-00ff135f0cfa

---
