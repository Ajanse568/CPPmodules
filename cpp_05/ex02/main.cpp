#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat  bert(31, "Bert");

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}