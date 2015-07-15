/*******************************************************************************
 { LSystem Class
 { written by Sungchul Kim
 { 2003.4.27
 {
 { F : ����
 { + : �������� ȸ��
 { - : ���������� ȸ��
 { | : �������� 180 �� ȸ��
 { [ : ������ǥ, ���� ������ ���ÿ�����
 { ] : ������ǥ, ���� ������ �����ߴ� ��ǥ,������ ����
 { { : ������ǥ�� ����
 { } : ������ǥ�� �����ߴ� ��ǥ�� ����
 { @ : ���Ÿ� �׸���.
*******************************************************************************/

#ifndef _LSYSTEM_H_
#define _LSYSTEM_H_


#pragma warning(disable : 4786)

#include <map>
#include <string>
#include "turtle.h"

using namespace std;

typedef map< char, string > trule_list;
typedef map< char, string >::iterator ai;

class LSystem
{
public:
	string TotalAxiom;    //���� ����
	trule_list TRuleList; //��ȯ��Ģ ����Ʈ
	float angle;  //ȸ������
	float length; //�������
	float factor; //������ ����
	Turtle *turtle; //�ź���
public:
	LSystem();

	void SetAngle(float rotate_angle); 
	void SetLength(float move_distance);
	void SetFactor(float magnification);

	void SelectTurtle(Turtle *pturtle);
	void AddTransRule(char name, string rule);
	void MakeAxiom(string axiom, int n); //n ������ ���� ��ȯ
	void Draw(void); 
};


#endif
 