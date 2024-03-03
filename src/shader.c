#include <stdio.h>
#include <stdlib.h>
#include "include/shader.h"
#include "include/utils.h"

static GLuint getShader(GLenum type, const char* src){
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);
    // Check vertex shader compilation
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::%s::COMPILATION_FAILED\n%s\n", type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT", infoLog);
        exit(1);
    }
    return shader;
}

GLuint getShaderProgram(const char* vertexFile, const char *fragmentFile){
    GLuint shaderProgram = glCreateProgram();
    GLuint vertShader = getShader(GL_VERTEX_SHADER, readFile(vertexFile));
    GLuint fragShader = getShader(GL_FRAGMENT_SHADER, readFile(fragmentFile));
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    return shaderProgram;
}