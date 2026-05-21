#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

    int ksizes[] = { 3, 10, 30 };

    for (int i = 0; i < 3; i++) {
        int ksize = ksizes[i];
        Mat dst;

        auto startTime = std::chrono::steady_clock::now();
        blur(src, dst, Size(ksize, ksize));
        auto endTime = std::chrono::steady_clock::now();

        float totalTime = std::chrono::duration<float, std::milli>(endTime - startTime).count();
        cout << ksize << "x" << ksize << " 실행시간: " << totalTime << " ms" << endl;
    }
    return 0;
}
