#include "BigNum.h"

BigNum::BigNum(const std::string &dataIn)
	: data(dataIn)
{
	int a=1;
}

void BigNum::operator += (const BigNum &other)
{
	const char zero = '0';
	std::string sum;
	char carryOver(0);

	std::string num1(data);
	std::string num2(other.data);

	if(num1.size() > num2.size())
	{
		int padSize = num1.size()-num2.size();
		std::string pad(padSize,'0');
		num2 = pad + num2;
	}
	else if(num2.size() > num1.size())
	{
		int padSize = num2.size()-num1.size();
		std::string pad(padSize,'0');
		num1 = pad+num1;
	}

	for(int i=num1.size()-1;i>=0;--i)
	{
		char digit(carryOver);
		digit+=num1[i]-zero;
		digit+=num2[i]-zero;
		carryOver = 0;
		while(digit>=10)
		{
			digit -= 10;
			carryOver += 1;
		}
		sum.push_back(digit+zero);
	}

	if(carryOver != 0)
		sum.push_back(carryOver+zero);

	//invert sum
	data.clear();
	data.resize(sum.size());
	for(size_t i=0;i<sum.size();++i)
		data[i]=sum[sum.size()-i-1];
	//data=sum;
}

void BigNum::operator *= (const BigNum &other)
{

}

void BigNum::operator *= (int  mult)
{
	const char zero = '0';
	std::string output;
	char carryOver(0);
	for(int i=data.size()-1;i>=0;--i)
	{
		char digit = data[i]-zero;
		digit*=mult;
		int tempCarryOver(carryOver);
		carryOver=0;
		while(digit>=10)
		{
			digit -= 10;
			carryOver += 1;
		}
		output = std::string(1,digit+tempCarryOver+zero)+output;
	}
	if(carryOver!=0)
		output = std::string(1,carryOver+zero)+output;

	//invert sum
	data=output;
}

long long BigNum::getSumOfDigits() const
{
	long long sum(0);
	const char zero = '0';
	for(size_t i=0;i<data.size();++i)
		sum+=data[i]-zero;
	return sum;
}