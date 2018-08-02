#pragma once

#include "Graphics_Interface.hpp"

namespace amaneshi {

	namespace glfw {

		void HookToAmaneshi();

		void Initialize(const amaneshi::graphics::WindowStruct& window);
		void PrintOpenGLVersion();
		void Terminate();
	}
}
