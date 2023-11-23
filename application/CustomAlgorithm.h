#include <thread>
#include <numeric>

class ParallelAlgorithm
{
public:
	ParallelAlgorithm() 
	{
	};

	template <typename Iterator, typename Predicate>
	bool processSubrange(Iterator begin, Iterator end, Predicate pred);

	template <typename Iterator, typename Predicate>
	bool parallel_any_of(Iterator begin, Iterator end, Predicate pred, int num_threads);
};