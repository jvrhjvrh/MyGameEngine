#ifndef LOADTEXTURES_H_
#define LOADTEXTURES_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint loadBmp_custom(const char *imagepath);
GLuint loadDDS(const char *imagepath);

#endif // LOADTEXTURES_H_
