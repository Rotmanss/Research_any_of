#pragma once

#include <thread>
#include <numeric>
#include <algorithm>
#include <vector>

class ParallelAlgorithm
{
public:
	ParallelAlgorithm()
	{
	};

	bool processSubrange(std::vector<int>::iterator begin, std::vector<int>::iterator end, bool (*pred)(int x));
	bool parallel_any_of(std::vector<int>& data, bool (*pred)(int x), int num_threads);
};