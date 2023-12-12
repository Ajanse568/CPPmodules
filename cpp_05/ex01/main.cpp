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
		Form	test("testBForm", 151, 45);
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Form	test("testCForm", 0, 45);
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}