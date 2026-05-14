# 실습과제 1

lenna.bmp 영상에 대하여 콘솔창처럼 출력하는 프로그램을 작성하시오.
최대, 최소값은 minMaxLoc( ) 함수를 사용하여 구하시오.

## 코드

```cpp
#include <iostream>            // 표준 입출력 헤더
#include <opencv2/opencv.hpp>  // OpenCV 헤더
using namespace std;           // std:: 생략
using namespace cv;            // cv:: 생략

// 그레이스케일 영상의 히스토그램을 계산하여 반환하는 함수
Mat calcGrayHist(const Mat& img)
{
    // 입력 영상이 그레이스케일(8비트 1채널)인지 확인, 아니면 프로그램 종료
    CV_Assert(img.type() == CV_8UC1);

    Mat hist;                               // 히스토그램 결과를 저장할 빈 행렬
    int channels[] = { 0 };                // 처리할 채널번호 (그레이스케일이므로 0번)
    int dims = 1;                           // 히스토그램 차원 수
    const int histSize[] = { 256 };         // 빈(bin) 개수: 256개
    float graylevel[] = { 0, 256 };         // 화소값 범위: 0~255
    const float* ranges[] = { graylevel };  // 범위의 배열

    // 히스토그램 계산 (noArray(): 마스크 없이 영상 전체 대상)
    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

    return hist; // 256x1 크기의 CV_32FC1 행렬 반환 (각 행 = 해당 픽셀값의 빈도수)
}

int main(void)
{
    // lenna.bmp를 그레이스케일로 로드
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    // 영상 로드 실패 시 오류 메시지 출력 후 종료
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("src", src); // 원본 영상 출력

    // 전체 픽셀수 출력 (행 x 열 = 512 x 512 = 262,144)
    cout << "영상의 전체 픽셀수 : " << src.rows * src.cols << endl;

    // minMaxLoc()으로 영상에서 직접 최솟값, 최댓값 탐색
    double minVal, maxVal;
    minMaxLoc(src, &minVal, &maxVal);
    cout << "영상에서 픽셀값의 최소값 : " << minVal << endl;
    cout << "영상에서 픽셀값의 최대값 : " << maxVal << endl;

    // 히스토그램 계산 (256x1 행렬로 반환)
    Mat hist = calcGrayHist(src);

    // hist 행렬에서 최대 빈도수와 그 위치(픽셀값) 탐색
    double histMax;
    Point maxLoc;
    minMaxLoc(hist, nullptr, &histMax, nullptr, &maxLoc);
    // maxLoc.y = 빈도수가 최대인 픽셀값 (hist가 256x1 행렬이므로 y가 행 번호)
    cout << "빈도수가 가장많은 픽셀값과 빈도수 : "
         << maxLoc.y << ", " << (int)histMax << endl;

    // hist.at<float>(80, 0) = 픽셀값 80의 빈도수 (80번째 행, 0번째 열)
    cout << "픽셀값 80의 빈도수 : "
         << (int)hist.at<float>(80, 0) << endl;

    waitKey(); // 키 입력 대기
    return 0;  // 프로그램 정상 종료
}
```

## calcGrayHist 함수

```cpp
CV_Assert(img.type() == CV_8UC1);
```

* 입력 영상이 그레이스케일(8비트 1채널)인지 확인합니다.
* 조건이 false이면 에러 메시지 출력 후 프로그램을 종료합니다.

```cpp
int channels[] = { 0 };
```

* 히스토그램을 계산할 채널 번호를 지정합니다.
* 그레이스케일 영상은 채널이 1개뿐이므로 항상 0번 채널을 사용합니다.

```cpp
const int histSize[] = { 256 };
```

* 히스토그램의 빈(bin) 개수를 256개로 설정합니다.
* 픽셀값 0~255 각각에 대해 빈도수를 셉니다.

```cpp
float graylevel[] = { 0, 256 };
const float* ranges[] = { graylevel };
```

* `graylevel` : 히스토그램을 계산할 픽셀값 범위로 0~255를 의미합니다. (256은 포함되지 않음)
* `ranges` : `graylevel`을 `calcHist()`에 전달하기 위한 포인터 배열입니다.

```cpp
calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
```

* `&img` : 입력 영상의 주소
* `1` : 입력 영상 개수
* `channels` : 처리할 채널 번호
* `noArray()` : 마스크 없이 영상 전체 대상으로 계산
* `hist` : 결과를 저장할 행렬 (256×1 크기의 CV_32FC1)
* `dims` : 히스토그램 차원 수 (1)
* `histSize` : 빈 개수 (256)
* `ranges` : 픽셀값 범위 (0~255)

## 전체 픽셀수 출력

```cpp
cout << "영상의 전체 픽셀수 : " << src.rows * src.cols << endl;
```

* `src.rows` : 영상의 행(세로) 수
* `src.cols` : 영상의 열(가로) 수
* 두 값을 곱하면 전체 픽셀수를 구할 수 있습니다. (512 × 512 = 262,144)

## 최솟값, 최댓값 출력

```cpp
double minVal, maxVal;
minMaxLoc(src, &minVal, &maxVal);
```

* `minMaxLoc()` 함수를 영상에 직접 적용하여 최솟값과 최댓값을 구합니다.
* `&minVal`, `&maxVal` : 결과를 저장할 변수의 주소를 전달합니다.

## 최빈값, 최대 빈도수 출력

```cpp
double histMax;
Point maxLoc;
minMaxLoc(hist, nullptr, &histMax, nullptr, &maxLoc);
```

* `minMaxLoc()` 함수를 hist 행렬에 적용하여 최대 빈도수와 그 위치를 구합니다.
* `nullptr` : 최솟값과 최솟값 위치는 관심 없으므로 무시합니다.
* `maxLoc.y` : hist가 256×1 행렬이므로 행 번호가 곧 픽셀값을 의미합니다.

## 특정 픽셀값의 빈도수 출력

```cpp
cout << "픽셀값 80의 빈도수 : "
     << (int)hist.at<float>(80, 0) << endl;
```

* `hist.at<float>(80, 0)` : hist 행렬의 80번째 행, 0번째 열에 접근합니다.
* hist는 256×1 행렬이므로 행 번호가 픽셀값, 열은 항상 0입니다.
* `(int)` : float로 저장된 빈도수를 정수로 변환하여 출력합니다.

## 실행 결과

<img width="637" height="807" alt="image" src="https://github.com/user-attachments/assets/1d9616ed-e833-4daf-9eb2-066793a051f4" />
