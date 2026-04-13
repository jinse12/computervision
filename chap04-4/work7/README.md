# 과제 7
500x300 흰색 영상에 Red, Green, Blue 버튼 메뉴를 만들고,
마우스로 버튼 클릭 시 해당 버튼이 반전되고 오른쪽에 눌린 버튼 이름을 출력하시오.

---

## 코드
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void event_handler(int event, int x, int y, int flags, void* userdata);
// 마우스 이벤트 발생 시 호출될 콜백 함수 선언

Mat img; // 메뉴 화면을 그릴 이미지 (전역변수로 선언하여 event_handler에서 공유)

int main(void)
{
    // 500x300 크기의 3채널 컬러 영상을 흰색으로 초기화
    img = Mat(300, 500, CV_8UC3, Scalar(255, 255, 255));

    // 버튼 영역 사각형 그리기 (테두리만, thickness=2)
    // Rect(x, y, width, height) : 시작좌표(x,y)부터 width x height 크기의 사각형
    rectangle(img, Rect(0,   0, 200, 100), Scalar(0, 0, 0), 2); // Red 버튼 영역
    rectangle(img, Rect(0, 100, 200, 100), Scalar(0, 0, 0), 2); // Green 버튼 영역
    rectangle(img, Rect(0, 200, 200, 100), Scalar(0, 0, 0), 2); // Blue 버튼 영역

    // 각 버튼 영역 안에 텍스트 출력
    // putText(img, text, org, fontFace, fontScale, color, thickness)
    // org : 텍스트 좌하단 기준 좌표
    putText(img, "Red",   Point(70, 60),  FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    putText(img, "Green", Point(55, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    putText(img, "Blue",  Point(65, 260), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);

    namedWindow("Menu"); // "Menu" 이름의 윈도우 생성

    // 마우스 이벤트 발생 시 event_handler 콜백 함수 등록
    setMouseCallback("Menu", event_handler);

    int key;
    while (true) {
        imshow("Menu", img);         // img를 계속 갱신하여 화면에 표시
        key = waitKey(10);           // 10ms마다 키 입력 확인
        if (key == 'q') break;       // q 입력 시 종료
    }
    return 0;
}

void event_handler(int event, int x, int y, int flags, void* userdata)
{
    // 왼쪽 버튼 클릭(EVENT_LBUTTONDOWN)이 아니면 즉시 함수 종료
    if (event != EVENT_LBUTTONDOWN) return;

    // 클릭 시마다 img를 흰색으로 초기화 (이전 상태 제거)
    img = Mat(300, 500, CV_8UC3, Scalar(255, 255, 255));

    // 버튼 영역과 텍스트를 기본 상태로 다시 그림
    rectangle(img, Rect(0,   0, 200, 100), Scalar(0, 0, 0), 2);
    rectangle(img, Rect(0, 100, 200, 100), Scalar(0, 0, 0), 2);
    rectangle(img, Rect(0, 200, 200, 100), Scalar(0, 0, 0), 2);
    putText(img, "Red",   Point(70, 60),  FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    putText(img, "Green", Point(55, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    putText(img, "Blue",  Point(65, 260), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);

    // 클릭한 좌표(x, y)가 어느 버튼 영역에 해당하는지 판별
    if (x >= 0 && x < 200 && y >= 0 && y < 100) {
        // Red 버튼 클릭: 버튼 영역을 검정으로 채우고(반전) 텍스트를 흰색으로 변경
        rectangle(img, Rect(0, 0, 200, 100), Scalar(0, 0, 0), -1); // -1: 내부 채우기
        putText(img, "Red",          Point(70, 60),   FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
        putText(img, "Red pressed.", Point(220, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    }
    else if (x >= 0 && x < 200 && y >= 100 && y < 200) {
        // Green 버튼 클릭: 버튼 영역을 검정으로 채우고(반전) 텍스트를 흰색으로 변경
        rectangle(img, Rect(0, 100, 200, 100), Scalar(0, 0, 0), -1);
        putText(img, "Green",          Point(55, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
        putText(img, "Green pressed.", Point(220, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    }
    else if (x >= 0 && x < 200 && y >= 200 && y < 300) {
        // Blue 버튼 클릭: 버튼 영역을 검정으로 채우고(반전) 텍스트를 흰색으로 변경
        rectangle(img, Rect(0, 200, 200, 100), Scalar(0, 0, 0), -1);
        putText(img, "Blue",          Point(65, 260), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
        putText(img, "Blue pressed.", Point(220, 160), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2);
    }
}
```

---

## 개념

### 전역변수
```cpp
Mat img;
```
`main`과 `event_handler` 양쪽에서 같은 `img`를 수정해야 하므로 전역변수로 선언한다.

### Rect()
```cpp
Rect(x, y, width, height)
// x, y     : 사각형 좌상단 시작 좌표
// width    : 가로 크기
// height   : 세로 크기
```

### putText()
```cpp
putText(img, text, org, fontFace, fontScale, color, thickness);
```
| 매개변수 | 설명 |
|----------|------|
| `org` | 텍스트 좌하단 기준 좌표 |
| `FONT_HERSHEY_SIMPLEX` | 기본 폰트 |
| `fontScale` | 폰트 크기 배율 |
| `thickness` | 글자 두께 |

### rectangle() thickness
| thickness | 효과 |
|-----------|------|
| 양수 (ex. 2) | 테두리만 그리기 |
| -1 | 내부 채우기 (버튼 반전 효과) |

### 버튼 클릭 판별
클릭한 좌표 `(x, y)`가 각 버튼 영역 범위 안에 있는지 조건문으로 판별한다.

| 버튼 | x 범위 | y 범위 |
|------|--------|--------|
| Red | 0 ~ 200 | 0 ~ 100 |
| Green | 0 ~ 200 | 100 ~ 200 |
| Blue | 0 ~ 200 | 200 ~ 300 |

### img 초기화 후 재그리기
클릭할 때마다 `img`를 흰색으로 초기화한 뒤 버튼을 다시 그린다.
이전 클릭 상태(반전된 버튼, pressed 텍스트)를 깨끗하게 제거하기 위함이다.

### 실행 결과

https://github.com/user-attachments/assets/99ed7676-b5ab-4f52-991b-7f3d3e220bde
