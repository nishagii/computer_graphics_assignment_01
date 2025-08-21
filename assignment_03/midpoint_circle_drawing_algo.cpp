#include <GL/glut.h>
#include <iostream>
using namespace std;

int xc, yc, r; // Circle center and radius

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Function to plot all 8 symmetric points
void plotCirclePoints(int xc, int yc, int x, int y)
{
    plot(xc + x, yc + y);
    plot(xc - x, yc + y);
    plot(xc + x, yc - y);
    plot(xc - x, yc - y);
    plot(xc + y, yc + x);
    plot(xc - y, yc + x);
    plot(xc + y, yc - x);
    plot(xc - y, yc - x);
}

// Midpoint Circle Drawing Algorithm
void midpointCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    plotCirclePoints(xc, yc, x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotCirclePoints(xc, yc, x, y);
    }
}

void init()
{
    glClearColor(1, 1, 1, 1); // White background
    glColor3f(0, 0, 0);       // Black points
    glPointSize(2.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500); // 2D orthographic projection
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    midpointCircle(xc, yc, r);
    glFlush();
}

int main(int argc, char **argv)
{
    // eg: 250 250 r = 100
    cout << "Enter the center of the circle (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    cout << "Drawing Midpoint Circle at (" << xc << ", " << yc << ") with radius " << r << "\n";

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
