# 과제 2
Lenna 영상 위에서 발생하는 마우스 이벤트의 횟수를 세어서
출력하는 프로그램을 작성하시오.

## 코드
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

// 각 이벤트 발생 횟수를 저장하는 전역 카운터 변수
// 전역변수로 선언하여 onMouse 호출 시마다 누적 카운트
int cntMove = 0;        // 마우스 이동 횟수
int cntLButtonDown = 0; // 왼쪽 버튼 클릭 횟수
int cntLButtonUp = 0;   // 왼쪽 버튼 뗌 횟수

void onMouse(int event, int x, int y, int flags, void* userdata);
// 마우스 이벤트 발생 시 호출될 콜백 함수 선언

int main() {
    Mat img = imread("lenna.bmp"); // lenna.bmp 이미지 파일을 읽어 img에 저장
                                   // 픽셀값 참조 없이 표시만 하므로 지역변수로 선언

    // 이미지 로드 실패 시 에러 메시지 출력 후 종료
    if (img.empty()) {
        cout << "영상을 불러올 수 없습니다." << endl;
        return -1;
    }

    namedWindow("img"); // "img" 이름의 윈도우 생성

    // 마우스 이벤트 발생 시 onMouse 콜백 함수 등록
    setMouseCallback("img", onMouse);

    imshow("img", img); // 이미지 화면에 표시
    waitKey(0);         // 키 입력 대기 (프로그램 유지)
    return 0;
}

void onMouse(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_MOUSEMOVE) {
        // 마우스가 윈도우 위에서 움직일 때마다 호출
        // 픽셀 단위로 감지하므로 조금만 움직여도 횟수가 빠르게 증가
        cntMove++;
        cout << "EVENT_MOUSEMOVE:" << cntMove << endl;
    }
    else if (event == EVENT_LBUTTONDOWN) {
        // 왼쪽 버튼을 누르는 순간 호출
        cntLButtonDown++;
        cout << "EVENT_LBUTTONDOWN:" << cntLButtonDown << endl;
    }
    else if (event == EVENT_LBUTTONUP) {
        // 왼쪽 버튼을 떼는 순간 호출
        cntLButtonUp++;
        cout << "EVENT_LBUTTONUP:" << cntLButtonUp << endl;
    }
}
```

---

## 개념

### 전역 카운터 변수
```cpp
int cntMove = 0;
int cntLButtonDown = 0;
int cntLButtonUp = 0;
```
`onMouse`는 이벤트 발생 시마다 새로 호출되므로 지역변수로 선언하면 매번 초기화된다.
전역변수로 선언하여 호출 간에도 값이 누적 유지된다.

| 선언 위치 | 함수 재호출 시 값 |
|-----------|-----------------|
| 지역변수 | 초기화됨 (0으로 리셋) |
| 전역변수 | 유지됨 (누적 카운트) |

### img 지역변수 선언
```cpp
Mat img = imread("lenna.bmp");
```
이전 코드들과 달리 `img`를 전역변수가 아닌 지역변수로 선언했다.
`onMouse`에서 `img`의 픽셀값을 참조할 필요가 없고
이벤트 횟수만 카운트하면 되므로 전역변수가 불필요하다.

### 마우스 이벤트 종류
| 이벤트 | 발생 시점 |
|--------|-----------|
| `EVENT_MOUSEMOVE` | 마우스가 윈도우 위에서 움직일 때 (픽셀 단위 감지) |
| `EVENT_LBUTTONDOWN` | 왼쪽 버튼을 누르는 순간 |
| `EVENT_LBUTTONUP` | 왼쪽 버튼을 떼는 순간 |

### EVENT_MOUSEMOVE 특징
마우스를 조금만 움직여도 픽셀 단위로 이벤트가 감지되므로
`cntMove`는 다른 카운터에 비해 매우 빠르게 증가한다.

### 실행 결과

https://github.com/user-attachments/assets/9cc3d773-8ec3-455c-8e96-c893ecd0f0ea
