/* Midpoint line algorithm */
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int x00,y00,x01,y01;


void init()
{
          glClearColor(1,1,1,1);
          glClear(GL_COLOR_BUFFER_BIT);
          glMatrixMode(GL_PROJECTION);
          gluOrtho2D(-500,500,-500,500);
}

void writepixel(int x,int y)
{
        //glPointSize(4);
        glBegin(GL_POINTS);       //WRITE PIXEL
                glColor3f(0,0,0);
                glVertex2f(x,y);
        glEnd();
        glFlush();
}
void display()
{
  float dx=x01-x00 , dy = y01-y00;
  float d = 2*dy-dx;
  float incrE = dy;
  float incrNE = dy - dx;

  int x=x00,y=y00;

  writepixel(x,y);

  if (1 >= abs(dy / dx))
  {
      while(x<x01)
     {
        x=x+1;
        if(d<=0)
        {
                d=d+2*incrE;

         }
        else
       {
                d=d+2*incrNE;
                y=y+1;
       }
        writepixel(x,y);
    }
  }

  else
  {
        d = 2*dx - dy;
        incrE = dx;
        incrNE = dx - dy;

        while(y<y01)
        {
                y=y+1;
                if(d<=0)
                {
                        d=d+2*incrE;

                 }
                else
               {
                        d=d+2*incrNE;
                        x=x+1;
               }
                writepixel(x,y);
        }
  }
}

int main(int argc,char *argv[])
{

  printf("Enter the values \n");
  printf("x0="); scanf("%d",&x00);
  printf("y0="); scanf("%d",&y00);
  printf("x1="); scanf("%d",&x01);
  printf("y1="); scanf("%d",&y01);

  glutInit(&argc,argv);
  glutInitWindowSize(500,500);
  glutCreateWindow("MIDPOINT LINE ALGORITHM");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
