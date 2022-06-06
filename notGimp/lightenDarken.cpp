#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "filters.h"

void ngp::filters::contrast(cv::Mat& srcfile, double contrastControl, int brightnessControl){

	if (contrastControl >= 1 && contrastControl <=3){ 
		std::cout << "Inserted value is greater than 3 or lower than 1, please provide valid value" << std::endl; 
	}
	
	else if  (brightnessControl>=0 && brightnessControl <=100){
		std::cout << "Inserted value is greater than 100 or lower than 0, please provide valid value" << std::endl; 
	}
	
	else {
		srcfile.convertTo(srcfile, -1, contrastControl, brightnessControl);
	}
}
