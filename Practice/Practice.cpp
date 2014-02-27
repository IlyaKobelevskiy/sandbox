#include <vector>
#include <iostream>

void insertionSort(std::vector<int> &input);
void selectionSort(std::vector<int> &input);

class ExitWatcher
{
#ifndef __linux__
public:
    ~ExitWatcher()
    {
        std::cout << "Done, press any key..." << std::endl;
        ::getchar();
    }
#endif
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
	selectionSort(input);

	return 0;
}

void insertionSort(std::vector<int> &input)
{
	ExitWatcher watcher;
	std::cout << "Input :";
	for(auto p: input)
		std::cout << p << " ";
	std::cout << std::endl;

	for(size_t j=0;j<input.size();++j)
	{
		auto currElem = input[j];
		//find position where to insert current element - it is ii
		int insertionPos(0);
		for(;insertionPos<j && currElem>input[insertionPos];++insertionPos)
		{
		}

		//shift elements between ii and j one left
		for(size_t ii=j;ii>insertionPos;--ii)
		{
			input[ii]=input[ii-1];
		}
		input[insertionPos]=currElem;
	}

	std::cout << "Output :";
	for(auto p: input)
		std::cout << p << " ";
	std::cout << std::endl;
}

void selectionSort(std::vector<int> &input)
{
	ExitWatcher watcher;
	std::cout << "Input :";
	for(auto p: input)
		std::cout << p << " ";
	std::cout << std::endl;

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

	std::cout << "Output :";
	for(auto p: input)
		std::cout << p << " ";
	std::cout << std::endl;
}