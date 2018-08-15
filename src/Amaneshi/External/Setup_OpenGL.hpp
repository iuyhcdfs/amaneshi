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
		
		class Shader
		{
		protected:
			Shader() {};
		public:
			// int id?
			
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

		/*class CircleShader : public Shader
		{
		public:
			float position;
			float radius;
			GLuint Dimensions = 2;
			GLuint Resolution;

			void CompileShaders() override;
			void Draw() override;
		};*/


	} // namespace opengl
} // namespace amaneshi
