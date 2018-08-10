#pragma once

#include <Amaneshi/External/Setup_GLFW.hpp>
#include <Amaneshi/External/Graphics_Interface.hpp>
#include <Amaneshi/External/Graphics_Primitives.hpp>
#include <Amaneshi/External/OpenGLShaders/HelloWorld.hpp>
namespace amaneshi
{
	graphics::WindowStruct window;
	graphics::Polygon hello;

	void TempSetup()
	{
		// using namespace amaneshi;
		
		glfw::StartGLFW();
		window.width = 1280;
		window.height = 800;
		window.title = "hello amaneshi";
		window.fullscreen = false;
		graphics::InitializeWindow(window);
		
		hello.GLShader = amaneshi::opengl::HelloWorld();
		hello.Points.push_back(graphics::Point(-0.5, -0.5, 0.0));
		hello.Points.push_back(graphics::Point(0.3, 0.8, 0.0));
		hello.Points.push_back(graphics::Point(0.6, -0.7, 0.0));
		hello.CompileShaders();	
	}
	void TempUpdate()
	{
		// draw triangle
		hello.Render();
		// put on screen
		graphics::UpdateWindow();
	}
}