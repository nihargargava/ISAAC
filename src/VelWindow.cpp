#include"everything.h"

#define VelScale 20

int BeingDrawn;
int start[2];
int fin[2];



void mouse3(int button, int state, int x, int y)
{
    switch(button)
    {   case GLUT_LEFT_BUTTON:  if(state==GLUT_DOWN &&lastState == GLUT_UP)
                                {
                                    BeingDrawn=1;
                                    start[0]=x;
                                    start[1]=y;

                                }
                                if(state==GLUT_UP &&lastState == GLUT_DOWN)
                                {
                                    BeingDrawn=0;
                                    fin[0]=x;
                                    fin[1]=y;
                                    double Velo[2];
                                    double r[2];
                                    r[0]=(start[0]-200)/400.0;
                                    r[1]=(start[1]-200)/400.0;
                                    Velo[0]=(fin[0]-start[0])/400.0*VelScale;
                                    Velo[1]=(-fin[1]+start[1])/400.0*VelScale;
                                    ToDraw->Lvel[0]+=Velo[0];
                                    ToDraw->Lvel[1]+=Velo[1];

                                    double Avelo=r[0]*Velo[1]-Velo[0]*r[1];
                                    ToDraw->Avel+=Avelo;

                                    ToDraw=NULL;
                                    glutDestroyWindow(glutGetWindow());
                                    glutSetWindow(LayerWindow);


                                }

                                break;
    }
    lastState=state;
}

void motionMouse3(int x,int y)
{
    start[0]=(x-200)/400.0;
    start[1]=-(y-200)/400.0;
}

void init4()//Used to define windows. Used by GLUT
{
  //  glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200.0/700,200.0/700,-200.0/700,200.0/700,-1.0,1.0);
   	glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    BeingDrawn=0;
    start[0]=fin[0]=start[1]=fin[1]=-1000;

}

char instructions2[]="Click And Drag to add velocity";

void MakePolygon3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3dv(ToDraw->Color);
    glBegin(GL_POLYGON);
        for(int i=0;i<ToDraw->NumVertices;i++)
            glVertex2dv(ToDraw->LocalSpaceList[i]);
    glEnd();
    glLineWidth(2.0);
    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<ToDraw->NumVertices;i++)
            glVertex2dv(ToDraw->LocalSpaceList[i]);
    glEnd();
    MakeDot(0,0);
    if(BeingDrawn)
    {

        MakeDot((start[0]-200)/700.0,-((start[1]-200)/700.0));

        MakeDot((fin[0]-200)/700.0,-((fin[1]-200)/700.0));
        glBegin(GL_LINE_LOOP);
            glVertex2d((start[0]-200)/700.0,-((start[1]-200)/700.0));
            glVertex2d((fin[0]-200)/700.0,-((fin[1]-200)/700.0));
        glEnd();
        MakeDot(0,0);

    }
    else
    {   MakeDot((start[0]-200)/700.0,-((start[1]-200)/700.0));
        MakeDot((fin[0]-200)/700.0,-((fin[1]-200)/700.0));

    }
    text(instructions2,-0.2,-0.05,0);


    glutSwapBuffers();

    if(-1000!=fin[0] && -1000!=fin[1] && BeingDrawn==0)
    {
        ToDraw=NULL;
        glutDestroyWindow(glutGetWindow());
        glutSetWindow(LayerWindow);


    }

}

void motion3(int x,int y)
{   MakeDot((x-200)/700.0,-((y-200)/700.0));

    fin[0]=x;
    fin[1]=y;
}


void VelWindow()
{
    glutInitWindowSize(400,400);
	glutCreateWindow("Put in some Velocity");
	glutPositionWindow(840,40);
    init4();
	glutDisplayFunc(MakePolygon3);
	glutMouseFunc(mouse3);
	glutPassiveMotionFunc(motionMouse3);
	glutMotionFunc(motion3);


}
