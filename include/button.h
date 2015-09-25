#ifndef BUTTON_H
#define BUTTON_H



class button
{
    public:
    char ch[100];
    GLubyte pic[30];
    double position[2];
    double dimention[2];
    int PresFlag;
    button (char *a,GLubyte b[30],double x1,double x2,double x3,double x4);
    int isPressed(double a[2]);
    void Render();
};

#endif // BUTTON_H
