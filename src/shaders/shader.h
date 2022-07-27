#ifndef LOADSHADER_H_
#define LOADSHADER_H_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

class Shader {
  GLuint id;

public:
  GLuint init(const char *vertex_file_path, const char *fragment_file_path);
  void setUniform(const std::string &name, const glm::mat4 value);
  void setUniform(const std::string &name, const glm::vec3 value);
  void setUniform(const std::string &name, const GLuint value);
  void activate();
};
#endif // LOADSHADER_H_
