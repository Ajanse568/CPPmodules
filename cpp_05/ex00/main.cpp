#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	test(149, "Test");
		test.decrementGrade();
		std::cout << test << std::endl;
		test.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}