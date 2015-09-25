#ifndef EVERYTHING_H_INCLUDED
#define EVERYTHING_H_INCLUDED

#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<GL/freeglut.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"include/body.h"
#include"include/button.h"

#define pushfactor 0.5
#define dt 0.000199
#define TimerInt 1
#define ImpLimit 0.08
#define CollisionIndex 5
#define restit 0.505
#define Default_Density 10.0
#define g_default 50.0

#define NoOfLayers 10
#define BodiesPerLayer 20

#define norm(x,y) sqrt(x*x + y*y)
#define normsq(x,y) x*x + y*y
#define sq(a) a*a



extern body layer[NoOfLayers][BodiesPerLayer];


int DetectColl(body &, body &);


//For Main Window

void text(char*, double, double,int);
extern int MainWindow;
extern int Pause;
extern int let;
extern double CurrMousePos[2];
void keydown(unsigned char,int, int);
void simulate();
void reshape(int,int);
void init();
void select(int,int,int,int);
void Simulator();





//For Draw Window
extern int lastState;
extern int VertInd;
void DrawWindow();
void mouse(int, int, int, int);
void motionMouse(int, int);
void init2();
void MakePolygon();
void DrawWindow();

//Collide
double abs(double);
int Collide(body&,body&, double*, double*);

//DetectColl


//LayerManagerWindow
void LayerManagerWindow();
extern int LayerIndex;
extern int BodyIndex[NoOfLayers];
extern int FirstTime2;
extern int LayerWindow;



//MakeDot
void MakeDot(double,double);
void MakeDot(double*);
void MakeDot2(double*);


void VelWindow();


#endif //EVERYTHING_H_INCLUDED

