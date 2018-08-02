#pragma once

#include <GLFW/glfw3.h>
#include "Input_Interface.hpp"

namespace amaneshi
{
	namespace glfw
	{
		struct Mouse_Struct
		{
			int x;
			int y;
			bool button[];
		};
		
		void HookToAmaneshi();
		void Initalize();
		void Terminate();

		void ClickCallback(GLFWwindow* window, int button, int action, int mods);
		void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);

		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	} // namespace amaneshi::glfw
} // namespace amaneshi
