#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		PresidentialPardonForm form("Bender");
		Bureaucrat bureaucrat(30, "Harm Konraad");

		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}