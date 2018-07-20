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
		extern void(*Initialize) (WindowStruct windowParams);
		extern void(*Terminate) ();
		
		// below todo for glfw ~at least =================================

		//void(*PrintOpenGLVersion) ();
		//void(*WindowResize) ();

	}
}