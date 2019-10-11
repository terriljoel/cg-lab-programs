
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float house[2][9]={{100.0,100.0,175.0,250.0,250.0,150.0,150.0,200.0,200.0},{100.0,300.0,400.0,300.0,100.0,100.0,150.0,150.0,100.0}};
float theta;
float h=175.0,k=400.0;
void drawhouse()
{
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][0],house[1][0]);
    glVertex2f(house[0][1],house[1][1]);
    glVertex2f(house[0][3],house[1][3]);
    glVertex2f(house[0][4],house[1][4]);
    glEnd();
    glColor3f(1,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][5],house[1][5]);
    glVertex2f(house[0][6],house[1][6]);
    glVertex2f(house[0][7],house[1][7]);
    glVertex2f(house[0][8],house[1][8]);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][1],house[1][1]);
    glVertex2f(house[0][2],house[1][2]);
  glVertex2f(house[0][3],house[1][3]);
  glEnd();
  glFlush();


}
void display()
{
    int i;
    float m[16],p,q;
    p=-h*(cos(theta)-1)+k*(sin(theta));
    q=-k*(cos(theta)-1)-h*(sin(theta));
    for(i=0;i<15;i++)
    m[i]=0.0;
        m[0]=cos(theta);
        m[1]=sin(theta);
        m[4]=-sin(theta);
        m[5]=cos(theta);
        m[12]=p;
        m[13]=q;
        m[10]=1;
        m[15]=1;
        //glMatrixMode(GL_MODELVIEW);
        glClear(GL_COLOR_BUFFER_BIT);
        drawhouse();
        glPushMatrix();
        glMultMatrixf(m);
        drawhouse();
        glPopMatrix();
        glFlush();
}
void init()
{
    glClearColor(1,1,1,1);
    //glMatrixMode(GL_PROJECTION);
    glColor3f(1,1,0);
    //glLoadIdentity();
    gluOrtho2D(0,499,0,499);
   // glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
    printf("Enter the angle of rotation\n");
    scanf("%f",&theta);
    theta=(theta*3.14)/180;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("House Rotation");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;


}




