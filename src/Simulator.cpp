#include"everything.h"

int i,j,k,l;
int FirstTime=1;

body ground;
body wallL;
body wallR;
body wallU;

GLubyte play[30] =
{0x00,0x00,
0x60,0x00,
0x70,0x00,
0x78,0x00,
0x7c,0x00,
0x7e,0x00,
0x7f,0x00,
0x7f,0x80,
0x7f,0x00,
0x7e,0x00,
0x7c,0x00,
0x78,0x00,
0x70,0x00,
0x60,0x00,
0x00,0x00};

GLubyte pause[30] =
{0x00,0x00,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x31,0x80,
0x00,0x00};

GLubyte lay[30] =
{0x00,0x00,
0x1E,0xD0,
0x1E,0xD0,
0x1E,0xD0,
0x00,0x00,
0x00,0x00,
0x1E,0xD0,
0x1E,0xD0,
0x1E,0xD0,
0x00,0x00,
0x00,0x00,
0x1E,0xD0,
0x1E,0xD0,
0x1E,0xD0,
0x00,0x00
};
GLubyte none[30]=
{0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00
};
button PlayButton("Play     ",play,0.05,0.05,0.065,0.06);
button PauseButton("Pause     ",pause,0.05,0.05,0.065,0.06);
button LayerManager("Layer", lay ,0.05,0.15,0.065,0.065);
button lwall("| ",none,0.05,0.55,0.030,0.035);
button rwall(" |",none,0.05,0.60,0.030,0.035);
button gwall("_",none,0.05,0.65,0.030,0.035);
button uwall("^",none,0.05,0.70,0.030,0.035);

button Button1=PlayButton;


void makesquares()//Edit this function to try various stunts or to play around
{   ground.Exists=0;
    ground.IsConcrete=1;
    ground.IsGhost=0;
    ground.density=100.0;
    ground.Color[0]=0.0;
    ground.Color[1]=0.0;
    ground.Color[2]=0.0;
    ground.COM[0]=0.50;
    ground.COM[1]=0.00;
    ground.NumVertices=4;
    ground.LocalSpaceList[0][0]=10;
    ground.LocalSpaceList[0][1]=0.05;
    ground.LocalSpaceList[1][0]=-10;
    ground.LocalSpaceList[1][1]=0.05;
    ground.LocalSpaceList[2][0]=-10;
    ground.LocalSpaceList[2][1]=-0.05;
    ground.LocalSpaceList[3][0]=10;
    ground.LocalSpaceList[3][1]=-0.05;
    ground.Spin=0.0;
    ground.FillEnvSpaceList();
    ground.Lvel[0]=0.0;
    ground.Lvel[1]=0.0;
    ground.Avel=-0.00;
    ground.UpdateParameters();



    wallU.Exists=0;
    wallU.IsConcrete=1;
    wallU.IsGhost=0;
    wallU.density=100.0;
    wallU.Color[0]=0.0;
    wallU.Color[1]=0.0;
    wallU.Color[2]=0.0;
    wallU.COM[0]=0.50;
    wallU.COM[1]=1.00;
    wallU.NumVertices=4;
    wallU.LocalSpaceList[0][0]=10;
    wallU.LocalSpaceList[0][1]=0.05;
    wallU.LocalSpaceList[1][0]=-10;
    wallU.LocalSpaceList[1][1]=0.05;
    wallU.LocalSpaceList[2][0]=-10;
    wallU.LocalSpaceList[2][1]=-0.05;
    wallU.LocalSpaceList[3][0]=10;
    wallU.LocalSpaceList[3][1]=-0.05;
    wallU.Spin=0.0;
    wallU.FillEnvSpaceList();
    wallU.Lvel[0]=0.0;
    wallU.Lvel[1]=0.0;
    wallU.Avel=-0.00;
    wallU.UpdateParameters();

    wallR.Exists=0;
    wallR.IsConcrete=1;
    wallR.IsGhost=0;
    wallR.density=100.0;
    wallR.Color[0]=0.0;
    wallR.Color[1]=0.0;
    wallR.Color[2]=0.0;
    wallR.COM[0]=1.0;
    wallR.COM[1]=0.500;
    wallR.NumVertices=4;
    wallR.LocalSpaceList[0][0]=1;
    wallR.LocalSpaceList[0][1]=0.05;
    wallR.LocalSpaceList[1][0]=-1;
    wallR.LocalSpaceList[1][1]=0.05;
    wallR.LocalSpaceList[2][0]=-1;
    wallR.LocalSpaceList[2][1]=-0.05;
    wallR.LocalSpaceList[3][0]=1;
    wallR.LocalSpaceList[3][1]=-0.05;
    wallR.Spin=3.1415925/2;
    wallR.FillEnvSpaceList();
    wallR.Lvel[0]=0.0;
    wallR.Lvel[1]=0.0;
    wallR.Avel=-0.00;
    wallR.UpdateParameters();

    wallL.Exists=0;
    wallL.IsConcrete=1;
    wallL.IsGhost=0;
    wallL.density=100.0;
    wallL.Color[0]=0.0;
    wallL.Color[1]=0.0;
    wallL.Color[2]=0.0;
    wallL.COM[0]=0.0;
    wallL.COM[1]=0.500;
    wallL.NumVertices=4;
    wallL.LocalSpaceList[0][0]=1;
    wallL.LocalSpaceList[0][1]=0.05;
    wallL.LocalSpaceList[1][0]=-1;
    wallL.LocalSpaceList[1][1]=0.05;
    wallL.LocalSpaceList[2][0]=-1;
    wallL.LocalSpaceList[2][1]=-0.05;
    wallL.LocalSpaceList[3][0]=1;
    wallL.LocalSpaceList[3][1]=-0.05;
    wallL.Spin=3.14159265/2;
    wallL.FillEnvSpaceList();
    wallL.Lvel[0]=0.0;
    wallL.Lvel[1]=0.0;
    wallL.Avel=-0.00;
    wallL.UpdateParameters();
}


void text(char str[],double x,double y,int choice=0)
{
    glColor3d(0.0,0.0,0.0);
    glRasterPos2d(x,y);
    if(!choice)glutBitmapString(GLUT_BITMAP_HELVETICA_12,(const unsigned char*)str);
    else glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)str);
}

void keydown(unsigned char key,int x, int y) //Defines keyboard events. Used by GLUT
{
    if(key==' ')
    {   if(Pause==1)Pause=0;
        else
        {
            Pause=1;
        }
    }
    if(key=='n')
    {
        let=1;
    }
}

char hello[100];

void simulate()//GLUT required function.
{   glClear(GL_COLOR_BUFFER_BIT);
 //   glClearColor((rand()%100)/100.0,(rand()%100)/100.0,(rand()%100)/100.0,1.0);
    glClearColor(1.0,1.0,1.0,1.0);


    if(!Pause || let)
    {//Detect collisions
        for(i=0;i<NoOfLayers;i++)
        {
            for(j=0;j<BodiesPerLayer;j++)
            {   if(layer[i][j].Exists)
                {   if(wallL.Exists)DetectColl(layer[i][j],wallL);
                    if(wallR.Exists)DetectColl(layer[i][j],wallR);
                    if(ground.Exists)DetectColl(layer[i][j],ground);
                    if(wallU.Exists)DetectColl(layer[i][j],wallU);
                    for(k=i;k<NoOfLayers;k++)
                    {
                        for(l=(k==i)?j+1:0;l<BodiesPerLayer;l++)
                        {
                            if(layer[k][l].Exists)
                                DetectColl(layer[i][j],layer[k][l]);
                        }
                    }
                }
            }
        }

    }

    //Render everything

    for(i=0;i<NoOfLayers;i++)
    {
        for(j=0;j<BodiesPerLayer;j++)
        {
            if(layer[i][j].Exists)
               layer[i][j].Render();
        }
    }
    if(wallR.Exists)wallR.Render();
    if(wallL.Exists)wallL.Render();
    if(ground.Exists)ground.Render();
    if(wallU.Exists)wallU.Render();


    if(!Pause || let)
    {//Detect collisions
        for(i=0;i<NoOfLayers;i++)
        {
            for(j=0;j<BodiesPerLayer;j++)
            {
                if(layer[i][j].Exists)
                    layer[i][j].Update();
            }
        }
        if(wallL.Exists)wallL.Update();
        if(wallR.Exists)wallR.Update();
        if(ground.Exists)ground.Update();
        if(wallU.Exists)wallU.Update();
        let=0;

    }
    if(Pause)Button1=PlayButton;
    else Button1=PauseButton;

    strcpy(hello,"");
    if(Pause)strcpy(hello,"Simulation paused.\nPress 'N' for next frame.");


    if(Button1.isPressed(CurrMousePos))strcpy(hello,"Press for Play/Pause.");
    Button1.Render();

    if(LayerManager.isPressed(CurrMousePos))strcpy(hello,"Press for Layer Manager.");
    LayerManager.Render();

    if(lwall.isPressed(CurrMousePos))strcpy(hello,"Press for Left Wall Toggle.");
    lwall.Render();

    if(rwall.isPressed(CurrMousePos))strcpy(hello,"Press for Right Wall Toggle.");

    rwall.Render();

    if(uwall.isPressed(CurrMousePos))strcpy(hello,"Press for Ceiling Toggle.");
    uwall.Render();

    if(gwall.isPressed(CurrMousePos))strcpy(hello,"Press for Ground Toggle.");

    gwall.Render();

    text(hello,CurrMousePos[0]+0.01,CurrMousePos[1]+0.01);

    MakeDot(CurrMousePos);

    if(FirstTime)text("No Objects defined. Use Layer manager to add some layers.\nPlease don't close any window manually. This will end the program.",0.25,0.50);

    glutSwapBuffers();
}


void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0,1.0*(w/700.0),0,1.0*(h/700.0),-1.0,1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
wallR.COM[0]=w/700.0;
wallU.COM[1]=h/700.0;
}

void init()//Used to define windows. Used by GLUT
{
    makesquares();
    glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.0,1.0,-0.0,1.0,-1.0,1.0);
	glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

}

void select(int button, int state, int x, int y)
{

    switch(button)
    {   case GLUT_LEFT_BUTTON:  if(state==GLUT_UP &&lastState == GLUT_DOWN)
                                {   if(Button1.isPressed(CurrMousePos))
                                    {
                                        if(Pause==1)
                                        {
                                            Pause=0;
                                            Button1=PauseButton;
                                        }
                                        else
                                        {
                                            Pause=1;
                                            Button1=PlayButton;
                                        }
                                    }
                                    if(LayerManager.isPressed(CurrMousePos))
                                    {
                                        FirstTime=0;
                                        Pause=1;
                                        LayerManagerWindow();
                                    }
                                    if(lwall.isPressed(CurrMousePos))
                                    {
                                        wallL.Exists=(wallL.Exists==0)?1:0;
                                    }
                                    if(rwall.isPressed(CurrMousePos))
                                    {
                                        wallR.Exists=(wallR.Exists==0)?1:0;
                                    }
                                    if(uwall.isPressed(CurrMousePos))
                                    {
                                        wallU.Exists=(wallU.Exists==0)?1:0;
                                    }
                                    if(gwall.isPressed(CurrMousePos))
                                    {
                                        ground.Exists=(ground.Exists==0)?1:0;
                                    }

                                    //Check selecion in all obects
                                }
                                break;
    }
    lastState=state;
}

void passiveMouse(int x, int y)
{
    CurrMousePos[0]=x/700.0;
    CurrMousePos[1]=(glutGet(GLUT_WINDOW_HEIGHT)/700.0)-(y/700.0);

   //Check selection in all objects
}

void Timer(int Unused)//Used for double buffering. Required by GLUT
{
    glutPostRedisplay();
    glutTimerFunc(TimerInt, Timer, 0);
}

void Simulator()
{
    glutInitWindowSize(700,700);
    MainWindow=glutCreateWindow("ISAAC");
    init();
    //Make all polygons
    glutDisplayFunc(simulate);
	glutKeyboardFunc(keydown);
 	glutReshapeFunc(reshape);
 	glutMouseFunc(select);
 	glutPassiveMotionFunc(passiveMouse);
    Timer(0);

}



