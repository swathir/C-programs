#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct line
{
   int sl;
   int x_intercept;
   int max_of_y;
   float slope;
   float inverse_slope;
   struct line* link;
};

line* buckets[200];


void create_SET(int scanline,int x_intercept,int ymax,float slope)
{
  int i;
  line* num=new line();
  num->x_intercept=x_intercept;
  num->max_of_y=ymax;
  num->slope=slope;
  num->inverse_slope=(float)1/slope;
  num->link=NULL;

  line* num1=buckets[scanline];
  while(num1->link!=NULL)
  {
	num1=num1->link;
  }
  num1->link=num;

}

void color_line(int y,int x1,int x2)
{
   glColor3f(1,0,0);
   glBegin(GL_POINTS);
     for(int i=x1;i<=x2;i++)
   	glVertex2f(i,y+150);

   glEnd();
   glFlush();

}


void scanline_color_fill()
{
  int counter=0;
   for(int i=0;i<200;)
   {
	line* num=new line();
	num=buckets[i]->link;
	cout<<i<<"\n";
	cout<<"Scanline\n";
	int miny_max=num->max_of_y;
	int count=0;
	while(num!=NULL)
	{
		if(num->max_of_y < miny_max)
			miny_max=num->max_of_y;
		num=num->link;
		count++;
	}

	for(int j=i;j<=miny_max;j++)
	{
		int x_coordinates[count];

		num=buckets[i]->link;
		while(num!=NULL)
		{

			int x=(j *(num->inverse_slope))+(num->x_intercept);
			x_coordinates[counter++]=x;
			num=num->link;
		}
		sort(x_coordinates,x_coordinates+count);
		for(int k=0;k<count;k+=2)
		  color_line(j,x_coordinates[k],x_coordinates[k+1]);
	}
        i=i+miny_max;
   }

}


void draw(void)
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,1,0);

  glBegin(GL_LINES);
	glVertex2f(250,150);
	glVertex2f(350,250);

	glVertex2f(350,250);
	glVertex2f(250,350);

	glVertex2f(250,350);
	glVertex2f(150,250);

	glVertex2f(150,250);
	glVertex2f(250,150);

  glEnd();
  glFlush();
  scanline_color_fill();
}

int main(int argc,char **argv)
{

  for(int i=0;i<300;i++)
  {
	line* num=new line();
	num->sl=i;
	num->link=NULL;
	buckets[i]=num;
  }

  create_SET(0,100,200,-1.00);
  create_SET(0,100,100,1.00);
  create_SET(100,-300,100,-1.00);
  create_SET(100,200,300,1.00);

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("scanline");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 glOrtho(0.0, 500.0, 0.0, 500.0,-1.0,1.0);

  glutDisplayFunc(draw);

  glutMainLoop();

  return 0;
}
