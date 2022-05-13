#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main_02(int argc, char** argv) {
	Mat src, dst, dst2;
	src = imread("opencv_pic/test.jpg", IMREAD_UNCHANGED);
	if (!src.data) {
		std::cout << "NO IMAGE" << std::endl;
		return -1;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);
	
	// 自己实现掩膜
	int cols = (src.cols - 1) * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;

	dst = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < (rows - 1); row++) {
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* current = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
		}
	}
	namedWindow("contrast image demo", WINDOW_AUTOSIZE);
	imshow("contrast image demo", dst);

	// 官方实现
	double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst2, src.depth(), kernel);
	double timeconsume = (getTickCount() - t) / getTickFrequency();
	printf("tim consume %.4f\n", timeconsume);

	namedWindow("contrast2 image demo", WINDOW_AUTOSIZE);
	imshow("contrast2 image demo", dst2);

	waitKey(0);
	return 0;
}