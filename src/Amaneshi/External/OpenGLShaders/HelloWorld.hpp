#pragma once

#include "../Messy_OpenGL.hpp"
#include <iostream>

namespace amaneshi
{
	namespace opengl
	{
		// this is not how it might work in the future
		// but its okay to break hello world code.

		PolygonShader HelloWorld()
		{
			PolygonShader newShader;
			newShader.VertexString = 
				#include "HelloWorld.vs"
			;
			newShader.FragmentString =
				#include "HelloWorld.fs"
			;
			return newShader;
		}
		
	}
}
