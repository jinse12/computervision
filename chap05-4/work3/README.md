# 실습과제 3

코드5-9의 코드를 연산자 함수 대신에 픽셀값을 직접 참조하는 방식으로 수정하여 같은 결과가 나오도록 하라.
힌트 : Mat::at 함수와 포화연산(saturate_cast) 함수를 이용할 것

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

    // 히스토그램 계산
    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

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
            Point(i, 100),                                                  // 막대 바닥점 (항상 고정)
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), // 막대 꼭대기점 (빈도수 정규화)
            Scalar(0));                                                     // 검은색 직선
    }

    return imgHist; // 히스토그램 막대그래프 영상 반환
}

int main(void)
{
    // hawkes.bmp를 그레이스케일로 로드
    Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

    // minMaxLoc()으로 영상의 최솟값(gmin), 최댓값(gmax) 탐색
    double gmin, gmax;
    minMaxLoc(src, &gmin, &gmax);

    // src와 동일한 크기, 타입으로 결과 행렬 dst 생성
    Mat dst(src.rows, src.cols, src.type());

    // 이중 for문으로 모든 픽셀을 순회하며 히스토그램 스트레칭 수행
    for (int j = 0; j < src.rows; j++) {      // 행(세로) 반복
        for (int i = 0; i < src.cols; i++) {  // 열(가로) 반복

            // 스트레칭 수식을 픽셀값 직접 참조 방식으로 적용
            // saturate_cast: 결과값이 0~255 범위를 벗어나면 포화 연산 수행
            dst.at<uchar>(j, i) = saturate_cast<uchar>(
                (src.at<uchar>(j, i) - gmin) * 255 / (gmax - gmin)
            );
        }
    }

    imshow("src", src);                                    // 원본 영상 출력
    imshow("srcHist", getGrayHistImage(calcGrayHist(src))); // 원본 히스토그램 출력
    imshow("dst", dst);                                    // 스트레칭 결과 영상 출력
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst))); // 결과 히스토그램 출력

    waitKey(); // 키 입력 대기
    return 0;  // 프로그램 정상 종료
}
```

## 실행 결과

<img width="1118" height="572" alt="스크린샷 2026-05-14 224211" src="https://github.com/user-attachments/assets/5556039a-5f2d-4bee-9f15-5803cac6343d" />
