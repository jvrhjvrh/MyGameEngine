#include "keys.h"
#include <GLFW/glfw3.h>

int Keys::mapKey(int key) {
  switch (key) {
  case GLFW_KEY_SPACE:
    return 0;
  case GLFW_KEY_APOSTROPHE:
    return 1;
  case GLFW_KEY_COMMA ... GLFW_KEY_9:
    return key - 42;
  case GLFW_KEY_SEMICOLON:
    return 16;
  case GLFW_KEY_EQUAL:
    return 17;
  case GLFW_KEY_A ... GLFW_KEY_RIGHT_BRACKET:
    return key - 47;
  case GLFW_KEY_WORLD_1:
    return 48;
  case GLFW_KEY_WORLD_2:
    return 49;
  case GLFW_KEY_ESCAPE ... GLFW_KEY_END:
    return key - 206;
  case GLFW_KEY_CAPS_LOCK ... GLFW_KEY_PAUSE:
    return key - 216;
  case GLFW_KEY_F1 ... GLFW_KEY_F25:
    return key - 221;
  case GLFW_KEY_KP_0 ... GLFW_KEY_KP_EQUAL:
    return key - 226;
  case GLFW_KEY_LEFT_SHIFT ... GLFW_KEY_MENU:
    return key - 229;
  default:
    return 0;
  }
}
