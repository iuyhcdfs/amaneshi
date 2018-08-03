#pragma once
#include <string>
// the engine side touching the wall called abstraction

namespace amaneshi {
	namespace graphics {

		struct WindowStruct {
			int width;
			int height;
			std::string title;
			bool fullscreen;
		};
		
		extern std::string Framework;
		extern void(*Initialize)(const WindowStruct& window);
		extern void(*Terminate)();

		extern void(*DrawPrimitive)();

		// below todo for glfw ~at least =================================
		//extern void(*WindowResize) ();

		// SOMETHING ABOUT DRAWING UKNO? hand over an asset? hand over vertices? hand over shaders?

	}
}
