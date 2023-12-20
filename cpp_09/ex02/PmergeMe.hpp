#include <deque>
#include <list>
#include <iostream>

class PmergeMe
{
private:
	std::deque<int> _d;
	std::list<int> _l;
public:
	PmergeMe();
	PmergeMe(PmergeMe const &copy);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &copy);

	void 	addNumber(int n);
	void	sortDeque();
	void	sortList();
};
