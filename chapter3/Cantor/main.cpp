#include <windows.h>
#include "lib\egl.h"

using namespace egl;

#define N 1.0f

void DrawRectangle(GLfloat x, GLfloat y, GLfloat length)
{
	glPushMatrix();
		//지정 위치로 이동
		glTranslatef(x, y, 0.0f);
		//Y축으로 length 만큼 확대
		glScalef(1.0f, length, 1.0f);
		//넓이 1*length 의 사각형
		glBegin(GL_QUADS); 
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, 0.0f, 0.0f);
			glVertex3f( 0.0f, 0.0f, 0.0f);
			glVertex3f( 0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();
	glPopMatrix();	
}

void Cantor(GLfloat x, GLfloat y, GLfloat length)
{
	if(length > 0.1f)
	{
		DrawRectangle(x, y, length); //A
		
		//각 사각형의 간격은 1.5
		Cantor(x+1.5f, y,			  length/3.0f); //B
		Cantor(x+1.5f, y+length*(2.0f/3.0f), length/3.0f); //C
	}
}
class RenderWindow : public Window
{
private:
	GLsizei width, height;
public:
	virtual void RenderGLScene(void);
	virtual void OnSize(WPARAM wParam, LPARAM lParam);
};
void RenderWindow::OnSize(WPARAM wParam, LPARAM lParam)
{
	width  = LOWORD(lParam);
	height = HIWORD(lParam);

	if (height == 0)
		height = 1;                    

	glViewport( 0, 0, width, height ); 

	glMatrixMode(GL_PROJECTION);       
	glLoadIdentity();                  

	width /= 5;  //X축 5배 확대
	height /= 5; //Y축 5배 확대
	
	// {left, top}~{right,bottom} => {0,0}~{width, height}
	glOrtho(0, width, height, 0, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();           
}
void RenderWindow::RenderGLScene(void)
{
	static float length=60.0f;
	static float OriginX =0.0f; 
	static float OriginY =0.0f; 

	OriginX = (float)(width/2); //칸토어 먼지가 그려질 X축 원점은 윈도우 너비의 1/2
	OriginY = (float)(height/2)-(length*0.5); //칸토어 먼지가 그려질 Y축 원점은 윈도우 높이의 1/2 - 막대기 길이의 1/2

	Window::RenderGLScene();

	Cantor(OriginX, OriginY, length);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE,"Fractal Graphics - Cantor Set"))
		return EXIT_FAILURE;
	return app.Run();
}