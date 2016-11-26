#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include<stdlib.h>
#include <stdio.h>

int x,y,px,py,rrx2,rry2,rx2,ry2,p;
void drawEllipse(int xc,int yc,int rx,int ry){

    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,1.0);
	glPointSize(10.0);

    glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);

	ry2=ry*ry;
	rx2=rx*rx;
	rrx2=2*rx2;
	rry2=2*ry2;

    x=0;
    y=ry;

	p=(int)(ry2-rx2*ry+(0.25*rx2));
	px=0;
	py=rrx2*y;

	while(px<py)
	{
		x=x+1;
		px=px+rry2;
		if(p>=0)
		{
			y=y-1;
			py=py-rrx2;
		}
		if(p<0)
			p=p+ry2+px;
		else
			p=p+ry2+px-py;

	glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);

	}

	p=(int)(ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2);

	while(y>0)
	{
		y=y-1;
		py=py-rrx2;

		if(p<=0)
		{
			x=x+1;
			px=px+rry2;
		}

		if(p>0)
			p=p+rx2-py;
		else
			p=p+rx2-py+px;

	glVertex2i(xc+x,yc+y);
    glVertex2i(xc-x,yc+y);
    glVertex2i(xc+x,yc-y);
    glVertex2i(xc-x,yc-y);

	}


  glEnd();
}

void init(void){
    glClearColor(0.0,.0,.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,100.0,0.0,100,0.0,100.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawEllipse(40,40,30,15);
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(50,50);
    glutCreateWindow("ELLIPSE");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
