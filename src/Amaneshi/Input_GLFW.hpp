#pragma once

#include <GLFW/glfw3.h>

namespace amaneshi
{
	namespace glfw
	{
		// mouse
		void ClickCallback(GLFWwindow* window, int button, int action, int mods);
		void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);

		// keyboard
		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	} // namespace amaneshi::glfw
} // namespace amaneshi