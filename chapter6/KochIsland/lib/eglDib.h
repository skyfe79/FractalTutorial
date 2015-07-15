/***************************************************************************
 { 
 { Class for Windows DIB Image File 
 {
 { can read a file
 {
 { 04.?? / 2003 
 { Sungchul Kim 
 { paranwave@korea.com
 {
 { ����
 { 04.08 : egl namespace �߰�
 {
***************************************************************************/

/* 
   {                                                               
   { �������� BMP ������ �о� ���� ������ �Ѵ�.                     
   { ���� ����� ����.                                             
   { ��Ÿ ������� BMP ������ ���� �б� ����                        
   {                                                              
   { ���� : �輺ö( paranwave@korea.com )                         
   {                                                             
*/

#ifndef _EGL_DIB_H_
#define _EGL_DIB_H_

#include <windows.h>

namespace egl {

class Dib
{
protected:
	LPBITMAPFILEHEADER mBMPFileHeader;
	LPBITMAPINFO	   mBMPInfo;
	LPBITMAPINFOHEADER mBMPInfoHeader;
	RGBQUAD			   *mRGBTable;
	BYTE			   *mRawData;
	UINT			   mColorCount;
	
	void CreateLogicalPallete(void);
	Dib(const Dib&);
public:
	float RedPal[256], GreenPal[256], BluePal[256];

	Dib();
	~Dib(void);
	Dib(const char * filename);
	BOOL LoadFromFile(const char * filename);
	BOOL LoadFromResource(const char * resource) { return TRUE; }
	DWORD GetImageSize(void);
	UINT  GetWidth(void);
	UINT  GetHeight(void);
	UINT  GetChannelCount(void);
	UINT  GetColorCount(void);
	UINT  GetPixelDepth(void);
	LPBITMAPINFOHEADER GetInfoHeaderPtr(void);
	LPBITMAPINFO GetInfoPtr(void);
	LPRGBQUAD GetRGBTablePtr(void);
	BYTE* GetRawData(void);
};

}; //end of namespace
#endif