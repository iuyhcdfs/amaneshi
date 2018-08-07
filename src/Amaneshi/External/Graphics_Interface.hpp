#pragma once
#include <vector>
#include <string>
// the engine side touching the wall called abstraction

namespace amaneshi 
{
	namespace graphics 
	{
		extern std::string Library;

		struct WindowStruct 
		{
			int width;
			int height;
			std::string title;
			bool fullscreen;
		};

		void InitializeWindow (const WindowStruct& window);
		void TestDrawTriangle ();

	}
}
