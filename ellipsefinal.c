#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
//#include <stdlib.h>

int h,k;
float a,b;


void display(void)
{
 	int i,j;
 	glClear (GL_COLOR_BUFFER_BIT);// clear buffers to preset values
 	glColor3f (0.0, 1.0, 0.0);
 	glBegin(GL_POINTS);
 	glVertex2s(h,k); //short
 	for( i=0 ; i<=a ; i+=1)
 	{ 
 		j=(int)(sqrt(1 - (i*i)/(a*a))*b);
 		glVertex2s(h+i,k+j);
 		glVertex2s(h-i,k+j);
 		glVertex2s(h-i,k-j);
 		glVertex2s(h+i,k-j);
 	}
 	glColor3f (1.0, 1.0, 1.0);
 	for(i=-100 ; i<=100 ; i++)
 	{
 		glVertex2s(i,0);
 		glVertex2s(0,i);
 	}
 	
 	glEnd();
 	glFlush();//force execution of GL commands in finite time
}

void init(void)
{
 	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0); // multiply the current matrix with an orthographic matrix
}

int main(int argc, char** argv)
{
 	printf("Enter the center wrt axis \n");
 	scanf("%d %d",&h,&k);
 	printf("Enter a and b \n");
 	scanf("%f %f",&a,&b);
 	glutInit(&argc, argv); //initialize glut library
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// sets the initial display mode index/color
 	glutInitWindowSize (500, 500);
 	glutInitWindowPosition (900, 100);
 	glutCreateWindow ("ELLIPSE");
 	init ();
 	glutDisplayFunc(display);
 	glutMainLoop();
 	return 0;
}
