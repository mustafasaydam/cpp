#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	(void)src;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	(void)src;
	return (*this);
}

/*
	Database functions to check if it is in the correct format and it's posible
	to open the file.

	Second part saving database in a container.
*/

void BitcoinExchange::checkDatabase(std::ifstream &db)
{
	db.open("./src/data.csv");
	try
	{
		if (!db.is_open())
			throw std::logic_error("Did you deleted the database?");
	}
	catch (const std::exception &e)
	{
		std::cout << "Database failed due: ";
		std::cout << e.what() << std::endl;
	}
}

//-------- Second part ---------

bool BitcoinExchange::saveDatabase(std::ifstream &db, std::map<std::string, float> &info)
{
	std::string line;

	checkDatabase(db);
	std::getline(db, line);
	if (line != "date,exchange_rate\r"){
		std::cout << "Error: Empty file or invalid header\n";
		return false;
	}
	while (std::getline(db, line))
	{
		std::istringstream linestream(line);
		std::string date;
		std::string value;

		if (std::getline(linestream, date, ',') && std::getline(linestream, value))
		{
			try
			{
				float fvalue = std::stof(value);
				checkDate(date);
				info[date] = fvalue;
			}
			catch (const std::exception &e)
			{
				std::cout << e.what() << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

/*
	Input file functions to check the format of the inputs
	and their value in the database.
*/

void BitcoinExchange::checkValue(std::string value)
{

	for (int i = 0; i < (int)value.length(); i++)
	{
		if(i == 0 && value[i] == '-')
			;
		else if (!std::isdigit(value[i]) && value[i] != '.')
			throw std::invalid_argument("value invalid number.");
	}
	float fvalue = std::stof(value);

	if (fvalue < 0)
		throw std::out_of_range("Error: not a positive number");
	if (fvalue > 1000.0f)
		throw std::out_of_range("Error: too large number");
}

void BitcoinExchange::checkFormatInput(std::ifstream &in, std::map<std::string, float> &info)
{
	std::string line;
	std::getline(in, line);
	if (line != "date | value")
		std::cout << "Error: Empty file or invalid header\n";
	while (std::getline(in, line))
	{
		std::istringstream linestream(line);
		std::string date;
		std::string value;
		if (!(std::getline(linestream, date, '|') && std::getline(linestream, value)))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		try
		{
			date = date.substr(0, 10);
			value = value.substr(1, value.length());
			float fvalue = 0;
			try
			{
				checkValue(value);
				fvalue = std::stof(value);
				checkDate(date);
			}
			catch (const std::exception &e)
			{
				throw std::invalid_argument(e.what());
			}
			std::map<std::string, float>::const_iterator it = info.lower_bound(date);
			if (it != info.begin() && it->first != date)
				--it;
			std::cout << date << " => " << fvalue << " = " << it->second * fvalue << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

bool BitcoinExchange::checkFile(std::ifstream &in, std::string file, std::map<std::string, float> &info)
{
	in.open(file);
	try
	{
		if (!in.is_open())
		{
			std::string error("Error: could not open file.");
			throw std::logic_error(error);
			return (false);
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	checkFormatInput(in, info);
	return (true);
}

// AUX FUNCTIONS

void BitcoinExchange::checkYear(const std::string date)
{
	std::string stringYear = date.substr(0, 4);
	int year = std::stoi(stringYear);
	if (year < 2009 || year > 2023)
		throw std::out_of_range(" year is out of range");
}

void BitcoinExchange::checkMonth(const std::string date)
{
	std::string stringMonth = date.substr(5, 7);
	int month = std::stoi(stringMonth);
	if (month < 1 || month > 12)
		throw std::out_of_range(" month is out of range");
}

void BitcoinExchange::checkDay(const std::string date)
{
	std::string stringMonth = date.substr(5, 7);
	int month = std::stoi(stringMonth);
	bool thirtyOne = false;
	bool february = false;

	std::string stringDay = date.substr(8, 10);
	int day = std::stoi(stringDay);
	std::string stringYear = date.substr(0, 4);
	int year = std::stoi(stringYear);
	if (month == 2)
		february = true;
	else if (month % 2 != 0 && month <= 7)
		thirtyOne = true;
	if (month % 2 == 0 && month > 7)
		thirtyOne = true;
	if (day < 1)
		throw std::out_of_range(" day is out of range");
	if (february == true && day > 29)
		throw std::out_of_range(" day is out of range");
	else if (february == true && year % 4 != 0 && day == 29)
		throw std::out_of_range(" day is out of range");
	else if (thirtyOne == false && day > 30)
		throw std::out_of_range(" day is out of range");
	else if (thirtyOne == true && day > 31)
		throw std::out_of_range(" day is out of range");
}

void BitcoinExchange::checkDate(const std::string date)
{
	for (size_t i = 0; i < date.length(); i++)
	{
		if ((i == 4 || i == 7) && date[i] != '-')
			throw std::runtime_error("date must be separated by '-'");
		else if (!isdigit(date[i]) && !(i == 4 || i == 7))
			throw std::runtime_error("only numbers accepted");
		else
			continue;
	}
	try
	{
		checkYear(date);
		checkMonth(date);
		checkDay(date);
	}
	catch (const std::exception &e)
	{
		std::string error("Error in ");
		error.append(date);
		error.append(e.what());
		throw std::invalid_argument(error);
	}
}

/*
	Main function of exchange where you recive the input file
*/

void BitcoinExchange::exchange(std::string file)
{
	std::map<std::string, float> info;
	std::ifstream in;
	std::ifstream db;

	if (saveDatabase(db, info) == false)
		return;
	if (checkFile(in, file, info) == false)
		return;
}