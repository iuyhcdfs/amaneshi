#pragma once

#include <Amaneshi/External_Modes.hpp>
#include <Amaneshi/External/Graphics_Window.hpp>
namespace amaneshi
{
	namespace engine
	{
		graphics::WindowStruct Window;

		void Initialize() 
		{
			Window.width = 1280;
			Window.height = 800;
			Window.title = "hello amaneshi";
			Window.fullscreen = false;
			graphics::InitializeWindow(Window);

			// shaders are already built into code
			// but could already split task to read shader files

			// establish a base game world perhaps?

			// menu stuff
		}

	}
}