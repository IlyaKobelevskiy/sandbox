//stl
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//own
#include "../euler13/ScopedTimer.h"

int greatestProductBruteForce(const std::string &num);
bool isPalindrom(int num)
{
	char buff[7] = {0,0,0,0,0,0,0}; //max is 998001
	::_itoa(num,buff,10);
	std::string temp(buff);
	for(size_t i=0;i<temp.size()/2;++i)
		if(temp[i]!=temp[temp.size()-i-1])
			return false;
	return true;
}

bool isPrime(int k,const std::vector<int> primesToCheck)
{
	for(size_t i=0;i<primesToCheck.size();++i)
		if(k%primesToCheck[i]==0)
			return false;
	return true;
}

int main(int argc, char* argv[])
{
	ScopedTimer timer;

	std::ifstream inputStream("input.txt");
	if(!inputStream)
	{
		std::cout << "Cannot open input file" <<std::endl;
		return 0;
	}
	std::string num;
	while(inputStream)
	{
		std::string temp;
		inputStream >> temp;
		if(!inputStream)
			break;
		num.append(temp);
	}
	std::cout << "Input is "<<num.c_str() <<std::endl;
	std::cout << "Greatest product is "<< greatestProductBruteForce(num) <<std::endl;

	//euler1
	{
		int sum=0;
		for(int i=0;i<1000;i+=3)
			sum+=i;
		for(int i=0;i<1000;i+=5)
			sum+=i;
		for(int i=0;i<1000;i+=15)
			sum-=i;
		std::cout << "Euler 1 solution is "<<sum<<std::endl;
	}

	//euler2
	{
		int num1(1),num2(2),sum(2);
		int count(0);
		while(num1<4000000)
		{
			//update number
			int temp=num1+num2;
			num1=num2;
			num2=temp;

			++count;
			if(count==3)
			{
				count=0;
				if(num2<4000000)
					sum+=num2;
				else
					break;
			}
		}
		std::cout << "Euler 2 solution is "<<sum <<std::endl;
	}

	//euler3
	{
		long long num(600851475143);
		int maxPrime(1);
		for(int i=2;i<=num;++i)
		{
			if(num % i != 0)
				continue;
			num = num/i;
			maxPrime = std::max(maxPrime,i);
			i=2;
		}
		std::cout << "Euler 3 solution is "<<maxPrime<<std::endl;
	}

	//euler6
	{
		long res(0);
		for(int n=1;n<100;++n)
		{
			int innerSum(0);
			for(int k=n+1;k<101;++k)
				innerSum+=k;
			res+=n*innerSum;
		}
		res*=2;
		std::cout << "euler 6 solution is "<<res <<std::endl;
	}

	//euler4
	{
		int num1(999),num2(999);
		int maxPalindrom(0);
		while(num1>=100 && num2>=100)
		{
			int prod = num1*num2;
			if(isPalindrom(prod))
			{
				//std::cout << "Palindrom is "<<prod<<", which is "<<num1 << "x" <<num2 << std::endl;
				maxPalindrom=std::max(maxPalindrom,prod);
				//break;
			}
			//if(prod == 906609)
			//	::getchar();

			if(num2>100)
			{
				num2--;
			}
			else
			{
				num1--;
				num2=num1;	
			}
		}
		std::cout << "Euler 4 answer is "<<maxPalindrom<<std::endl;
	}

	//euler7
	{
		int k(2);
		std::vector<int> primes;
		for( ; primes.size()<10001;++k)
		{
			if(isPrime(k,primes))
				primes.push_back(k);
		}
		std::cout << "Euler 7 answer is "<<primes.back()<<std::endl;
	}

	return 0;
}

int greatestProductBruteForce(const std::string &num)
{
	int output(0);
	const char zero = '0';
	for(size_t i=0;i<num.size()-4;++i)
	{
		int prod = (num[i]-zero)*(num[i+1]-zero)*(num[i+2]-zero)*(num[i+3]-zero)*(num[i+4]-zero);
		output = std::max(output,prod);
	}
	return output;
}