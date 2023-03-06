#include "Form.hpp"

int main()
{
	try
	{
		Form	test("testform", 30, 45);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}