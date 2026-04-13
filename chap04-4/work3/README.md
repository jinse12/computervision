# 과제 3
Lenna 영상을 그레이스케일 영상으로 변환 후 화면에 출력하고
마우스로 클릭하는 화면 좌표와 그점에서 화소값을 출력하는
프로그램을 작성하시오.

---

## 코드
```cpp
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat img; // lenna.bmp를 저장할 이미지 (전역변수로 선언하여 onMouse에서 공유)

void onMouse(int event, int x, int y, int flags, void* userdata);
// 마우스 이벤트 발생 시 호출될 콜백 함수 선언

int main() {
    // lenna.bmp를 그레이스케일로 읽기
    // IMREAD_GRAYSCALE : 3채널 컬러 영상을 1채널 흑백 영상으로 변환하여 로드
    img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 이미지 로드 실패 시 에러 메시지 출력 후 종료
    if (img.empty()) {
        cout << "영상을 불러올 수 없습니다." << endl;
        return -1;
    }

    namedWindow("gray"); // "gray" 이름의 윈도우 생성

    // 마우스 이벤트 발생 시 onMouse 콜백 함수 등록
    setMouseCallback("gray", onMouse);

    imshow("gray", img); // 그레이스케일 이미지 화면에 표시
    waitKey(0);          // 키 입력 대기 (프로그램 유지)
    return 0;
}

void onMouse(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_LBUTTONDOWN) { // 왼쪽 버튼 클릭 시에만 동작

        // img.at<uchar>(y, x) : (y, x) 좌표의 픽셀값을 uchar 타입으로 읽기
        // 그레이스케일은 1채널이므로 Vec3b 대신 uchar 사용
        // 주의: Mat의 좌표 순서는 (행, 열) -> (y, x) 순서
        int pixel = img.at<uchar>(y, x);

        // uchar -> int로 저장했으므로 캐스팅 없이 바로 숫자 출력 가능
        cout << "좌표: (" << x << "," << y << "), 화소값: " << pixel << endl;
    }
}
```

---

## 개념

### IMREAD_GRAYSCALE
```cpp
img = imread("lenna.bmp", IMREAD_GRAYSCALE);
```
| 플래그 | 설명 |
|--------|------|
| `IMREAD_COLOR` (기본값) | 3채널 BGR 컬러 영상으로 로드 |
| `IMREAD_GRAYSCALE` | 1채널 흑백 영상으로 로드 |

### uchar vs Vec3b
그레이스케일은 1채널이므로 픽셀값이 숫자 하나로 표현된다.

| 영상 종류 | 채널 수 | at<> 타입 | 값 |
|-----------|---------|-----------|-----|
| 그레이스케일 | 1채널 | `uchar` | 0 ~ 255 단일 값 |
| 컬러 | 3채널 | `Vec3b` | B, G, R 3개 값 |

### at<>() 좌표 순서
```cpp
img.at<uchar>(y, x)
// Mat은 (행, 열) 순서 -> (y, x) 순서로 접근
// 화면 좌표 (x, y)와 반대임에 주의
```

| 표현 | 순서 |
|------|------|
| 화면 좌표 | (x, y) -> (가로, 세로) |
| Mat.at<> | (y, x) -> (행, 열) |

---
### 실행 결과

https://github.com/user-attachments/assets/20fb1efb-fd9b-4374-9629-4785768d79f8
