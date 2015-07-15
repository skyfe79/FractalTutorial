#ifndef _TURTLE_GRAPHICS_
#define _TURTLE_GRAPHICS_

#ifdef __DLL__
    #define DLL_EXP __declspec(dllexport)
#else
    #define DLL_EXP __declspec(dllimport)
#endif

#include <vcl.h>
class DLL_EXP Turtle
{
private:
    TCanvas* cv;
    bool     isUpPen;
    float    sx,sy;  //시작 위치
    float    cx,cy;  //현재 위치
    float    dx,dy;  //변위 dx,dy
    float    degree; //회전 각도 및 방향, 음수면 시계방향, 양수면 반시계방향

public:
    Turtle(void);
    Turtle(TCanvas* Canvas);
    void AttachCanvas(TCanvas* Canvas);
    TCanvas* GetCanvas(void);

    void SetStartPoint(int x, int y);
    void Forward(double length);
    void Backward(double length);
    void Left(double angle);
    void Right(double angle);
    void Up(void);
    void Down(void);

    void MadeBy(void);
};

#endif
