/**
	@file   Console.cpp
	@date   2019/09/27
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  a.exe 실행 시 나타나는 콘솔을 기술
*/
#include "Console.h"

void Console::waitForAnyKey() {
	systemMessage.print(ALL, WAITKEY);
	_getch();
}

/**
	@return  greeter에서 입력받은 int값
*/
int Console::main_menu() {
	string stringBuf;
	regex regex_SelectionInMain(REGEX_ONE_TO_FOUR);

	system("cls");
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Deletion" << endl;
	cout << "4. Exit" << endl;

	cout << "\n> ";
	cin >> stringBuf;
	//양식에 맞는 입력값이 들어올 때까지 반복
	while (!regex_match(stringBuf, regex_SelectionInMain)) {
		systemMessage.print(MAIN, SELETION);
		cin >> stringBuf;
	}
	cin.ignore();

	return atoi(stringBuf.c_str());
}

/**
	@return	insertion창을 통해 입력받은 학생 정보
*/
Student Console::insertion() {
	string stringBuf;
	Student studentBuf;

	system("cls");
	cout << "- Insertion -" << endl;

	cout << "Name ? > ";
	getline(cin, stringBuf, '\n');
	while (!studentBuf.setName(stringBuf)) {
		systemMessage.print(INSERTION, NAME);
		cout << "Name ? > ";
		getline(cin, stringBuf, '\n');
	}
	studentBuf.setName_Lowercase();

	cout << "Student ID ? > ";
	getline(cin, stringBuf, '\n');
	while (!studentBuf.setId(stringBuf)) {
		systemMessage.print(INSERTION, ID);
		cout << "Student ID ? > ";
		getline(cin, stringBuf, '\n');
	}

	cout << "Department ? > ";
	getline(cin, stringBuf, '\n');
	while (!studentBuf.setDepartment(stringBuf)) {
		systemMessage.print(INSERTION, DEPARTMENT);
		cout << "Department ? > ";
		getline(cin, stringBuf, '\n');
	}

	cout << "Age ? > ";
	getline(cin, stringBuf, '\n');
	while (!studentBuf.setAge(stringBuf)) {
		systemMessage.print(INSERTION, AGE);
		cout << "Age ? > ";
		getline(cin, stringBuf, '\n');
	}

	cout << "Tel ? > ";
	getline(cin, stringBuf, '\n');
	while (!studentBuf.setTelephone(stringBuf)) {
		systemMessage.print(INSERTION, TELEPHONE);
		cout << "Tel ? > ";
		getline(cin, stringBuf, '\n');
	}

	return studentBuf;
}

void Console::search(StudentDB studentList) {
	string stringBuf;
	Student studentBuf;
	regex regex_SelectionInSearch(REGEX_ONE_TO_FIVE);

	system("cls");
	cout << "1. Search by name" << endl;
	cout << "2. Search by studeint ID (10 numbers)" << endl;
	cout << "3. Search by department name" << endl;
	cout << "4. Search by Age" << endl;
	cout << "5. List All" << endl;

	cout << "\n> ";
	cin >> stringBuf;
	while (!regex_match(stringBuf, regex_SelectionInSearch)) {
		systemMessage.print(SEARCH, SELETION);
		cout << "> ";
		cin >> stringBuf;
	}
	cin.ignore();

	system("cls");
	//콘솔에서의 입력값을 기준으로 검색
	switch (atoi(stringBuf.c_str())) {
	case NAME:
		cout << "Name keyword? > ";
		getline(cin, stringBuf);
		//입력문자열을 소문자로 변환하여 검색
		for (int i = 0; i < stringBuf.length(); i++) {	
			if (stringBuf[i] >= 'A'&&stringBuf[i] <= 'Z')  stringBuf[i] = stringBuf[i] + 'a' - 'A';
		}
		studentList.search(NAME, stringBuf).print();
		break;

	case ID:
		cout << "Student ID number? > ";
		getline(cin, stringBuf);
		studentList.search(ID, stringBuf).print();
		break;

	case DEPARTMENT:
		cout << "Department keyword? > ";
		getline(cin, stringBuf);
		studentList.search(DEPARTMENT, stringBuf).print();
		break;

	case AGE:
		cout << "Age? > ";
		getline(cin, stringBuf);
		while (!studentBuf.setAge(stringBuf)) {
			systemMessage.print(INSERTION, AGE);
			cout << "Age? > ";
			getline(cin, stringBuf, '\n');
		}
		studentList.search(AGE, stringBuf).print();
		break;

	case ALL:
		studentList.print();
		break;
	}

	waitForAnyKey();
}