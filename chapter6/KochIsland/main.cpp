#include "lib\egl.h"
#include "turtle.h"

using namespace egl;

class RenderWindow : public Window
{
private:
	Turtle turtle;
public:
	void KochCurve(int n);
	void KochIsland(int n);
	virtual void RenderGLScene(void);
	virtual void OnSize(WPARAM wParam, LPARAM lParam);
};
void RenderWindow::KochCurve(int n)
{
	if(n==0)
	{
		turtle.Forward(1.0f);
	}
	else
	{
						 KochCurve(n-1);
		turtle.Left(60); KochCurve(n-1);
		turtle.Right(120); KochCurve(n-1);
		turtle.Left(60); KochCurve(n-1);
	}
}
void RenderWindow::KochIsland(int n)
{
						KochCurve(n);
	turtle.Right(120);  KochCurve(n);
	turtle.Right(120);  KochCurve(n);
}
void RenderWindow::RenderGLScene(void)
{
	Window::RenderGLScene();

	glTranslatef(0.0f, 0.0f, -35.0f);

	turtle.SetStartPoint(-12.0f, 7.0f, 0.0f);

	KochIsland(3);
}
void RenderWindow::OnSize(WPARAM wParam, LPARAM lParam)
{
	GLsizei width  = LOWORD(lParam);
	GLsizei height = HIWORD(lParam);

	if (height == 0)
		height = 1;                     

	glViewport( 0, 0, width, height ); 

	glMatrixMode(GL_PROJECTION);       
	glLoadIdentity();                  

	gluPerspective(54.0f, GLfloat(width)/GLfloat(height), 1.0f, 1000.0f);
	
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();           
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE, "Fractal - Koch Island"))
		return EXIT_FAILURE;
	return app.Run();
}