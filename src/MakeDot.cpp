#include"everything.h"


void MakeDot(double point[2])   //Makes a dot.
{
    double r=1;
    glColor3b(1.0,1.0,0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2d(point[0]+r*0.007,point[1]+r*0.007);
        glVertex2d(point[0],point[1]+r*0.00991);
        glVertex2d(point[0]-r*0.007,point[1]+r*0.007);
        glVertex2d(point[0]-r*0.00991,point[1]);
        glVertex2d(point[0]-r*0.007,point[1]-r*0.007);
        glVertex2d(point[0],point[1]-r*0.00991);
        glVertex2d(point[0]+r*0.007,point[1]-r*0.007);
        glVertex2d(point[0]+r*0.00991,point[1]);
    glEnd();
}
void MakeDot2(double point[2])   //Makes a dot.
{
    double r=1;
    glColor3b(1.0,1.0,0.0);
    glLineWidth(1.0);
    glBegin(GL_POLYGON);
        glVertex2d(point[0]+r*0.007,point[1]+r*0.007);
        glVertex2d(point[0],point[1]+r*0.00991);
        glVertex2d(point[0]-r*0.007,point[1]+r*0.007);
        glVertex2d(point[0]-r*0.00991,point[1]);
        glVertex2d(point[0]-r*0.007,point[1]-r*0.007);
        glVertex2d(point[0],point[1]-r*0.00991);
        glVertex2d(point[0]+r*0.007,point[1]-r*0.007);
        glVertex2d(point[0]+r*0.00991,point[1]);
    glEnd();
}
void MakeDot(double a, double b)
{
    double c[2];
    c[0]=a;
    c[1]=b;
    MakeDot(c);
}
