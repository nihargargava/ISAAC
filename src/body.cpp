#include"everything.h"

body *ToDraw;
body temp;

double CurrMousePos[2];

void body::Render()
    {
        if(SelFlag)glColor3d(1.0,1.0,1.0);
        else glColor3dv(Color);
        glBegin(GL_POLYGON);
            for(int i=0;i<NumVertices;i++)
                glVertex2dv(EnvSpaceList[i]);
        glEnd();
        glColor3d(0.0,0.0,0.0);
        glLineWidth(2.0);
        glBegin(GL_LINE_LOOP);
            for(int i=0;i<NumVertices;i++)
                glVertex2dv(EnvSpaceList[i]);
        glEnd();
     //   MakeDot(EnvSpaceList[0]);
        MakeDot(COM);

    }
void body::UpdateParameters()
    {
        double area=0,temp;
        MaxDist=0;
        COM[0]=COM[1]=0.0;
        EnvSpaceList[NumVertices][0]=EnvSpaceList[0][0];
        EnvSpaceList[NumVertices][1]=EnvSpaceList[0][1];
        for(int i=0;i<NumVertices;i++)
        {
            temp=(EnvSpaceList[i][0]*EnvSpaceList[i+1][1] - EnvSpaceList[i][1]*EnvSpaceList[i+1][0]);
            area+=temp;
            COM[0]+=(EnvSpaceList[i][0]+EnvSpaceList[i+1][0])*temp;
            COM[1]+=(EnvSpaceList[i][1]+EnvSpaceList[i+1][1])*temp;
        }
        area/=2.0;
        Mass=area*density;
        COM[0]/=6*area;
        COM[1]/=6*area;
        for(int i=0;i<=NumVertices;i++)
        {
            LocalSpaceList[i][0]=EnvSpaceList[i][0]-COM[0];
            LocalSpaceList[i][1]=EnvSpaceList[i][1]-COM[1];
            temp=norm(LocalSpaceList[i][0],LocalSpaceList[i][1]);
            if(MaxDist>=temp)MaxDist=temp;
        }
        Spin=0.0;
        MOI=0.0;
        for(int i=0;i<NumVertices;i++)
        {
            MOI+=(LocalSpaceList[i][0]*LocalSpaceList[i+1][1]  -  LocalSpaceList[i][1]*LocalSpaceList[i+1][0])*(normsq(LocalSpaceList[i][0],LocalSpaceList[i][1]) + normsq(LocalSpaceList[i+1][0],LocalSpaceList[i+1][1])+ LocalSpaceList[i+1][1]*LocalSpaceList[i][1] + LocalSpaceList[i+1][0]*LocalSpaceList[i][0] );
        }
        MOI*=density/12;
        g= 10.0*(!IsConcrete);
    }
void body::UpdateVels()
    {
        Lvel[1]-=g*dt;
    }


void body::FillEnvSpaceList()
    {
        double x,y,s=sin(Spin),c=cos(Spin);
        for(int i=0;i<NumVertices;i++)
        {
            x=LocalSpaceList[i][0]*c - LocalSpaceList[i][1]*s;
            y=LocalSpaceList[i][0]*s + LocalSpaceList[i][1]*c;
            EnvSpaceList[i][0]=COM[0]+x;
            EnvSpaceList[i][1]=COM[1]+y;
        }

    }

void body::Update()
    {
        FillEnvSpaceList();
        COM[0]+=Lvel[0]*dt;
        COM[1]+=Lvel[1]*dt;

        Spin+=Avel*dt;
        if(Spin>3.1415926)Spin-=2*3.1415926;
        else if(Spin<-3.1415926)Spin+=2*3.1415926;
        UpdateVels();
        CollFlag=0;

    }

void body::push(double a, double b)
    {
        if(IsConcrete==0)
        {
            COM[0]+=a;
            COM[1]+=b;
        }
    }

void body::push(double a[2])
    {   push(a[0],a[1]);
    }

void body::draw()
    {   VertInd=0;
        ToDraw=this;
        Pause=1;
        DrawWindow();
    }
void body::createVels()
    {
        ToDraw=this;
        VelWindow();
    }
void body::checkForDraw()
    {   if(SelFlag)
        {   draw();
        }
    }

void body::CheckSelect()
    {
        if(norm((CurrMousePos[0]-COM[0]),(CurrMousePos[1]-COM[1]))<=0.01)
        {
            SelFlag=1;
        }
        else SelFlag=0;
    }



