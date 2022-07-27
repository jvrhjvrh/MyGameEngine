#include "window.h"
#include "../controls/keys.h"
#include "../glfw/glfw.h"
#include <functional>
#include <stdio.h>

Window::Window() {
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  glfwSetWindowUserPointer(window, this);
  glfwSetKeyCallback(window, customKeyCallback);
  glfwSetCursorPosCallback(window, customMouseCallback);
  glfwSetWindowSizeCallback(window, customResizeCallback);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::getMousePosition(int *x, int *y) {
  *x = mousePos[0];
  *y = mousePos[1];
}

void Window::getWindowSize(int *width, int *height) {
  *width = windowSize[0];
  *height = windowSize[1];
}

void Window::resizeCallback(int width, int height) {
  glViewport(0, 0, width, height);
  windowSize[0] = width;
  windowSize[1] = height;
}

void Window::keyCallback(int key, int scancode, int action, int mods) {
  if (action == GLFW_REPEAT) {
    return;
  }
  int mappedKey = Keys::mapKey(key);

  if (action == GLFW_PRESS) {
    keys[mappedKey] = KEYS_PRESS;
  } else if (action == GLFW_RELEASE) {
    keys[mappedKey] = KEYS_RELEASE;
  }
}

void Window::mouseCallback(double xpos, double ypos) {
  mousePos[0] = xpos;
  mousePos[1] = ypos;
}

void Window::makeWindowCurrent() { glfwMakeContextCurrent(window); }

int Window::windowShouldClose() { return glfwWindowShouldClose(window); }

int Window::getKeyStatus(int key) { return keys[key]; }

void Window::closeWindow() { glfwSetWindowShouldClose(window, GLFW_TRUE); }

void Window::update() {
  glfwSwapBuffers(window);
  updateKeys();
  updateTime();
}

void Window::updateKeys() {
  int keysSize = sizeof(keys) / sizeof(keys[0]);
  for (int i = 0; i < keysSize; i++) {
    switch (keys[i]) {
    case KEYS_PRESS:
      keys[i] = KEYS_HOLD;
      break;
    case KEYS_RELEASE:
      keys[i] = KEYS_NOTHING;
    }
  }
}

void Window::updateTime() {
  double currentTime = glfwGetTime();
  deltaTime = float(currentTime - lastTime);
  lastTime = currentTime;
}

int Window::windowSuccess() {
  if (window) {
    return true;
  }
  return false;
}
