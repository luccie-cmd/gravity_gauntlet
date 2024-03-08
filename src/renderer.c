#include "include/renderer.h"
#include "include/shader.h"
#include "include/utils.h"
#include "include/vao.h"
#include "include/vbo.h"

static Vector2 switchToOpenGLCoords(Vector2 coords){
    Vector2 openGLVector;
    // Convert x coordinate
    openGLVector.x = (coords.x / 1920.0f) * 2.0f - 1.0f;
    // Convert y coordinate
    openGLVector.y = 1.0f - (coords.y / 1080.0f) * 2.0;
    return openGLVector;
}

void RenderTriangle(Vector2 p1,Vector2 p2, Vector2 p3, Color color){
    Vector2 openglp1, openglp2, openglp3;
    openglp1 = switchToOpenGLCoords(p1);
    openglp2 = switchToOpenGLCoords(p2);
    openglp3 = switchToOpenGLCoords(p3);

    GLuint shaderProgram = getShaderProgram("./shaders/shader.vert", "./shaders/shader.frag");

    GLfloat vertices[] = {
        openglp1.x, openglp1.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        openglp2.x, openglp2.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        openglp3.x, openglp3.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
    };

    Vao vao = getVAO();
    Vbo vbo = getVBO(GL_ARRAY_BUFFER, GL_TRUE);

    bindVAO(vao);

    setVBOBuffer(vbo, vertices, sizeof(vertices));

    setVAOAttrib(vao, vbo, 0, 3, GL_FLOAT, 7*sizeof(float), 0);
    setVAOAttrib(vao, vbo, 1, 4, GL_FLOAT, 7*sizeof(float), 3*sizeof(float));

    glUseProgram(shaderProgram);
    bindVAO(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RenderQuad(Vector2 top_left, Vector2 bottom_right, Color color){
    Vector2 opengl_tl, opengl_br;
    opengl_tl = switchToOpenGLCoords(top_left);
    opengl_br = switchToOpenGLCoords(bottom_right);
    
    GLuint shaderProgram = getShaderProgram("./shaders/shader.vert", "./shaders/shader.frag");
    
    GLfloat vertices[] = {
        opengl_tl.x, opengl_tl.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        opengl_tl.x, opengl_br.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        opengl_br.x, opengl_tl.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        opengl_br.x, opengl_br.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
    };
    
    // Indices for vertices order
    GLuint indices[] = {
    	0, 1, 2, // Upper triangle
    	1, 2, 3 // Lower triangle
    };

    Vao vao = getVAO();
    Vbo vbo = getVBO(GL_ARRAY_BUFFER, GL_TRUE);
    Vbo ebo = getVBO(GL_ELEMENT_ARRAY_BUFFER, GL_TRUE);

    bindVAO(vao);

    setVBOBuffer(vbo, vertices, sizeof(vertices));
    setVBOBuffer(ebo, indices, sizeof(indices));
    setVAOAttrib(vao, vbo, 0, 3, GL_FLOAT, 7*sizeof(float), 0);
    setVAOAttrib(vao, vbo, 1, 4, GL_FLOAT, 7*sizeof(float), 3*sizeof(float));

    glUseProgram(shaderProgram);
    bindVAO(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}