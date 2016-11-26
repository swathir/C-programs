#include<glut.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define ROUND(a) ((int)(a+0.5))
int xa, ya, xb, yb;

void display(void)
{
int dx=xb-xa, dy=yb-ya, steps,k,i;
float xInc, yInc, x=xa,y=ya,m1,m,m2;
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 0.0, 0.0);

glBegin(GL_POINTS);


if(abs(dx)>abs(dy))
steps=abs(dx);

else steps=abs(dy);

if(dx==0)
{
for(k=0;k<steps;k++)
{
x=xa;
y+=1;

glVertex2s(ROUND(x),ROUND(y));
printf("%lf %lf\n",x,y);
//delay(1000);

}
goto loop;
}

if(dy==0)
{
for(k=0;k<steps;k++)
{
x+=1;
y=ya;

glVertex2s(ROUND(x),ROUND(y));
printf("%lf %lf\n",x,y);
//delay(1000);

}
goto loop;
}

m=xInc=dx/(float)steps;
m2=yInc=dy/(float)steps;
m1=dy/dx;

glVertex2s(ROUND(x),ROUND(y));

if(m1>0)
{
for(k=0;k<steps;k++)
{
x+=xInc;
y+=yInc;

glVertex2s(ROUND(x),ROUND(y));
printf("%lf %lf\n",x,y);
//delay(1000);

}
}

if(m1<0)
{
	x=xb;
	y=yb;

for(k=0;k<steps;k++)
{
x-=xInc;
y-=yInc;

glVertex2s(ROUND(x),ROUND(y));
printf("%lf %lf\n",x,y);
//delay(1000);

}
}

loop:

 	glColor3f (1.0, 1.0, 1.0);
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

printf("Enter the values of xa,ya,xb,yb dda : ");
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