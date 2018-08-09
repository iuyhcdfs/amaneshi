#include "Graphics_Interface.hpp"
#include "Setup_GLFW.hpp"
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
			if (Library == "glfw")
			{
				amaneshi::glfw::InitializeWindow(windowParams);
			}
			else
			{
				std::cout << "ERROR: Tried to initalize window without library" << std::endl;
			}
		}
		void UpdateWindow()
		{
			if (Library == "glfw")
			{
				amaneshi::glfw::UpdateWindow();
			}
		}

		void TestDrawTriangle()
		{

		}

	}
}
