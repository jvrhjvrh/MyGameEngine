#ifndef MODELS_H_
#define MODELS_H_

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>

bool loadOBJ(const char *path, std::vector<glm::vec3> &out_vertices,
             std::vector<glm::vec2> &out_uvs,
             std::vector<glm::vec3> &out_normals);

#endif // MODELS_H_
