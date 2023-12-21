#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() = default;

PmergeMe::PmergeMe(PmergeMe const &copy) = default;

PmergeMe::~PmergeMe() = default;

PmergeMe &PmergeMe::operator=(PmergeMe const &copy) = default;

void PmergeMe::addNumber(int n) {
	_v.push_back(n);
	_l.push_back(n);
}

bool PmergeMe::checkDuplicates() {
	this->_sortedVector = this->_v;
	std::sort(this->_sortedVector.begin(), this->_sortedVector.end());
	return std::adjacent_find(this->_sortedVector.begin(), this->_sortedVector.end()) != this->_sortedVector.end();
}

void PmergeMe::printTimes() {
	std::cout << "Vector sort time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(this->_endVec - this->_startVec).count() << "ns" << std::endl;
	std::cout << "List sort time:   " << std::chrono::duration_cast<std::chrono::nanoseconds>(this->_endList - this->_startList).count() << "ns" << std::endl;
}

void PmergeMe::printSequencePart() {
	std::vector<int>::iterator it = this->_v.begin();
	for (int i = 0; it != this->_v.end() && i < 10; std::advance(it, 1), i++)
		std::cout << *it << " ";
	if (it != this->_v.end())
		std::cout << "[...] ";
}

void PmergeMe::checkIfSorted() {
	std::vector<int>::iterator vec = this->_v.begin();
	std::list<int>::iterator list = this->_l.begin();
	std::vector<int>::iterator sorted = this->_sortedVector.begin();

	for (; vec != this->_v.end(); std::advance(vec, 1), std::advance(list, 1), std::advance(sorted, 1)) {
		if (*vec != *list || *vec != *sorted) {
			std::cout << "No not sorted!" << std::endl;
			return;
		}
	}

	std::cout << "Yess sorted!" << std::endl;
}
