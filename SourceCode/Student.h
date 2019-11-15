/**
	@file   Student.h
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  학생 한 명을 표현하는 Student.cpp의 헤더파일
*/
#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include "Constant.h"
#include "SystemMessage.h"


using namespace std;
using namespace Constant;

/**
	@class  Student
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  학생 한명을 표현
*/
class Student
{
private:
	string name,
		name_Lowercase, ///<이름을 소문자로 변환, 정렬 기준을 위해 존재함
		department,
		telephone,
		id;
	int age;
	SystemMessage systemMessage;

public:
	//stringBuf가 각 형식에 맞지 않을 시 false 반환
	bool setName(string stringBuf);
	void setName_Lowercase();
	bool setDepartment(string stringBuf);
	bool setTelephone(string stringBuf);
	bool setId(string stringBuf);
	bool setAge(string stringBuf);

	string getName();
	string getName_Lowercase();
	string getDepartment();
	string getTelephone();
	string getId();
	int getAge();

	void print();	///<학생 한 명의 정보 출력
};

#endif
