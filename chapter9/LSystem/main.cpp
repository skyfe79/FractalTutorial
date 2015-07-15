#include "lib\egl.h"
#include "LSystem.h"
using namespace egl;
class RenderWindow : public Window
{
private:
	LSystem lsystem;
	Turtle  turtle;
public:
	virtual BOOL InitGL(void);
	virtual void RenderGLScene(void);
};
BOOL RenderWindow::InitGL(void)
{
	Window::InitGL();

	lsystem.SelectTurtle(&turtle);
	lsystem.SetAngle(60.0f);
	lsystem.SetLength(1.0f);
	lsystem.SetFactor(1.0f);
	lsystem.AddTransRule('F', "F+F--F+F");
	lsystem.MakeAxiom("F", 3);
	return TRUE;
}
void RenderWindow::RenderGLScene(void)
{
	Window::RenderGLScene();

	turtle.SetStartPoint(-13.0f, 0.0f, -30.0f);
	lsystem.Draw();
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE, "Fractal - L-SYSTEM [Koch curve]"))
		return EXIT_FAILURE;
	return app.Run();
}