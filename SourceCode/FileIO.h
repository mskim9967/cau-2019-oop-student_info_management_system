/**
	@file   FileIO.h
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  File과 class StudentDB간의 입출력을 기술한 FileIO.cpp의 헤더파일
*/

#ifndef FILEIO
#define FILEIO

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "StudentDB.h"
#include "Student.h"
#include "Console.h"
#include "Constant.h"
#include "SystemMessage.h"

using namespace std;
using namespace Constant;

/**
	@class  FileIO
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  File과 class StudentDB간의 입출력
*/
class FileIO {
private:
	ifstream studentListFileIn;
	ofstream studentListFileOut;
	SystemMessage systemMessage;
	vector<string> split(string str, char delimiter);	///<delimiter로 나뉜 문자열들을 vector로 반환

public:
	StudentDB openFile_StudentList(string filePath);	///<filePath에 존재하는 파일을 열어 studentDB로 반환
	void saveStudent_StudentList(string filePath, Student student);
	void closeFile_StudentList(string filePath);
};

#endif