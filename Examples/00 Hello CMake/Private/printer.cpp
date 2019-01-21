#include <iostream>
#include "printer.hpp"

void printer::test() {
	this->i++;
}
void printer::print() {
	std::cout << i << std::endl;
}