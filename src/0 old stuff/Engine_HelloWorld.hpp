#pragma once

#include <Amaneshi/External/Setup_GLFW.hpp>
#include <Amaneshi/External/Graphics_Interface.hpp>
#include <Amaneshi/External/Graphics_Classes.hpp>
#include <Amaneshi/External/OpenGLShaders/HelloWorld.hpp>
#include <Amaneshi/Internal/Math_Position.hpp>

// a temp engine setup just to make helloworld work

// engine standard will be more general and accomodating for any single-windowed game

namespace amaneshi
{
	graphics::WindowStruct window;
	graphics::Polygon hello;

	void TempSetup()
	{
		
		glfw::StartGLFW();
		window.width = 1280;
		window.height = 800;
		window.title = "hello amaneshi";
		window.fullscreen = false;
		graphics::InitializeWindow(window);
		
		hello.GLShader = amaneshi::opengl::HelloWorld();
		hello.Points.push_back(amaneshi::math::Point(-0.8, -0.8, 0.0));
		hello.Points.push_back(amaneshi::math::Point(-0.5, 0.8, 0.0));
		hello.Points.push_back(amaneshi::math::Point(0.6, -0.7, 0.0));
		hello.Points.push_back(amaneshi::math::Point(1, 0, 0.0));
		hello.Points.push_back(amaneshi::math::Point(0.5, 1, 0.0));
		/*
		hello.Points.push_back(amaneshi::math::Point(-0.5, -0.5,  0.0));
		hello.Points.push_back(amaneshi::math::Point(-0.5,  0.5,  0.0));
		hello.Points.push_back(amaneshi::math::Point(-0.2,  0.5,  0.0));
		hello.Points.push_back(amaneshi::math::Point(-0.2,  0.0,  0.0));
		hello.Points.push_back(amaneshi::math::Point( 0.2,  0.0,  0.0));
		hello.Points.push_back(amaneshi::math::Point( 0.2,  0.5,  0.0));
		hello.Points.push_back(amaneshi::math::Point( 0.5,  0.5,  0.0));
		hello.Points.push_back(amaneshi::math::Point( 0.5, -0.8,  0.0));
		*/
		hello.CompileShaders();	
	}
	void TempUpdate()
	{
		// draw triangle
		hello.Render();
		// put on screen
		graphics::UpdateWindow();
		input::PollInput();
	}
}