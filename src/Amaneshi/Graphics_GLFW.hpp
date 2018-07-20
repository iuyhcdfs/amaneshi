#pragma once

#include "Graphics_Interface.hpp"

namespace amaneshi {

	namespace glfw {

		void HookToAmaneshi();

		void Initialize(struct amaneshi::graphics::WindowStruct windowParams);
		void Terminate();

	}
}