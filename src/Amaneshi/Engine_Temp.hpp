#pragma once

#include <Amaneshi/External/Setup_GLFW.hpp>
#include <Amaneshi/External/Graphics_Interface.hpp>
#include <Amaneshi/External/Graphics_Primitives.hpp>
namespace amaneshi
{
	graphics::WindowStruct window;

	void TempSetup()
	{
		// using namespace amaneshi;
		
		glfw::StartGLFW();
		window.width = 1280;
		window.height = 800;
		window.title = "hello amaneshi";
		window.fullscreen = false;
		graphics::InitializeWindow(window);
	
		graphics::Polygon hello;
		hello.Points.push_back(graphics::Point(0.1, 0.1));
		hello.Points.push_back(graphics::Point(0.2, 0.2));
		hello.Points.push_back(graphics::Point(0.2, 0.4));
		hello.Points.push_back(graphics::Point(0.4, 0.3));
		hello.Points.push_back(graphics::Point(0.4, 0.1));
		hello.CompileShaders();
		while (1)
		{
			// draw triangle
			hello.Render();
			// put on screen
			graphics::UpdateWindow();
		}

	}
	
}