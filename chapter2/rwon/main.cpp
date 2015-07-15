#include <windows.h>
#include "lib\egl.h"
#include <math.h>
#include <time.h>

using namespace egl;
#define TORAD (0.01745f)

void DrawCircle(GLfloat x, GLfloat y, GLfloat r)
{
	glBegin(GL_POINTS);
		for(int i=0; i<360; ++i)
		{
			glVertex2f(x+(r*cos(i*TORAD)), y+(r*sin(i*TORAD)));
		}
	glEnd();
}

void RecursiveCircle(GLfloat x, GLfloat y, GLfloat r)
{
	
	if(r>8.0f)
	{
		
		DrawCircle(x, y, r);
		
		RecursiveCircle(x-r/2, y, r/2);
		RecursiveCircle(x+r/2, y, r/2);
		RecursiveCircle(x, y-r/2, r/2);
		RecursiveCircle(x, y+r/2, r/2);

	
	}
}
class RenderWindow : public Window
{
public:
	virtual void RenderGLScene(void);
};


void RenderWindow::RenderGLScene(void)
{
	static GLfloat rot = 0.0f;
	Window::RenderGLScene();

	glTranslatef(0.0f, 0.0f, -170.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	RecursiveCircle(0.0f, 0.0f, 60.0f);
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE,"Recursive Circle"))
		return EXIT_FAILURE;
	return app.Run();
}