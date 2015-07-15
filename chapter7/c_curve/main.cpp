#include "lib\egl.h"
#include "turtle.h"

using namespace egl;

class RenderWindow : public Window
{
private:
	Turtle turtle;
public:
	void c_curve(int n);
	virtual void RenderGLScene(void);
	virtual void OnSize(WPARAM wParam, LPARAM lParam);
};
void RenderWindow::OnSize(WPARAM wParam, LPARAM lParam)
{
	GLsizei width  = LOWORD(lParam);
	GLsizei height = HIWORD(lParam);

	if (height == 0)
		height = 1;                     // Making Height Equal One

	glViewport( 0, 0, width, height ); // Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);       // Select The Projection Matrix
	glLoadIdentity();                  // Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(54.0f, GLfloat(width)/GLfloat(height), 1.0f, 1000.0f);
	
	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity();           // Reset The Modelview Matrix
}
void RenderWindow::c_curve(int n)
{
	if(n == 0)
	{
		turtle.Forward(1.0f);
		//glFlush();
		//apBuffers(mDC);
	}
	else
	{
		turtle.Left(45); c_curve(n-1);
		turtle.Right(90); c_curve(n-1);
		turtle.Left(45); 
	}
}
void RenderWindow::RenderGLScene(void)
{
	Window::RenderGLScene();

	glTranslatef(0.0f, 0.0f, -400.0f);

	turtle.SetStartPoint(-90.0f, 0.0f, 0.0f);
	c_curve(15);

}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE, "Fractal - C curve"))
		return EXIT_FAILURE;
	return app.Run();
}