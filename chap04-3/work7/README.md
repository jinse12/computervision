# 과제 7
다음처럼 출력하는 초시계를 만들어 보시오.
  - 윈도우 사이즈는 300x300으로 만드시오.
  - 초기상태는 0을 출력하고 대기한다. 's'키를 누르면 카운트를 시작하고 't'키를 누르면 정지한다. 'r'키를 누르면 0으로 리셋 된다. 'q'키를 입력하면 프로그램을 종료한다.
  - 시간제어 및 문자입력을 위하여 waitKey함수를 사용하라.
  - 숫자출력을 위하여 변수의 값을 문자열로 변환할 때 format함수를 사용하고 문자열을 출력할 때 putText함수를 사용할 것.
  - 반복문은 1번만 사용하라. 같은 함수를 2번 이상 호출하지 말 것.
---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <string>               // string 타입 사용을 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::putText 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::string 등을 쓸 때 std::를 생략하기 위해 사용

int main()
{
    int count = 0;
    bool running = false;

    while (true) {
        Mat img(300, 300, CV_8UC3, Scalar(255, 255, 255));  // 300x300 흰색 영상 생성

        // format()으로 숫자를 문자열 변환 후 putText()로 바로 출력
        putText(img, format("%d", count), Point(100, 220),
                FONT_HERSHEY_SCRIPT_SIMPLEX, 5, Scalar(0, 0, 0), 10, LINE_AA);

        imshow("Stopwatch", img);

        // running이면 1초 대기, 정지 중이면 키 입력까지 무한 대기
        int key = waitKey(running ? 1000 : 0);
        if      (key == 's' || key == 'S') running = true;          // 카운트 시작
        else if (key == 't' || key == 'T') running = false;         // 카운트 정지
        else if (key == 'r' || key == 'R') { count = 0; running = false; } // 리셋
        else if (key == 'q' || key == 'Q') break;                   // 종료

        if (running) count++;   // 1초마다 카운트 증가
    }
    return 0;
}
```
---
## 개념
### format() — 숫자를 문자열로 변환
`format("%d", count)` 는 printf 스타일로 숫자를 문자열로 변환한다.
`putText()` 인자에 바로 인라인으로 넣어 별도 변수 선언 없이 간결하게 사용할 수 있다.

### putText() — 문자열 출력
`putText(img, text, org, fontFace, fontScale, color, thickness, lineType)` 으로 영상에 문자열을 출력한다.

| 인자 | 의미 |
|------|------|
| `org` | 텍스트 좌하단 기준 좌표 |
| `fontFace` | 폰트 종류 |
| `fontScale` | 폰트 크기 배율 |
| `color` | 글자 색상 (BGR) |
| `thickness` | 글자 두께 |

### waitKey(running ? 1000 : 0) — 시간 제어
삼항연산자를 사용해 waitKey()는 한 번만 호출하고, 조건에 따라 동작을 다르게 처리한다.

| 상태 | delay | 동작 |
|------|-------|------|
| `running = true` | 1000ms | 1초마다 자동 갱신 |
| `running = false` | 0 | 키 입력까지 무한 대기 |

### 키 입력 처리
| 키 | 동작 |
|----|------|
| `s` / `S` | 카운트 시작 |
| `t` / `T` | 카운트 정지 |
| `r` / `R` | 0으로 리셋 |
| `q` / `Q` | 프로그램 종료 |

---
## 실행 결과

https://github.com/user-attachments/assets/f0ed4ee4-b658-423c-a58e-87b5c97cdcfb
