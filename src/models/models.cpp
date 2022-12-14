#include "models.h"
#include <stdio.h>
#include <string.h>

bool loadOBJ(const char *path, std::vector<glm::vec3> &out_vertices,
             std::vector<glm::vec2> &out_uvs,
             std::vector<glm::vec3> &out_normals) {
  std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
  std::vector<glm::vec3> temp_vertices;
  std::vector<glm::vec2> temp_uvs;
  std::vector<glm::vec3> temp_normals;

  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("Impossible to open the file !\n");
    return false;
  }

  while (true) {
    char lineHeader[128];
    // Read first word of each line
    int res = fscanf(file, "%s", lineHeader);
    if (res == EOF) {
      break;
    }

    if (strcmp(lineHeader, "v") == 0) {
      glm::vec3 vertex;
      fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
      temp_vertices.push_back(vertex);
    } else if (strcmp(lineHeader, "vt") == 0) {
      glm::vec2 uv;
      fscanf(file, "%f %f\n", &uv.x, &uv.y);
      uv.y = -uv.y;
      temp_uvs.push_back(uv);
    } else if (strcmp(lineHeader, "vn") == 0) {
      glm::vec3 normals;
      fscanf(file, "%f %f %f\n", &normals.x, &normals.y, &normals.z);
      temp_normals.push_back(normals);
    } else if (strcmp(lineHeader, "f") == 0) {
      int vertexIndex[3], uvIndex[3], normalIndex[3];
      int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                           &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                           &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                           &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
      if (matches != 9) {
        printf("File can't be read by our simple parser : ( Try exporting with "
               "other options\n");
        return false;
      }
      vertexIndices.push_back(vertexIndex[0]);
      vertexIndices.push_back(vertexIndex[1]);
      vertexIndices.push_back(vertexIndex[2]);
      uvIndices.push_back(uvIndex[0]);
      uvIndices.push_back(uvIndex[1]);
      uvIndices.push_back(uvIndex[2]);
      normalIndices.push_back(normalIndex[0]);
      normalIndices.push_back(normalIndex[1]);
      normalIndices.push_back(normalIndex[2]);
    } else {
      // Probably comment, remove rest of line
      char buff[1000];
      fgets(buff, 1000, file);
    }
  }
  // For each vertex of each triangle
  for (unsigned int i = 0; i < vertexIndices.size(); i++) {

    // Get the indices of its attributes
    unsigned int vertexIndex = vertexIndices[i];
    unsigned int uvIndex = uvIndices[i];
    unsigned int normalIndex = normalIndices[i];

    // Get the attributes thanks to the index
    glm::vec3 vertex = temp_vertices[vertexIndex - 1];
    glm::vec2 uv = temp_uvs[uvIndex - 1];
    glm::vec3 normal = temp_normals[normalIndex - 1];

    // Put the attributes in buffers
    out_vertices.push_back(vertex);
    out_uvs.push_back(uv);
    out_normals.push_back(normal);
  }
  fclose(file);
  return true;
}
