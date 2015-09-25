#include"everything.h"




double abs(double a)
{
    if(a<0)return -a;
    else return a;
}


int Collide(body &a,body &b, double axis[2], double point[2])//This is responsible for imparting impulse. Point is environment cordinates of collision point. Axis is normal of collision. DetectColl calls this function just before returning 1.
{
    axis[0]=-axis[0];
    axis[1]=-axis[1];

  //  MakeDot2(point);//higlights point of collion
/*    printf("\n\n----------------------BOXES COLLIDE");
    printf("\nCollision on axis =(%lf,%lf)",axis[0],axis[1]);
    printf("\nInitial momentum in x = %lf",a.Mass*a.Lvel[0]+b.Mass*b.Lvel[0]);
    printf("\nInitial momentum in y = %lf",a.Mass*a.Lvel[1]+b.Mass*b.Lvel[1]);
    printf("\nInitial angular momentum about origin = %lf",(a.Mass*(a.COM[0]*a.Lvel[1]-a.COM[1]*a.Lvel[0])+a.MOI*a.Avel)+(b.Mass*(b.COM[0]*b.Lvel[1]-b.COM[1]*b.Lvel[0])+b.MOI*b.Avel));
    printf("\nInitial energy =%lf",0.5*(a.Mass*normsq(a.Lvel[0],a.Lvel[1])+a.MOI*a.Avel*a.Avel+b.Mass*normsq(b.Lvel[0],b.Lvel[1])+b.MOI*b.Avel*b.Avel));

//--------------------------------COLLISION HAPPENS BELOW-------------------------------------------------------
*/
    double imp[2];
    double ProjVelA=( a.Lvel[0] - a.Avel*(point[1]-a.COM[1]) )*axis[0] + ( a.Lvel[1] + a.Avel*(point[0]-a.COM[0]) )*axis[1];//Velocity of the point along the normal axis
    double ProjVelB=( b.Lvel[0] - b.Avel*(point[1]-b.COM[1]) )*axis[0] + ( b.Lvel[1] + b.Avel*(point[0]-b.COM[0]) )*axis[1];//Same as above for b
 //   printf("\n------------Velocity of approach= %lf",ProjVelA-ProjVelB);


    double ProjPosA=a.COM[0]*axis[0] + a.COM[1]*axis[1];//Projected position on normal
    double ProjPosB=b.COM[0]*axis[0] + b.COM[1]*axis[1];//Projected position on normal
    double rAXn=(point[0]-a.COM[0])*(axis[1]) - (point[1]-a.COM[1])*(axis[0]); //Cross product of vector joining the point and COM with axis.
    double rBXn=(point[0]-b.COM[0])*(axis[1]) - (point[1]-b.COM[1])*(axis[0]);//same


    if((ProjPosA-ProjPosB)/(ProjVelA-ProjVelB)>0.0)return 1; //because impulse has already been imparted

//Below is what defines the impulse. Momentums will coserve no matter what the value of imulse is. Energy will conserve only for one value
    double impMag=-((1+restit)*(ProjVelA-ProjVelB))/(((!a.IsConcrete)/a.Mass)+((!b.IsConcrete)/b.Mass)+(sq(rAXn*(!a.IsConcrete))/a.MOI)+(sq(rBXn*(!b.IsConcrete))/b.MOI));



 //   printf("\nMagnitude of IMPULSE!!!=%lf",impMag);
    imp[0]=impMag*axis[0];
    imp[1]=impMag*axis[1];


    //The commented lines of code below will make two vectors represented by two dots, origin at 0.25, 0.25. One represents the impulse vects, and another is the axis unit vector by ten

  /*  double fraud[2];
    fraud[0]=imp[0]+0.25;
    fraud[1]=imp[1]+0.25;
    MakeDot(fraud);
    fraud[0]=0.1*axis[0]+0.25;
    fraud[1]=0.1*axis[1]+0.25;
    MakeDot(fraud);*/


    a.Lvel[0]+=imp[0]/a.Mass*(!a.IsConcrete);
    a.Lvel[1]+=imp[1]/a.Mass*(!a.IsConcrete);
    b.Lvel[0]-=imp[0]/b.Mass*(!b.IsConcrete);
    b.Lvel[1]-=imp[1]/b.Mass*(!b.IsConcrete);

    a.Avel+=(rAXn*impMag)/a.MOI*(!a.IsConcrete);
    b.Avel-=(rBXn*impMag)/b.MOI*(!b.IsConcrete);


/*
//---------------------------------------------------------------------------------------------------------------
    printf("\nFinal momentum in x = %lf",a.Mass*a.Lvel[0]+b.Mass*b.Lvel[0]);
    printf("\nFinal momentum in y = %lf",a.Mass*a.Lvel[1]+b.Mass*b.Lvel[1]);
    printf("\nFinal angular momentum about origin = %lf",(a.Mass*(a.COM[0]*a.Lvel[1]-a.COM[1]*a.Lvel[0])+a.MOI*a.Avel)+(b.Mass*(b.COM[0]*b.Lvel[1]-b.COM[1]*b.Lvel[0])+b.MOI*b.Avel));
    printf("\nFinal energy =%lf",0.5*(a.Mass*normsq(a.Lvel[0],a.Lvel[1])+a.MOI*a.Avel*a.Avel+b.Mass*normsq(b.Lvel[0],b.Lvel[1])+b.MOI*b.Avel*b.Avel));
    ProjVelA=( a.Lvel[0] - a.Avel*(point[1]-a.COM[1]) )*axis[0] + ( a.Lvel[1] + a.Avel*(point[0]-a.COM[0]) )*axis[1];
    ProjVelB=( b.Lvel[0] - b.Avel*(point[1]-b.COM[1]) )*axis[0] + ( b.Lvel[1] + b.Avel*(point[0]-b.COM[0]) )*axis[1];
    printf("\n--------------Velocity of regression= %lf",ProjVelA-ProjVelB);
    printf("\n-----------------------------------------------------------------------\n");

 //   printf("\n________________------------COLLISION SUCESSFUL!!!-----------------");*/
   return 1;


}

