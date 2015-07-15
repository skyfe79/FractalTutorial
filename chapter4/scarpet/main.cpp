#include "lib\egl.h"
using namespace egl;
void DrawRectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(x1, y1, x2, y2);
}
void SCarpet_b(GLfloat x, GLfloat y, GLfloat r)
{
	if(r >= 1.0)
	{
		DrawRectangle(x-r/3,y-r/3,x+r/3,y+r/3);
		SCarpet_b(x-r, y-r, r/2.0f);
		SCarpet_b(x+r, y-r, r/2.0f);
		SCarpet_b(x-r, y+r, r/2.0f);
		SCarpet_b(x+r, y+r, r/2.0f);
	}
}
void SCarpet_a(GLfloat x, GLfloat y, GLfloat r)
{
	if(r >= 1.0f)
	{
		DrawRectangle(x-r/6, y-r/6, x+r/6, y+r/6);
		SCarpet_a(x-r/3, y-r/3, r/3);
		SCarpet_a(x    , y-r/3, r/3);
		SCarpet_a(x+r/3, y-r/3, r/3);
		SCarpet_a(x-r/3, y    , r/3);
		SCarpet_a(x+r/3, y    , r/3);
		SCarpet_a(x-r/3, y+r/3, r/3);
		SCarpet_a(x    , y+r/3, r/3);
		SCarpet_a(x+r/3, y+r/3, r/3);
	}
}
class RenderWindow : public Window
{
private:
	bool mode;
public:
	virtual void RenderGLScene(void);
	virtual void OnCreate(WPARAM wParam, LPARAM lParam);
	virtual void OnSize(WPARAM wParam, LPARAM lParam);
	virtual void OnKeyDown(WPARAM wParam, LPARAM lParam);
};
void RenderWindow::OnCreate(WPARAM wParam, LPARAM lParam)
{
	mode = true;
}
void RenderWindow::OnSize(WPARAM wParam, LPARAM lParam)
{
	GLfloat width, height;
	width = LOWORD(lParam);
	height = HIWORD(lParam);
	if (height == 0)
		height = 1; 
	glViewport( 0, 0, width, height ); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(54.0f, GLfloat(width)/GLfloat(height), 1.0f, 1000.0f);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
}
void RenderWindow::OnKeyDown(WPARAM wParam, LPARAM lParam)
{
	if(wParam == VK_F1)
	{
		mode = !mode;
	}
	Window::OnKeyDown(wParam, lParam);
}
void RenderWindow::RenderGLScene(void)
{
	Window::RenderGLScene();

	if(mode)
	{
		glTranslatef(0.0f, 0.0f, -70.0f);
		SCarpet_a(0.0f, 0.0f, 50.0f);
	}
	else
	{
		glTranslatef(0.0f, 0.0f, -400.0f);
		SCarpet_b(0.0f, 0.0f, 80.0f);
	}
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE, "Fractal - Sierpinski Carpet",252,258))
		return EXIT_FAILURE;
	return app.Run();
}