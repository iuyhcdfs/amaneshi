#include "Graphics_Interface.hpp"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace amaneshi 
{
	namespace graphics 
	{

		void(*InitializeWindow)(const WindowStruct& windowParams);
		void(*TestDrawTriangle)();

	}
}
