#pragma once
#include <string>

class BigNum
{
public:
	explicit BigNum(const std::string &num);

	void operator += (const BigNum &other);
	void operator *= (const BigNum &other);

	void operator *= (int  mult);
	long long getSumOfDigits() const;
	std::string getdata() const { return data;};

private:
	std::string data;
};

template <class OutputStream> 
	OutputStream &operator << (OutputStream &stream,const BigNum &num)
{
	stream << num.getdata().c_str() << std::endl;
	return stream;
}