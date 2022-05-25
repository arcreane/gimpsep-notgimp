#include "Utils.h"

namespace ngp {



	int parseInt(std::string toBeParsed) {
		try {
			return stoi(toBeParsed);
		}
		catch (std::exception) {
			std::cout << " : Wrong parameter type provided" <<std::endl;
		}
		return 0;
	}

	double parseDouble(std::string toBeParsed) {
		try {
			return stod(toBeParsed);
		}
		catch (std::exception) {
			std::cout << "Wrong parameter type provided" << std::endl;
		}
		return 0.0;
	}

	std::vector<std::string> split(std::string s, std::string delimiter) {
		size_t pos_start = 0, pos_end, delim_len = delimiter.length();
		std::string token;
		std::vector<std::string> res;

		while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
			token = s.substr(pos_start, pos_end - pos_start);
			pos_start = pos_end + delim_len;
			res.push_back(token);
		}

		res.push_back(s.substr(pos_start));
		return res;
	}
}