/***************************************************************************
 { 
 { Class for Opengl Windowed Application
 {
 {
 { 03.?? / 2003 
 { Sungchul Kim 
 { paranwave@korea.com
 {
 { 수정
 { 04.08 : egl namespace (추가
 { 04.15 : 각각의 버퍼를 사용할 수 있도록 해당 가상함수 추가
 {       : UseColorBuffer() { return 1; } <- 해당 버퍼를 사용하게 된다.
 {       : UseColorBuffer() { return 0; } <- 해당 버퍼를 사용하지 않게 한다.
***************************************************************************/
#ifndef _EGL_WINDOW_H_
#define _EGL_WINDOW_H_

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>
#include "eglMsgMacro.h"

//egl : Edin's Game Library
namespace egl {

class Window
{
protected:
	BOOL				mFullscreen;
	HWND				mHWnd;
	MSG					mMsg;
	HDC					mDC;
	HGLRC				mRC;
	HINSTANCE			mHInstance;
	void				DestroyGLWindow(void);
public:
	Window();
	~Window();
	virtual BOOL InitGL(void);
	virtual void RenderGLScene(void);
	HWND GetHWND(void);
	HDC  GetHDC(void);
	
	BOOL Create(BOOL bFullScreen=FALSE, const char *title="EDin OpenGL Framework", int width=640, int height=480, int bits=16, LPTSTR menu=NULL);
	int Run(void);
	
	//어떤 버퍼를 사용할 것인가?
	//사용하려면 함수를 오버로딩해서 1를 리턴하라
	virtual int UseStencilBuffer() { return 0; } //스텐실버퍼
	virtual int UseAccumulationBuffer() { return 0; } //누적버퍼

	DECLARE_MESSAGE_MAP(Window);
	virtual void OnCreate(WPARAM wParam, LPARAM lParam){}
	virtual void OnSize(WPARAM wParam, LPARAM lParam);
	virtual void OnClose(WPARAM wParam, LPARAM lParam);
	virtual void OnKeyDown(WPARAM wParam, LPARAM lParam);
	virtual void OnSysCommand(WPARAM wParam, LPARAM lParam);
	virtual void OnEraseBkgnd(WPARAM wParam, LPARAM lParam);
	virtual void OnCommand(WPARAM wParam, LPARAM lParam) {}
	virtual void OnKeyUp(WPARAM wParam, LPARAM lParam){}
	virtual void OnLButtonDown(WPARAM wParam, LPARAM lParam){}
	virtual void OnLButtonUp(WPARAM wParam, LPARAM lParam){}
	virtual void OnMouseMove(WPARAM wParam, LPARAM lParam){}
	virtual void OnRButtonDown(WPARAM wParam, LPARAM lParam){}
	virtual void OnRButtonUp(WPARAM wParam, LPARAM lParam){}
	virtual void OnChar(WPARAM wParam, LPARAM lParam){}

};

/*
class glWindow : public Window
{

};

class dxWindow : public Window
{

};
*/

}; //end of namespace
#endif