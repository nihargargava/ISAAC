#include"everything.h"






button::button (char *a,GLubyte b[30],double x1,double x2,double x3,double x4)
    {
        strcpy(ch,a);
        for(int i=0;i<30;i++)pic[i]=b[i];
        position[0]=x1;
        position[1]=x2;
        dimention[0]=x3;
        dimention[1]=x4;
    }
int button::isPressed(double a[2])
    {
        if(a[0]>=position[0] && a[0]<=(position[0]+dimention[0]) && a[1]>=position[1] && a[1]<=(position[1]+dimention[1]))
        {
            PresFlag=1;
            return 1;
        }
        else
        {
            PresFlag=0;
            return 0;
        }
    }
void button::Render()
    {
        glColor3d(PresFlag,0.0,0.0);
        glLineWidth(2.0);
        glBegin(GL_LINE_LOOP);
            glVertex2dv(position);
            glVertex2d(position[0]+dimention[0],position[1]);
            glVertex2d(position[0]+dimention[0],position[1]+dimention[1]);
            glVertex2d(position[0],position[1]+dimention[1]);
        glEnd();
        text(ch,position[0]+0.01,position[1]+dimention[1]-0.02,0);

        glRasterPos2f(position[0]+0.02,position[1]+0.01);
        glBitmap(16, 15, 0, 0, 0.0, 0.0, pic);


    }
