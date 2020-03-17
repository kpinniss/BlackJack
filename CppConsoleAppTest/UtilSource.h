#pragma once
#include <iostream>
#include <string>
#include <array>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>
#include <string>
class UtilSource
{
public:
	UtilSource();
	~UtilSource();

	void print(std::string str)
	{
		std::cout << str << std::endl;
	};
	std::string getInput()
	{
		std::string input;
		std::cin >> input;
		return input;
	};
	void cLog(std::string str)
	{
		print("Debug : " + str);
	};

	int sum(int nums[]) {
		int total = 0;
		for (int i{ 0 }; i < sizeof(nums); ++i)
		{
			total = total + nums[i];
		}
		return total;
	};

	std::string toStr(int val)
	{
		return std::to_string(val);
	}
	std::string toStr(double val)
	{
		return std::to_string(val);
	}

	int toInt(std::string val)
	{
		int number_value = std::atoi(val.c_str());
		return number_value;
	}
};

