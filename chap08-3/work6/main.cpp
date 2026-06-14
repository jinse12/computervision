#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
    VideoCapture cap(0);

    int rotateCode = -1;

    while (true) {
        Mat frame, dst;
        cap >> frame;
        if (frame.empty()) break;

        if (rotateCode == -1) dst = frame;
        else rotate(frame, dst, rotateCode);

        imshow("dst", dst);

        int key = waitKey(10);
        if (key == 'q') break;
        else if (key == 'r') {
            if (rotateCode == -1) rotateCode = ROTATE_90_CLOCKWISE;
            else if (rotateCode == ROTATE_90_CLOCKWISE) rotateCode = ROTATE_180;
            else if (rotateCode == ROTATE_180) rotateCode = ROTATE_90_COUNTERCLOCKWISE;
            else rotateCode = -1;
        }
    }
    return 0;
}
