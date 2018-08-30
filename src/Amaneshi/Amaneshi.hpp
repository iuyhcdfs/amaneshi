#pragma once

#define WINDOW_GLFW
#define GRAPHICS_OPENGL

#include <Amaneshi/Game_World.hpp>
#include <Amaneshi/External/Window.hpp>

namespace amaneshi
{
	namespace engine
	{		
		graphics::WindowStruct MainWindow;
		game::World * MainWorld;

		void Initialize() 
		{
			window::StartGLFW();

			MainWindow.width = 1280;
			MainWindow.height = 800;
			MainWindow.title = "hello amaneshi";
			MainWindow.fullscreen = false;
			graphics::InitializeWindow(MainWindow);
		}

		void CreateWorld() {

		}

		void MainThreadUpdate()
		{
			graphics::UpdateWindow();
			input::PollInput();

			// thread::Sync();
			// time::FPS();
		}
	}
}
