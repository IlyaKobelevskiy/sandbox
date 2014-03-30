//stl
#include <chrono>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
#include <unordered_set>
//own
#include "SortingPractice.h"
#include "ExitWatcher.h"
#include "RedBlackBst.h"

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

void testBstTree(std::vector<int> &input);

int main(int argc, char* argv[])
{
	std::vector<int> treeInput = generate_input(100,0,100);
	testBstTree(treeInput);

	//sorting
	std::vector<int> input = generate_input(10000000,0,100);
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
	
	//for(auto f : functors)
	//{
	//	//create copy of input
	//	std::vector<int> data(input);
	//	f(data);
	//}

#ifndef __linux__
	std::cout << "Done, press any key..." << std::endl;
	::getchar();
#endif
	return 0;
}

void testBstTree(std::vector<int> &input)
{
	ExitWatcher watcher(&input,"RedBlackBst",true);
	//trees
	RedBlackBst<int,int>	tree;
	
	for(auto p:input)
		tree.insert(p,p);

	std::cout << tree;
}