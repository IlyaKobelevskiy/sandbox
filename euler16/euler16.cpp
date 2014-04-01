#include "../euler13/ScopedTimer.h"
//stl
#include <array>
#include <iostream>
//own
#include "BigNum2.h"

typedef unsigned long long int nat;
using namespace std;
#include <deque>
#include <set>
#include <iostream>

vector<nat> gensqsq(nat lim)
{
    vector<nat> sqsq;
    for(nat i=1;i*i <= lim;++i)
        sqsq.push_back(i*i);
    return sqsq;
}

bool ispalindromic( nat n )
{
    if( n >= 10 && n % 10 == 0 )
        return false;
    deque<int> d;
    while( n )
    {
        d.push_front( n % 10 );
        n /= 10;
    }
    for( int i=0, j=d.size()-1; i <= j; ++i, --j )
    {
        if( d[i] != d[j] )
            return false;
    }
    return true;
}

nat pe125()
{
    set<nat> s;
    nat limit = 100000000;
    nat total = 0;

    vector<nat> sq = gensqsq(limit);

    for( nat from = 0; from < sq.size(); ++from)
    {
        nat seqsum = 0;
        for(nat to=from; to < sq.size(); ++to )
        {
            seqsum += sq[(unsigned int )to];
            if( to == from )
                continue;
            if( seqsum >= limit )
                break;
            if( ispalindromic( seqsum ) )
                s.insert( seqsum );
        }
    }
    for( set<nat>::iterator itr = s.begin(); itr != s.end(); ++itr )
        total += *itr;
    std::cout << "Sum is "<<total <<", number count is "<<s.size()<<std::endl;
    return total;
}


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

