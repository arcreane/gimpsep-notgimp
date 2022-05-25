#pragma once
#include <string>
#include <exception>
#include <vector>
#include <iostream>


namespace ngp{
	int parseInt(std::string toBeParsed);
	double parseDouble(std::string toBeParsed);
	std::vector<std::string> split(std::string s, std::string delimiter);
}