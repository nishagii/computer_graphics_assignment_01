#include <GL/glut.h>
#include <iostream>
#include <algorithm>

using namespace std;

// Global variables for start and end points (initialized to 0)
int x0, y_start, x1, y_end;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Bresenham's line drawing algorithm for slope 0 < m < 1
void bresenhamLine(int x0, int y_start, int x1, int y_end)
{
    if (x0 > x1)
    {
        swap(x0, x1);
        swap(y_start, y_end);
    }

    int dx = x1 - x0;
    int dy = y_end - y_start;

    int x = x0;
    int y = y_start;

    int p = 2 * dy - dx;

    plot(x, y);

    while (x < x1)
    {
        x++;
        if (p < 0)
        {
            p += 2 * dy;
        }
        else
        {
            y++;
            p += 2 * dy - 2 * dx;
        }
        plot(x, y);
    }
}

void init()
{
    glClearColor(1, 1, 1, 1); // white background
    glColor3f(0, 0, 0);       // black points
    glPointSize(2.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    bresenhamLine(x0, y_start, x1, y_end);
    glFlush();
}

int main(int argc, char **argv)
{
    cout << "Enter the coordinates of the start point (x0 y_start): ";
    cin >> x0 >> y_start;

    cout << "Enter the coordinates of the end point (x1 y_end): ";
    cin >> x1 >> y_end;

    cout << "Drawing Bresenham's Line from (" << x0 << ", " << y_start << ") to (" << x1 << ", " << y_end << ")\n";

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing (0 < m < 1)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
