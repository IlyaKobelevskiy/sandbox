//stl
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
//own
#include "ExitWatcher.h"

//input generators
std::vector<int> generate_input(std::vector<int>::size_type n,int minVal, int maxVal)
{
	std::vector<int> output(n,0);
	for(auto &p : output)
	{
		p = minVal + (maxVal-minVal)*std::rand()/RAND_MAX;
	}
	return output;
}

//known implementation wrappers
void stl_sort(std::vector<int> &input);

//own
void insertionSort(std::vector<int> &input);
void selectionSort(std::vector<int> &input);
void mergeSortRecursive(std::vector<int> &input);
void mergeSortIterative(std::vector<int> &input);
void quickSort(std::vector<int> &input);

template <class Iterator> inline
void insertBefore(Iterator start, Iterator end)
{
	auto valueToBeInserted = *end;
	//shift right all items starting at insertion position up to the value to be inserted
	for(Iterator it = end; it != start; *it = *(it--))
	{
	}
	*start = valueToBeInserted;
}

int main(int argc, char* argv[])
{
	std::vector<int> input = generate_input(100000,0,100);

	std::vector<std::function<void(std::vector<int>&)> > functors;
	functors.push_back(&stl_sort);
	functors.push_back(&quickSort);
	functors.push_back(&mergeSortIterative);
	functors.push_back(&mergeSortRecursive);
	functors.push_back(&insertionSort);
	functors.push_back(&selectionSort);

	//{
	//	std::vector<int> data(input);
	//	{
	//		ExitWatcher watcher(&data,"test",true);
	//		insertBefore(data.begin(),data.begin()+5);
	//	}
	//}
	
	for(auto f : functors)
	{
		//create copy of input
		std::vector<int> data(input);
		f(data);
	}

#ifndef __linux__
	std::cout << "Done, press any key..." << std::endl;
	::getchar();
#endif
	return 0;
}

void insertionSort(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"insertionSort");
	for(auto j=0;j<input.size();++j)
	{
		auto currElem = input[j];
		//find position where to insert current element - it is ii
		auto insertionPos(0);
		for(;insertionPos<j && currElem>input[insertionPos];++insertionPos)
		{
		}

		//shift elements between ii and j one left
		for(auto ii=j;ii>insertionPos;--ii)
		{
			input[ii]=input[ii-1];
		}
		input[insertionPos]=currElem;
	}
}

void selectionSort(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"selectionSort");
	for(size_t i=0;i<(input.size()-1);++i)
	{
		int minIdx(i);
		//find minimal index in [i..end]
		for(size_t j=i;j<input.size();++j)
		{
			if(input[j]<input[minIdx])
				minIdx=j;
		}
		//swap
		int temp=input[i];
		input[i]=input[minIdx];
		input[minIdx]=temp;
	}
}

template <class Iterator> inline
void merge(Iterator start1Idx,Iterator start2Idx, Iterator endIdx)
{
	//Check if input is valid
	if((endIdx-start1Idx) <=1 || (endIdx - start2Idx) <=0 || (start2Idx - start1Idx) <=0 )
		return;

	//Iterate through left array, for each element compare it with right array, 
	Iterator rightPos(start2Idx);
	int shiftCount(0);
	for(Iterator iter = start1Idx; iter != (start2Idx+shiftCount);++iter)
	{
		///if current item in left array greater then item in right array, insert right item before current item
		while( rightPos < endIdx && *iter > *rightPos)
		{
			insertBefore(iter,rightPos);
			++iter;
			++rightPos;
			++shiftCount;
		}
	}
}
void merge(std::vector<int> &data, size_t start1Idx,size_t start2Idx, size_t endIdx)
{
	//temp arrrays
	std::vector<int> left(data.begin()+start1Idx,data.begin()+start2Idx);
	std::vector<int> right(data.begin()+start2Idx,data.begin()+endIdx);
	auto rightPos(0);
	auto dataPos(start1Idx);
	for(auto p: left)
	{
		while(rightPos < right.size() && right[rightPos]<p)
		{
			data[dataPos++]=right[rightPos++];
		}
		data[dataPos++]=p;
	}
}
void mergeSortRecursive(std::vector<int> &input, size_t l, size_t r)
{
	if(l<(r-1))
	{
		auto q = (l+r)/2;
		mergeSortRecursive(input,l,q);
		mergeSortRecursive(input,q,r);
		merge(input,l,q,r);
	}
}
void mergeSortRecursive(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"mergeSortRecursive");
	mergeSortRecursive(input,0,input.size());
}

void mergeSortIterative(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"mergeSortIterative");
	size_t intervalSize(1);
	while(intervalSize<input.size())
	{
		auto count(0);
		for(std::vector<int>::iterator it=input.begin();count<input.size()/*-2*intervalSize*/;it+=2*intervalSize , count += 2*intervalSize)
		{
			merge(it,std::min(it+intervalSize,input.end()),std::min(it+2*intervalSize,input.end()));
		}
		intervalSize*=2;
	}
}

template <class Iterator> inline
void quickSort(Iterator begin,Iterator end);
void quickSort(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"quickSort");
	quickSort(input.begin(),input.end());
}
template <class Iterator> inline
void quickSort(Iterator begin, Iterator end)
{
	size_t inputSize = end-begin;
	if(inputSize <=1)
		return;

	Iterator pivotPos = begin+inputSize/2;
	auto pivotVal = *pivotPos;

	//move pivot to the end
	*pivotPos = *(end-1);
	*(end-1) = pivotVal;

	for(Iterator iter = begin; iter < (end-1); ++iter)
	{
		//if greater then pivot, move to the end, shifting remaining array left (insert behind pivot)
		if(*iter > pivotVal)
		{
			auto currVal = *iter;
			for(Iterator iter2 = (end-1); iter2 != iter; )
			{
				*iter2=*(iter2--);
			}
			*(end-1) = currVal;
		}
	}
	//recursively call self
	quickSort(begin,pivotPos);
	quickSort(pivotPos,end);
}

//known implementation wrappers
void stl_sort(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"std::sort");
	std::sort(input.begin(),input.end());
}
