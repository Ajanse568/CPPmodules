#include "BitcoinExchange.hpp"

int	main(int argc, char **argv){

	std::string inputfile;
	BitcoinExchange exchange("data.csv");
	
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	inputfile = argv[1];

	exchange.printData(inputfile);
	return 0;
}