#ifndef SHADER_H
#define SHADER_H

typedef struct shader_t {
	int id;
} * Shader;

Shader Shader_construct(const char* vertexPath, const char* fragmentPath);

void Shader_destruct(Shader* shader);

void Shader_useProgram(const Shader shader);

void Shader_deleteProgram(const Shader shader);

void Shader_setBool(const Shader shader, const char* name, int value);

void Shader_setInt(const Shader shader, const char* name, int value);

void Shader_setFloat(const Shader shader, const char* name, float value);

void Shader_set3Float(const Shader shader, const char* name, float x, float y, float z);

void Shader_setMat4(const Shader shader, const char* name, float* value);

#endif
