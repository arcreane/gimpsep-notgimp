#include "Application.h"
#include "opencv2/opencv.hpp"
#include "filters.h"
#include "Utils.h"
#include <future>


namespace ngp {

	const std::string WRONG_ARG_COUNT = "Wrong argument count given, see manual for correct command use";

	const int MILLIS_UNTIL_NEXT_INPUT_CHECK = 25;

	const char* MANUAL =
		"Available functions:\n"
		"man : shows this manual\n"
		"exit : closes the application\n"
		"erode <distance> <erosion type [0-2]> : expands dark areas\n"
		"dilate <distance> <dilate type [0-2]> : expands bright areas\n"
		"resize <new width> <new height> <interpolation type [0-4]> : resize the image to the width and height selected (number of pixels)\n"
		"brightness <value> : linearly change brightness\n"
		"contrast <value> : linearly change contrast\n"
		"panorama <path list> : stitch this image and others provided they overlap sufficiently (enter one absolute path per image)\n"
		"canny <minimum threshold value [0-100]>: detects edges of the image\n"
		"\n";


	Application::Application() {
		cv::Mat s_Mat;
		//TODO Init event handlers
	}

	void Application::Run() {
		while (openFile());
		while (askForFunction());
	}


	int Application::openFile() {
		std::cout << "Please provide an absolute link to an image" << std::endl;
		std::string input;
		std::getline(std::cin, input);

		return readFile(s_Mat, input);
	}

	int Application::readFile(cv::Mat& matrix, std::string path) {
		try {
			std::string image_path = cv::samples::findFile(path);
			matrix = cv::imread(image_path, cv::IMREAD_COLOR);
			std::cout << "Image opened at : " << image_path << std::endl;
		}
		catch (cv::Exception) {
			std::cout << "Could not read the image with path: " << path << " please provide valid link" << std::endl;
			return 1;
		}
		return 0;
	}


	std::vector<cv::Mat> Application::readFiles(std::vector<std::string> args) {
		std::vector<cv::Mat> matrices = std::vector<cv::Mat>();
		matrices.push_back(s_Mat);
		for (int i = 1; i < args.size();++i)
		{
			auto matrix = cv::Mat();
			readFile(matrix, args[i]);
			matrices.push_back(matrix);
		}
		return matrices;
	}

	int Application::parseCommand(std::vector<std::string> args) {
		if (!args.size()) {
			std::cout << "No arguments were provided" << std::endl;
			return 1;
		}
		std::string funcName = args[0];
		size_t argCount = args.size();


		if (funcName == "erode" && argCount == 3) { filters::erode(s_Mat, parseInt(args[1]), parseInt(args[2])); }
		if (funcName == "dilate" && argCount == 3) { filters::dilate(s_Mat, parseInt(args[1]), parseInt(args[2])); }
		if (funcName == "resize" && argCount == 4) { filters::resize(s_Mat, parseInt(args[1]), parseInt(args[2]), parseInt(args[3])); }
		if (funcName == "brightness" && argCount == 2) { filters::brightness(s_Mat, parseInt(args[1])); }
		if (funcName == "contrast" && argCount == 2) { filters::contrast(s_Mat, parseDouble(args[1])); }
		if (funcName == "canny" && argCount == 2) { filters::contrast(s_Mat, parseInt(args[1])); }
		if (funcName == "panorama" && argCount > 1) {
			std::vector<cv::Mat> files = readFiles(args);
			filters::panorama(s_Mat, files);
		}
		if (funcName == "man" || funcName == "help") { std::cout << MANUAL << std::endl; }

		if (funcName == "exit") { return 0; }
		return 1;
	}

	
	int Application::askForFunction() {
		cv::imshow("Output", s_Mat);
		std::cout << ">>> ";

		auto futureParse = std::async(std::launch::async, [] {
			std::string input;
			std::getline(std::cin, input);
			return input;
			});

		while (!futureParse._Is_ready()) {
			cv::waitKey(MILLIS_UNTIL_NEXT_INPUT_CHECK);
		}
		std::string awaitedInput = futureParse.get();
		std::string delimiter = " ";
		std::vector<std::string> args = split(awaitedInput, delimiter);
		return parseCommand(args);
	}



}