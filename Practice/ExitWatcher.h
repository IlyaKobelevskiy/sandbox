#pragma once
#include <vector>
#include <chrono>

class ExitWatcher
{
public:
	ExitWatcher(const std::vector<int> *dataIn, const std::string &nameIn, bool printDataIn = false);
	~ExitWatcher();
private:
	bool								  printData;
	const std::string				      name;
	const std::vector<int>				  *data;
	std::chrono::system_clock::time_point startTime;
};