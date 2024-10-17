#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include "base.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

const char *vertex_shader_source =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char *fragment_shader_source =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";

void error_callback(int error_code, const char *description) {
  fprintf(stderr, "GLFW error %d:%s\n", error_code, description);
}

int main(int argument_count, const char *arguments[]) {
  fprintf(stdout, "Hello world\n");

  if(!glfwInit()) {
    return -1;
  }

  glfwSetErrorCallback(error_callback);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(1280, 1080, "Hello world", 0, 0);
  if(window == NULL) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  gladLoadGL();

  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };

  u32 VBO = {};
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glClearColor(1.0, 0.0, 0.0, 1.0);

  u32 vert_shader = glCreateShader(GL_VERTEX_SHADER);
  u32 frag_shader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vert_shader, 1, &vertex_shader_source, NULL);
  glShaderSource(frag_shader, 1, &fragment_shader_source, NULL);

  glCompileShader(vert_shader);
  glCompileShader(frag_shader);

  u32 shader_program = glCreateProgram();
  glAttachShader(shader_program, vert_shader);
  glAttachShader(shader_program, frag_shader);
  glLinkProgram(shader_program);

  glUseProgram(shader_program);

  glDeleteShader(vert_shader);
  glDeleteShader(frag_shader);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), (void*)0);
  glEnableVertexAttribArray(0);

  while(!glfwWindowShouldClose(window)) {
    double time = (double)glfwGetTime();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}

#include <glad/gl.c>
// #include "base.c"

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "opengl32.lib")

