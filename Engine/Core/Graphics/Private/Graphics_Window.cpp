#include "Graphics_Window.hpp"
#include "Messy_GLFW.hpp"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace amaneshi 
{
	namespace graphics 
	{
		std::string Library;
		std::string API = "opengl";

		void InitializeWindow(const WindowStruct& windowParams)
		{
			{
				amaneshi::glfw::InitializeWindow(windowParams);
			}
			{
				std::cout << "ERROR: Tried to initalize window without library" << std::endl;
			}
		}
		void UpdateWindow()
		{
			{
				amaneshi::glfw::UpdateWindow();
			}
		}

	}
}
