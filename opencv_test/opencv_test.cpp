#include "stdafx.h"
//将opencv中所有的模块都加载进去了，所以不用单独添加其他模块



int main(int, char**)
{
	Mat img;
	cv::namedWindow("hi",WINDOW_NORMAL);
	img=cv::imread("C:\\Users\\11235\\Pictures\\Camera Roll\\IMG_20170915_171544.jpg");
	cv::imshow( "hi",img );
	cv::waitKey();
	return 0;
}