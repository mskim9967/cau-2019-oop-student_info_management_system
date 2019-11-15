/**
	@file   SystemMessage.cpp
	@date   2019/10/01
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  a.exe 실행 중 발생하는 Event에 대한 문자열들을 기술
*/

#include "SystemMessage.h"

void SystemMessage::print(int menuType, int dataType) {
	if (menuType == MAIN) {
		switch (dataType) {
		case SELETION:
			cout << "[ERROR] Wrong type input. Press 1~4" << endl;
			break;
		case ARGUMENT:
			cout << "[SYSTEM] Only 1 arguments allowed. (a.exe filename.txt)" << endl;
			cout << "[SYSTEM] Exit the Program..." << endl;
			break;
		}
	}
	else if (menuType == SEARCH) {
		switch (dataType) {
		case SELETION:
			cout << "[ERROR] Wrong type input. Press 1~5" << endl;
			break;
		case EMPTY:
			cout << "[SYSTEM] No student found" << endl;
			break;
		}
	}
	else if (menuType == INSERTION) {
		switch (dataType) {
		case NAME:
			cout << "[ERROR] Wrong type input. Write equal or less than " << LENGTH_MAX_NAME << " characters(Only Eng)" << endl;
			break;
		case ID:
			cout << "[ERROR] Wrong type input. Write " << LENGTH_ID << " characters(Only number)" << endl;
			break;
		case DEPARTMENT:
			cout << "[ERROR] Wrong type input. Write equal or than " << LENGTH_MAX_DEPARTMENT << " characters(Only Eng)" << endl;
			break;
		case AGE:
			cout << "[ERROR] Wrong type input. Write equal or less than " << LENGTH_MAX_AGE << " characters(Only number)" << endl;
			break;
		case TELEPHONE:
			cout << "[ERROR] Wrong type input. Write equal or than " << LENGTH_MAX_TELEPHONE << " characters(Only number)" << endl;
			break;
		case OVERLAP:
			cout << "[ERROR] Student ID overlapped" << endl;
			break;
		}
	}
	else if (menuType == FILEIO_) {
		switch (dataType) {
		case EMPTY:
			cout << "[SYSTEM] There is no file in directory, so new file created" << endl;
			break;
		}
	}
	else if (menuType == ALL) {
		switch (dataType) {
		case WAITKEY:
			cout << "[SYSTEM] Press any key to continue..." << endl;
			break;
		}
	}
}