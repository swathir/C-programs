#include<glut.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int xa, ya, xb, yb;;

void display(void)
{
int dx=abs(xb-xa),dy= abs(yb-ya),i;
int p=2*dy-dx;
 int twoDy=2*dy,twoDyDx=2*(dy-dx);
int x,y,xEnd;
glBegin(GL_POINTS);

if(xa>xb)
{
x=xa;
y=yb;
xEnd=xa;
}

else
{ x=xa;
y=ya;
xEnd=xb;
}
glVertex2f(x,y);

while(x<xEnd)
 {
 x++;

   if(p<0)
   p+=twoDy;

   else
   {
   y++;
   p+=twoDyDx;
   }

 glVertex2f(x,y);
 }

 	glColor3f (1.0, 0.4, 1.0);
 	for(i=-100 ; i<=100 ; i++)
 	{
 		glVertex2s(i,0);
 		glVertex2s(0,i);
 	}

glEnd();
glFlush();
}

void init(void)
{
 	glClearColor (0.0, 0.0, 0.0, 0.0);
 	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

void main(int argc, char** argv)
{
printf("Enter the values of xa,ya,xb,yb bres : ");
scanf_s("%d%d%d%d",&xa,&ya,&xb,&yb);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
 	glutInitWindowPosition (100, 100);
    glutCreateWindow("DDA");
		init();
    glutDisplayFunc(display);
    glutMainLoop();
	return 0;
 
}