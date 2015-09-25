#include"everything.h"



int DetectColl(body &a, body &b)//Look up Separating axis theorom to understand this. Also, this function has been thoroughly tested nd verified. Returns 1 if colliding, 0 if not
{ //  printf("\n----------------------Collision detection called\n");
  //  if(norm((a.COM[0]-b.COM[0]),(a.COM[1]-b.COM[1]))>a.MaxDist+b.MaxDist)return 0;

    double normal[2],temp,MTD=1000000.0,x,y,pushVect[2],axis[2],finPoint[2];
    double maxa,maxb,mina,minb,canPoint[4][2],point[2],mag;
    char belongsto;
    //for all edges of a
    a.EnvSpaceList[a.NumVertices][0]=a.EnvSpaceList[0][0];
    a.EnvSpaceList[a.NumVertices][1]=a.EnvSpaceList[0][1];
    for(int i=0;i<(a.NumVertices);i++)
    {   //Dot produce environment position vector with normal to edge
        mag=norm((a.EnvSpaceList[i+1][0]-a.EnvSpaceList[i][0]),(a.EnvSpaceList[i+1][1]-a.EnvSpaceList[i][1]));
        normal[0]= (a.EnvSpaceList[i+1][1]-a.EnvSpaceList[i][1])/mag;
        normal[1]=-(a.EnvSpaceList[i+1][0]-a.EnvSpaceList[i][0])/mag;
     //   printf("\nNormal in a= (%lf ,%lf )\n",normal[0],normal[1]);
        maxa=mina=a.EnvSpaceList[0][0]*normal[0]+a.EnvSpaceList[0][1]*normal[1];
        canPoint[0][0]=canPoint[1][0]=a.EnvSpaceList[0][0];
        canPoint[0][1]=canPoint[1][0]=a.EnvSpaceList[0][1];
        for(int j=1;j<a.NumVertices;j++)
        {
            temp=a.EnvSpaceList[j][0]*normal[0]+a.EnvSpaceList[j][1]*normal[1];
            if(temp>maxa)
            {
                canPoint[0][0]=a.EnvSpaceList[j][0];
                canPoint[0][1]=a.EnvSpaceList[j][1];
                maxa=temp;
            }
            if(temp<mina)
            {
                canPoint[1][0]=a.EnvSpaceList[j][0];
                canPoint[1][1]=a.EnvSpaceList[j][1];
                mina=temp;
            }
       //     printf("\n\n\tTemp= %lf",temp);

        }
        maxb=minb=b.EnvSpaceList[0][0]*normal[0]+b.EnvSpaceList[0][1]*normal[1];
        canPoint[2][0]=canPoint[3][0]=b.EnvSpaceList[0][0];
        canPoint[2][1]=canPoint[3][1]=b.EnvSpaceList[0][1];
        for(int j=1;j<b.NumVertices;j++)
        {
            temp=b.EnvSpaceList[j][0]*normal[0]+b.EnvSpaceList[j][1]*normal[1];
            if(temp>maxb)
            {
                canPoint[2][0]=b.EnvSpaceList[j][0];
                canPoint[2][1]=b.EnvSpaceList[j][1];
                maxb=temp;
            }
            if(temp<minb)
            {
                canPoint[3][0]=b.EnvSpaceList[j][0];
                canPoint[3][1]=b.EnvSpaceList[j][1];
                minb=temp;
            }
       //    printf("\n\n\tTemp= %lf",temp);

        }
   //     printf("\nValues are ->%lf ,%lf ,%lf ,%lf \n",mina,maxa,minb,maxb);

        if(mina>=maxb || minb>=maxa)
        {
            return 0;
        }
        else
        {

            x=maxa-minb;
            y=maxb-mina;
            if(x<y)
            {
                temp=x;
                point[0]=canPoint[3][0];
                point[1]=canPoint[3][1];

            }
            else
            {
                temp=y;
                point[0]=canPoint[2][0];
                point[1]=canPoint[2][1];
            }
            if(temp<=MTD)
            {   belongsto='a';
                MTD=temp;
                pushVect[0]=normal[0];
                pushVect[1]=normal[1];
                finPoint[0]=point[0];
                finPoint[1]=point[1];
     //           printf("PushVect Could be me.\n");
            }

        }

    }


    //Now same thing with b
    b.EnvSpaceList[b.NumVertices][0]=b.EnvSpaceList[0][0];
    b.EnvSpaceList[b.NumVertices][1]=b.EnvSpaceList[0][1];
    for(int i=0;i<(b.NumVertices);i++)
    {   //Dot produce environment position vector with normal to edge
        mag=norm((b.EnvSpaceList[i+1][0]-b.EnvSpaceList[i][0]),(b.EnvSpaceList[i+1][1]-b.EnvSpaceList[i][1]));
        normal[0]= (b.EnvSpaceList[i+1][1]-b.EnvSpaceList[i][1])/mag;
        normal[1]=-(b.EnvSpaceList[i+1][0]-b.EnvSpaceList[i][0])/mag;
    //    printf("\nNormal in b= (%lf ,%lf )\n",normal[0],normal[1]);
        maxa=mina=a.EnvSpaceList[0][0]*normal[0]+a.EnvSpaceList[0][1]*normal[1];
        canPoint[0][0]=canPoint[1][0]=a.EnvSpaceList[0][0];
        canPoint[0][1]=canPoint[1][1]=a.EnvSpaceList[0][1];
        for(int j=1;j<a.NumVertices;j++)
        {
            temp=a.EnvSpaceList[j][0]*normal[0]+a.EnvSpaceList[j][1]*normal[1];
            if(temp>maxa)
            {
                canPoint[0][0]=a.EnvSpaceList[j][0];
                canPoint[0][1]=a.EnvSpaceList[j][1];
                maxa=temp;
            }
            if(temp<mina)
            {
                canPoint[1][0]=a.EnvSpaceList[j][0];
                canPoint[1][1]=a.EnvSpaceList[j][1];
                mina=temp;
            }
       //     printf("\n\n\tTemp= %lf",temp);

        }
        maxb=minb=b.EnvSpaceList[0][0]*normal[0]+b.EnvSpaceList[0][1]*normal[1];
        canPoint[3][0]=canPoint[2][0]=a.EnvSpaceList[0][0];
        canPoint[3][1]=canPoint[2][0]=a.EnvSpaceList[0][1];
        for(int j=1;j<b.NumVertices;j++)
        {
            temp=b.EnvSpaceList[j][0]*normal[0]+b.EnvSpaceList[j][1]*normal[1];
            if(temp>maxb)
            {
                canPoint[2][0]=b.EnvSpaceList[j][0];
                canPoint[2][1]=b.EnvSpaceList[j][1];
                maxb=temp;
            }
            if(temp<minb)
            {
                canPoint[3][0]=b.EnvSpaceList[j][0];
                canPoint[3][1]=b.EnvSpaceList[j][1];
                minb=temp;
            }
       //    printf("\n\n\tTemp= %lf",temp);

        }
   //     printf("\nValues are ->%lf ,%lf ,%lf ,%lf \n",mina,maxa,minb,maxb);

        if(mina>=maxb || minb>=maxa)
        {
            return 0;
        }
        else
        {

            x=maxa-minb;
            y=maxb-mina;
            if(x<y)
            {
                temp=x;
                point[0]=canPoint[0][0];
                point[1]=canPoint[0][1];
            }
            else
            {
                temp=y;
                point[0]=canPoint[1][0];
                point[1]=canPoint[1][1];
            }
            if(temp<=MTD)
            {   belongsto='b';
                MTD=temp;
                pushVect[0]=normal[0];
                pushVect[1]=normal[1];
                finPoint[0]=point[0];
                finPoint[1]=point[1];
  //              printf("PushVect Could be me.\n");
            }

        }

    }
    axis[0]=pushVect[0];
    axis[1]=pushVect[1];
    temp=MTD;
    temp*=(1+(a.IsConcrete || b.IsConcrete));
 //   printf("\ntemp is %lf, normsq is %lf",temp, normsq(pushVect[0],pushVect[1]));
    pushVect[0]*=pushfactor*temp;
    pushVect[1]*=pushfactor*temp;
    if(Collide(a,b,axis,finPoint))

    {
   // printf("\n\n---------Gonna now push! PushVect = (%lf , %lf); MTD = %lf \nBelongs to %c, ",pushVect[0],pushVect[1],MTD,belongsto);
 //   MakeDot(0.85,0.85);
 //   MakeDot(0.85+pushVect[0],0.85+pushVect[1]);
 //   printf("\n!!point cordinates (%lf,%lf)",finPoint[0],finPoint[1]);
  //  printf("\n%lf",norm(axis[0],axis[1]));

    switch(belongsto)
    {   case 'a':   if((pushVect[0]*(b.COM[0]-a.COM[0]) + pushVect[1]*(b.COM[1]-a.COM[1]))<0){pushVect[0]*=-1.0;pushVect[1]*=-1.0;}
                    b.push(pushVect[0],pushVect[1]);
                    a.push(-1*pushVect[0],-1*pushVect[1]);
                    break;
        case 'b':   if((pushVect[0]*(b.COM[0]-a.COM[0]) + pushVect[1]*(b.COM[1]-a.COM[1]))>0){pushVect[0]*=-1.0;pushVect[1]*=-1.0;}
                    a.push(pushVect[0],pushVect[1]);
                    b.push(-1*pushVect[0],-1*pushVect[1]);
                    break;

    }

    }
  //  for(int i=0;i<CollisionIndex;i++)Collide(a,b,axis,finPoint);
    a.CollFlag=1;
    b.CollFlag=1;
    return 1;
}

