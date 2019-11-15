/**
	@file   StudentDB.h
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  class Student들을 저장하고 관리하는 StudentDB.cpp의 헤더파일
*/
#ifndef STUDENTLIST
#define STUDENTLIST

#include "Student.h"
#include "Constant.h"
#include "Console.h"
#include "SystemMessage.h"
#include <vector>

using namespace std;
using namespace Constant;

/**
	@class  StudentDB
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  학생들의 정보 DB 관리
*/
class StudentDB
{
private:
	vector <Student> studentList;   ///<class Student를 저장할 동적 배열
	SystemMessage systemMessage;
public:
	Student getStudent(int i);
	void push_back(Student studentBuf);
	void sortByName(bool order);
	StudentDB search(int type, string stringBuf);	///<string과 비교하여 탐색 후 그에 맞는 학생들 반환
	bool isIdOverlap(Student studentBuf);	///<중복되면 true 반환
	void print();   ///<배열에 저장된 학생 정보 모두 출력
};

#endif