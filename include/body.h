#ifndef BODY_H
#define BODY_H


class body
{
    public:
    int Exists;
    int NumVertices;  //Num of vertices
    int CollFlag;   //Is 1 when there's a collision. Otherwise is 0. Not used in program
    int IsGhost;
    int IsConcrete;
    int SelFlag;
    double g;      //gravity constant
    double Color[3];  //RGB values of polygon. It will be highlighted
    double COM[2];  //COM of polygon, intially given, autmatically recaluclulated later
    double LocalSpaceList[50][2]; //Vertices have to be listed in anticlockwise manner only or else algorithm will not work. These cordinates are with respect to an initial COM
    double EnvSpaceList[50][2]; //Fills up autmatically. First vertex is highlighted
    double Lvel[2];  //Linear velocity vector
    double Avel; //Angular velocity
    double Mass; //Automatically calculated
    double MOI;  //Moment of intertia, auto calced
    double Spin; //Angular displacemement, can be initially set but later is automatically calculated
    double density; //Surface density, actually
    double MaxDist;

    void Render(); //used to draw the polygon
    void UpdateParameters(); //calculates MOI, COM based on initial data. etc. This function has been thoroughly tested and verified. This function also recalculates LocalSpaceList with respect to the actual corrected COM
    void FillEnvSpaceList(); //Caclulates vertexes in Environment space by looking up cordinates of polygon space
    void UpdateVels();
    void Update();
    void push(double*);
    void push(double, double);
    void draw();
    void checkForDraw();
    void CheckSelect();
    void createVels();

};
extern body *ToDraw;

#endif // BODY_H
