#include "lib\egl.h"
#include "turtle.h"

using namespace egl;

class RenderWindow : public Window
{
private:
	Turtle turtle;
public:
	void BinaryTree(int n, float length);
	virtual void RenderGLScene(void);
};

void RenderWindow::BinaryTree(int n, float length)
{
	turtle.Forward(length);
	if(n>0)
	{
		turtle.Push();
		turtle.Left(30);  BinaryTree(n-1, length*0.8);
		turtle.Pop();
		turtle.Right(60); BinaryTree(n-1, length*0.8);
		turtle.Left(30);
	}
}

void RenderWindow::RenderGLScene(void)
{
	Window::RenderGLScene();

	glTranslatef(0.0f, 0.0f, -7.0f);
	
	turtle.SetStartPoint(0.0f, -2.0f, 0.0f);
	turtle.Left(90);

	BinaryTree(12, 1.0f);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	RenderWindow app;
	if(!app.Create(FALSE, "Fractal - Binary Tree"))
		return EXIT_FAILURE;
	return app.Run();
}