#include "LSystem.h"

LSystem::LSystem(void)
{
	angle = 0.0f;
	length = 1.0f;
	factor = 1.0f;
	turtle = NULL;

	TotalAxiom = "";
	TRuleList.clear();
}
void LSystem::SetAngle(float rotate_angle)
{
	angle = rotate_angle;
}
void LSystem::SetLength(float move_distance)
{
	length = move_distance;
}
void LSystem::SetFactor(float magnification)
{
	factor = magnification;
}
void LSystem::SelectTurtle(Turtle *pturtle)
{
	turtle = pturtle;
}
void LSystem::AddTransRule(char name, string rule)
{
	TRuleList[name] = rule;
}
void LSystem::MakeAxiom(string axiom, int n)
{
	ai fi;
	string buffer;
	TotalAxiom = axiom;
	for(int x=0; x<n /*&& RuleString.length() <=20000*/; ++x)
	{
		buffer.erase(buffer.begin(), buffer.end());
		for(int i=0; i<TotalAxiom.length(); ++i)
		{
			switch(TotalAxiom[i])
			{
			case 'F':
				fi = TRuleList.find('F');
				if(fi!=TRuleList.end())
				{
					buffer += fi->second;
				}
				else
				{
					buffer += "F";
				}
				break;

			case '@':
				buffer += "@";
				break;
			case '+':
				buffer += "+";
				break;
			case '-':
				buffer += "-";
				break;
			case '[':
				buffer += "[";
				break;
			case ']':
				buffer += "]";
				break;
			case '{':
				buffer += "{";
				break;
			case '}':
				buffer += "}";
				break;
			case '|':
				buffer += "|";
				break;
			default:
				fi = TRuleList.find((char)(TotalAxiom[i]));
				if(fi!=TRuleList.end())
				{
					buffer += fi->second;
				}
				break;
			}
		}
		TotalAxiom = buffer;
	}
}
void LSystem::Draw(void)
{
	for(string::iterator i = TotalAxiom.begin(); i!=TotalAxiom.end(); ++i)
	{
		switch((char)(*i))
		{
		case 'F':
			turtle->Forward(length*factor);
			break;
		case '@':
			turtle->MarkCurrentPoint();
			break;
		case '+':
			turtle->Left(angle);
			break;
		case '-':
			turtle->Right(angle);
			break;
		case '|':
			turtle->Left(180);
			break;
		case '[':
			turtle->Push(true);
			break;
		case ']':
		case '}':
			turtle->Pop();
			break;
		case '{':
			turtle->Push(false);
			break;
		}
	}
}