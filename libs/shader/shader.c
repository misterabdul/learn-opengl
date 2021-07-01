#include "glad.h"
#include "shader.h"

#include <stdio.h>
#include <stdlib.h>

#include <GLFW/glfw3.h>

char*
readText(const char* path)
{
  FILE* textFile = fopen(path, "r");

  fseek(textFile, 0, SEEK_END);
  int fileSize = ftell(textFile);
  fseek(textFile, 0, SEEK_SET);

  char* text = malloc(fileSize * sizeof(char));
  int i = 0;
  char ch;
  while ((ch = fgetc(textFile)) != EOF) {
    text[i++] = ch;
  }
  text[i] = '\0';
  return text;
}

Shader
Shader_construct(const char* vertexPath, const char* fragmentPath)
{
  char* vertexShaderSource = readText(vertexPath);
  char* fragmentShaderSource = readText(fragmentPath);

  // build and compile our shader program
  // ------------------------------------
  // vertex shader
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
  }
  // fragment shader
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  // check for shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
  }
  // link shaders
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  // check for linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  free(vertexShaderSource);
  free(fragmentShaderSource);

  Shader shader = malloc(sizeof(struct shader_t));
  shader->id = shaderProgram;

  return shader;
}

void
Shader_destruct(Shader* shader)
{
  free(*shader);
  *shader = NULL;
}

void
Shader_useProgram(const Shader shader)
{
  glUseProgram(shader->id);
}

void
Shader_deleteProgram(const Shader shader)
{
  glDeleteProgram(shader->id);
}

void
Shader_setBool(const Shader shader, const char* name, int value)
{
  glUniform1i(glGetUniformLocation(shader->id, name), value);
}

Shader_setInt(const Shader shader, const char* name, int value)
{
  glUniform1i(glGetUniformLocation(shader->id, name), value);
}

Shader_setFloat(const Shader shader, const char* name, float value)
{
  glUniform1f(glGetUniformLocation(shader->id, name), value);
}

Shader_set3Float(const Shader shader, const char* name, float x, float y, float z)
{
  glUniform3f(glGetUniformLocation(shader->id, name), x, y, z);
}
