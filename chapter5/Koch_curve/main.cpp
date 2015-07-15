#include "lib\egl.h"
#include "turtle.h"

using namespace egl;

Turtle turtle;

class RenderWindow : public Window
{
private:
public:
	virtual void RenderGLScene(void);
};
void Koch(int n)
{
	if(n==0)
	{
		turtle.Forward(0.3f);
	}
	else
	{
							Koch(n-1);
		turtle.Left(60);	Koch(n-1);
		turtle.Right(120);  Koch(n-1);
		turtle.Left(60);    Koch(n-1);
	}
}
void RenderWindow::RenderGLScene(void)
{
	Window::RenderGLScene();
	glTranslatef(0.0f, 0.0f, -70.0f);

	turtle.SetStartPoint(-35.0f, 0.0f, 0.0f);
	Koch(7);
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE, "EDin's OpenGL - Koch Curve"))
		return EXIT_FAILURE;
	return app.Run();
}