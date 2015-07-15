#ifndef _TURTLE_H_
#define _TURTLE_H_

#pragma once
#include <vector>

#define TORAD 0.01745f

struct Point3D
{
	float x, y, z;
	Point3D() { x=y=z=0.0f; }
	Point3D(const Point3D& pt) { x=pt.x; y=pt.y; z=pt.z; }
	Point3D(float ax, float ay, float az) { x=ax; y=ay; z=az;}
};

using namespace std;
typedef vector<Point3D> plist;
typedef vector<Point3D>::iterator pi;

class Turtle
{
private:
	plist PointList;
	bool  IsUp;
	int   angle;
public:
	Turtle(void);
	void SetStartPoint(float x, float y, float z);
	void Forward(float length);
	void Left(float rotate_angle);
	void Right(float rotate_angle);
	void Up(void);
	void Down(void);

	void MarkPoint(void);
};

#endif