#ifndef WINDOW_H_
#define WINDOW_H_
#include <GLFW/glfw3.h>

class Window {
public:
  Window();
  void keyCallback(int key, int scancode, int action, int mods);
  void mouseCallback(double xpos, double ypos);
  void resizeCallback(int width, int height);
  void makeWindowCurrent();
  int getKeyStatus(int key);
  void getMousePosition(int *x, int *y);
  void getWindowSize(int *width, int *height);
  int windowShouldClose();
  void closeWindow();
  void update();
  int windowSuccess();
  void windowResizeCallback(GLFWwindow window, int height, int width);
  float deltaTime;

private:
  GLFWwindow *window;
  float lastTime = 0;
  void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                   int mods);
  void updateTime();
  void updateKeys();
  double mousePos[2];
  int keys[120];
  int windowSize[2];
};

#endif // WINDOW_H_
