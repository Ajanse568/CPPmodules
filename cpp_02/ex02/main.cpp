#include "Fixed.hpp"

int main(void)
{
    //Comparison operators
    std::cout << "COMPARISON OPERATORS\n";

    Fixed	const a(10);
    Fixed	const b(5);
    Fixed	const c(10.0f);
    Fixed	const d(a - b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << std::endl;

     if (a > b)
     	std::cout << "a > b" << std::endl;
     if (a == c)
     	std::cout << "a == c" << std::endl;
     if (a != b)
     	std::cout << "a != b" << std::endl;
     if (b < c)
     	std::cout << "b < c" << std::endl;
     if (a >= b && a >= c)
     	std::cout << "a >= b && a >= c" << std::endl;
     if (b <= c)
     	std::cout << "b <= c" << std::endl;

     // ARITHMETIC OPERATORS
     std::cout << "\nARITHMETIC OPERATORS\n";
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << std::endl;

     std::cout << "a + b = " << a + b << std::endl;
     std::cout << "a - b = " << a - b << std::endl;
     std::cout << "a * b = " << a * b << std::endl;
     std::cout << "a / b = " << a / b << std::endl;
     std::cout << "a + 5 = " << a + 5 << std::endl;
     std::cout << "a - 5 = " << a - 5 << std::endl;
     std::cout << "a * 5 = " << a * 5 << std::endl;
     std::cout << "a / 5 = " << a / 5 << std::endl;

    // MIN_MAX FUNCTIONS
    std::cout << "\nMIN_MAX FUNCTIONS\n";
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << std::endl;

    Fixed	normal_a(10);
    Fixed	normal_b(5);

    const Fixed	const_a(10);
    const Fixed	const_b(5);

    std::cout << "First the normals\n";
    std::cout << Fixed::min(normal_a,normal_b) << std::endl;
    std::cout << Fixed::max(normal_a, normal_b) << std::endl;
    std::cout << std::endl;
    std::cout << "Now the const member functions\n";
    std::cout << Fixed::min(const_a,const_b) << std::endl;
    std::cout << Fixed::max(const_a,const_b) << std::endl;


//    Given main
    std::cout << "\nGiven main\n";

    Fixed	f;
    Fixed	const g(Fixed(5.05f) * Fixed(2));

    std::cout << f << std::endl;
    std::cout << ++f << std::endl;
    std::cout << f << std::endl;
    std::cout << f++ << std::endl;
    std::cout << f << std::endl;

    std::cout << g << std::endl;

    std::cout << Fixed::max(f, g) << std::endl;

    return (0);
}