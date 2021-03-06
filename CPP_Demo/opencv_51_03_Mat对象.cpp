#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main_cv03(int argc, char** argv) {
	Mat src;
	src = imread("opencv_pic/test.jpg");
	if (src.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat dst0;
	dst0 = Mat(src.size(), src.type());
	dst0 = Scalar(127, 0, 255);
	namedWindow("output0", WINDOW_AUTOSIZE);
	imshow("output0", dst0);

	Mat dst;
	src.copyTo(dst);
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output", dst);

	cvtColor(src, dst, COLOR_BGR2GRAY);
	printf("input image channels : %d\n", src.channels());
	printf("output image channels : %d\n", dst.channels());

	int cols = dst.cols;
	int rows = dst.rows;

	printf("rows : %d cols : %d\n", rows, cols);
	const uchar* firstRow = dst.ptr<uchar>(0);
	printf("fist pixel value : %d\n", *firstRow);

	Mat M(3, 3, CV_8UC1, Scalar(127));
	cout << "M =" << endl << M << endl;

	Mat m1;
	m1.create(src.size(), src.type());
	m1 = Scalar(0, 0, 255);

	Mat csrc;
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, csrc, -1, kernel);

	Mat m2 = Mat::eye(2, 2, CV_8UC1);
	cout << "m2 =" << endl << m2 << endl;

	imshow("output", m2);
	waitKey(0);
	return 0;
}