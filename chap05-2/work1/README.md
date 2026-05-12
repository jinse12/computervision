## 실습과제 1

코드 5-5에서 연산자 함수를 사용하지 말고 픽셀값을 직접 참조하는 방식으로 같은 결과를 얻도록 수정하라. 204페이지 코드 5-3을 참고할 것.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>  // OpenCV 헤더
#include <iostream>            // 표준 입출력 헤더
using namespace cv;            // cv:: 생략
using namespace std;           // std:: 생략

int main(void)
{
    // 레나 영상을 그레이스케일로 불러와 Mat 객체 src에 저장
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 영상 로드 실패 시 오류 메시지 출력 후 종료
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

    float s = 2.f;  // 명암비 조절 상수 (float형, s > 1이면 명암비 증가)

    // src와 동일한 크기(rows x cols) 및 타입(CV_8UC1)으로 결과 행렬 dst 생성
    Mat dst(src.rows, src.cols, src.type());

    // 이중 for문으로 영상의 모든 픽셀을 순회
    for (int j = 0; j < src.rows; j++) {      // 행(세로) 반복
        for (int i = 0; i < src.cols; i++) {  // 열(가로) 반복

            // 픽셀값에 s를 곱한 후 포화 연산하여 dst에 저장
            dst.at<uchar>(j, i) = saturate_cast<uchar>(s * src.at<uchar>(j, i));
        }
    }

    imshow("src", src);  // 원본 영상 출력
    imshow("dst", dst);  // 결과 영상 출력
    waitKey();           // 키 입력 대기
    return 0;
}
```

---

### 명암비 상수 설정
```cpp
float s = 2.f;
```
- `s`는 픽셀값에 곱해지는 명암비 배율입니다.
- `s > 1` : 명암비 **증가** (영상이 밝아지고 대비가 강해짐)
- `0 < s < 1` : 명암비 **감소** (영상이 어두워지고 대비가 약해짐)

---

### 결과 행렬 생성
```cpp
Mat dst(src.rows, src.cols, src.type());
```
- `src.rows` : 원본 영상의 행 수 (세로 크기)
- `src.cols` : 원본 영상의 열 수 (가로 크기)
- `src.type()` : 원본 영상의 데이터 타입 반환 (그레이스케일 8비트 -> `CV_8UC1`)
- src와 동일한 크기와 타입으로 결과 행렬을 생성합니다.

---

### 픽셀 직접 참조 및 명암비 계산
```cpp
dst.at<uchar>(j, i) = saturate_cast<uchar>(s * src.at<uchar>(j, i));
```
- `src.at<uchar>(j, i)` : (j행, i열)의 픽셀값을 직접 참조합니다.
- `s * src.at<uchar>(j, i)` : 픽셀값에 명암비 배율 s를 곱합니다.
- `saturate_cast<uchar>` : 계산 결과가 0 미만이면 0, 255 초과면 255로 지정하는 포화 연산입니다.  
   s가 클수록 255를 초과하는 픽셀이 많아지므로 포화 연산이 반드시 필요합니다.

---

## 실행 결과

<img width="1272" height="670" alt="image" src="https://github.com/user-attachments/assets/931e534f-90ae-45b0-b117-557a6cbb35d7" />
