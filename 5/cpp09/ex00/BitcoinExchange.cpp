#include "BitcoinExchange.hpp"
#include <sstream>
#include <stdexcept>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) { *this = rhs; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs)
		exchangeRates = rhs.exchangeRates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseDb(const std::string& dataFile)
{
    std::ifstream db(dataFile.c_str());
    if (!db.is_open())
        throw std::logic_error("Error: could not open data file.");

    std::string line;
    std::getline(db, line); // Skip header

    while (std::getline(db, line))
    {
        std::istringstream lineStream(line);
        std::string date, value;

        if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, value))
            continue;
        if (!isValidDate(date))
            throw std::logic_error("Error: incorrect date => " + date);
        if (!isNumber(value))
            throw std::logic_error("Error: incorrect value => " + value);

        exchangeRates[date] = std::strtod(value.c_str(), NULL);
    }
    db.close();
}

void BitcoinExchange::exchange(const std::string &inputFile)
{
    std::ifstream input(inputFile.c_str());
    if (!input.is_open())
        throw std::logic_error("Error: could not open file.");

    std::string line;
    std::getline(input, line); // Skip header

    while (std::getline(input, line))
    {
        try {
            std::istringstream lineStream(line);
            std::string date, valueStr;

            if (!std::getline(lineStream, date, '|') || !std::getline(lineStream, valueStr))
                throw std::logic_error("Error: bad input => " + line);

            date = date.substr(0, date.size() - 1); // Remove trailing space
            valueStr = valueStr.substr(1); // Remove leading space

            if (!isValidDate(date))
                throw std::logic_error("Error: incorrect date => " + date);
            if (!isNumber(valueStr))
                throw std::logic_error("Error: not a positive number.");

            double value = std::strtod(valueStr.c_str(), NULL);
            if (value < 0)
                throw std::logic_error("Error: not a positive number.");
            if (value > 1000)
                throw std::logic_error("Error: too large a number.");

			double exchangeRate = getExchangeRate(date);
            double result = value * exchangeRate;

            std::cout << date << " => " << valueStr << " = " << result << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    input.close();
}

bool BitcoinExchange::isNumber(const std::string &value)
{
    char *end;
    double val = std::strtod(value.c_str(), &end);
    return (end != value.c_str() && *end == '\0' && val >= 0);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1)
        return (false);

    if (month == 2 && day == 29) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return (true);
        else
            return (false);
    }

    int max_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (day <= max_day[month - 1]);
}

double BitcoinExchange::getExchangeRate(const std::string &date)
{
    std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date);

    if (it == exchangeRates.begin() && it->first != date)
        throw std::logic_error("Error: no exchange rate available for date => " + date);

    if (it == exchangeRates.end() || it->first != date)
        --it;

    return it->second;
}