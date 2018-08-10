#pragma once

#include "../Graphics_OpenGL.hpp"
#include <iostream>

namespace amaneshi
{
	namespace opengl
	{
		// this is not how it might work in the future
		// but its okay to break hello world code.

		const char* vertex_shader =
			"#version 400\n"
			"in vec3 vp;"
			"void main() {"
			"  gl_Position = vec4(vp, 1.0);"
			"}";
		const char* fragment_shader =
			"#version 400\n"
			"out vec4 frag_colour;"
			"void main() {"
			"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
			"}";

		PolygonShader HelloWorld2()
		{
			PolygonShader newShader;
			newShader.VertexString = vertex_shader;
			newShader.FragmentString = fragment_shader;
			std::cout << "=======================" << std::endl;
			std::cout << newShader.VertexString << std::endl;
			std::cout << "=======================" << std::endl;
			std::cout << newShader.FragmentString << std::endl;
			std::cout << "=======================" << std::endl;

			return newShader;
		}

		PolygonShader HelloWorld()
		{
			PolygonShader newShader;
			newShader.VertexString = 
				#include "HelloWorld.vs"
			;
			newShader.FragmentString =
				#include "HelloWorld.fs"
			;
			std::cout << "=======================" << std::endl;
			std::cout << newShader.VertexString << std::endl;
			std::cout << "=======================" << std::endl;
			std::cout << newShader.FragmentString << std::endl;
			std::cout << "=======================" << std::endl;

			return newShader;
		}
		
	}
}
