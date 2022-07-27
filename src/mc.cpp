#include "controls/keys.h"
#include "game/game.h"
#include "glfw/glfw.h"
#include "models/models.h"
#include "shaders/shader.h"
#include "textures/loadTextures.h"
#include "window/window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <stdio.h>

#include "components/component.h"
#include "entities/entityHandle.hpp"
// position
glm::vec3 position = glm::vec3(0, 0, 5);
// horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
// Initial Field of View

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;

glm::vec3 direction(cos(verticalAngle) * sin(horizontalAngle),
                    sin(verticalAngle),
                    cos(verticalAngle) * cos(horizontalAngle));
glm::vec3 right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0,
                            cos(horizontalAngle - 3.14f / 2.0f));
glm::vec3 up = glm::cross(right, direction);
float FoV = 90;
double currentMouseX = 0;
double currentMouseY = 0;

void controlLoop(Window window) {
  float deltaTime = window.deltaTime;
  // Close window when esc is pressed
  if (window.getKeyStatus(KEYS_ESCAPE) == KEYS_PRESS)
    window.closeWindow();

  // Move forward
  {
    int action = window.getKeyStatus(KEYS_W);
    if (action == KEYS_PRESS || action == KEYS_HOLD) {
      position += direction * deltaTime * speed;
    }
  }
  // Move backward
  {
    int action = window.getKeyStatus(KEYS_S);
    if (action == KEYS_PRESS || action == KEYS_HOLD) {
      position -= direction * deltaTime * speed;
    }
  }
  // Strafe right
  {
    int action = window.getKeyStatus(KEYS_D);
    if (action == KEYS_PRESS || action == KEYS_HOLD) {
      position += right * deltaTime * speed;
    }
  }
  // Strafe left
  {
    int action = window.getKeyStatus(KEYS_A);
    if (action == KEYS_PRESS || action == KEYS_HOLD) {
      position -= right * deltaTime * speed;
    }
  }
  int x, y;
  window.getWindowSize(&x, &y);
  int xpos, ypos;
  window.getMousePosition(&xpos, &ypos);
  horizontalAngle += mouseSpeed * deltaTime * float(currentMouseX - xpos);
  verticalAngle += mouseSpeed * deltaTime * float(currentMouseY - ypos);
  currentMouseX = xpos;
  currentMouseY = ypos;
  if (verticalAngle > 0.9f) {
    verticalAngle = 0.9f;
  }
  if (verticalAngle < -0.9f) {
    verticalAngle = -0.9f;
  }
  direction =
      glm::vec3(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle),
                cos(verticalAngle) * cos(horizontalAngle));
  right = glm::vec3(sin(horizontalAngle - 3.14f / 2.0f), 0,
                    cos(horizontalAngle - 3.14f / 2.0f));
  up = glm::cross(right, direction);
}

struct Position : Component<Position> {
  int x, y, z;
  Position(int x, int y, int z) : x(x), y(y), z(z){};
};

int main() {
  Game game = Game();
  EntityHandle gameObject = game.createEntity();
  gameObject.addComponent<Position>(Position(1, 2, 3));
  auto test = gameObject.getComponent<Position>();
  printf("%d %d %d", test->x, test->y, test->z);
  // if (initializeWindowLibrary() == -1) {
  //   return -1;
  // }
  // Window window = Window();

  // if (!window.windowSuccess()) {
  //   glfwTerminate();
  //   return -1;
  // }

  // window.makeWindowCurrent();
  // if (glewInit() != GLEW_OK) {
  //   return -1;
  // }

  // GLuint VertexArrayID;
  // glGenVertexArrays(1, &VertexArrayID);
  // glBindVertexArray(VertexArrayID);

  // // Read our .obj file
  // std::vector<glm::vec3> vertices;
  // std::vector<glm::vec2> uvs;
  // std::vector<glm::vec3> normals; // Won't be used at the moment.
  // bool res = loadOBJ(
  //     "/home/jvrh/Documents/estudos/gameEngine/resources/models/cube.obj",
  //     vertices, uvs, normals);

  // GLuint vertexBuffer;
  // glGenBuffers(1, &vertexBuffer);
  // glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  // glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
  //              &vertices[0], GL_STATIC_DRAW);

  // GLuint uvBuffer;
  // glGenBuffers(1, &uvBuffer);
  // glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
  // glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0],
  //              GL_STATIC_DRAW);

  // GLuint normalbuffer;
  // glGenBuffers(1, &normalbuffer);
  // glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
  // glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3),
  // &normals[0],
  //              GL_STATIC_DRAW);

  // Shader shader = Shader();
  // int programID = shader.init("/home/jvrh/Documents/estudos/gameEngine/"
  //                             "resources/shaders/basicVertShader.vert",
  //                             "/home/jvrh/Documents/estudos/gameEngine/"
  //                             "resources/shaders/basicFragShader.frag");

  // GLuint texture = loadDDS("/home/jvrh/Documents/estudos/gameEngine/"
  //                          "resources/textures/uvmap.DDS");

  // // enable depth test
  // glEnable(GL_DEPTH_TEST);
  // glEnable(GL_CULL_FACE);

  // // Accept fragments closer to the screen and hides the one farther even if
  // // drawn after
  // glDepthFunc(GL_LESS);

  // // Get a handle for our "LightPosition" uniform
  // shader.activate();
  // while (!window.windowShouldClose()) {
  //   controlLoop(window);
  //   // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1
  //   // unit
  //   // <-> 100 units
  //   glm::mat4 Projection =
  //       glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
  //   // Or, for an ortho camera :
  //   // glm::mat4 Projection =
  //   glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f);
  //   // In world coordinates

  //   // Camera matrix
  //   glm::mat4 View = glm::lookAt(position, position + direction, up);

  //   // Model matrix : an identity matrix (model will be at the origin)
  //   glm::mat4 Model = glm::mat4(1.0f);

  //   // Our ModelViewProjection : multiplication of our 3 matrices
  //   glm::mat4 MVP =
  //       Projection * View *
  //       Model; // Remember, matrix multiplication is the other way around
  //   glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  //   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //   shader.setUniform("MVP", MVP);
  //   shader.setUniform("M", Model);
  //   shader.setUniform("V", View);

  //   glm::vec3 lightPos = glm::vec3(4, 4, 4);
  //   shader.setUniform("LightPosition_worldspace", lightPos);
  //   // Bind our texture in Texture Unit 0
  //   glActiveTexture(GL_TEXTURE0);
  //   glBindTexture(GL_TEXTURE_2D, texture);

  //   shader.setUniform("myTextureSampler", 0);

  //   glEnableVertexAttribArray(0);
  //   glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  //   glUseProgram(programID);
  //   glVertexAttribPointer(0, // attribute 0. No particular reason for 0, but
  //                            // must match the layout in the shader.
  //                         3, // size
  //                         GL_FLOAT, // type
  //                         GL_FALSE, // normalized?
  //                         0,        // stride
  //                         (void *)0 // array buffer offset
  //   );

  //   glEnableVertexAttribArray(1);
  //   glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
  //   glVertexAttribPointer(1, // attribute. No particular reason for 1, but
  //   must
  //                            // match the layout in the shader.
  //                         2, // size
  //                         GL_FLOAT, // type
  //                         GL_FALSE, // normalized?
  //                         0,        // stride
  //                         (void *)0 // array buffer offset
  //   );

  //   glEnableVertexAttribArray(2);
  //   glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
  //   glVertexAttribPointer(2,        // attribute
  //                         3,        // size
  //                         GL_FLOAT, // type
  //                         GL_FALSE, // normalized?
  //                         0,        // stride
  //                         (void *)0 // array buffer offset
  //   );

  //   glDrawArrays(GL_TRIANGLES, 0, vertices.size());
  //   // Swap buffers to draw on screen
  //   window.update();

  //   glfwPollEvents();
  // }

  // // Close openGL and terminate GLFW
  // glfwTerminate();
  return 0;
}
