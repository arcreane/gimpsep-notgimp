#include "Application.h"
#include "opencv2/opencv.hpp"

ngp::Application::Application() {
	s_Mat = cv::Mat::zeros(100, 100, 0);
	//Init event handlers
	cv::imshow("notGimp", s_Mat);
}

void ngp::Application::Run() {
	while (ReadFile());
	
	//stop
	while (1) {
		cv::imshow("notGimp", s_Mat);
		char c = (char)cv::waitKey(25);
		if (c == 27) break;
	}
}


int ngp::Application::ReadFile() {
	std::string input;
	std::getline(std::cin, input);
	try {
		std::string image_path = cv::samples::findFile(input);
		s_Mat = cv::imread(image_path, cv::IMREAD_COLOR);
		std::cout << "Image opened at" << image_path << std::endl;
	} catch (cv::Exception){
		std::cout << "Could not read the image: " << input << " please provide valid link" << std::endl;
		return 1;
	}

	return 0;
}