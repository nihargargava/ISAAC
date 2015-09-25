#include"everything.h"

int Pause=1;
int let=0;
int lastState;
int FirstTime2=1;


body layer[NoOfLayers][BodiesPerLayer];




int main(int argc, char** argv)
{
    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    for(int i=0;i<NoOfLayers;i++)
    {
        for(int j=0;j<BodiesPerLayer;j++)
        {
            layer[i][j].Exists=0;
        }
    }

    Simulator();


    //Main code
	glutMainLoop();
	return 0;
}

