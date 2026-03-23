#include <opencv2/opencv.hpp>   // OpenCV의 Mat 클래스를 사용하기 위한 헤더
#include <iostream>             // 콘솔 입출력(cout 등)을 위한 헤더

using namespace cv;             // cv::Mat 대신 Mat 등으로 쓰기 위해 사용
using namespace std;            // std::cout 대신 cout 등으로 쓰기 위해 사용

int main()
{
    // mat1 = [ 3.5   2.1
    //         -1.5  -6.5 ]
    // 2행 2열의 double 타입 행렬을 만들고, << 뒤에 값을 순서대로 채워 넣는다.
    Mat mat1 = (Mat_<double>(2, 2) << 3.5, 2.1,
        -1.5, -6.5);

    // mat2 = [ 0   2  -1
    //          5  10  8
    //          6  -7  9 ]
    // 3행 3열의 int 타입 행렬, 값은 행 기준으로 왼쪽에서 오른쪽 순서로 들어간다.
    Mat mat2 = (Mat_<int>(3, 3) << 0, 2, -1,
        5, 10, 8,
        6, -7, 9);

    // mat3 = [ 1  2  3  4 ]
    // 1행 4열(행 벡터)인 int 타입 행렬
    Mat mat3 = (Mat_<int>(1, 4) << 1, 2, 3, 4);

    // mat4 = [ 5
    //          6
    //          7
    //          8 ]
    // 4행 1열(열 벡터)인 int 타입 행렬
    Mat mat4 = (Mat_<int>(4, 1) << 5,
        6,
        7,
        8);

    // 각 Mat 객체를 콘솔에 출력한다.
    // endl << mat1 << endl; 형태로 쓰면, 보기 좋은 행렬 형태로 출력된다.
    cout << "mat1 = " << endl << mat1 << endl << endl;
    cout << "mat2 = " << endl << mat2 << endl << endl;
    cout << "mat3 = " << endl << mat3 << endl << endl;
    cout << "mat4 = " << endl << mat4 << endl << endl;

    // 프로그램 정상 종료
    return 0;
}
