#pragma once

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

template <class InputIterator> inline 
void mergeSortRecursive(InputIterator begin, InputIterator end)
{
	if(end-begin > 1)
	{
		auto q = (end-begin)/2;
		mergeSortRecursive(begin,begin+q);
		mergeSortRecursive(begin+q,end);
		merge(begin,begin+q,end);
	}
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