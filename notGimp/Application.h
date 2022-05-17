#pragma once
#include "opencv2/opencv.hpp"
namespace ngp {
	class Application
	{
	public:
		Application();
		void Run();
		int ReadFile();
	private:
		cv::Mat s_Mat;
	};
}
