#include <deque>
#include <list>
#include <vector>
#include <iostream>
#include <chrono>

class PmergeMe
{
private:
	PmergeMe(PmergeMe const &copy);
	PmergeMe &operator=(PmergeMe const &copy);
	std::vector<int> _v;
	std::list<int> _l;
	std::vector<int> _sortedVector;

	std::chrono::steady_clock::time_point _startVec, _endVec, _startList, _endList;

	void	mergeInsertlist(std::list<int>::iterator first, std::list<int>::iterator last, int step_size);
	void	mergeInsertvector(std::vector<int>::iterator first, std::vector<int>::iterator last, int step_size);
public:
	PmergeMe();
	~PmergeMe();


	void 	addNumber(int n);
	void	sortVector();
	void	sortList();
	bool	checkDuplicates();
	void	printTimes();
	void	printSequencePart();
	void	checkIfSorted();

};
