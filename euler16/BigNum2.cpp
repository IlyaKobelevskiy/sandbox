#include "BigNum2.h"
//stl
#include <stdlib.h>     /* atoi */

BigNum2::BigNum2()
	: numbers(1,0)
{
}

BigNum2::BigNum2(const std::string &input)
{
	for(size_t i=0;i<input.size();i+=9)
	{
		char buff[10]={0,0,0,0,0,0,0,0,0,0};
		for(size_t k=i;k<std::min(input.size(),i+9);++k)
			buff[k-i]=input[k];
		int num = atoi(buff);
		numbers.push_back(num);
	}
}

BigNum2 operator + (const BigNum2 &left, const BigNum2 &right)
{
	BigNum2 output;
	int carryOver(0);
	output.numbers.resize(std::max(left.numbers.size(),right.numbers.size())+1,0);
	for(int i=0;i<std::max(left.numbers.size(),right.numbers.size());++i)
	{
		int temp = carryOver;
		carryOver=0;
		if(i<left.numbers.size())
			temp+=left.numbers[i];
		if(i<right.numbers.size())
			temp+=right.numbers[i];
		while(temp>BigNum2::MAX_UNIT_VAL)
		{
			temp -= BigNum2::MAX_UNIT_VAL;
			carryOver += 1;
		}
		output.numbers[i]=temp;
	}

	if(carryOver !=0)
		output.numbers.back()=carryOver;


	return output;
}

BigNum2 operator * (const BigNum2 &left, const BigNum2 &right)
{
	return BigNum2("0");
}

BigNum2 operator * (const BigNum2 &left, const short &mult)
{
	return BigNum2();
}


long long BigNum2::sumOfDigits()
{
	long long output(0);
	for(int p :numbers)
	{
		while(p>0)
		{
			output+=p%10;
			p=p/10;
		}
	}
	return output;
}
