# 과제 2
500x500 흰색 컬러영상을 만들고 트랙바 위치에 따라 마우스 드래그로 색상별 사각형을 그리시오.
- 트랙바 0~3 범위, 초기위치 0
- 트랙바 0: 파란색 사각형
- 트랙바 1: 초록색 사각형
- 트랙바 2: 빨간색 사각형
- 트랙바 3: 드래그한 부분 지우기 (흰색으로 채우기)

---

## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, cerr 등 입출력을 사용하기 위한 헤더 파일
using namespace std;            // std::cout, std::cerr 등을 쓸 때 std::를 생략하기 위해 사용
using namespace cv;             // cv::Mat, cv::VideoCapture 등을 쓸 때 cv::를 생략하기 위해 사용

void on_mouse(int event, int x, int y, int flags, void* userdata);
void on_trackbar(int pos, void* userdata);

Mat img;          // 그림을 그릴 캔버스 (전역변수로 선언하여 콜백 함수에서 공유)
int track_pos = 0; // 현재 트랙바 위치 (전역변수로 선언하여 on_mouse에서 참조)
Point pt1, pt2;   // 드래그 시작점(pt1), 끝점(pt2)
bool drawing = false; // 마우스를 클릭한 채로 이동 중인지 판단하는 플래그
                      // false: 그냥 마우스 이동, true: 클릭한 채로 이동

int main() {
    // 500x500 크기의 3채널 컬러 영상을 흰색(255,255,255)으로 초기화
    img = Mat(500, 500, CV_8UC3, Scalar(255, 255, 255));

    namedWindow("img"); // "img" 이름의 윈도우 생성

    // 마우스 이벤트 발생 시 on_mouse 콜백 함수 등록
    setMouseCallback("img", on_mouse);

    // 트랙바 생성
    // "level"   : 트랙바 이름
    // "img"     : 부착할 윈도우 이름
    // 0         : value 포인터 없음 (따로 저장할 변수 지정 안 함)
    // 3         : 트랙바 최대값 (0~3)
    // on_trackbar: 트랙바 이동 시 자동으로 호출될 콜백 함수
    createTrackbar("level", "img", 0, 3, on_trackbar);

    // while 루프로 imshow를 반복 실행하여 img 변경사항을 화면에 계속 갱신
    while (true) {
        imshow("img", img);
        if (waitKey(1) == 'q') break;  // q 입력 시 종료
    }
    return 0;
}

void on_trackbar(int pos, void* userdata) {
    // 트랙바 위치값을 전역변수 track_pos에 저장
    // on_mouse에서 track_pos를 참조하여 색상 결정
    // img는 초기화하지 않으므로 이전에 그린 사각형은 누적 유지됨
    track_pos = pos;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
    switch (event) {
    case EVENT_LBUTTONDOWN:         // 마우스 왼쪽 버튼 클릭 시
        drawing = true;             // 드래그 시작 -> true로 변경
        pt1 = Point(x, y);         // 드래그 시작점 저장
        break;

    case EVENT_LBUTTONUP:           // 마우스 왼쪽 버튼 뗄 시
        drawing = false;            // 드래그 종료 -> false로 변경
        pt2 = Point(x, y);         // 드래그 끝점 저장
        // track_pos 값에 따라 img에 직접 사각형을 그림
        // thickness 양수(2): 테두리만, -1: 내부 채우기
        switch (track_pos) {
        case 0: rectangle(img, pt1, pt2, Scalar(255, 0, 0), 2);     break; // 파란색 테두리
        case 1: rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2);     break; // 초록색 테두리
        case 2: rectangle(img, pt1, pt2, Scalar(0, 0, 255), 2);     break; // 빨간색 테두리
        case 3: rectangle(img, pt1, pt2, Scalar(255, 255, 255), -1); break; // 흰색으로 채워서 지우기
        }
        break;
    }
}
```

---

## 개념

### 전역변수
콜백 함수 간 데이터를 공유하기 위해 전역변수로 선언한다.

| 변수 | 역할 |
|------|------|
| `Mat img` | 그림을 그릴 캔버스 |
| `int track_pos` | 현재 트랙바 위치 |
| `Point pt1, pt2` | 드래그 시작점/끝점 |
| `bool drawing` | 드래그 중 여부 판단 |

### bool drawing
마우스를 클릭한 채로 이동 중인지 판단하는 플래그.

```
LBUTTONDOWN → drawing = true  (드래그 시작)
LBUTTONUP   → drawing = false (드래그 끝)
```

`drawing`이 없으면 마우스를 그냥 움직이기만 해도 동작해버린다.

### createTrackbar
```cpp
createTrackbar("level", "img", 0, 3, on_trackbar);
//              이름     윈도우  초기값 최대값 콜백함수
```
- 3번째 인자 `0` -> value 포인터 없음 (저장할 변수 지정 안 함)
- 트랙바 이동 시 `on_trackbar` 콜백 자동 호출

### on_trackbar
```cpp
void on_trackbar(int pos, void* userdata) {
    track_pos = pos;  // 위치값만 전역변수에 저장
}
```
트랙바가 바뀌어도 img는 초기화하지 않으므로 이전에 그린 사각형이 누적 유지된다.

### rectangle()
```cpp
rectangle(img, pt1, pt2, color, thickness);
```
| thickness | 효과 |
|-----------|------|
| 양수 (ex. 2) | 테두리만 그리기 |
| -1 | 내부 채우기 |

### 트랙바 위치별 동작
| 트랙바 | 색상 | Scalar |
|--------|------|--------|
| 0 | 파란색 | `Scalar(255, 0, 0)` |
| 1 | 초록색 | `Scalar(0, 255, 0)` |
| 2 | 빨간색 | `Scalar(0, 0, 255)` |
| 3 | 지우기 | `Scalar(255, 255, 255), -1` |

### img 직접 사용
`img`에 직접 `rectangle`을 그리므로 사각형이 누적된다.
트랙바 3은 흰색으로 채워서 덮어쓰는 방식으로 지운다.

---

## 실행 화면

https://github.com/user-attachments/assets/68f4b4cc-16e9-404d-a719-3f4b8a017a84
