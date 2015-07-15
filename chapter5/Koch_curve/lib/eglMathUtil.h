/***************************************************************************
 { 
 { 2D, 3D Mathematical Utility
 {
 {
 { a. 2D, 3D Vector Functions
 { b. 2D, 3D Matrix
 {
 { 04.05 / 2003 
 { Sungchul Kim 
 { paranwave@korea.com
 {
 { ���� 
 { 04.08 : 2D �� 3D �� ���� ����ü�� ǥ���Ѵ�.
 { 04.08 : egl namespace �� ���´�
 {
***************************************************************************/
#ifndef _EGL_MATH_UTIL_H_
#define _EGL_MATH_UTIL_H_

namespace egl {

struct Vector
{
	float x, y, z;
	Vector() { x=y=z=0.0f; }
	Vector(float ax, float ay, float az=0.0f) : x(ax),y(ay),z(az) {}
	Vector(const Vector& v) { x=v.x; y=v.y; z=v.z; }
};

/* 3D Vector Util */
/* ������ 2D ���� ���������� ���ǵ��� �ʴ´�. */
extern Vector operator+(const Vector& v1, const Vector& v2);
extern Vector operator-(const Vector& v1, const Vector& v2);
extern Vector operator*(const Vector& v1, const float factor);
extern Vector operator*(const float factor, const Vector& v1);
extern Vector operator/(const Vector& v1, float factor);
extern Vector operator+=(Vector& v1,const Vector& v2);
extern Vector operator-=(Vector& v1,const Vector& v2);
extern float  getLength(const Vector& v1);
extern Vector getUnit(const Vector& v1);
extern Vector getNormal(const Vector& p1, const Vector& p2, const Vector& p3);
extern float  Dot(const Vector& v1, const Vector& v2);
extern Vector Cross(const Vector& v1, const Vector& v2);
//extern Vector getNormal(const Vector& v1, const Vector& v2);

}; //end of namespace;

#endif