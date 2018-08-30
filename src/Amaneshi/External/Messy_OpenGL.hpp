#pragma once

#include <Amaneshi/External_Modes.hpp>
#ifdef GRAPHICS_OPENGL

#include <vector>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace amaneshi
{
	namespace opengl
	{
		// the ACTUAL shader here, plug and play things in the neighbouring folder OpenGLShaders
		class Shader
		{
		protected:
		public:
			Shader() {};
			
			std::string VertexString;
			std::string FragmentString;
			
			GLuint ShaderProgram;
			GLuint VertexBufferObject;
			GLuint VertexArrayObject;
			GLuint VertexShader;
			GLuint FragmentShader;

			virtual void CompileShaders() = 0;
			virtual void Draw() = 0;
		};

		class PolygonShader : public Shader
		{
		public:
			GLuint PointCount;
			GLuint Dimensions = 3;
			float * Points;

			void CompileShaders() override;
			void Draw() override;
		};

		class SphereShader : public Shader
		{
		public:
			float * Location;
			float Radius;
			void CompileShaders() override;
			void Draw() override;
		};

		/*
		no you DONT need a "circle shader" class
		because the best way to make a circle is not via some dumb polygon
		you need SHADERS and MATH
		that should be the first port of call.

		vector graphics is more math like
		i mean the better you are at describing things mathematically the more interesting you can make things

		*/


	} // namespace opengl
} // namespace amaneshi

#endif // GRAPHICS_OPENGL
