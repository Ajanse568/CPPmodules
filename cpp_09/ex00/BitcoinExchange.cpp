#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
	*this = obj;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
	if (this != &obj)
		*this = obj;
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ifstream file(filename);

	if (!file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
		addLinetomap(line);
}

void BitcoinExchange::addLinetomap(std::string line) {
	std::string date = line.substr(0, 10);
	std::string price = line.substr(11);

	std::chrono::year_month_day ymd(std::chrono::year(std::stoi(date.substr(0, 4))), std::chrono::month(std::stoi(date.substr(5, 2))), std::chrono::day(std::stoi(date.substr(8, 2))));
	_data.insert(std::pair<std::chrono::year_month_day, float>(ymd, std::stof(price)));
}

void BitcoinExchange::printData(std::string inputfile) {
	std::ifstream file(inputfile);
	std::string line;

	if (!file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}

	std::getline(file, line);
	if (!line.empty() && line != "date | value")
		handleLine(line);
	while (std::getline(file, line))
		handleLine(line);
}

void BitcoinExchange::handleLine(std::string line) {
	std::string delimiter = " | ";
	std::string date = line.substr(0, line.find(delimiter));
	std::string value = line.substr(line.find(delimiter) + delimiter.length());
	int	valueInt;
	std::chrono::year_month_day ymd;
	std::chrono::year_month_day now(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()));

	ymd = handleDate(date);
	if (!ymd.ok())
		std::cout << "Error: wrong date format" << std::endl;
	if (ymd > now)
		std::cout << "Error: date is in the future" << std::endl;
	try{
		valueInt = std::stoi(value);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
	if (valueInt < 0 || valueInt > 1000)
		std::cout << "Error: value is out of range" << std::endl;
	printRateCalculation(ymd, valueInt);
}

std::chrono::year_month_day BitcoinExchange::handleDate(std::string date) {
	std::string delimiter = "-";
	std::string year = date.substr(0, date.find(delimiter));
	std::string month = date.substr(date.find(delimiter) + delimiter.length(), date.find(delimiter, date.find(delimiter) + delimiter.length()));
	std::string day = date.substr(date.find(delimiter, date.find(delimiter) + delimiter.length()) + delimiter.length());

	try{
		std::chrono::year_month_day ymd(std::chrono::year(std::stoi(year)), std::chrono::month(std::stoi(month)), std::chrono::day(std::stoi(day)));
		return (ymd);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (std::chrono::year_month_day());
	}

	
}

void	BitcoinExchange::printRateCalculation(std::chrono::year_month_day date, int rate) {
	std::map<std::chrono::year_month_day, float>::iterator it = _data.lower_bound(date);

	std <<
}