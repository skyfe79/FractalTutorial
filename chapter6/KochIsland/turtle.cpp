#include <windows.h>
#include <gl\gl.h>
#include <math.h>
#include "turtle.h"

Turtle::Turtle(void)
{
	PointList.clear();
	Point3D startPoint(0.0f, 0.0f, 0.0f);
	PointList.push_back(startPoint);
	IsUp = false;
	angle = 0.0f;
}
void Turtle::SetStartPoint(float x, float y, float z)
{
	angle = 0.0f;
	Point3D startPoint(x, y, z);
	PointList.clear();
	PointList.push_back(startPoint);
}
void Turtle::Forward(float length)
{
	static unsigned int count = 0;
	static float radian = 0.0f;
	static Point3D pt;
	count = PointList.size();
	radian = angle*TORAD;
	pt.x =  (length*cos(radian))+PointList[count-1].x;
	pt.y =  (length*sin(radian))+PointList[count-1].y;
	pt.z = (PointList[count-1].z);
	if(!IsUp)
	{
		glBegin(GL_LINES);
			glVertex3f(PointList[count-1].x, PointList[count-1].y, PointList[count-1].z);
			glVertex3f(pt.x, pt.y, pt.z);
		glEnd();
	}
	PointList.push_back(pt);
}

void Turtle::Left(float rotate_angle)
{
	angle = (angle + rotate_angle);
	angle = fmod(angle, 360.0f);
}
void Turtle::Right(float rotate_angle)
{
	angle = (angle - rotate_angle);
	angle = fmod(angle, 360.0f);
}
void Turtle::Up(void)
{
	IsUp = true;
}
void Turtle::Down(void)
{
	IsUp = false;
}
void Turtle::MarkPoint(void)
{
	glPointSize(5.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
		for(unsigned int i=0; i<PointList.size(); ++i)
		{
			glColor3f(0.5f-((float(i)+1.0f)*0.00001f), 0.6f-((float(i)+1.0f)*0.0001f), 0.7f-((float(i)+1.0f)*0.0001f));
			glVertex3f(PointList[i].x, PointList[i].y, PointList[i].z);
		}
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
}