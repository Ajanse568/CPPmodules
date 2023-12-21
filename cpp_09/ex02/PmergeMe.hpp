#include <deque>
#include <list>
#include <vector>
#include <iostream>

class PmergeMe
{
private:
	std::vector<int> _v;
	std::list<int> _l;

	void	mergeInsertlist(std::list<int>::iterator first, std::list<int>::iterator last, int step_size);
	void	mergeInsertvector(std::vector<int>::iterator first, std::vector<int>::iterator last, int step_size);
public:
	PmergeMe();
	PmergeMe(PmergeMe const &copy);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &copy);

	void 	addNumber(int n);
	void	sortVector();
	void	sortList();
};
