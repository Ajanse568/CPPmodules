//
// Created by allej on 12/11/2023.
//

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> intArray(5);
	unsigned int i;
    std::cout << intArray.size() << std::endl;
    intArray[0] = 1;
    intArray[1] = 2;
	std::cout << "intArray" << std::endl;
	std::cout << "[";
    for(i = 0; i < intArray.size() - 1; i++)
		std::cout  << intArray[i] << ", ";
	std:: cout << intArray[i] << "]" << std::endl << std::endl;

    Array<int> intArray2(intArray);
	std::cout << "intArray2(intArray)" << std::endl;
	std::cout << "intArray2" << std::endl;
	std::cout << "[";
	for(i = 0; i < intArray2.size() - 1; i++)
		std::cout  << intArray2[i] << ", ";
	std:: cout << intArray2[i] << "]" << std::endl << std::endl;
    intArray2[0]++;
	std::cout << "intArray2[0]++" << std::endl;
	std::cout << "intArray" << std::endl;
	std::cout << "[";
	for(i = 0; i < intArray.size() - 1; i++)
		std::cout  << intArray[i] << ", ";
	std:: cout << intArray[i] << "]" << std::endl;
	std::cout << "intArray2" << std::endl;
	std::cout << "[";
	for(i = 0; i < intArray2.size() - 1; i++)
		std::cout  << intArray2[i] << ", ";
	std:: cout << intArray2[i] << "]" << std::endl << std::endl;

    Array<int>  intArray3(3);
    intArray3 = intArray2;
	std::cout << "intArray3(3)" << std::endl << "intArray3 = intArray2" << std::endl;
	std::cout << "intArray3" << std::endl;
	std::cout << "[";
	for(i = 0; i < intArray3.size() - 1; i++)
		std::cout  << intArray3[i] << ", ";
	std:: cout << intArray3[i] << "]" << std::endl << std::endl;
	intArray3[0]++;
	std::cout << "intArray3[0]++" << std::endl;
	std::cout << "intArray" << std::endl;
	std::cout << "[";
	for(i = 0; i < intArray2.size() - 1; i++)
		std::cout  << intArray2[i] << ", ";
	std:: cout << intArray2[i] << "]" << std::endl;
	std::cout << "intArray3" << std::endl;
	std::cout << "[";
	for(i = 0; i < intArray3.size() - 1; i++)
		std::cout  << intArray3[i] << ", ";
	std:: cout << intArray3[i] << "]" << std::endl << std::endl;
    try {
        std::cout << intArray3[3] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "intArray3[3]: " << e.what() << std::endl << std::endl;
    }

    Array<std::string> stringArray(2);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    std::cout << stringArray[0] << stringArray[1] << std::endl;
    try
    {
        std::cout << "stringArray[-2]: " << stringArray[-2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "stringArray[3]: " << stringArray[3] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
