#include <opencv2/core/core.hpp> 
#include <opencv2/imgcodecs.hpp> 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main_04_2(int argc, char** args) {
	Mat image = imread("opencv_pic/test.jpg", IMREAD_COLOR);
	if (image.empty()) {
		cout << "could not find the image resource..." << std::endl;
		return -1;
	}

	Mat grayImg;
	Mat dst;
	Mat dst1;
	dst.create(image.size(), image.type());
	cvtColor(image, grayImg, COLOR_BGR2GRAY);
	int height = image.rows;
	int width = image.cols;
	int channels = image.channels();
	printf("height=%d width=%d channels=%d", height, width, channels);
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (channels == 3) {
				int b = image.at<Vec3b>(row, col)[0];
				int g = image.at<Vec3b>(row, col)[1];
				int r = image.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = 255 - b;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - r;
			}
			else if (channels == 1) {
				int gray = grayImg.at<uchar>(row, col);
				grayImg.at<uchar>(row, col) = 255 - gray;
			}
		}
	}
	bitwise_not(image, dst1); // 同上功能一样
	namedWindow("My Image", WINDOW_AUTOSIZE);
	imshow("My Image", dst);
	namedWindow("My Image1", WINDOW_AUTOSIZE);
	imshow("My Image1", dst1);
	waitKey(0);
	return 0;
}