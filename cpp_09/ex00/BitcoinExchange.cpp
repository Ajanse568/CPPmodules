#include "BitcoinExchange.hpp"
#include <fstream>
#include <iomanip>

bool checkString(std::string& rpn) {
	if (rpn.empty())
		throw std::invalid_argument("Error: empty string");
	size_t onlywhite = rpn.find_first_not_of(" \t");
	size_t valid = rpn.find_first_not_of("0123456789-| \t");
	if (onlywhite == std::string::npos || valid != std::string::npos)
		throw std::invalid_argument("Error: invalid string");
	return (true);
}

BitcoinExchange::BitcoinExchange() = default;

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) =default;

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) = default;

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
	if (line != "date | value"){
		try {
			checkString(line);
			handleLine(line);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	while (std::getline(file, line)){
		try {
			checkString(line);
			handleLine(line);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::handleLine(std::string line) {
	std::string delimiter = "|";
	std::string date = line.substr(0, line.find(delimiter));
	std::string value = line.substr(line.find(delimiter) + delimiter.length());
	int			valueInt;
	std::chrono::year_month_day ymd;
	std::chrono::year_month_day now(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()));

	try{
		ymd = handleDate(date);
		valueInt = std::stoi(value);
	} catch (std::exception &e) {
		std::cout << "Error: " << "Not a valid integer" << std::endl;
		return ;
	}
	if (!ymd.ok()){	
		std::cout << "Error: wrong date format" << std::endl;
		return ;
	}
	if (ymd > now) {
		std::cout << "Error: date is in the future ->" << std::endl;
		printDate(ymd);
		std::cout << std::endl;
		return ;
	}
	if (ymd < this->_data.begin()->first) {
		std::cout << "Error: no data for this date -> ";
		printDate(ymd);
		std::cout << std::endl;
		return ;
	}

	if (valueInt < 0 || valueInt > 1000)
		std::cout << "Error: value is out of range -> " << valueInt << std::endl;
	else
		printRateCalculation(ymd, valueInt);
}

std::chrono::year_month_day BitcoinExchange::handleDate(std::string date) {
	std::string delimiter = "-";
	std::string year = date.substr(0, date.find(delimiter));
	std::string month = date.substr(date.find(delimiter) + delimiter.length(), date.find(delimiter, date.find(delimiter) + delimiter.length()));
	std::string day = date.substr(date.find(delimiter, date.find(delimiter) + delimiter.length()) + delimiter.length());

	std::chrono::year_month_day ymd(std::chrono::year(std::stoi(year)), std::chrono::month(std::stoi(month)), std::chrono::day(std::stoi(day)));
	return (ymd);	
}

void	BitcoinExchange::printRateCalculation(std::chrono::year_month_day date, int value) {
	std::map<std::chrono::year_month_day, float>::iterator it = std::prev(_data.upper_bound(date), 1);

	std::cout << static_cast<int>(date.year()) << "-" << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(date.month()) << "-" << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(date.day());
	std::cout << " => " << value << " = " << value * it->second << " Rate used: " << std::fixed << std::setprecision(2)<< it->second;
	std::cout << " (" << static_cast<int>(it->first.year()) << "-" << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(it->first.month()) << "-" << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(it->first.day()) << ")";
	std::cout << std::endl;
}

void	printDate(std::chrono::year_month_day date) {
	std::cout << static_cast<int>(date.year()) << "-" << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(date.month()) << "-" << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(date.day());
}