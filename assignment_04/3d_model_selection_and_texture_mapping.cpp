#include <GL/glut.h>
#include <iostream>
using namespace std;

GLuint texture;

void loadTexture()
{
    // Simple checkerboard texture (for demo, no external file needed)
    const int width = 64, height = 64;
    unsigned char data[width][height][3];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int c = (((i & 8) == 0) ^ ((j & 8) == 0)) * 255; // checker pattern
            data[i][j][0] = (unsigned char)c;
            data[i][j][1] = (unsigned char)c;
            data[i][j][2] = (unsigned char)c;
        }
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, data);
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    loadTexture();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    // Front face
    glTexCoord2f(0, 0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(1, 0);
    glVertex3f(1, -1, 1);
    glTexCoord2f(1, 1);
    glVertex3f(1, 1, 1);
    glTexCoord2f(0, 1);
    glVertex3f(-1, 1, 1);
    // Back face
    glTexCoord2f(0, 0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0);
    glVertex3f(1, -1, -1);
    glTexCoord2f(1, 1);
    glVertex3f(1, 1, -1);
    glTexCoord2f(0, 1);
    glVertex3f(-1, 1, -1);
    // Left face
    glTexCoord2f(0, 0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0);
    glVertex3f(-1, -1, 1);
    glTexCoord2f(1, 1);
    glVertex3f(-1, 1, 1);
    glTexCoord2f(0, 1);
    glVertex3f(-1, 1, -1);
    // Right face
    glTexCoord2f(0, 0);
    glVertex3f(1, -1, -1);
    glTexCoord2f(1, 0);
    glVertex3f(1, -1, 1);
    glTexCoord2f(1, 1);
    glVertex3f(1, 1, 1);
    glTexCoord2f(0, 1);
    glVertex3f(1, 1, -1);
    // Top face
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(1, 1);
    glVertex3f(1, 1, 1);
    glTexCoord2f(0, 1);
    glVertex3f(-1, 1, 1);
    // Bottom face
    glTexCoord2f(0, 0);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0);
    glVertex3f(1, -1, -1);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, 1);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, 1);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3, 3, 5, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Textured Cube");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
