#ifndef GAME_SHADER_H
#define GAME_SHADER_H
#include <glad/glad.h>
typedef GLuint Shader;

Shader createShader(const char * vertexPath, const char * fragmentPath);
void uniform1f(Shader shader, const char * name, float x);
void uniform2f(Shader shader, const char * name, float x, float y);
void uniform4f(Shader shader, const char * name, float x, float y, float z, float a);
void setMat4(Shader shader, const char * name, float * x);
#endif //GAME_SHADER_H
