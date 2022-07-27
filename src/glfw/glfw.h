#ifndef GLFW_H_
#define GLFW_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

int initializeWindowLibrary();
void customKeyCallback(GLFWwindow *window, int key, int scancode, int action,
                       int mods);
void customMouseCallback(GLFWwindow *window, double xpos, double ypos);
void customResizeCallback(GLFWwindow *window, int width, int height);

#endif // GLFW_H_
