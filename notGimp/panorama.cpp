#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>
#include "filters.h"

void ngp::filters::panorama(cv::Mat& srcfile, std::vector<cv::Mat>& srcfiles){
	cv::Stitcher::Mode mode = cv::Stitcher::Mode::PANORAMA;

	cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(mode);
	cv::Stitcher::Status status = stitcher->stitch(srcfiles, srcfile);
	 if (status != cv::Stitcher::OK)
    {
        std::cout << "Can't stitch images , status:\n" << status << "make sure images overlap sufficently (meaning a lot!!)";
        return;
    }
	 
	 
}
