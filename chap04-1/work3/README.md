# 과제 3
카메라로 촬영한 영상을 화면에 출력하라.
- 무한루프로 작성하고 Q 또는 q를 누르면 종료하도록 하라.
- s를 누를 때마다 현재 프레임을 파일로 저장하라.
- 파일명은 `frame00.jpg` 형식으로 누를 때마다 숫자는 증가하도록 하라.
- 규칙적인 파일명을 만들기 위해 `format` 함수를 사용하라.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, cerr 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용
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

    Mat frame;
    int cnt = 0;    // 저장된 파일 번호 카운터

    while (true) {
        // 카메라에서 프레임 한 장 읽기
        cap >> frame;

        // 프레임이 비어있으면 종료
        if (frame.empty()) {
            cerr << "frame empty!" << endl;
            break;
        }

        // 카메라 영상 출력
        imshow("frame", frame);

        // 키 입력 대기 (10ms)
        int key = waitKey(10);

        // Q 또는 q 누르면 종료
        if (key == 'q' || key == 'Q')
            break;

        // s 누르면 현재 프레임을 파일로 저장
        if (key == 's') {
            // format 함수로 "frame00.jpg" 형식의 파일명 생성
            String filename = format("frame%02d.jpg", cnt);
            imwrite(filename, frame);
            cout << filename << " saved." << endl;
            cnt++;
        }
    }

    return 0;
}
```

---

## 개념

### format 함수

`format` 함수는 C언어의 `printf` 방식의 서식 문자열을 사용하여 `cv::String` 을 생성하는 함수이다.
`format("frame%02d.jpg", cnt)` 는 cnt 값을 2자리 정수(빈 자리는 0으로 채움)로 변환하여
`frame00.jpg`, `frame01.jpg`, `frame02.jpg` ... 형식의 파일명을 만든다.

### imwrite

`imwrite(filename, frame)` 은 Mat 객체를 이미지 파일로 저장하는 함수이다.
파일 확장자(`.jpg`, `.png` 등)에 따라 자동으로 포맷을 결정한다.
저장 성공 시 `true`, 실패 시 `false` 를 반환한다.

### waitKey 반환값

`waitKey(10)` 은 10ms 동안 키 입력을 대기하며 눌린 키의 ASCII 코드를 반환한다.
`'q'`(113), `'Q'`(81), `'s'`(115) 와 같이 문자 리터럴로 직접 비교할 수 있다.

---

---
