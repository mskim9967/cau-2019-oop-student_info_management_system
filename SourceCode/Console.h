/**
	@file   Console.h
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  a.exe 실행 시 나타나는 콘솔을 기술한 Console.cpp의 헤더파일
*/
#ifndef CONSOLE
#define CONSOLE

#include <iostream>
#include <string>
#include <regex>
#include <windows.h>
#include <conio.h>
#include "Student.h"
#include "StudentDB.h"
#include "Constant.h"
#include "SystemMessage.h"

using namespace std;
using namespace Constant;

/**
	@class  Console
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  a.exe 실행 시 나타나는 콘솔 정의
*/
class StudentDB;
class Console {
private:
	SystemMessage systemMessage;
public:
	int main_menu();    ///<Greeter
	Student insertion();	///<insertion창을 띄우고 입력 받은 학생 정보를 반환
	void search(StudentDB studentList);	///<함수인자인 studentDB에서 탐색
	void waitForAnyKey();	///<콘솔 창에서 하나의 아무 키를 입력 받을때까지 대기
};

#endif