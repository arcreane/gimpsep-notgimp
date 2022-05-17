#pragma once
namespace ngp {
	namespace filters {
		void dilate(cv::Mat& srcfile, int dilation_size, int dilation_elem);
		void erode(cv::Mat& srcfile, int erosion_size, int erosion_elem);
	}
}