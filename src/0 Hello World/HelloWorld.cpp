#include <iostream>
#include <Amaneshi/Graphics_GLFW.hpp>
#include <Amaneshi/Input_Interface.hpp>

int main() 
{
	//std::cout << (int) nullptr << std::endl; std::cout << ((char) nullptr == '\0') << std::endl;
	//while (true);
	amaneshi::glfw::HookToAmaneshi();
	amaneshi::graphics::WindowStruct window;
	window.width = 600;
	window.height = 400;
	window.title = "Hello World!";
	amaneshi::graphics::Initialize(window);

	while (true) 
	{
		// FIRST: just print hello world in text on the screen. possible aye?

		// basic updating shit for now.
		// how can we update each object
		// how are we using opengl

		// take a shitty polygon file
		// take a camera system
		// just start doing the fkn math for it
		// lets make primitive 3d shit
		
		
	}
}