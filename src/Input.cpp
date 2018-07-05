#include "Input.h"

#include <iostream>
#include <GLFW/glfw3.h>

namespace amaneshi {
	namespace input {

		double x, y;

		void ClickCallback(GLFWwindow* window, int button, int action, int mods) {
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {

				// TODO get frontmost clickable-enabled object displayed (need hitboxes)
				// then trigger it's onClick

				// temporary test function to kill on bottom right corner
				std::cout << "click" << std::endl;
				if (x > 320 && y > 240) {
					glfwSetWindowShouldClose(window, GL_TRUE);
				}

			}
		}

		void CursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
			//std::cout << "x: "<<xpos<<std::endl<<"y: "<<ypos<<std::endl;
			x = xpos;
			y = ypos;
		}

		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);
		}

	} // namespace amaneshi::input
} // namespace amaneshi