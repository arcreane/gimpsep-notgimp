#pragma once
#include "opencv2/opencv.hpp"
namespace ngp {

	class Application
	{
	public:
		Application();
		void Run();


	private:
		cv::Mat s_Mat;
		int ReadFile();
		int parseCommand(std::vector<std::string> args);
		int askForFunction();
	};


}
