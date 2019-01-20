#pragma once
#include <vector>
#include <string>
namespace amaneshi 
{
	namespace graphics 
	{
		extern std::string Library;
		extern std::string API;
		struct WindowStruct 
		{
			int width;
			int height;
			std::string title;
			bool fullscreen;
		};

		void InitializeWindow (const WindowStruct& window);
		void UpdateWindow();

	}
}
