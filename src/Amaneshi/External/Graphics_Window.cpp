#include "Graphics_Window.hpp"
#include "Messy_GLFW.hpp"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Amaneshi/External_Modes.hpp>
namespace amaneshi 
{
	namespace graphics 
	{
		std::string Library;
		std::string API = "opengl";

		void InitializeWindow(const WindowStruct& windowParams)
		{
			#ifdef WINDOW_GLFW
			{
				amaneshi::glfw::InitializeWindow(windowParams);
			}
			#else
			{
				std::cout << "ERROR: Tried to initalize window without library" << std::endl;
			}
			#endif
		}
		void UpdateWindow()
		{
			#ifdef WINDOW_GLFW
			{
				amaneshi::glfw::UpdateWindow();
			}
			#endif
		}

	}
}
