#pragma once
//stl
#include <vector>
#include <string>

class BigNum2
{
public:

	BigNum2();
	BigNum2(const std::string &input);

	friend BigNum2 operator + (const BigNum2 &left, const BigNum2 &right);
	friend BigNum2 operator * (const BigNum2 &left, const BigNum2 &right);

	friend BigNum2 operator * (const BigNum2 &left, const short &mult);

	long long sumOfDigits();

	template <class OutputStream> friend 
		OutputStream & operator << (OutputStream &,const BigNum2 &val);
private:
	std::vector<int>	numbers;

	static const int MAX_UNIT_VAL = static_cast<int>(1e9);
};

template <class OutputStream> inline 
	OutputStream & operator << (OutputStream &stream,const BigNum2 &val)
{
	for(const auto &num : val.numbers)
		stream << num;
	return stream;
}