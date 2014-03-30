#include "ScopedTimer.h"
//stl
#include <iostream>

ScopedTimer::ScopedTimer()
	: startTime(std::chrono::high_resolution_clock::now())
{
}

ScopedTimer::~ScopedTimer()
{
	auto endTime = std::chrono::high_resolution_clock::now();
	std::cout << "\n" << std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime).count() 
		<< "\tmilliseconds"
		<< std::endl;
	::getchar();
}