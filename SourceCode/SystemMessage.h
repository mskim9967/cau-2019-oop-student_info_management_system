/**
	@file	SystemMessage.h
	@date   2019/09/30
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  a.exe 실행 중 발생하는 Event에 대한 문자열들을 기술한 SystemMessage.cpp의 헤더파일
*/
#ifndef SYSTEMMESSAGE
#define SYSTEMMESSAGE

#include <iostream>
#include "Constant.h"

using namespace std;
using namespace Constant;

/**
	@class	SystemMessage
	@date   2019/09/30
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  a.exe 실행 중 발생하는 Event에 대한 문자열들을 기술
*/
class SystemMessage {
public:
	void print(int menuType, int dataType);
};

#endif