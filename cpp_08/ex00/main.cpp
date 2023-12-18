//
// Created by allej on 12/11/2023.
//
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

void	print(int& i){
	std::cout << i << ", ";
}

int main() {

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::cout << "easyfind(vector)" << std::endl << std::endl;
	std::cout << "[";
	std::for_each(v.begin(), v.end(), print);
	std::cout << "]" << std::endl;

	std::cout << "[";
	std::for_each(easyfind(v, 2), v.end(), print);
	std::cout << "]" << std::endl;
	std::cout << "[";
	std::for_each(easyfind(v, 3), v.end(), print);
	std::cout << "]" << std::endl;
	try { std::cout << *easyfind(v, 4) << std::endl; }
	catch (std::exception &e) { std::cout << "Not found" << std::endl; }

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	std::cout << std::endl << "easyfind(list)" << std::endl << std::endl;
	std::cout << "[";
	std::for_each(l.begin(), l.end(), print);
	std::cout << "]" << std::endl;

	std::cout << "[";
	std::for_each(easyfind(l, 2), l.end(), print);
	std::cout << "]" << std::endl;
	std::cout << "[";
	std::for_each(easyfind(l, 3), l.end(), print);
	std::cout << "]" << std::endl;
	try { std::cout << *easyfind(l, 4) << std::endl; }
	catch (std::exception &e) { std::cout << "Not found" << std::endl; }
}