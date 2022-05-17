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
		std::vector<std::string> split(std::string s, std::string delimiter);
		int parseCommand(std::vector<std::string> args);
		int askForFunction();
		int parseInt(std::string toBeParsed);
	};


}
