# 실습과제 2

앞 예제에서 calcGrayHist 함수를 직접 구현하여 같은 결과가 나오도록 작성하라.  
함수명은 mycalcGrayHist으로 정의하고 매개변수와 리턴타입은 calcGrayHist 함수와 같게 정의하라.  
교재 219페이지 코드를 참고하라.

## 코드

```cpp
#include <iostream>            // 표준 입출력 헤더
#include <opencv2/opencv.hpp>  // OpenCV 헤더
using namespace std;           // std:: 생략
using namespace cv;            // cv:: 생략

// calcHist() 없이 직접 구현한 히스토그램 계산 함수
Mat mycalcGrayHist(const Mat& img)
{
    // 입력 영상이 그레이스케일(8비트 1채널)인지 확인, 아니면 프로그램 종료
    CV_Assert(img.type() == CV_8UC1);

    // 256x1 크기의 행렬을 0으로 초기화 (각 행 = 해당 픽셀값의 빈도수)
    Mat hist = Mat::zeros(256, 1, CV_32FC1);

    // 이중 for문으로 영상의 모든 픽셀을 순회
    for (int j = 0; j < img.rows; j++)        // 행(세로) 반복
        for (int i = 0; i < img.cols; i++)    // 열(가로) 반복
            hist.at<float>(img.at<uchar>(j, i), 0)++; // 해당 픽셀값의 빈도수 1 증가

    return hist; // 256x1 크기의 CV_32FC1 행렬 반환
}

// 히스토그램 행렬을 막대그래프 영상으로 변환하는 함수
Mat getGrayHistImage(const Mat& hist)
{
    // hist 행렬이 CV_32FC1 타입이고 256x1 크기인지 확인
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));

    // hist 행렬에서 최대 빈도수 탐색 (정규화에 사용)
    double histMax;
    minMaxLoc(hist, 0, &histMax);

    // 100x256 크기의 흰색 영상 생성 (가로=픽셀값 범위, 세로=막대 최대 길이)
    Mat imgHist(100, 256, CV_8UC1, Scalar(255));
    for (int i = 0; i < 256; i++) {
        line(imgHist,
            Point(i, 100),                                                         // 막대 바닥점 (항상 고정)
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), // 막대 꼭대기점 (빈도수 정규화)
            Scalar(0));                                                            // 검은색 직선
    }
    return imgHist; // 히스토그램 막대그래프 영상 반환
}

int main(void)
{
    // lenna.bmp를 그레이스케일로 로드
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    imshow("입력 영상", src); // 원본 영상 출력

    // 히스토그램 계산 후 막대그래프 영상으로 변환
    Mat hist = mycalcGrayHist(src);
    Mat hist_img = getGrayHistImage(hist);

    imshow("srcHist", hist_img); // 히스토그램 그래프 출력

    waitKey(); // 키 입력 대기
    return 0;  // 프로그램 정상 종료
}
```

## mycalcGrayHist 함수

```cpp
CV_Assert(img.type() == CV_8UC1);
```

* 입력 영상이 그레이스케일(8비트 1채널)인지 확인합니다.
* 조건이 false이면 에러 메시지 출력 후 프로그램을 종료합니다.

```cpp
Mat hist = Mat::zeros(256, 1, CV_32FC1);
```

* 256×1 크기의 행렬을 0으로 초기화합니다.
* `CV_32FC1` : 실수형(float) 1채널 타입으로 큰 빈도수와 이후 실수 연산을 위해 사용합니다.

```cpp
for (int j = 0; j < img.rows; j++)
    for (int i = 0; i < img.cols; i++)
        hist.at<float>(img.at<uchar>(j, i), 0)++;
```

* 이중 for문으로 영상의 모든 픽셀을 순회합니다.
* `img.at<uchar>(j, i)` : (j행, i열)의 픽셀값을 직접 읽습니다.
* `hist.at<float>(픽셀값, 0)++` : 해당 픽셀값의 빈도수를 1 증가시킵니다.

## getGrayHistImage 함수

```cpp
double histMax;
minMaxLoc(hist, 0, &histMax);
```

* hist 행렬에서 최대 빈도수를 구합니다.
* 이후 정규화에 사용합니다.

```cpp
Mat imgHist(100, 256, CV_8UC1, Scalar(255));
```

* 100×256 크기의 흰색(255) 영상을 생성합니다.
* 가로 256 = 픽셀값 0~255, 세로 100 = 막대 최대 길이

```cpp
line(imgHist,
    Point(i, 100),
    Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)),
    Scalar(0));
```

* `Point(i, 100)` : 막대의 바닥점 (항상 고정)
* `Point(i, 100 - h[i])` : 막대의 꼭대기점 (빈도수에 따라 변함)
* `hist.at<float>(i, 0) * 100 / histMax` : 빈도수를 0~100 범위로 정규화
* `cvRound()` : 실수를 정수로 반올림
* `Scalar(0)` : 검은색 직선

## 실행 결과

<img width="622" height="662" alt="image" src="https://github.com/user-attachments/assets/b3cf545c-e9f3-4b5f-86e8-20aa763b0d71" />
