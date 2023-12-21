#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	PmergeMe 		p;
	std::string input;
	
	if (ac < 2) {
		std::cout << "Usage: PMergeMe [int]" << std::endl;
		return 1;
	}
	for(int i = 1; i < ac; i++) {
		input = av[i];
		if (input.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Error: invalid input" << std::endl;
			return 1;
		}
		try {
			p.addNumber(std::stoi(input));
		} catch (std::exception &e) {
			std::cout << "Error: " << "Containing invalid integer" << std::endl;
			return 1;
		}
	}
	if (p.checkDuplicates()) {
		std::cout << "Error: " << "No duplicates allowed" << std::endl;
		return 1;
	}
	std::cout << "Unsorted: ";
	p.printSequencePart();
	std::cout << std::endl;
	p.sortList();
	p.sortVector();
	std::cout << "Sorted:   ";
	p.printSequencePart();
	std::cout << std::endl;
	p.printTimes();
	std::cout << std::endl;
	p.checkIfSorted();
	std::cout << std::endl;
	return 0;
}