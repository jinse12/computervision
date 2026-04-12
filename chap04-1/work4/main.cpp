#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    VideoCapture cap(0);

    while (true) {
        Mat frame;
        cap >> frame;

        int h = frame.rows;
        int w = frame.cols;

        Mat cross = frame.clone();
        line(cross, Point(w/2, 0), Point(w/2, h), Scalar(0, 0, 255), 2);
        line(cross, Point(0, h/2), Point(w, h/2), Scalar(0, 0, 255), 2);

        imshow("frame", frame);
        imshow("cross", cross);

        if (waitKey(1) == 'q') break;
    }

    return 0;
}
