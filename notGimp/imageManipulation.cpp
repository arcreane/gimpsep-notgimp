#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "filters.h"
void ngp::filters::resize(cv::Mat& srcfile, int width, int height, int interpolation = 1) {
	int interpolation_type = 0;
	if(interpolation == 0) { interpolation_type = cv::INTER_NEAREST; }
	else if (interpolation == 1) {interpolation_type = cv::INTER_LINEAR; }
	else if (interpolation == 2) { interpolation_type = cv::INTER_AREA; }
	else if (interpolation == 3) { interpolation_type = cv::INTER_CUBIC; }
	else if (interpolation == 4) { interpolation_type = cv::INTER_LANCZOS4; }
	cv::resize(srcfile, srcfile, cv::Size(width, height), 0.0, 0.0, interpolation_type );

}