#include "Product.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

Product::Product()
	: _name("Unknown"), _description(""), _price(0.), _expdate(0), _location("")
{ }


Product::Product(std::string name, std::string description, double price, time_t expdate, std::string location)
	: _name(name), _description(description), _price(price), _expdate(expdate), _location(location)
{ }

Product::Product(const Product& other)
	: _name(other.getName()), _description(other.getDescription()), _price(other.getPrice()), _expdate(other.getExpDate()), _location(other.getLocation())
{ }

Product::~Product() {
} // мог бы и не писать, динамически выделять нечего;

std::string Product::getName() const
{
	return _name;
}

std::string Product::getDescription() const
{
	return _description;
};

double Product::getPrice() const
{
	return _price;
};

time_t Product::getExpDate() const
{
	return _expdate;
};

std::string Product::getFormattedExpDate() const
{
	return formatDate(_expdate);
};

std::string Product::getLocation() const
{
	return _location;
};

int Product::setPrice(double new_price) {
	_price = new_price;
	return 0;
};

void Product::printInfo() const
{
	std::cout << "Name: " << getName() << std::endl << "Description: " << getDescription() << std::endl << "Price: " << getPrice() << std::endl << "Expiration date: " << getFormattedExpDate() << std::endl << "Located in: " << getLocation() << std::endl;
};

void Product::printLocInfo() const
{
	std::cout << "Located in: " << getLocation() << std::endl;
};

int Product::decreaseExpDate(size_t days)
{
	time_t seconds = static_cast<time_t>(days) * 60 * 60 * 24;
	time_t now = time(nullptr);
	if (seconds > _expdate || _expdate - seconds <= now)
		return 1;
	_expdate -= seconds;
	return 0;
};

std::string Product::formatDate(time_t date) const
{
	tm local = *localtime(&date);
	
	std::stringstream ss;
	ss << std::setfill('0')
			<< std::setw(2) << local.tm_mday << ", "
			<< std::setw(2) << local.tm_mon + 1 << ", "
			<< std::setw(2) << local.tm_year + 1900;
	return ss.str();
};