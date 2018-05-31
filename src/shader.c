#include <shader.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char * tryReadFile(const char * filePath) {
	FILE * file = fopen(filePath, "r");
	assert(file);
	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);
	char * result = malloc((size_t) (length + 1));
	assert(result);
	size_t read = fread(result, 1, (size_t) length, file);
	assert(read);
	result[length] = '\0';
	fclose(file);
	return result;
}

Shader createShader(const char * vertexPath, const char * fragmentPath) {
	GLchar * vertexData = tryReadFile(vertexPath);
	GLchar * fragmentData = tryReadFile(fragmentPath);
	// TODO: add error checking
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexData, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentData, NULL);
	glCompileShader(fragmentShader);
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	free(vertexData);
	free(fragmentData);
	return shaderProgram;
}

void uniform1f(Shader shader, const char * name, float x) {
	glUniform1f(glGetUniformLocation(shader, name), x);
}
void uniform2f(Shader shader, const char * name, float x, float y) {
	glUniform2f(glGetUniformLocation(shader, name), x, y);
}
void uniform4f(Shader shader, const char * name, float x, float y, float z, float a) {
	glUniform4f(glGetUniformLocation(shader, name), x, y, z, a);
}
void setMat4(Shader shader, const char * name, float * x) {
	glUniformMatrix4fv(glGetUniformLocation(shader, name), 1, GL_FALSE, x);
}