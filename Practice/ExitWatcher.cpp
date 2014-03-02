#include "ExitWatcher.h"
//stl
#include <iostream>
#include <algorithm>

ExitWatcher::ExitWatcher(const std::vector<int> *dataIn, const std::string &nameIn, bool printDataIn)
	: printData(printDataIn)
	, name(nameIn)
	, data(dataIn)
{
	if(printData)
	{
		std::cout << "Input :";
		for(auto p: *data)
			std::cout << p << " ";
		std::cout << std::endl;
	}

	startTime = std::chrono::high_resolution_clock::now();
}

ExitWatcher::~ExitWatcher()
{
	if(printData)
	{
		std::cout << "Output :";
		for(auto p: *data)
			std::cout << p << " ";
		std::cout << std::endl;
	}

	auto endTime = std::chrono::high_resolution_clock::now();
	std::cout << name.c_str() << "\t" 
		<< std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime).count() 
		<< "\tmilliseconds, is_sorted returns\t"
		<< std::is_sorted(data->cbegin(),data->cend())
		<< std::endl;
}