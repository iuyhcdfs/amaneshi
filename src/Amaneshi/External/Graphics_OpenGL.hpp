#pragma once
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace amaneshi
{
	namespace opengl
	{
		// opengl unique stuff... its basically raw shaders n stuff
		

		struct PolygonShader
		{
			std::string VertexString;
			std::string FragmentString;

			//int ID;  //abstract our own ids?
			GLsizei PointSize;
			GLuint ShaderProgram;
			GLuint VertexBufferObject;
			GLuint VertexArrayObject;
			GLuint VertexShader;
			GLuint FragmentShader;

			void CompileShaders(std::vector<amaneshi::graphics::Point> points);
			void Draw();

		};


	} // namespace opengl
} // namespace amaneshi
