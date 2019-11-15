/**
	@file   Main.cpp
	@date   2019/09/27
	@author 김명승(소프트웨어학부 20186274)
	@brief  학생 목록 관리 프로그램인 a.exe를 생성
*/

#include "Console.h" 
#include "Student.h"
#include "StudentDB.h"
#include "FileIO.h"
#include "SystemMessage.h"

int main(int argc, char** argv) {
	SystemMessage systemMessage;
	if (argc != 2) {
		systemMessage.print(MAIN, ARGUMENT);
		return -1;
	}

	Console console;
	Student studentBuf;
	StudentDB studentDB;
	FileIO fileIO;
	const string PATH_STUDENT_DB(argv[1]);

	//파일을 읽어서 studentDB에 저장한다
	//없으면 새로 생성한다
	studentDB = fileIO.openFile_StudentList(PATH_STUDENT_DB);
	//파일에는 추가된 순서대로 정렬되어 있음으로, studentDB는 이름 순으로 정렬한다.
	studentDB.sortByName(ASCENDING);

	while (true) {
		switch (console.main_menu()) {
		case INSERTION:
			studentBuf = console.insertion();

			//Id 중복시 studentDB에 저장하지 않는다
			if (studentDB.isIdOverlap(studentBuf)) {
				systemMessage.print(INSERTION, OVERLAP);
				console.waitForAnyKey();
			}
			else {
				fileIO.saveStudent_StudentList(PATH_STUDENT_DB, studentBuf);
				studentDB.push_back(studentBuf);
				studentDB.sortByName(ASCENDING);
			}
			break;

		case SEARCH:
			console.search(studentDB);
			break;

		case EXIT:
			return 0;
			break;
		}
	}
}