#ifndef _TURTLE_H_
#define _TURTLE_H_

#pragma once
#include <vector>
#include <stack>

#define TORAD 0.01745f

struct Point3D
{
	float x, y, z;
	Point3D() { x=y=z=0.0f; }
	Point3D(const Point3D& pt) { x=pt.x; y=pt.y; z=pt.z;}
	Point3D(float ax, float ay, float az) { x=ax; y=ay; z=az; }
};

struct StackItem
{
	Point3D cp;
	float   angle;
	bool    save_angle;
	StackItem() { cp.x=cp.y=cp.z=0.0f; angle=0.0f; save_angle=false; }
	StackItem(const Point3D& pt, float a, bool s)
	{
		cp.x = pt.x;
		cp.y = pt.y;
		cp.z = pt.z;
		angle = a;
		save_angle = s;
	}
	StackItem(const StackItem& i)
	{
		cp = i.cp;
		angle = i.angle;
		save_angle = i.save_angle;
	}
};


using namespace std;
typedef vector<Point3D> plist;
typedef vector<Point3D>::iterator pi;
typedef stack<StackItem> pstack;

class Turtle
{
private:
	plist  PointList;
	pstack PointStack;
	bool  IsUp;
	float angle;
public:
	
	Turtle(void);
	void SetStartPoint(float x, float y, float z);
	void Forward(float length);
	void Left(float rotate_angle);
	void Right(float rotate_angle);
	void Up(void);
	void Down(void);

	void MarkPoint(void);
	void MarkCurrentPoint(void);

	void Push(bool save_angle=true);
	void Pop(void);
};

#endif
