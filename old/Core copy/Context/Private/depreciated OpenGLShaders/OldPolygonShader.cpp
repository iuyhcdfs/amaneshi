#include <string>
#include "../Graphics_Interface.hpp"
#include "../Messy_OpenGL.hpp"

namespace amaneshi
{
	namespace opengl
	{

		void OldPolygonShader::CompileShaders()
		{
			const char * vs = VertexString.c_str();
			const char * fs = FragmentString.c_str();

			glGenBuffers(1, &this->VertexBufferObject);
			glBindBuffer(GL_ARRAY_BUFFER, this->VertexBufferObject);
			glBufferData(GL_ARRAY_BUFFER,
				this->PointCount * this->Dimensions * sizeof(float),
				this->Points,
				GL_STATIC_DRAW);

			// vertex array?
			this->VertexArrayObject = 0;
			glGenVertexArrays(1, &this->VertexArrayObject);
			glBindVertexArray(this->VertexArrayObject);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, this->VertexBufferObject);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

			// making the shader here
			this->VertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(this->VertexShader, 1, &vs, NULL);
			glCompileShader(this->VertexShader);
			// we have two shaders.
			this->FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(this->FragmentShader, 1, &fs, NULL);
			glCompileShader(this->FragmentShader);

			// shaders need to join this
			this->ShaderProgram = glCreateProgram();
			glAttachShader(this->ShaderProgram, this->VertexShader);
			glAttachShader(this->ShaderProgram, this->FragmentShader);
			glLinkProgram(this->ShaderProgram);
		}

		void OldPolygonShader::Draw()
		{
			// just using tempdraw for now

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram(this->ShaderProgram);
			glBindVertexArray(this->VertexArrayObject);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, PointCount);
		}


	} // namespace opengl
} // namespace amaneshi
