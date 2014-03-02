#include "SortingPractice.h"
//stl
#include <algorithm> 
//own
#include "ExitWatcher.h"

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
	//mergeSortRecursive(input,0,input.size());
	mergeSortRecursive(input.begin(),input.end());
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

void quickSort(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"quickSort");
	quickSort(input.begin(),input.end());
}

//known implementation wrappers
void stl_sort(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"std::sort");
	std::sort(input.begin(),input.end());
}
