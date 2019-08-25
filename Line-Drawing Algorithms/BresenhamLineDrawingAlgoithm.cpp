//Author Manish sharma
//Computer Graphics Lab Work
//All rights reserved
//Command to compile file is :    g++ main.cpp -o firstOpenGlApp -lglut -lGLU -lGL
#include<GL/glut.h> //graphics Library 
#include<stdlib.h>
#include<math.h>

void myinit(void)
{
 
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // multiply the current matrix by identity matrix
	gluOrtho2D (0.0,640.0,0.0,480.0);
 }
 
float xstart=200 ,ystart=300,xend=200,yend=400,x,y;

int Round(float a)//any x i.e 1>=a>=0.5 is rounded to 1
{
  if(a-int(a)>=0.5)
  return int(a)+1;
  else
  return int(a);
     }

void BresenhamAlgo()
     {   
      int dx=xend-xstart;
      int dy=yend-ystart;
	int p=2*dy-dx;
	glBegin(GL_POINTS);
	glVertex2i(xstart,ystart);
	glEnd();
	while(xstart<xend)
	{
	
	xstart=xstart+1;
	if(p<0)
	{
	p=p+2*dy;	
	}
	else
	{
	ystart+=1;
	p=p+(2*dy-2*dx);
	}
	glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
       glVertex2i(xstart,ystart);//sets vertex
	   glEnd();
	}

  
  glutPostRedisplay(); 
  } 
       
void display(void)
{  
     
    glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call     
    glColor3f(0,0,1); // sets the current drawing (foreground) color to blue 
    glPointSize(3); // sets the size of points to be drawn (in pixels)
    BresenhamAlgo();// calls programmer defined function(drawline)
    glFlush(); // flushes the frame buffer to the screen
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize(640,480);//sets the width and height of the window in pixels
    glutInitWindowPosition(100,100);//sets the position of the window in pixels from top left corner 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
    glutCreateWindow("Bresenham Line Drawing Algorithm");//creates the window as specified by the user as above.
	myinit();
	glutDisplayFunc(display);//links the display event with the display event handler(display)
    glutIdleFunc(BresenhamAlgo);
    glutMainLoop();//loops the current event
}
