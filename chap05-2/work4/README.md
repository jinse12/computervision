# 실습과제 4
코드 5-6에서 128을 입력 영상 픽셀값의 평균값으로 변경하여 명암비 개선을 수행하라. 영상의 픽셀값의 평균값을 구할 때는 함수 mean()을 이용하라.

코드

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

    float alpha = 1.f;  // 명암비 조절 강도 (float형, alpha > 0이면 명암비 증가)

    // 영상 전체 픽셀값의 평균 계산
    Scalar avg = mean(src);
    float mean_val = (float)avg[0];  // 그레이 영상이므로 avg[0]에 평균값 저장

    // src와 동일한 크기(rows x cols) 및 타입(CV_8UC1)으로 결과 행렬 dst 생성
    Mat dst(src.rows, src.cols, src.type());

    // 이중 for문으로 영상의 모든 픽셀을 순회
    for (int j = 0; j < src.rows; j++) {      // 행(세로) 반복
        for (int i = 0; i < src.cols; i++) {  // 열(가로) 반복

            // 128 대신 mean_val을 기준으로 명암비 수식 계산
            float val = src.at<uchar>(j, i) + (src.at<uchar>(j, i) - mean_val) * alpha;

            // 포화 연산 후 dst에 저장
            dst.at<uchar>(j, i) = saturate_cast<uchar>(val);
        }
    }

    imshow("src", src);  // 원본 영상 출력
    imshow("dst", dst);  // 결과 영상 출력
    waitKey();           // 키 입력 대기
    return 0;
}
```

## 평균값 계산

```cpp
Scalar avg = mean(src);
float mean_val = (float)avg[0];
```

- `mean(src)` : 영상 전체 픽셀값의 평균을 계산하여 Scalar 타입으로 반환합니다.
- `avg[0]` : 그레이스케일 영상은 채널이 1개이므로 평균값이 avg[0]에 저장됩니다.
- `(float)avg[0]` : Scalar의 기본 타입은 double이므로 float으로 형변환합니다.

## 결과 행렬 생성

```cpp
Mat dst(src.rows, src.cols, src.type());
```

- `src.rows` : 원본 영상의 행 수 (세로 크기)
- `src.cols` : 원본 영상의 열 수 (가로 크기)
- `src.type()` : 원본 영상의 데이터 타입 반환 (그레이스케일 8비트 -> `CV_8UC1`)
- src와 동일한 크기와 타입으로 결과 행렬을 생성합니다.

## 픽셀 직접 참조 및 명암비 계산

```cpp
float val = src.at<uchar>(j, i) + (src.at<uchar>(j, i) - mean_val) * alpha;
dst.at<uchar>(j, i) = saturate_cast<uchar>(val);
```

- `src.at<uchar>(j, i)` : (j행, i열)의 픽셀값을 직접 참조합니다.
- `(src.at<uchar>(j, i) - mean_val) * alpha` : 픽셀값과 평균값의 차이에 alpha를 곱해 조절량을 계산합니다. 코드 5-6의 고정값 128 대신 영상의 실제 평균값을 기준으로 사용합니다.
- `float val` : 계산 중 0 미만 또는 255 초과가 발생할 수 있으므로 float으로 중간값을 저장합니다.
- `saturate_cast<uchar>` : 계산 결과가 0 미만이면 0, 255 초과면 255로 지정하는 포화 연산입니다.

## 실행 결과

<img width="1276" height="666" alt="스크린샷 2026-05-12 235403" src="https://github.com/user-attachments/assets/9e6106a6-ec1f-42e4-959f-2e37ede00e87" />
