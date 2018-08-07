#include <iostream>
#include <Amaneshi/External/Input_Interface.hpp>
#include <Amaneshi/External/Graphics_Interface.hpp>

#include <Choose_Game.h>

#ifdef HELLO_WORLD
int main() 
{
	//std::cout << (int) nullptr << std::endl; std::cout << ((char) nullptr == '\0') << std::endl;
	//while (true);
	amaneshi::graphics::WindowStruct window;
	window.width = 600;
	window.height = 400;
	window.title = "Hello World!";
	amaneshi::graphics::InitializeWindow(window);

	while (true) 
	{
		
		
	}
}
#endif
