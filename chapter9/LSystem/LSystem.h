/*******************************************************************************
 { LSystem Class
 { written by Sungchul Kim
 { 2003.4.27
 {
 { F : 전진
 { + : 왼쪽으로 회전
 { - : 오른쪽으로 회전
 { | : 왼쪽으로 180 도 회전
 { [ : 현재좌표, 현재 각도를 스택에저장
 { ] : 현재좌표, 현재 각도를 저장했던 좌표,각도로 설정
 { { : 현재좌표만 저장
 { } : 현재좌표만 저장했던 좌표로 설정
 { @ : 열매를 그린다.
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
	string TotalAxiom;    //최종 공리
	trule_list TRuleList; //변환규칙 리스트
	float angle;  //회전각도
	float length; //진행길이
	float factor; //길이의 배율
	Turtle *turtle; //거북이
public:
	LSystem();

	void SetAngle(float rotate_angle); 
	void SetLength(float move_distance);
	void SetFactor(float magnification);

	void SelectTurtle(Turtle *pturtle);
	void AddTransRule(char name, string rule);
	void MakeAxiom(string axiom, int n); //n 차까지 공리 변환
	void Draw(void); 
};


#endif
 