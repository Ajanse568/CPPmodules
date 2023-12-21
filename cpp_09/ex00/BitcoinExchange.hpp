#include <map>
#include <chrono>
#include <iostream>

void	printDate(std::chrono::year_month_day date);
class BitcoinExchange
{
private:
	std::map<std::chrono::year_month_day, float> _data;
	
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &obj);
	BitcoinExchange &operator=(const BitcoinExchange &obj);

	void addLinetomap(std::string line);
	void handleLine(std::string line);
	std::chrono::year_month_day handleDate(std::string date);
	void	printRateCalculation(std::chrono::year_month_day date, int value);
public:
	BitcoinExchange(std::string filename);
	~BitcoinExchange();

	void printData(std::string inputfile);
};
