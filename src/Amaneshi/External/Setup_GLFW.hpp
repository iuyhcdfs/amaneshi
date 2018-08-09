#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Graphics_Interface.hpp"
#include "Input_Interface.hpp"
#include "Sound_Interface.hpp"

namespace amaneshi 
{
	namespace glfw 
	{
		// just call this
		void StartGLFW();

		void InitializeWindow(const amaneshi::graphics::WindowStruct& window);
		void UpdateWindow();
		void PollInput();

		/*
		glfw callbacks exist for WINDOW:
			position == no need
			resize == need to resize
			close == try to shut down everything
			content refresh == ?? what is that
			framebuffer resize == ?? need research
			focus/defocus == change game tick efficiency
			iconify/restore == same as focus/defocus?
			^ above two need some kinda sleep stalling or whatever

			you can also make the above things happen. 
			this is more for, some kind of data-handling application
			rather than a game.
		*/
	}
}
