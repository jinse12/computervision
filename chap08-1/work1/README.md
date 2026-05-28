# 실습과제 1
입력영상의 크기를 1/2로 변환하는 어파인 변환 행렬 M을 구하고 입력, 결과영상을 출력하시오.  
힌트: 3개 점(좌측상단, 우측상단, 우측하단)의 변환 관계를 구한다.

---

## 코드

```cpp
#include <opencv2/opencv.hpp>   // OpenCV 함수들을 사용하기 위한 헤더 파일
#include <iostream>             // cout, endl 등 입출력을 사용하기 위한 헤더 파일
using namespace cv;             // cv::Mat, cv::Point2f 등을 쓸 때 cv::를 생략하기 위해 사용
using namespace std;            // std::cout, std::endl 등을 쓸 때 std::를 생략하기 위해 사용

int main(void)
{
    // 컬러(BGR 3채널)로 이미지 읽기
    Mat src = imread("tekapo.bmp");

    // 이미지 로드 실패 체크
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

    // 입력 영상의 기준점 3개와 결과 영상의 기준점 3개 선언
    Point2f srcPts[3], dstPts[3];

    // 입력 영상의 기준점: 좌측 상단, 우측 상단, 우측 하단 모서리
    srcPts[0] = Point2f(0, 0);
    srcPts[1] = Point2f(src.cols - 1, 0);
    srcPts[2] = Point2f(src.cols - 1, src.rows - 1);

    // 결과 영상의 기준점: 각 좌표를 절반으로 줄인 위치로 지정 → ½ 축소 효과
    dstPts[0] = Point2f(0, 0);
    dstPts[1] = Point2f((src.cols - 1) / 2.f, 0);
    dstPts[2] = Point2f((src.cols - 1) / 2.f, (src.rows - 1) / 2.f);

    // 3쌍의 대응점으로부터 2×3 어파인 변환 행렬 M 계산
    Mat M = getAffineTransform(srcPts, dstPts);

    // 계산된 어파인 변환 행렬 출력
    cout << M << endl;

    // 어파인 변환 적용 (dsize에 Size()를 전달하면 결과 영상 크기 = 입력 영상 크기)
    Mat dst;
    warpAffine(src, dst, M, Size());

    // 원본과 결과 영상 출력
    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    return 0;
}
```

---

## 개념

### 어파인 변환 행렬
어파인 변환은 입력 좌표 `(x, y)`를 결과 좌표 `(x', y')`로 변환하는 2×3 행렬로 표현된다.

```
[x']   [a b c] [x]
[y'] = [d e f] [y]
                [1]
```

| 파라미터 | 역할 |
|---------|------|
| a, e | 크기변환 (대각 성분) |
| b, d | 전단 및 회전 성분 |
| c, f | 평행이동 성분 |

### 기준점을 3개로 잡는 이유
| 항목 | 내용 |
|------|------|
| 미지수 개수 | 6개 (a, b, c, d, e, f) |
| 점 1개에서 얻는 방정식 | 2개 (x 변환식 1개 + y 변환식 1개) |
| 필요한 최소 점 개수 | 3개 (방정식 6개 = 미지수 6개) |

### 좌표에서 -1을 하는 이유
영상의 좌표 인덱스는 0부터 시작하므로, 마지막 픽셀의 좌표는 `cols - 1`, `rows - 1`이다.

| | 값 (cols = 640 기준) |
|--|------|
| `src.cols` | 640 (픽셀 개수) |
| 마지막 픽셀 x좌표 | 639 = `src.cols - 1` |

### / 2.f 를 사용하는 이유
`src.cols - 1`은 `int` 타입이므로, 그냥 `/ 2`를 하면 정수 나눗셈으로 소수점이 버려진다. `/ 2.f`를 쓰면 float 나눗셈이 되어 정확한 실수 좌표를 얻을 수 있다.

| 표현 | 결과 (639 기준) |
|------|----------------|
| `639 / 2` | 319 (소수점 버림) |
| `639 / 2.f` | 319.5 (실수) |

### warpAffine의 dsize에 Size()를 전달하면
결과 영상 크기가 입력 영상과 동일하게 유지된다. 따라서 1/2로 축소된 영상은 좌측 상단에 위치하고 나머지 영역은 검은색으로 채워진다.

---

## 출력 결과

<img width="1581" height="737" alt="image" src="https://github.com/user-attachments/assets/207b72c9-5fac-4bb3-aed5-f0f20808ef45" />
