//stl
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
//own
#include "../euler13/BigNum.h"
#include "../euler13/ScopedTimer.h"

using namespace std;

const int UPPER_LIMIT = 2*1000*1000;
bool isPrime(int k,const std::vector<int> primesToCheck)
{
	for(size_t i=0;i<primesToCheck.size();++i)
		if(k%primesToCheck[i]==0)
			return false;
	return true;
}

void grabNextPrime(std::set<int> &searchSpace, std::vector<int> &primes, int &sum)
{
	int prime = *searchSpace.begin();
	primes.push_back(prime);
	sum+=prime;
	for(int k=prime;k<=UPPER_LIMIT;k+=prime)
		searchSpace.erase(k);
}

int getSumOfDigits(int power)
{
	int num(1<<power);
	int sum(0);
	while(num>0)
	{
		sum+=num%10;
		num=num/10;
	}
	return sum;
}

int main(int argc, char* argv[])
{
	ScopedTimer timer;

	//euler9
	{
		const int val =1000*1000/2;
		for(int a=1; (val-1000*a)>0;++a)
		{
			if((val-1000*a) % (1000-a) != 0)
				continue;

			int b = (val-1000*a)/(1000-a);
			int c = (1000-a-b);

			if(c<=0)
				continue;

			int prod = a*b*c;
			std::cout << "Product is "<<prod<<"="<<a<<"x"<<b<<"x"<<c<<endl;
			std::cout << "a2+b2="<<a*a+b*b<<"while c2 = "<<c*c<<endl;
			break;
		}
	}

	//euler10
	//{
	//	ScopedTimer timer;
	//	long sum(0);
	//	std::vector<int> primes;
	//	for(int k=2;k<UPPER_LIMIT;++k)
	//	{
	//		if(!isPrime(k,primes))
	//			continue;
	//		primes.push_back(k);
	//		sum+=k;
	//	}
	//	cout << "Euler 10 answer is "<<sum<<std::endl;
	//}

	//{
	//	ScopedTimer timer;
	//	std::set<int> searchSpace;
	//	std::vector<int> primes;
	//	for(int i = 2;i<=UPPER_LIMIT;++i)
	//		searchSpace.insert(i);
	//	int sum(0);
	//	while(!searchSpace.empty())
	//		grabNextPrime(searchSpace,primes,sum);
	//	cout << "Discovered "<<primes.size() << " prime numbers" <<endl;
	//	cout << "First five are : ";
	//	for(int i=0;i<5;++i)
	//		cout << primes[i] << " ";
	//	cout << "\nLast five are : ";
	//	for(int i=primes.size()-5;i<primes.size();++i)
	//		cout << primes[i] << " ";
	//	long long sum1(0);
	//	for(auto &p:primes)
	//		sum1+=p;
	//	cout << "\nEuler 10 answer is "<<sum<<" "<<sum1<<std::endl;
	//}

	//euler 16
	{
		BigNum num("2");
		for(int i=1;i<1000;++i)
			num*=2;
		std::cout << "Sum is "<<num.getSumOfDigits()<<endl;
		//for(int i=1;i<20;++i)
		//{
		//	num*=2;
		//	cout << "Number is "<<num<<", sum of digits is "<<num.getSumOfDigits()<<endl;
		//}
		//for(int i=1;i<20;++i)
		//{
		//	int sum = getSumOfDigits(i);
		//	std::cout << "For i="<<i<<", sum is "<<sum<<endl;
		//}
	}

	//euler20
	{
		BigNum num("1");
		for(int i=1;i<=100;++i)
			num*=i;
		std::cout << num.getSumOfDigits() << std::endl;
	}

	//euler19
	{

	}
	return 0;
}

