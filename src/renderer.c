#include "include/renderer.h"
#include "include/shader.h"
#include "include/utils.h"
#include "include/vao.h"
#include "include/vbo.h"
#include <stdio.h>
#include <math.h>

static Vector2 switchToOpenGLCoords(Vector2 coords){
    Vector2 openGLVector;
    // Convert x coordinate
    openGLVector.x = (coords.x / 1280.0f) * 2.0f - 1.0f;
    // Convert y coordinate
    openGLVector.y = 1.0f - (coords.y / 720.0f) * 2.0;
    return openGLVector;
}

void RenderTriangle(Vector2 p1,Vector2 p2, Vector2 p3, Color color){
    printf("Renderering triangle!\n");
    Vector2 openglp1, openglp2, openglp3;
    openglp1 = switchToOpenGLCoords(p1);
    openglp2 = switchToOpenGLCoords(p2);
    openglp3 = switchToOpenGLCoords(p3);
    printf("Coords = `\n");
    printf("p1 = %f, %f\n", openglp1.x, openglp1.y);
    printf("p2 = %f, %f\n", openglp2.x, openglp2.y);
    printf("p3 = %f, %f`\n", openglp3.x, openglp3.y);
    GLuint shaderProgram = getShaderProgram("./shaders/triangle.vert", "./shaders/triangle.frag");
    printf("Shader program compiled handle N: %ld\n", shaderProgram);
    GLfloat vertices[] = {
        openglp1.x, openglp1.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        openglp2.x, openglp2.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        openglp3.x, openglp3.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
    };
    printf("Made vertices\n");
    Vao vao = getVAO();
    printf("Vao gotten\n");
    Vbo vbo = getVBO(GL_ARRAY_BUFFER, GL_FALSE);
    printf("Vbo gotten\n");
    bindVAO(vao);
    bindVBO(vbo);

    setVBOBuffer(vbo, vertices, sizeof(vertices));
    printf("Vbo attribute set\n");
    setVAOAttrib(vao, vbo, 0, 3, GL_FLOAT, 7*sizeof(float), 0);
    setVAOAttrib(vao, vbo, 1, 4, GL_FLOAT, 7*sizeof(float), 3*sizeof(float));
    printf("VAo attribute set\n");

    printf("Drawing\n");
    glUseProgram(shaderProgram);
    bindVAO(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    printf("Drawing complete\n");
}
void RenderQuad(Vector2 top_left, Vector2 bottom_right, Color color){}