#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int bright = 0;
Mat src,dst;
void onMouse(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		bright += 10;
	}
	else if (event == EVENT_RBUTTONDOWN) {
		bright -= 10;
	}
	else {
		return;
	}
	dst = src + bright;
	imshow("dst", dst);
}
int main() {
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	dst = src.clone();
	namedWindow("dst");
	setMouseCallback("dst", onMouse);
	imread("dst",dst);
	waitKey();
}
