#pragma once

#include <ctime>
#include <string>

class Product {
public:
	Product(std::string name, std::string description, double price, time_t expdate, std::string location);
	Product();
	Product(const Product& other);
	~Product();

	std::string getName() const;
	std::string getDescription() const;
	double getPrice() const;
	time_t getExpDate() const;
	std::string getFormattedExpDate() const;
	std::string getLocation() const;
	int setPrice(double new_price);
	void printInfo() const;
	void printLocInfo() const;
	int decreaseExpDate(size_t days);
protected:
	std::string _name;
	std::string _description;
	double _price;
	time_t _expdate;
	std::string _location;
private:
	std::string formatDate(time_t date) const;
};