#include <stdio.h>
#include<GL/glut.h>

float x1,x2,x3,x4,y1,y2,y3,y4;

void draw_pixel(int x,int y)
{
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void edgedetect(float x1,float y1,float x2,float y2,int *le,int *re)
{
    float temp,x,mx;
    int i;

    if(y1>y2)
    {
        temp=x1,x1=x2,x2=temp;
        temp=y1,y1=y2,y2=temp;
    }

    if(y1==y2)
        mx=x2-x1;
    else
        mx=(x2-x1)/(y2-y1);

    x=x1;

    for(i=int(y1);i<=(int)y2;i++)
    {
        if(x<(float)le[i]) le[i]=(int)x;
        if(x>(float)re[i]) re[i]=(int)x;
        x+=mx;
    }
}

void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    int le[500],re[500],i,j;

    for(i=0;i<500;i++)
        le[i]=500,re[i]=0;

    edgedetect(x1,y1,x2,y2,le,re);
    edgedetect(x2,y2,x3,y3,le,re);
    edgedetect(x3,y3,x4,y4,le,re);
    edgedetect(x4,y4,x1,y1,le,re);

    for(j=0;j<500;j++)
    {
        if(le[j]<=re[j])
            for(i=le[j];i<re[j];i++)
                draw_pixel(i,j);
    }
}


void display()
{
    x1=250.0;y1=200.0;x2=150.0;y2=300.0;x3=250.0;
    y3=400.0;x4=350.0;y4=300.0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();

    scanfill(x1,y1,x2,y2,x3,y3,x4,y4);

    glFlush();
}


void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
}

void main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);

    glutCreateWindow("scanline");
    glutDisplayFunc(display);

    init();
    glutMainLoop();
}


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}


#include<stdio.h>
#include<GL/glut.h>

float x1,x2,x3,x4,y1,y2,y3,y4;

void draw_pixel(int x,int y)
{
    glColor3f(0.0,1.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void edgedetect(float x1,float y1,float x2,float y2,int *le,int *re)
{
    float temp,x,mx;
    int i;

    if(y1>y2)
    {
        temp=x1,x1=x2,x2=temp;
        temp=y1,y1=y2,y2=temp;
    }

    if(y1==y2)
        mx=x2-x1;
    else
        mx=(x2-x1)/(y2-y1);

    x=x1;
    int zz = (int)y1;
    int yy = (int) y2;
    for(i=zz;i<=yy;i++)
    {
        if(x<(float)le[i]) le[i]=(int)x;
        if(x>(float)re[i]) re[i]=(int)x;
        x+=mx;
    }
}

void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    int le[500],re[500],i,j;

    for(i=0;i<500;i++)
        le[i]=500,re[i]=0;

    edgedetect(x1,y1,x2,y2,le,re);
    edgedetect(x2,y2,x3,y3,le,re);
    edgedetect(x3,y3,x4,y4,le,re);
    edgedetect(x4,y4,x1,y1,le,re);

    for(j=0;j<500;j++)
    {
        if(le[j]<=re[j])
            for(i=le[j];i<re[j];i++)
                draw_pixel(i,j);
    }
}


void display()
{
    x1=250.0;y1=200.0;x2=350.0;y2=100.0;x3=250.0;
    y3=400.0;x4=350.0;y4=200.0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();

    scanfill(x1,y1,x2,y2,x3,y3,x4,y4);

    glFlush();
}


void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
}

void main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);

    glutCreateWindow("scanline");
    glutDisplayFunc(display);

    init();
    glutMainLoop();
}

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int h,k,r;
void scanline(int,int);
void circle(void);
void Axes(void);
 void display(void)
 {
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 0.0, 0.0);
 glBegin(GL_POINTS);
 circle();
 glEnd();
 glFlush();
 }
 void scanline(int ax, int by)
{
 int varx;
 for(varx=h+ax ; varx>=(h-ax) ; varx--)
 glVertex2s(varx,by);
}
void circle(void)
{
 double XEnd,J;
 int i,j;
 XEnd=(r/1.414);
 for( i=0 ; i<=XEnd ; i++)
 {
 J=sqrt(r*r - i*i);
 j=(int)(J);
 scanline(i, j);
 scanline(j, i);
 scanline(j,-i);
 scanline(i,-j);
 }
 Axes();
 glVertex3s(h,k,-25);
}
 void Axes(void)
{
 int i;
 glColor3f (1.0, 1.0, 1.0);
 for(i=-100 ; i<=100 ; i++)
 {
 glVertex2s(i,0);
 glVertex2s(0,i);
 }
 for(i=-2; i<=2 ; i++)
 {
 glVertex2s(95+i,4+i);
 glVertex2s(95-i,4+i);
 }
 for(i=0; i<=2 ; i++)
 {
 glVertex2s(4+i,95+i);
 glVertex2s(4-i,95+i);
 glVertex2s(4,95-i);
 }
}
 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 printf("Enter the center of circle:\n");
 scanf("%d %d",&h,&k);
 printf("Enter the radius:\n");
 scanf("%d",&r);
 glutCreateWindow ("Circle : Scanline Filling Method ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
