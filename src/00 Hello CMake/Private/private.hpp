#pragma once 

#include <iostream>
#include "printer.h"
class printa : public printer {};

void printa::print(){
	std::cout << "oh no" << std::endl;
}