#include "PmergeMe.hpp"
#include <algorithm>

struct pend_el {
	std::list<int>::iterator 						it;
	std::list<std::list<int>::iterator>::iterator	higher;
	int												step_size;
};

bool	it_comp(pend_el pend, std::list<int>::iterator main) {

	return(*(std::next(pend.it, (pend.step_size - 1))) < *(std::next(main, (pend.step_size - 1))));
}

void	PmergeMe::mergeInsertlist(std::list<int>::iterator first, std::list<int>::iterator last, int step_size) {
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

	std::list<int>::iterator end = uneven ? std::prev(last, step_size): last;
	for (std::list<int>::iterator it = first; it != end; std::advance(it, step_size * 2)) {
		if(*std::next(it, step_size - 1) > *std::next(it, step_size *2 -1))
			std::swap_ranges(it, std::next(it, step_size), std::next(it, step_size));
	}

	mergeInsertlist(first, end, step_size * 2);

	std::list<std::list<int>::iterator> main = {first, std::next(first, step_size)};
	std::list<pend_el> pend;

	for (std::list<int>::iterator it = std::next(first, step_size * 2); it != end; std::advance(it, step_size * 2)) {
		main.push_back(std::next(it, step_size));
		pendie.it = it;
		pendie.higher = std::prev(main.end());
		pendie.step_size = step_size;
		pend.push_back(pendie);
	}

	if(uneven) {
		pendie.it = end;
		pendie.higher = main.end();
		pendie.step_size = step_size;
		pend.push_back(pendie);
	}

	for (int i = 0; ; i++){
		std::uint_least64_t dist = jacobsthal_diff[i];
		if (dist >= pend.size())
			break;
		std::list<pend_el>::iterator it = pend.begin();
		std::advance(it, dist - 1);

		while (true)
		{
			std::list<std::list<int>::iterator>::iterator insertion = std::upper_bound(main.begin(), it->higher, *it, it_comp);
			main.insert(insertion, it->it);
            it = pend.erase(it);
            if (it == pend.begin()) break;
            --it;
		}
	}

	while (!pend.empty()) {
		std::list<pend_el>::iterator pit = std::prev(pend.end());
		std::list<std::list<int>::iterator>::iterator insertion = std::upper_bound(main.begin(), pit->higher, *pit, it_comp);
		main.insert(insertion, pit->it);
		pend.pop_back();
	}

	std::list<int> swap;
	for (std::list<std::list<int>::iterator>::iterator it = main.begin(); it != main.end(); std::advance(it, 1)) {
		for (int i = 0; i < step_size; i++)
			swap.push_back(*std::next(*it, i));
	}
	for (size_t i = 0; i < swap.size(); i++)
		*(std::next(first, i)) = *(std::next(swap.begin(), i));
} 

void PmergeMe::sortList() {
	this->_startList = std::chrono::steady_clock::now();
	mergeInsertlist(_l.begin(), _l.end(), 1);
	this->_endList = std::chrono::steady_clock::now();
}