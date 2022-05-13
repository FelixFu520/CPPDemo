#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main_opencv02(int argc, char** argv) {
	Mat src = imread("opencv_pic/lena.jpg", IMREAD_UNCHANGED);
	namedWindow("opencv src", WINDOW_AUTOSIZE);
	cv::imshow("opencv src", src);

	namedWindow("output window", WINDOW_AUTOSIZE);
	Mat output_image;
	cv::cvtColor(src, output_image,COLOR_BGR2HLS);
	cv::imshow("output window", output_image);

	imwrite("D:/lena.png", output_image);
	waitKey(0);
	destroyAllWindows();
	return 0;
}