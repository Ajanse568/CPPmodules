#include "Harl.hpp"

int main( void ) {

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Harl        harl;

    for (int i = 0; i < 4; i++)
    {
        harl.complain(levels[i]);
        std::cout << std::endl;
    }
    harl.complain("INVALID");
    return EXIT_SUCCESS;
}