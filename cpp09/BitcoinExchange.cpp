#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>

bool ehBisi(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool validationDateInput(std::string date)
{
	std::string year;
	std::string month;
	std::string day;	
	std::stringstream ss(date);
	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day, '-');
	int intYear = std::atoi(year.c_str());
	int intMonth = std::atoi(month.c_str());
	int intDay = std::atoi(day.c_str());
    if (intYear < 1 || intMonth < 1 || intMonth > 12) {
        return false;
    }

    int daysInMonth = 31;

    if (intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11) {
    } else if (intMonth == 2) {
        daysInMonth = ehBisi(intYear) ? 29 : 28;
    }
    return (intDay >= 1 && intDay <= daysInMonth);
}

std::map<std::string, double> createConteiner()
{
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw std::out_of_range("error to open file!");

	}

	std::map<std::string, double> myMap;
	std::string line;
	std::string dateData;
	std::string ValueData;
	std::getline(file, line);
	while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::getline(ss, dateData, ',');
			std::getline(ss, ValueData, ',');
		myMap[dateData] = std::atof(ValueData.c_str());
	}
	file.close();
	return myMap;
}

std::string getDatelower(const std::string input, std::map<std::string, double> MyData)
{
	std::map<std::string, double>::const_iterator it = MyData.lower_bound(input);

    if (it != MyData.end() && it->first == input) {
        return it->first;
    }
    if (it == MyData.begin()) {
        return "";
    }
    --it;
    return it->first;
}

double valueBitcoin(const std::string date, double b, std::map<std::string, double> MyData)
{
	std::string dateFind =  getDatelower(date, MyData);
	if(dateFind != "")
	{
		return MyData[dateFind] * b;
	}
	return 0;
}

void parse(std::map<std::string, double> MyData, std::string line)
{
	std::string dateInput;
	std::string ValueInput;
	double convert = 0.0;
	std::stringstream ss(line);
	std::getline(ss, dateInput, '|');
	std::getline(ss, ValueInput, '|');
	dateInput.erase(std::remove(dateInput.begin(), dateInput.end(), ' '), dateInput.end());
	ValueInput.erase(std::remove(ValueInput.begin(), ValueInput.end(), ' '), ValueInput.end());
	if(line.find('|') == std::string::npos || !validationDateInput(dateInput))
	{
		std::ostringstream oss;
		oss << "Error: bad input => " << dateInput << ".";
		throw std::runtime_error(oss.str());
		return;
	}
	convert = std::atoi(ValueInput.c_str());
	if(convert < 0)
	{
		std::ostringstream oss;
		oss << "Error: not a positive number" << ".";
		throw std::runtime_error(oss.str());
		return;
	}
	if(convert > 1000)
	{
		std::ostringstream oss;
		oss << "Error: too large a number" << ".";
		throw std::runtime_error(oss.str());
		return;
	}
	std::ostringstream oss;
	oss << dateInput << " => " << convert << " = " << valueBitcoin(dateInput, convert, MyData);
	std::cout << oss.str() << std::endl;
}

void readfileBitcoin(std::string nameFile)
{
	std::ifstream file(nameFile.c_str());
	if (!file.is_open()) {
		throw std::out_of_range("error to open file input!");
	}
	std::string line;
	std::getline(file, line);
	std::map<std::string, double> MyData = createConteiner();
	while (std::getline(file, line)) {
		try {
			parse(MyData, line);
		} catch (const std::out_of_range& e) {
			std::cout << "Error: too large a number." << std::endl;
		} catch (const std::invalid_argument& e) {
        	std::cout << "Error: bad input => " << line << std::endl;
   		}catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
	return ;
}