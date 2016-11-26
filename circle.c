#include <windows.h>
#include <glut.h>
#include <math.h>
#include<stdlib.h>
#include <stdio.h>

int x,y,p,xc,yc,r;
void lol ( int xc, int yc,int x, int y)
{
	
    glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);
    glVertex2i(xc+y,yc+x);
    glVertex2i(xc-y,yc+x);
    glVertex2i(xc+y,yc-x);
    glVertex2i(xc-y,yc-x);

}
void drawCircle(int xc,int yc,int r){
	
	glPointSize(1.0);

    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,1.0);
lol(xc,yc,x,y);

    x=0;
    y=r;
    p=1-r;
while(x<y)
{
	x++;
    if(p<0)
       p=p+2*x+1;
    else
	{     y=y-1;
        p=p+2*(x-y)+1;
	} 

lol(xc,yc,x,y);
}
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
 	glColor3f (1.0, 0.0, 0.0);
    drawCircle(xc,yc,r);
    glutSwapBuffers();
}

int main(int argc, char** argv){
	printf("Enter the centre and radius wrt the corner : "); 
    scanf("%d %d %d",&xc,&yc,&r);
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(50,50);
    glutCreateWindow("CIRCLE");
    init();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
