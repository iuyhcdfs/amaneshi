#pragma once
#include <GLFW/glfw3.h>

class printer {
public:
	int i;
	void test();
	void print();
    // without the pointer the struct wants the full implementation, and it's not ready yet huh.
    GLFWwindow * doesthiswork;
};