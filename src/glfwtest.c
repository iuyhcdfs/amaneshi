// main.c
#include <GLFW/glfw3.h>
int main(void) {
  if (!glfwInit()) return -1;
  GLFWwindow* window = glfwCreateWindow(320, 240, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glClearColor(0.5f, 0.5f, 1.0f, 0.0f);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
