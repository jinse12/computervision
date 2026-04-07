# 과제
Lenna 영상을 컬러 영상으로 읽은 후 화면에 출력하고 문자열을 출력하시오.
  - 폰트설정은 원하는 대로 하시오.
  - 문자열이 상단의 중앙에 위치하도록 위치를 조정하시오.
---
## 코드
```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <string>               // string 타입 사용을 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::putText 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::string 등을 쓸 때 std::를 생략하기 위해 사용

int main()
{
    Mat src = imread("lenna.bmp", IMREAD_COLOR);    // 컬러 영상으로 읽기
    if (src.empty()) return -1;

    string text      = "Hello, Lenna";
    int fontFace     = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 1.5;
    int thickness    = 2;

    // 텍스트 크기 측정 → 중앙 정렬 계산
    int baseline = 0;
    Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseline);
    Point org((src.cols - textSize.width) / 2, textSize.height + 30);  // 상단 중앙

    putText(src, text, org, fontFace, fontScale, Scalar(0, 255, 255), thickness, LINE_AA);

    imshow("image", src);
    waitKey(0);
    return 0;
}
```
---
## 개념
### getTextSize() — 텍스트 크기 측정
`getTextSize(text, fontFace, fontScale, thickness, &baseline)` 으로 텍스트가 차지하는 픽셀 크기를 미리 측정한다.
중앙 정렬 좌표 계산에 사용한다.

| 인자 | 의미 |
|------|------|
| `text` | 출력할 문자열 |
| `fontFace` | 폰트 종류 |
| `fontScale` | 폰트 크기 배율 |
| `thickness` | 글자 두께 |
| `&baseline` | 베이스라인 높이 (출력) |

### putText() — 문자열 출력
`putText(img, text, org, fontFace, fontScale, color, thickness, lineType)` 으로 영상에 문자열을 출력한다.

| 인자 | 의미 |
|------|------|
| `org` | 텍스트 좌하단 기준 좌표 |
| `fontFace` | 폰트 종류 |
| `fontScale` | 폰트 크기 배율 |
| `color` | 글자 색상 (BGR) |
| `thickness` | 글자 두께 |

### 상단 중앙 좌표 계산
```
x = (src.cols - textSize.width) / 2   // 가로 중앙 정렬
y = textSize.height + 30              // 상단에서 30px 여백
```
`getTextSize()` 로 텍스트 너비를 측정한 뒤 영상 너비에서 빼고 2로 나누면 중앙 x좌표가 된다.

---
## 실행 결과

<img width="632" height="671" alt="image" src="https://github.com/user-attachments/assets/dca88484-66ec-4d9c-a445-11dc1245a6b3" />
