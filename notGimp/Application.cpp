#include "Application.h"
#include "opencv2/opencv.hpp"

ngp::Application::Application() {
	cv::Mat frame = cv::Mat::zeros(100, 100, 0);
	//Init event handlers
	imshow("notGimp", frame);
}

void ngp::Application::Run() {
	cv::waitKey(0);
}
