//stl
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//own
#include "BigNum.h"
#include "ScopedTimer.h"

int main(int argc, char* argv[])
{
	ScopedTimer timer;

	std::ifstream inputStream("input.txt");
	if(!inputStream)
	{
		std::cout << "Cannot open input file" <<std::endl;
		return 0;
	}

	std::vector<BigNum> numbers;
	while(inputStream)
	{
		std::string temp;
		inputStream >> temp;
		if(!inputStream)
			break;
		numbers.push_back(BigNum(temp));
	}
	std::cout << "Read "<<numbers.size()<<" numbers "<<std::endl;

	BigNum sum(std::string("0"));
	for(const BigNum &num : numbers)
	{
		//std::cout << "================================" << std::endl;
		//std::cout << num;
		//std::cout << sum;
		sum+=num;
/*		std::cout << sum;
		std::cout << "================================" <<std::endl;	*/	
	}

	std::ofstream outStream("output.txt");
	outStream << sum;
	return 0;
}

