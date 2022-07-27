#include "glfw.h"
#include "../window/window.h"
#include <GL/glew.h>

int initializeWindowLibrary() {
  if (!glfwInit()) {
    return -1;
  }
  return 1;
}

void customKeyCallback(GLFWwindow *window, int key, int scancode, int action,
                       int mods) {
  Window *win = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
  win->keyCallback(key, scancode, action, mods);
}

void customMouseCallback(GLFWwindow *window, double xpos, double ypos) {
  Window *win = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
  win->mouseCallback(xpos, ypos);
}

void customResizeCallback(GLFWwindow *window, int width, int height) {
  Window *win = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
  win->resizeCallback(width, height);
}
