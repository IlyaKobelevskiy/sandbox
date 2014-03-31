#include "../euler13/ScopedTimer.h"
//stl
#include <array>
#include <iostream>
//own
#include "BigNum2.h"

int main(int argc, char* argv)
{
	ScopedTimer timer;

	{
		int sundayCount(0);
		int currentDay(0); //1 Jan 1901 - monday

		std::array<int,12> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
		//iterate through years
		for(int year=1901;year<2001;++year)
		{
			for(size_t month=0;month<daysInMonth.size();++month)
			{
				currentDay+= (month==1 && year % 4 ==0 && year != 2000) ? daysInMonth[month]+1 : daysInMonth[month];
				if(currentDay % 7 == 0)
					++sundayCount;
			}
		}
		std::cout << "Euler19 answer is "<<sundayCount<<std::endl;
	}

	BigNum2 test1("1111111111111111111");
	BigNum2 test2("0000000000000000090");
	std::cout << test1 << " + "<<test2 << " = "<<(test1+test2)<<std::endl;
	return 0;
}

