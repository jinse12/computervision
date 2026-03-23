#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;   // OpenCV 네임스페이스 사용
using namespace std;  // 표준 C++ 네임스페이스 사용

int main()
{
    Mat mat1; // empty matrix
    Mat mat2(2, 3, CV_8UC1); // uchar , 1ch, 쓰레기값
    Mat mat3(2, 3, CV_8UC1, Scalar(128));// 1ch, 128 로 초기화
    // Mat mat3(Size(3,2), CV_8UC1, Scalar(128));
    //128));// 1ch, 128 로 초기화
    Mat mat4(2, 3, CV_8UC3, Scalar(0, 0, 255));// 3ch, ( 로 초기화
    //Mat mat4(Size(3, 2), CV_8UC1, Scalar(128));
    //128));// 1ch, 128 로 초기화
    float data[] = { 1, 2, 3, 4, 5, 6 };
    Mat mat5(2, 3, CV_32FC1, data);
    // cout << mat1 << endl; // error
    cout << mat2 << endl;
    cout << mat3 << endl;
    cout << mat4 << endl;
    cout << mat5 << endl;

    Mat img1(480, 640, CV_8UC1);// unsigned char, 1 channel
    Mat img2(480, 640, CV_8UC3);// unsigned char, 3 channels
    Mat img3(Size(640, 480), CV_8UC3);// Size(width,
    Mat img4(480, 640, CV_8UC1, Scalar(128));// initial values, 128
    Mat img5(480, 640, CV_8UC3, Scalar(255, 0, 0));// initial values, blue
    Mat img6(480, 640, CV_8UC3, Scalar(0, 255, 0));// initial values, Green
    Mat img7(480, 640, CV_8UC3, Scalar(0, 0, 255));// initial values, red
    imshow(" img1", img1);
    imshow(" img2", img2);
    imshow(" img3", img3);
    imshow(" img4", img4);
    imshow(" img5", img5);
    imshow(" img6", img6);
    imshow("img7", img7);
    waitKey();
    return 0;
}
*/
