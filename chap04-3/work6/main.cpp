#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.bmp");
	if (src.empty()) return -1;

	string text = "Hello, Lenna";
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double fontScale = 1.5;
	int thickness = 2;

	int baseline = 0;
	Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseline);
	Point org((src.cols - textSize.width) / 2, textSize.height + 30);

	putText(src, text, org, fontFace, fontScale, Scalar(0, 255, 255), thickness, LINE_AA);

	imshow("image", src);
	waitKey(0);
	return 0;
}
