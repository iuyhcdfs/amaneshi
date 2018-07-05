#include <cstdio>
#include <iostream>
#include <thread>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//#define GLFW_DLL is it even necessary

int main(int argc, char* argv[]) {
	std::cout << "starting amaneshi" << std::endl;
	//std::cout << std::thread::hardware_concurrency() << std::endl;;
	if (!glfwInit()) {
		std::cout << "glfwInit() failed" << std::endl;
		return EXIT_FAILURE;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window) {
		std::cout << "glfwCreateWindow() failed" << std::endl;
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		std::cout << "glewInit() failed" << std::endl;
	}

	while (1) {
	
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}