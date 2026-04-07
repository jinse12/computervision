# 과제
키보드를 이용하여 파란색 버튼을 움직이는 프로그램을 만들고자 한다.
  - 초기 화면은 폭500, 높이500픽셀의 3채널 컬러영상으로 설정하라. 첫번째 그림처럼 바둑판모양으로 직선을 출력하고 파란색버튼이 가운데 위치하도록 하라.
  - 'l' 키를 누르면 현재위치에서 왼쪽으로 버튼을 한칸 움직인다. 윈도우를 벗어난 경우 현재 위치를 유지하라.
  - 'u' 키를 누르면 현재위치에서 위쪽으로 버튼을 한칸 움직인다. 윈도우를 벗어난 경우 현재 위치를 유지하라.
  - 'r' 키를 누르면 현재위치에서 오른쪽으로 버튼을 한칸 움직인다. 윈도우를 벗어난 경우 현재 위치를 유지하라.
  - 'd' 키를 누르면 현재위치에서 아래쪽으로 버튼을 한칸 움직인다. 윈도우를 벗어난 경우 현재 위치를 유지하라.
  - 'q'키를 누르면 종료하도록 하라.
  - waitKey함수로 키보드 입력을 받고 새로운 버튼의 좌표를 계산하라. 버튼의 이전 위치도 항상 저장하여 이전 버튼은 지우고 새버튼을 그린다. 버튼의 좌표가 윈도우를 벗어난 경우 현재 값을 유지하라.
---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::rectangle 등을 쓸 때 cv::를 생략하기 위해 사용

int main()
{
    const int CELL = 100;       // 셀 크기 100px (5x5 바둑판)
    int bx = 2, by = 2;         // button 초기 위치 (가운데)

    while (true) {
        Mat img(500, 500, CV_8UC3, Scalar(255, 255, 255));  // 500x500 흰색 영상 생성

        // 바둑판 그리기 (가로 + 세로 한 루프로 처리)
        for (int i = 0; i <= 5; i++) {
            line(img, Point(i*CELL, 0),   Point(i*CELL, 500), Scalar(0,0,0), 1);
            line(img, Point(0, i*CELL),   Point(500, i*CELL), Scalar(0,0,0), 1);
        }

        // 파란색 button 그리기 (셀 인덱스 → 픽셀 좌표)
        rectangle(img, Point(bx*CELL, by*CELL),
                       Point((bx+1)*CELL, (by+1)*CELL), Scalar(255,0,0), -1);

        imshow("src", img);

        // 키 입력에 따라 button 이동, 경계는 max/min으로 처리
        int key = waitKey(0);
        if      (key == 'l' || key == 'L') bx = max(0, bx-1);
        else if (key == 'r' || key == 'R') bx = min(4, bx+1);
        else if (key == 'u' || key == 'U') by = max(0, by-1);
        else if (key == 'd' || key == 'D') by = min(4, by+1);
        else if (key == 'q' || key == 'Q') break;
    }
    return 0;
}
```
---
## 개념
### 셀 인덱스 기반 위치 관리
버튼 위치를 픽셀이 아닌 **셀 인덱스(bx, by)** 로 관리한다.
픽셀 좌표는 `bx * CELL` 로 변환하므로 경계 계산이 단순해진다.

| 항목 | 값 |
|------|-----|
| 셀 크기 | 100px |
| 바둑판 크기 | 5x5 |
| 초기 위치 | (2, 2) — 가운데 |

### 바둑판 그리기 — 루프 1개
가로선과 세로선을 한 루프에서 동시에 그려 코드를 최소화한다.
```cpp
for (int i = 0; i <= 5; i++) {
    line(img, Point(i*CELL, 0),  Point(i*CELL, 500), ...); // 세로선
    line(img, Point(0, i*CELL),  Point(500, i*CELL), ...); // 가로선
}
```

### 경계 처리 — max() / min()
`if` 문 대신 `max()` / `min()` 으로 한 줄에 경계를 처리한다.

| 방향 | 경계 처리 |
|------|-----------|
| 왼쪽 | `bx = max(0, bx-1)` |
| 오른쪽 | `bx = min(4, bx+1)` |
| 위쪽 | `by = max(0, by-1)` |
| 아래쪽 | `by = min(4, by+1)` |

### 이전 버튼 지우기
매 루프마다 `Mat img` 를 새로 생성(흰색으로 초기화)하므로
이전 버튼이 자동으로 지워지고 새 버튼만 그려진다.

### 키 입력
| 키 | 동작 |
|----|------|
| `l` / `L` | 왼쪽 이동 |
| `r` / `R` | 오른쪽 이동 |
| `u` / `U` | 위쪽 이동 |
| `d` / `D` | 아래쪽 이동 |
| `q` / `Q` | 종료 |

---
## 실행 결과

https://github.com/user-attachments/assets/065a5b8c-b3ed-4799-9014-0a066cf650f5
