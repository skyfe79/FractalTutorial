#include <windows.h>
#include "lib\egl.h"

using namespace egl;

#define N 1.0f

void DrawRectangle(GLfloat x, GLfloat y, GLfloat length)
{
	glPushMatrix();
		//���� ��ġ�� �̵�
		glTranslatef(x, y, 0.0f);
		//Y������ length ��ŭ Ȯ��
		glScalef(1.0f, length, 1.0f);
		//���� 1*length �� �簢��
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
		
		//�� �簢���� ������ 1.5
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

	width /= 5;  //X�� 5�� Ȯ��
	height /= 5; //Y�� 5�� Ȯ��
	
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

	OriginX = (float)(width/2); //ĭ��� ������ �׷��� X�� ������ ������ �ʺ��� 1/2
	OriginY = (float)(height/2)-(length*0.5); //ĭ��� ������ �׷��� Y�� ������ ������ ������ 1/2 - ����� ������ 1/2

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