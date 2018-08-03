#include "Input_GLFW.hpp"

#include <iostream>
#include <GLFW/glfw3.h>

namespace amaneshi 
{
	namespace glfw 
	{

		Mouse_Struct Mouse;

		void Initalize() 
		{
			
		}

		void ClickCallback(GLFWwindow* window, int button, int action, int mods) 
		{
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) 
			{
				std::cout << "click" << std::endl;
			}
		}

		void CursorPosCallback(GLFWwindow* window, double xpos, double ypos) 
		{
			Mouse.x = xpos;
			Mouse.y = ypos;
		}

		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);
		}

	} // namespace amaneshi::glfw
} // namespace amaneshi
