#include <GL/glut.h>

// Window dimensions
const int WIDTH = 500;
const int HEIGHT = 500;

void init()
{
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the 2D orthographic viewing region
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT); // left, right, bottom, top
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the line color to white
    glColor3f(1.0, 1.0, 1.0);

    // Draw line using OpenGL routines
    glBegin(GL_LINES);
    glVertex2i(180, 15); // Start point (x1, y1)
    glVertex2i(10, 145); // End point   (x2, y2)
    glEnd();

    glFlush(); // Force execution of GL commands
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single buffer, RGB mode
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Basic Line Drawing");

    init();                   // Set up projection and clear color
    glutDisplayFunc(display); // Set display callback

    glutMainLoop(); // Start the main event loop
    return 0;
}
