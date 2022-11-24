#include <cstdlib>
#include <iostream>
 
int main()
{
    std::cout << std::atoi("3147483648") << '\n'
              << std::atof("4")        << '\n'
              << std::atof("0.012asdrf")        << '\n'
              << std::atof("15e16")        << '\n'
              << std::atof("-0x1afp-2")    << '\n'
              << std::atof("inF")          << '\n'
              << std::atof("-nan")          << '\n'
              << std::atof("invalid")      << '\n';
}