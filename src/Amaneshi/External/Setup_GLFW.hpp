#pragma once

#include <GLFW/glfw3.h>

#include "Graphics_Interface.hpp"
#include "Input_Interface.hpp"
#include "Sound_Interface.hpp"

namespace amaneshi 
{
	namespace glfw 
	{
		void StartGlfw();
		void InitializeWindow(const amaneshi::graphics::WindowStruct& window);
		void PrintOpenGLVersion();
		void SetAmaneshiGraphics();
		void SetAmaneshiInput();
		void CallbackMouseButton(GLFWwindow* window, int button, int action, int mods);
		void CallbackMousePosition(GLFWwindow* window, double xpos, double ypos);
		void CallbackKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
	}
}
