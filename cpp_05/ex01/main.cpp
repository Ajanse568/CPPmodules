#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat  bert(31, "Bert");
		AForm	    test("testAForm", 30, 45);
        bert.signAForm(test);
        bert.incrementGrade();
        bert.signAForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}