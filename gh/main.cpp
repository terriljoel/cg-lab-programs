#include<stdio.h>
#include<GL/glut.h>

int xmin=100,ymin=100,xmax=200,ymax=200;
float t1=0,t2=1;
float p[4],q[4];
int x01,y01,x02,y02,x03,y03,x04,y04;

void init()
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);
}
void display()
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0);
    glVertex2f(xmin,ymin);
    glVertex2f(xmin,ymax);
    glVertex2f(xmax,ymax);
    glVertex2f(xmax,ymin);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x01,y01);
    glVertex2f(x02,y02);
    glEnd();
    glFlush();

}
void lineclip()
{
    int dx,dy;
    dx=x02-x01;
    dy=y02-y01;

    p[0]=-dx;
    p[1]=dx;
    p[2]=-dy;
    p[3]=dy;
    q[0]=x01-xmin;
    q[1]=xmax-x01;
    q[2]=y01-ymin;
    q[3]=ymax-y01;

    int i;

    float t;
    int f=0;
    for(i=0;i<4;i++)
    {
        if(p[i]==0)
        {
            if(q[i]<0)
                return;
        }
        if(p[i]<0)
        {
            t=q[i]/p[i];
            if(t>t1 && t<t2)
                t1=t;
        }
        else if(p[i]>0)
        {
            t=q[i]/p[i];
            if(t>t1 && t<t2)
                t2=t;

        }
        /*if(q[i]<0)
        {
            x01=y01=x02=y02=0;
        }*/
    }
    if(t1<t2)
    {
        x03=x01+t1*(x02-x01);
        y03=y01+t1*(y02-y01);
        x04=x01+t2*(x02-x01);
        y04=y01+t2*(y02-y01);
        if(x03>=xmin&&x03<=xmax&&y03>=ymin&&y03<=ymax){
        if(x04>=xmin&&x04<=xmax&&y04>=ymin&&y04<=ymax){
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(x03,y03);
        glVertex2f(x04,y04);
        glEnd();
        glFlush();}
        }
    }
}
void keypressed(unsigned char key,int x,int y)
{
    if(key=='c')
    {
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP);
        glColor3f(0,1,0);
         glVertex2f(xmin,ymin);
    glVertex2f(xmin,ymax);
    glVertex2f(xmax,ymax);
    glVertex2f(xmax,ymin);
    glEnd();
    glFlush();
    lineclip();


    }
}
int main(int argc,char **argv)
{
    printf("Enter the line co-ordinates\n");
    scanf("%d%d%d%d",&x01,&y01,&x02,&y02);
    glutInit(&argc,argv);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Liang_barsky");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keypressed);
    glutMainLoop();

}
