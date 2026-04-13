### 과제 5
Lenna 영상을 컬러 영상으로 화면에 출력하고 마우스로 드래깅 한 영역을 추출하여 화면에 출력하는 프로그램을 작성하시오.


## 코드
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void event_handler(int event, int x, int y, int flags, void* userdata);
// 마우스 이벤트 발생 시 호출될 콜백 함수 선언

Mat img; // lenna.bmp를 저장할 이미지 (전역변수로 선언하여 event_handler에서 공유)

int main(void)
{
    img = imread("lenna.bmp"); // lenna.bmp 이미지 파일을 읽어 img에 저장

    // 이미지 로드 실패 시 에러 메시지 출력 후 종료
    if (img.empty()) {
        cerr << "영상을 불러올 수 없습니다" << endl;
        return -1;
    }

    namedWindow("img"); // "img" 이름의 윈도우 생성

    // 마우스 이벤트 발생 시 event_handler 콜백 함수 등록
    setMouseCallback("img", event_handler);

    int key;
    while (true) {
        imshow("img", img);    // img를 계속 갱신하여 화면에 표시
        key = waitKey(10);     // 10ms마다 키 입력 확인
        if (key == 'q') break; // q 입력 시 종료
    }
    return 0;
}

void event_handler(int event, int x, int y, int flags, void* userdata)
{
    static Point ptOld; // 드래그 시작점을 저장하는 정적 변수
                        // static: 함수가 끝나도 값이 유지됨
                        // LBUTTONDOWN에서 저장 -> LBUTTONUP에서 참조

    switch (event) {
    case EVENT_LBUTTONDOWN: // 왼쪽 버튼 클릭 시
        ptOld = Point(x, y); // 드래그 시작점 저장
        cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
        break;

    case EVENT_LBUTTONUP: // 왼쪽 버튼 뗄 시
        cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;
        {
            // Rect(pt1, pt2) : 두 점을 대각선으로 하는 사각형 영역 생성
            // ptOld : 드래그 시작점, Point(x, y) : 드래그 끝점
            Rect r1(ptOld, Point(x, y));

            // img(r1) : ROI (관심영역) - 얕은 복사
            // r1 영역만 잘라서 drag에 참조
            Mat drag = img(r1);

            namedWindow("drag");    // "drag" 이름의 새 윈도우 생성
            imshow("drag", drag);   // 잘라낸 영역을 새 윈도우에 표시
        }
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
`main`과 `event_handler` 양쪽에서 같은 `img`를 참조해야 하므로 전역변수로 선언한다.

### static 변수
```cpp
static Point ptOld;
```
일반 지역변수는 함수가 끝나면 사라지지만 `static` 변수는 함수가 끝나도 값이 유지된다.
`LBUTTONDOWN`에서 저장한 시작점을 `LBUTTONUP`에서 참조해야 하므로 `static`으로 선언한다.

| 변수 종류 | 함수 종료 후 값 |
|-----------|----------------|
| 일반 지역변수 | 사라짐 |
| `static` 지역변수 | 유지됨 |

### Rect() - 두 점으로 생성
```cpp
Rect r1(ptOld, Point(x, y));
// ptOld      : 드래그 시작점 (좌상단)
// Point(x,y) : 드래그 끝점 (우하단)
// 두 점을 대각선으로 하는 사각형 영역 자동 계산
```

### ROI (관심영역)
```cpp
Mat drag = img(r1);
```
`img(Rect)` 형태로 특정 영역만 잘라 `Mat`으로 참조한다.
ROI는 **얕은 복사**이므로 `drag`를 수정하면 원본 `img`도 함께 변경된다.

| 방식 | 메모리 |
|------|--------|
| `img(r1)` (ROI) | 원본과 같은 메모리 공유 (얕은 복사) |
| `img(r1).clone()` | 별도 메모리 생성 (깊은 복사) |

### cerr
```cpp
cerr << "영상을 불러올 수 없습니다" << endl;
```
`cout`은 표준 출력, `cerr`는 표준 에러 출력이다.

### 실행 결과

https://github.com/user-attachments/assets/fc32923b-cb10-4f0a-bc3b-431cf8b5e917
