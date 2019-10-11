
#include<stdio.h>
#include<GL/glut.h>
#define maxx 10
#define maxy 10
#define dx 20
#define dy 20
float x[maxx+1],y[maxy+1],x0=100,y0=100;
int i,j;

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    for(i=0;i<=maxx;i++)
        x[i]=x0+i*dx;
    for(j=0;j<=maxy;j++)
        y[j]=y0+j*dy;
        //glColor3f(1,0,1);
    for(i=0;i<maxx;i++)
        for(j=0;j<maxy;j++)
    {

        glBegin(GL_LINE_LOOP);
        glVertex2f(x[i],y[j]);
         glVertex2f(x[i],y[j+1]);
          glVertex2f(x[i+1],y[j+1]);
           glVertex2f(x[i+1],y[j]);
           glEnd();
    }
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,500);
    glutCreateWindow("Polygon mesh");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
