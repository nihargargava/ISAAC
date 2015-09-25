#include"everything.h"
int MainWindow;
int VertInd;

void mousewheel2(int button,int state, int x, int y)
{   FirstTime2=0;
    switch(state)
    {
        case 1: ToDraw->NumVertices=(ToDraw->NumVertices==49)?ToDraw->NumVertices:ToDraw->NumVertices+1;
                break;
        case -1:ToDraw->NumVertices=(ToDraw->NumVertices==VertInd+1 || ToDraw->NumVertices==3)?ToDraw->NumVertices:ToDraw->NumVertices-1;
                break;
    }
}


void mouse(int button, int state, int x, int y)
{   FirstTime2=0;

    switch(button)
    {   case GLUT_LEFT_BUTTON:  if(state==GLUT_UP &&lastState == GLUT_DOWN)
                                {

                                    ToDraw->LocalSpaceList[VertInd][0]=(x-200)/700.0;
                                    ToDraw->LocalSpaceList[VertInd][1]=-(y-200)/700.0;
                                    printf("\n(%lf,%lf)",ToDraw->LocalSpaceList[VertInd][0],ToDraw->LocalSpaceList[VertInd][1]);
                                    if(VertInd>0)
                                        if(ToDraw->LocalSpaceList[VertInd][0]!=ToDraw->LocalSpaceList[VertInd-1][0]  &&  ToDraw->LocalSpaceList[VertInd][1]!=ToDraw->LocalSpaceList[VertInd-1][1])
                                            VertInd++;
                                    if(VertInd==0)VertInd++;
                                    if(VertInd>=ToDraw->NumVertices)
                                    {   ToDraw->FillEnvSpaceList();
                                        ToDraw->UpdateParameters();
                                        ToDraw->Spin=0;
                                        ToDraw=NULL;
                                        glutDestroyWindow(glutGetWindow());
                                        glutSetWindow(LayerWindow);

                                    }
                                }

                                break;
    }
    lastState=state;
}

void motionMouse(int x,int y)
{
    ToDraw->LocalSpaceList[VertInd][0]=(x-200)/700.0;
    ToDraw->LocalSpaceList[VertInd][1]=-(y-200)/700.0;

}

void init2()//Used to define windows. Used by GLUT
{
  //  glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200.0/700,200.0/700,-200.0/700,200.0/700,-1.0,1.0);
   	glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


}
char hello3[100];
char no2[2];
char instructions[]="Make sure that the polygon is an anticlockwise\ndrawn convex polygon.";

void MakePolygon()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    for(int i=0;i<=VertInd;i++)
        MakeDot(ToDraw->LocalSpaceList[i]);
    glColor3dv(ToDraw->Color);
    glBegin(GL_POLYGON);
        for(int i=0;i<=VertInd;i++)
            glVertex2dv(ToDraw->LocalSpaceList[i]);
    glEnd();
    glLineWidth(2.0);
    glColor3d(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<=VertInd;i++)
            glVertex2dv(ToDraw->LocalSpaceList[i]);
    glEnd();


    MakeDot(0,0);


    no2[0]=(ToDraw->NumVertices-VertInd)/10+'0';
    no2[1]=(ToDraw->NumVertices-VertInd)%10+'0';
    strcpy(hello3,"Vertices Left:   ");
    strcat(hello3,no2);
    text(hello3,-0.22,-0.15,1);
    text(instructions,-0.2,-0.05,0);


    glutSwapBuffers();

}

void DrawWindow()
{
    glutInitWindowSize(400,400);
	glutCreateWindow("Draw a polygon here");
	glutPositionWindow(840,40);
    init2();
	glutDisplayFunc(MakePolygon);
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(motionMouse);
	glutMouseWheelFunc(mousewheel2);
}
