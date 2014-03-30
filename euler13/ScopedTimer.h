#pragma once
#include <vector>
#include <chrono>

class ScopedTimer
{
public:
	ScopedTimer();
	~ScopedTimer();
private:
	std::chrono::system_clock::time_point startTime;
};