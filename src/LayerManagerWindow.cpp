#include"everything.h"



int LayerIndex;
int BodyIndex[NoOfLayers];
int LayerWindow;
int MovePointer[2];

int Mode=1;

GLubyte X_sign[30]=
{0x00,0x00,
0x00,0x00,
0x70,0x1c,
0x38,0x38,
0x1c,0x70,
0x0e,0xe0,
0x07,0xc0,
0x03,0x80,
0x07,0xc0,
0x0e,0xe0,
0x1c,0x70,
0x38,0x38,
0x70,0x1c,
0x00,0x00,
0x00,0x00
};

GLubyte edit_sign[30]=
{0x00,0x00,
0x07,0xe0,
0x0c,0x30,
0x18,0x30,
0x30,0x09,
0x60,0x06,
0xc0,0x03,
0xc0,0x03,
0xc0,0x03,
0x60,0x06,
0x30,0x09,
0x18,0x30,
0x0c,0x30,
0x07,0xe0,
0x00,0x00};


button CloseButton("Close",X_sign,0.05,0.05,0.065,0.065);
button EditMode("Edit", edit_sign,0.05,0.15,0.065,0.065);
button MoveMode("Move", edit_sign,0.05,0.25,0.065,0.065);


void keydown2(int key,int x, int y) //Defines keyboard events. Used by GLUT
{  if(key==GLUT_KEY_UP)
    {
        LayerIndex=(LayerIndex==NoOfLayers-1)?LayerIndex:LayerIndex+1;
    }
    if(key==GLUT_KEY_DOWN)
    {
        LayerIndex=(LayerIndex==0)?LayerIndex:LayerIndex-1;
    }
    FirstTime2=0;
}

char hello2[100];
char no[2];
char follower[100];
char bottomer[100];
void make()//GLUT required function.
{   glClear(GL_COLOR_BUFFER_BIT);
 //   glClearColor((rand()%100)/100.0,(rand()%100)/100.0,(rand()%100)/100.0,1.0);
    glClearColor(1.0,1.0,1.0,1.0);
     printf("\nSpin=%lf",layer[0][0].Avel);
    //Render everything

    for(int i=0;i<BodyIndex[LayerIndex];i++)
    {
        if(layer[LayerIndex][i].Exists)
        {
            layer[LayerIndex][i].CheckSelect();
            layer[LayerIndex][i].Render();
        }
    }

    if(Mode==1)strcpy(follower,"Right Click an object to Choose Velocity\nLeft Click to Create/Edit");
    else if(Mode==2)strcpy(follower,"Right Click an object to Delete\nLeft Click and drag to Move");
    if(CloseButton.isPressed(CurrMousePos))strcpy(follower,"Press to close Layer Manager.");
    CloseButton.Render();

    if(EditMode.isPressed(CurrMousePos))strcpy(follower,"Press to go to Edit mode.");
    EditMode.Render();

    if(MoveMode.isPressed(CurrMousePos))strcpy(follower,"Press to go to Edit mode.");
    MoveMode.Render();




    if(Mode-1)MakeDot2(CurrMousePos);
    else MakeDot(CurrMousePos);

    no[0]=LayerIndex/10+'0';
    no[1]=LayerIndex%10+'0';
    strcpy(hello2,"Currently Layer is:   ");
    strcat(hello2,no);
    if(BodyIndex[LayerIndex]==BodiesPerLayer-1)strcat(hello2,"  (LAYER FULL!!!)");
    strcat(hello2,"\nBody number:   ");
    no[0]=BodyIndex[LayerIndex]/10+'0';
    no[1]=BodyIndex[LayerIndex]%10+'0';
    strcat(hello2,no);
    text(hello2,0.2,0.05,1);

    if(FirstTime2)text("Scroll to Change Layer. Click anwhere in Edit mode to add objects to the lair",0.3,0.50,0);

    text(follower,0.65,0.06,0);

    glutSwapBuffers();


}

void reshape2(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0,1.0*(w/700.0),0,1.0*(h/700.0),-1.0,1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void init3()//Used to define windows. Used by GLUT
{

    glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.0,1.0,-0.0,1.0,-1.0,1.0);
	glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    if(FirstTime2)
    {
        for(int k=0;k<NoOfLayers;k++)
            BodyIndex[k]=0;
        LayerIndex=0;
    }
    MovePointer[0]=-1;
    MovePointer[0]=-1;

}

void select2(int button, int state, int x, int y)
{

    switch(button)
    {   case GLUT_LEFT_BUTTON:  if(state==GLUT_UP &&lastState == GLUT_DOWN)
                                {   MovePointer[0]=-1;
                                    MovePointer[1]=-1;
                                    if(CloseButton.isPressed(CurrMousePos))
                                    {   glutDestroyWindow(glutGetWindow());
                                        glutSetWindow(MainWindow);
                                    }
                                    else if(EditMode.isPressed(CurrMousePos))
                                    {   Mode=1;
                                    }
                                    else if(MoveMode.isPressed(CurrMousePos))
                                    {   Mode=2;
                                    }
                                    else if(Mode==1)
                                    {   int none=0;

                                        for(int i=0;i<NoOfLayers;i++)
                                        {
                                            for(int j=0;j<BodiesPerLayer;j++)
                                            {
                                                if(layer[i][j].Exists)
                                                {   if(layer[i][j].SelFlag==1)
                                                    {   none=1;
                                                        layer[i][j].draw();
                                                    }
                                                }
                                            }
                                        }

                                        if(BodyIndex[LayerIndex]<BodiesPerLayer && layer[LayerIndex][BodyIndex[LayerIndex]].Exists==0 && none==0)
                                        {
                                            layer[LayerIndex][BodyIndex[LayerIndex]].Exists=1;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].IsConcrete=0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].IsGhost=0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].COM[0]=CurrMousePos[0];
                                            layer[LayerIndex][BodyIndex[LayerIndex]].COM[1]=CurrMousePos[1];
                                            layer[LayerIndex][BodyIndex[LayerIndex]].Color[0]=(rand()%100)/100.0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].Color[1]=(rand()%100)/100.0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].Color[2]=(rand()%100)/100.0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].density=Default_Density;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].g=g_default;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].NumVertices=5;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].Lvel[0]=0.0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].Lvel[1]=0.0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].Avel=0.0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].Spin=0.0;
                                            layer[LayerIndex][BodyIndex[LayerIndex]].draw();
                                            BodyIndex[LayerIndex]+=1;

                                        }
                                    }

                                }
                                if(lastState==GLUT_UP && state==GLUT_DOWN)
                                {
                                    if(Mode==2)
                                    {
                                        for(int i=0;i<NoOfLayers;i++)
                                        {
                                            for(int j=0;j<BodiesPerLayer;j++)
                                            {
                                                if(layer[i][j].Exists)
                                                {   if(layer[i][j].SelFlag==1)
                                                    {
                                                        MovePointer[0]=i;
                                                        MovePointer[1]=j;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                break;
        case GLUT_RIGHT_BUTTON: if(state==GLUT_UP && lastState == GLUT_DOWN && Mode==2)
                                {   for(int i=0;i<NoOfLayers;i++)
                                    {
                                        for(int j=0;j<BodiesPerLayer;j++)
                                        {
                                            if(layer[i][j].Exists)
                                            {   layer[i][j].CheckSelect();
                                                if(layer[i][j].SelFlag==1)
                                                {
                                                    for(int k=j;k<BodiesPerLayer-1;k++)
                                                    {
                                                        layer[i][k]=layer[i][k+1];
                                                    }
                                                    layer[i][BodiesPerLayer].Exists=0;
                                                    BodyIndex[LayerIndex]--;
                                                }
                                            }
                                        }
                                    }
                                }
                                else if(state==GLUT_UP && lastState == GLUT_DOWN && Mode==1)
                                {
                                    for(int i=0;i<NoOfLayers;i++)
                                    {
                                        for(int j=0;j<BodiesPerLayer;j++)
                                        {
                                            if(layer[i][j].Exists)
                                            {   layer[i][j].CheckSelect();
                                                if(layer[i][j].SelFlag==1)
                                                {
                                                    layer[i][j].createVels();
                                                }
                                            }
                                        }
                                    }
                                }

    }
    lastState=state;
}

void mousewheel(int button,int state, int x, int y)
{   FirstTime2=0;
    switch(state)
    {
        case 1: LayerIndex=(LayerIndex==NoOfLayers-1)?LayerIndex:LayerIndex+1;
                break;
        case -1:LayerIndex=(LayerIndex==0)?LayerIndex:LayerIndex-1;
                break;
    }
}

void passiveMouse2(int x, int y)
{
    CurrMousePos[0]=x/700.0;
    CurrMousePos[1]=(glutGet(GLUT_WINDOW_HEIGHT)/700.0)-(y/700.0);

   //Check selection in all objects
}

void motion(int x,int y)
{
    CurrMousePos[0]=x/700.0;
    CurrMousePos[1]=(glutGet(GLUT_WINDOW_HEIGHT)/700.0)-(y/700.0);
    if(MovePointer[0]!=-1)
    {
        layer[MovePointer[0]][MovePointer[1]].COM[0]=CurrMousePos[0];
        layer[MovePointer[0]][MovePointer[1]].COM[1]=CurrMousePos[1];
        layer[MovePointer[0]][MovePointer[1]].FillEnvSpaceList();

    }


}

void LayerManagerWindow()
{
    glutInitWindowSize(700,700);
    LayerWindow=glutCreateWindow("Layer Manager");
    init3();
    //Make all polygons
    glutDisplayFunc(make);
	glutSpecialFunc(keydown2);
 	glutReshapeFunc(reshape2);
 	glutMouseFunc(select2);
 	glutMouseWheelFunc(mousewheel);
 	glutMotionFunc(motion);
 	glutPassiveMotionFunc(passiveMouse2);

}



