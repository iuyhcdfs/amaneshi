#include "Graphics_GLFW.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Input_GLFW.hpp"
#include "fpscounter.hpp"

// TEMP STUFF
// From Anton Gerdelan's opengl4 tutorials
// http://antongerdelan.net/opengl/hellotriangle.html
static const char* vertex_shader =
"#version 400\n"
"in vec3 vp;"
"void main() {"
"  gl_Position = vec4(vp, 1.0);"
"}";
static const char* fragment_shader =
"#version 400\n"
"out vec4 frag_colour;"
"void main() {"
"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
"}";

namespace amaneshi {
	
	namespace glfw {

		GLFWwindow * Window;

		void HookToAmaneshi() {
			if (amaneshi::graphics::Framework != "") {
				return;
			}
			amaneshi::graphics::Framework = "glfw";
			amaneshi::graphics::Initialize = Initialize;
			amaneshi::graphics::Terminate = Terminate;
		}

		void Initialize(amaneshi::graphics::WindowStruct windowParams) {

			if (!glfwInit()) {
				std::cerr << "ERROR: glfwInit failed" << std::endl;
				return;
			}
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			Window = glfwCreateWindow(640, 480, "lets make GO", NULL, NULL);
			if (!Window) {
				std::cerr << "ERROR: could not open window with GLFW3" << std::endl;
				glfwTerminate();
				return;
			}
			glfwMakeContextCurrent(Window);
			glfwSetKeyCallback(Window, amaneshi::glfw::KeyCallback);
			glfwSetMouseButtonCallback(Window, &amaneshi::glfw::ClickCallback);
			glfwSetCursorPosCallback(Window, &amaneshi::glfw::CursorPosCallback);

			glewExperimental = GL_TRUE;
			GLenum err = glewInit();
			if (GLEW_OK != err) {
				std::cerr << "ERROR: could not initalise GLEW" << std::endl;
				glfwTerminate();
				return;
			}

			// get version info
			const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
			const GLubyte* version = glGetString(GL_VERSION); // version as a string
			printf("Renderer: %s\n", renderer);
			printf("OpenGL version supported %s\n", version);

			// tell GL to only draw onto a pixel if the shape is closer to the viewer
			glEnable(GL_DEPTH_TEST); // enable depth-testing
			glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

								  /* OTHER STUFF GOES HERE NEXT */
			float points[] = {
				0.0f,  0.5f,  0.0f,
				0.5f, -0.5f,  0.0f,
				-0.5f, -0.5f,  0.0f
			};
			GLuint vbo = 0;
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);
			GLuint vao = 0;
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

			GLuint vs = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vs, 1, &vertex_shader, NULL);
			glCompileShader(vs);
			GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fs, 1, &fragment_shader, NULL);
			glCompileShader(fs);

			GLuint shader_programme = glCreateProgram();
			glAttachShader(shader_programme, fs);
			glAttachShader(shader_programme, vs);
			glLinkProgram(shader_programme);

			amaneshi::FpsCounter fpsCounter;

			while (!glfwWindowShouldClose(Window)) {
				// wipe the drawing surface clear
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glUseProgram(shader_programme);
				glBindVertexArray(vao);
				// draw points 0-3 from the currently bound VAO with current in-use shader
				glDrawArrays(GL_TRIANGLES, 0, 3);
				// update other events like input handling 
				glfwPollEvents();
				// put the stuff we've been drawing onto the display
				glfwSwapBuffers(Window);
				fpsCounter.Update();
			}
			return;
		}
		
		void Terminate() {
			glfwDestroyWindow(Window);
			glfwTerminate();
		}
	}
}