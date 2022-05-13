//opencv_demo.cpp
#pragma once
#include<opencv2/opencv.hpp>
using namespace cv;

int main_opencv_demo1(int argc, char *argv[]) {
	cv::Mat img = imread("lena.jpg");
	imshow("lena", img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
