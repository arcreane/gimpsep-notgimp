#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "filters.h"


	void saturation(cv::Mat &srcfile, int value) {
	}

	void value(cv::Mat& srcfile, int value) {

	}

	void hue(cv::Mat& srcfile, int value) {

	}

	void ngp::filters::brightness(cv::Mat& srcfile, int value) {
		srcfile.convertTo(srcfile, -1, 1.0, value);
	}

	void ngp::filters::contrast(cv::Mat& srcfile, double value) {
		srcfile.convertTo(srcfile, -1, value, 0);
	}

	void perHueManipulation(cv::Mat& srcfile, int value) {

	}