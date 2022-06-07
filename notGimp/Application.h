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
		int openFile();
		int parseCommand(std::vector<std::string> args);
		int askForFunction();
		int readFile(cv::Mat& matrix, std::string path);
		std::vector<cv::Mat> readFiles(std::vector<std::string> args);
	};


}
