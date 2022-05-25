#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "filters.h"


int const MAX_KERNEL_SIZE = 21;



void ngp::filters::dilate(cv::Mat& srcfile, int dilation_size, int dilation_elem = 0) {
	int dilation_type = 0;
	if (dilation_elem == 0) { dilation_type = cv::MORPH_RECT; }
	else if (dilation_elem == 1) { dilation_type = cv::MORPH_CROSS; }
	else if (dilation_elem == 2) { dilation_type = cv::MORPH_ELLIPSE; }

	int kernelSize = std::min(MAX_KERNEL_SIZE, std::max(0, dilation_size));

	cv::Mat element = cv::getStructuringElement(dilation_type,
		cv::Size(2 * kernelSize + 1, 2 * kernelSize + 1),
		cv::Point(kernelSize, kernelSize));

	/// Apply the dilation operation
	dilate(srcfile, srcfile, element);

}

void ngp::filters::erode(cv::Mat& srcfile, int erosion_size,int erosion_elem = 0) {

	int erosion_type = 0;
	if (erosion_elem == 0) { erosion_type = cv::MORPH_RECT; }
	else if (erosion_elem == 1) { erosion_type = cv::MORPH_CROSS; }
	else if (erosion_elem == 2) { erosion_type = cv::MORPH_ELLIPSE; }

	int kernelSize = std::min(MAX_KERNEL_SIZE, std::max(0, erosion_size));

	cv::Mat element = cv::getStructuringElement(erosion_type,
		cv::Size(2 * kernelSize + 1, 2 * kernelSize + 1),
		cv::Point(kernelSize, kernelSize));

	/// Apply the erosion operation
	erode(srcfile, srcfile, element);

}
