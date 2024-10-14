#include <stdio.h>

#define _GLFW_WIN32
#include <GLFW/glfw3.h>
#include <assert.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")

void error_callback(int error_code, const char* description) {
  fprintf(stderr, "glfw failed with %d : %s", error_code, description);
}

int main(int argument_count, const char *arguments[]) {
  (void)argument_count;
  (void)arguments;


  assert(glfwInit());
  glfwSetErrorCallback(error_callback);


  GLFWwindow *window = glfwCreateWindow(680, 480, "Hello world", NULL, NULL);
  if(!window) {
    goto end;
  }


  while(!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
end:
  glfwTerminate();
  return 0;
}
