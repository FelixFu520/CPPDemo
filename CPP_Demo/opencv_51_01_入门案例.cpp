#include<opencv2\opencv.hpp>
#include<iostream>

using namespace cv;

int main_cv01(int argc, char** argv) {
	cv::Mat src = cv::imread("opencv_pic/lena.jpg");
	if (src.empty()) {
		std::cout << "could not load image" << std::endl;
		return -1;
	}
	//namedWindow("test opencv setup", CV_WINDOW_AUTOSIZE);
	cv::imshow("test opencv setup", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}