#include "Product.hpp"
#include <iostream>

int main()
{
	Product p1 = Product("lol", "9desc9", 9.9, time(nullptr) + 10*60*60*24, "gde-to");
	Product p2 = Product();
	Product p3 = p1;

	p1.printInfo();
	std::cout << std::endl;
	p2.printInfo();
	std::cout << std::endl;
	p3.printInfo();
	std::cout << std::endl;

	std::cout << "p1: price = 10\n p3: expdate -= 1d" << std::endl;

	p1.setPrice(10);
	p3.decreaseExpDate(1);

	std::cout << std::endl;
	p1.printInfo();
	std::cout << std::endl;
	p3.printInfo();
	return 0;
}