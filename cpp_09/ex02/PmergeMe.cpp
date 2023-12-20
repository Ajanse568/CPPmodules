#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy) {
	if (this != &copy) {
		_d = copy._d;
		_l = copy._l;
	}
	return *this;
}

void PmergeMe::addNumber(int n) {
	_d.push_back(n);
	_l.push_back(n);
}

struct pend_el {
	std::deque<int>::iterator 						it;
	std::deque<std::deque<int>::iterator>::iterator	higher;
};

void	mergeInsertDeque(std::deque<int>::iterator first, std::deque<int>::iterator last, int step_size) {
	static constexpr std::uint_least64_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };
	
	int	size = std::distance(first, last)/step_size;
	bool uneven = (size % 2 != 0);
	pend_el	pendie;
	
	if (size < 2)
		return;

	std::deque<int>::iterator end = uneven ? std::prev(last, step_size): last;
	for (std::deque<int>::iterator it = first; it != end; std::advance(it, step_size * 2)) {
		if(*std::next(it, step_size - 1) > *std::next(it, step_size))
			std::swap_ranges(it, std::next(it, step_size), std::next(it, step_size));
	}

	mergeInsertDeque(first, end, step_size * 2);

	std::deque<std::deque<int>::iterator> main = {first, std::next(first, step_size)};
	std::deque<pend_el> pend;

	for (std::deque<int>::iterator it = std::next(first, step_size * 2); it != end; std::advance(it, step_size * 2)) {
		main.push_back(std::next(it, step_size));
		pendie.it = it;
		pendie.higher = std::prev(main.end());
		pend.push_back(pendie);
	}

	for (int i = 0; ; i++){
		std::uint_least64_t dist = jacobsthal_diff[i];
		if (dist >= pend.size())
			break;
		std::deque<pend_el>::iterator it = pend.begin();
		std::advance(it, dist - 1);

		while (true)
		{
			// std::deque<std::deque<int>::iterator>::iterator it2 = std::upper_bound(main.begin(), *(it).higher, *it.it);

		}
	

	}
} 

void PmergeMe::sortDeque() {
	for (auto it = _d.begin(); it != _d.end(); ++it)
        std::cout << ' ' << *it;
	std::cout << std::endl;

	mergeInsertDeque(_d.begin(), _d.end(), 1);
}