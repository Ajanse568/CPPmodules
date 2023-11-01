#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat  bert(31, "Bert");
		Form	    test("testAForm", 30, 45);
		std::cout << test << std::endl;
        bert.signForm(test);
        bert.incrementGrade();
        bert.signForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}