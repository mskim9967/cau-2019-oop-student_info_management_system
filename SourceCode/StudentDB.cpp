/**
	@file   StudentDB.cpp
	@date   2019/10/01
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  class Student들을 저장하고 관리
*/
#include "StudentDB.h"

bool compare_name_ascending(Student a, Student b) {
	return (a.getName_Lowercase() < b.getName_Lowercase());
}

bool compare_name_descending(Student a, Student b) {
	return (a.getName_Lowercase() > b.getName_Lowercase());
}

void StudentDB::push_back(Student studentBuf) {
	studentList.push_back(studentBuf);
}

Student StudentDB::getStudent(int i) {
	return studentList[i];
}

void StudentDB::sortByName(bool order) {

	if (order == ASCENDING) {
		sort(studentList.begin(), studentList.end(), compare_name_ascending);
	}
	else if (order == DESENDING) {
		sort(studentList.begin(), studentList.end(), compare_name_descending);
	}
}

bool StudentDB::isIdOverlap(Student studentBuf) {
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].getId().compare(studentBuf.getId()) == 0)
			return true;
	}
	return false;
}

/**
	@return 조건에 맞는 학생들을 담은 StudentDB 반환
	@warning 조건은 type변수로 판단한다, 이름은 대소문자 구분 없이 검색 가능하다
*/
StudentDB StudentDB::search(int type, string stringBuf) {
	StudentDB tempStudentDB = StudentDB();

	switch (type) {
	case NAME:
		for (int i = 0; i < studentList.size(); i++) {
			//stringBuf와 name이 일부 일치한다면
			if (studentList[i].getName_Lowercase().find(stringBuf) != string::npos) {
				tempStudentDB.push_back(studentList[i]);
			}
		}
		break;

	case ID:
		for (int i = 0; i < studentList.size(); i++) {
			//stringBuf와 ID가 전부 일치한다면
			if (studentList[i].getId().compare(stringBuf) == 0) {
				tempStudentDB.push_back(studentList[i]);
			}
		}
		break;

	case AGE:
		for (int i = 0; i < studentList.size(); i++) {
			//stringBuf의 정수형과 age가 전부 일치한다면
			if (studentList[i].getAge() == atoi(stringBuf.c_str())) {
				tempStudentDB.push_back(studentList[i]);
			}
		}
		break;

	case DEPARTMENT:
		for (int i = 0; i < studentList.size(); i++) {
			//stringBuf와 department가 일부 일치한다면
			if (studentList[i].getDepartment().find(stringBuf) != string::npos) {
				tempStudentDB.push_back(studentList[i]);
			}
		}
		break;
	}
	return tempStudentDB;
}

void StudentDB::print() {
	//검색된 학생이 없다면
	if (studentList.size() == 0) {
		systemMessage.print(SEARCH, EMPTY);
	}
	else {
		cout.setf(std::ios::left, std::ios::adjustfield);
		cout << endl;
		cout << setw(LENGTH_MAX_NAME) << "Name" << " " << setw(LENGTH_ID) << "StudentID "
			<< " " << setw(LENGTH_MAX_DEPARTMENT) << "Dept" << " " << setw(LENGTH_MAX_AGE)
			<< "Age" << " " << setw(LENGTH_MAX_TELEPHONE) << "Tel" << endl;

		for (int i = 0; i < studentList.size(); i++) {
			studentList[i].print();
		}
		cout << endl;
	}
}
