/**
	@file   Constant.h
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  prob2에서 사용할 const변수들을 모아둔 헤더파일
*/
#ifndef CONSTANT
#define CONSTANT

#include <string>

namespace Constant {

#define LENGTH_MAX_NAME 15
#define LENGTH_MAX_NAME_MINUS_ONE 14
#define LENGTH_MAX_DEPARTMENT 20
#define LENGTH_ID 10
#define LENGTH_MAX_AGE 3
#define LENGTH_MAX_TELEPHONE 12

#define ASCENDING 0
#define DESENDING 1
#define NUM_STUDENT_INFO 5

#define DELIMITER '|'

#define REGEX_ONE_TO_FOUR "[1-4]"
#define REGEX_ONE_TO_FIVE "[1-5]"
#define REGEX_NAME "^[a-zA-Z]+[a-zA-Z ]{0,14}$"
#define REGEX_ID "^[0-9]{10}$"
#define REGEX_DEPARTMENT "^[a-zA-Z ]{0,20}$"    //공백 허용
#define REGEX_TELEPHONE "^[0-9]{0,12}$" //공백 허용
#define REGEX_AGE "^[0-9]{0,3}$"    //공백 허용

	enum DataType {
		SELETION,
		NAME,
		ID,
		DEPARTMENT,
		AGE,
		TELEPHONE,
		OVERLAP,
		WAITKEY,
		EMPTY,
		ARGUMENT
	};

	enum MenuType {
		MAIN,
		INSERTION,
		SEARCH,
		DELETION,
		EXIT,
		ALL,
		FILEIO_
	};
}
#endif