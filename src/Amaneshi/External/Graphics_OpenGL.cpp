#include <string>
#include "Graphics_Primitives.hpp"
#include "Graphics_OpenGL.hpp"

namespace amaneshi
{
	namespace opengl
	{
		void PolygonShader::CompileShaders()
		{
			const char * vs = VertexString.c_str();
			const char * fs = FragmentString.c_str();

			glGenBuffers(1, &this->VertexBufferObject);
			glBindBuffer(GL_ARRAY_BUFFER, this->VertexBufferObject);
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), this->Points, GL_STATIC_DRAW);
			
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

		void PolygonShader::Draw()
		{
			// just using tempdraw for now

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram(this->ShaderProgram);
			glBindVertexArray(this->VertexArrayObject);
			glDrawArrays(GL_TRIANGLES, 0, PointCount);
		}


		/*
		// TEMP STUFF
		// From Anton Gerdelan's opengl4 tutorials
		// http://antongerdelan.net/opengl/hellotriangle.html
		static GLuint shader_programme;
		static GLuint vao;
		void TempShader() {

			// take vertices
			float points[] = {
				0.0f,  0.5f,  0.0f,
				0.5f, -0.5f,  0.0f,
				-0.5f, -0.5f,  0.0f
			};

			// google up:
			// these things, vertex buffer/array objects 
			// are graphics card container abstractions
			// obviously theyre fast then.

			// buffers?
			GLuint vbo = 0;
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);
			
			// vertex array?
			vao = 0;
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

			// making the shader here
			GLuint vs = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vs, 1, &vertex_shader, NULL);
			glCompileShader(vs);
			// we have two shaders.
			GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fs, 1, &fragment_shader, NULL);
			glCompileShader(fs);

			// the heck is a program
			shader_programme = glCreateProgram();
			glAttachShader(shader_programme, fs);
			glAttachShader(shader_programme, vs);
			glLinkProgram(shader_programme);
			// once we link apparently we can delete this other stuff?

			// so is this mainly a startup thing?
		}
		void TempDraw() {
			// wipe the drawing surface clear
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram(shader_programme);
			glBindVertexArray(vao);
			// draw points 0-3 from the currently bound VAO with current in-use shader
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		void Shader::CompileString()
		{
		this->String = "";
		// INs

		// OUTs

		// UNIFORMs
		this->String += "void main() {";
		{
		// PROCESS

		// PIPE TO OUTPUT

		}
		this->String += "}";
		}
		*/
	} // namespace opengl
} // namespace amaneshi
