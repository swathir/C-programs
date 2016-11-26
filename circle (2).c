#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include<stdlib.h>
#include <stdio.h>

int x,y,p;
void drawCircle(int xc,int yc,int r,int xx,int yy,int xx1,int yy1,int xx2,int yy2){
	/*
	glPointSize(10.0);

    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,1.0);

    glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);
    glVertex2i(xc+y,yc+x);
    glVertex2i(xc-y,yc+x);
    glVertex2i(xc+y,yc-x);
    glVertex2i(xc-y,yc-x);

    x=0;
    y=r;
    p=1-r;
while(x<y)
{
	if(p<0)
    {
        x=x+1;
    }
    else
    {
        x=x+1;
        y=y-1;
    }

    if(p<0)
       p=p+2*x+1;
    else
        p=p+2*(x-y)+1;

    glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);
    glVertex2i(xc+y,yc+x);
    glVertex2i(xc-y,yc+x);
    glVertex2i(xc+y,yc-x);
    glVertex2i(xc-y,yc-x);
}
glEnd();*/

glBegin(GL_TRIANGLE);
glVertex2i(xx,yy);
glVertex2i(xx1,yy1);
glVertex2i(xx2,yy2);
        glEnd();
}

void init(void){  //
    glClearColor(0.0,.0,.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,100.0,0.0,100,0.0,100.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(40,40,30,1,2,7,14,9,2);
    glutSwapBuffers();//
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Bresenham's Line Drawing!");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
