#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>

float r,h,k;

void init()
{
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-500,500,-500,500);
}

void writepixel(int x,int y)
{
    glPointSize(1);
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glColor3f(1,1,1);
    glEnd();
    glFlush();
}
void display()
{
    glBegin(GL_LINES);
    glVertex2f(0,-500);
 glVertex2f(0,500);
 glEnd(); glBegin(GL_LINES);
    glVertex2f(-500,0);
 glVertex2f(500,0);
 glEnd();


    int x=0+h,y=r+k;
    double d=5.0/4.0-r;
    writepixel(x,y);
    while(x<y)
    {
        if(d<0)
        {
            d+=2.0*x+3.0;

        }
        else
        {
            d+=2.0*(x-y)+5.0;
            y--;
        }
        x++;
        writepixel(x,y);
           writepixel(y,x);
       writepixel(x,-y);
       writepixel(y,-x);
       writepixel(-x,y);
       writepixel(-y,x);
       writepixel(-x,-y);
       writepixel(-y,-x);


    }


}
int main(int argc,char **argv)
{
    printf("Enter the radius of the circle:-");
    scanf("%f",&r);
     printf("Enter the co-ordinates for the center of the circle\n");
    scanf("%f%f",&h,&k);

    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Midpoint circle algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
