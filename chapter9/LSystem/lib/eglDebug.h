/***************************************************************************
 { 
 { Debug Utility
 {
 {
 { a. TRACE(...)
 {
 { 04.?? / 2003 
 { Sungchul Kim 
 { paranwave@korea.com
 {
 { ����
 { 04.08 : egl namespace �߰�
 {
***************************************************************************/
#ifndef _EGL_DEBUG_H_
#define _EGL_DEBUG_H_

namespace egl {

#ifdef _DEBUG
#	define TRACE _TRACE
#else
#	define TRACE
#endif

void _TRACE(const char* szMessage, ...);

}; //end of namespace
#endif