#include "stdafx.h"
#include "opencv2\opencv.hpp"

using namespace cv;

int main(int argc, char** argv)
{
	Mat img;
	cv::namedWindow("hi");
	img = cv::imread("C:\\Users\\11235\\Pictures\\Camera Roll\\IMG_20170915_171544.jpg");
	cv::imshow("hi",img);
	cv::waitKey(0);

	return 0;
}
