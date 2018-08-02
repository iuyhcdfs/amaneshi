#include "Graphics_Interface.hpp"
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace amaneshi {
	namespace graphics {
		std::string Framework;
		void(*Initialize)(const WindowStruct& windowParams);
		void(*Terminate)();
		void(*DrawPrimitive)();
	}
}
