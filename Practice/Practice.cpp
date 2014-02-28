#include <vector>
#include <iostream>

void insertionSort(std::vector<int> &input);
void selectionSort(std::vector<int> &input);
void mergeSort(std::vector<int> &input);

class ExitWatcher
{
public:
	ExitWatcher(const std::vector<int> *dataIn)
		: data(dataIn)
	{
		std::cout << "Input :";
		for(auto p: *data)
			std::cout << p << " ";
		std::cout << std::endl;
	}
	~ExitWatcher()
	{
		std::cout << "Output :";
		for(auto p: *data)
			std::cout << p << " ";
		std::cout << std::endl;
#ifndef __linux__
		std::cout << "Done, press any key..." << std::endl;
		::getchar();
#endif
	}
private:
	const std::vector<int> *data;
};

int main(int argc, char* argv[])
{
	std::vector<int> input(6);
	input[0]=31;
	input[1]=41;
	input[2]=59;
	input[3]=26;
	input[4]=41;
	input[5]=58;
	//insertionSort(input);
	//selectionSort(input);
	mergeSort(input);

	return 0;
}

void insertionSort(std::vector<int> &input)
{
	ExitWatcher watcher(&input);
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
	ExitWatcher watcher(&input);
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
void mergeSort(std::vector<int> &input, size_t l, size_t r)
{
	if(l<(r-1))
	{
		auto q = (l+r)/2;
		mergeSort(input,l,q);
		mergeSort(input,q,r);
		merge(input,l,q,r);
	}
}
void mergeSort(std::vector<int> &input)
{
	ExitWatcher watcher(&input);
	mergeSort(input,0,input.size());
}