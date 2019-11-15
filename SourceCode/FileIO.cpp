/**
	@file   FileIO.cpp
	@date   2019/10/01
	@author 김명승(mskim9967@gmail.com) 중앙대학교 소프트웨어학부 20186274
	@brief  File과 class StudentDB간의 입출력을 기술
*/
#include "FileIO.h"

/**
	@return	나뉜 TOKEN들
*/
vector<string> FileIO::split(string str, char delimiter) {
	vector<string> vectorToken;
	stringstream ss(str);
	string stringBuf;

	while (getline(ss, stringBuf, delimiter)) {
		vectorToken.push_back(stringBuf);
	}

	return vectorToken;
}

/**
	@return	파일의 정보들을 담은 studentDB
	@warning 파일이 경로에 존재하지 않으면 해당 파일을 생성한다
*/
StudentDB FileIO::openFile_StudentList(string filePath) {
	StudentDB studentDB_Buf = StudentDB();
	string stringBuf, token[NUM_STUDENT_INFO];

	studentListFileIn.open(filePath);
	//파일이 존재하지 않을 시 새롭게 생성
	if (!studentListFileIn.is_open()) {
		systemMessage.print(FILEIO_, EMPTY);
		new ofstream(filePath);
	}

	while (getline(studentListFileIn, stringBuf)) {
		Student studentBuf;
		vector<string> tokenBuf;

		tokenBuf = split(stringBuf, DELIMITER);

		for (int i = 0; i < NUM_STUDENT_INFO; i++) {

			switch (i + 1) {
			case NAME:
				studentBuf.setName(tokenBuf[i]);
				studentBuf.setName_Lowercase();
				break;
			case ID:
				studentBuf.setId(tokenBuf[i]);
				break;
			case DEPARTMENT:
				studentBuf.setDepartment(tokenBuf[i]);
				break;
			case AGE:
				//cout << tokenBuf[i] << endl;
				studentBuf.setAge(tokenBuf[i]);
				break;
			case TELEPHONE:
				studentBuf.setTelephone(tokenBuf[i]);
				break;
			}
		}
		studentDB_Buf.push_back(studentBuf);
	}

	studentListFileIn.close();
	return studentDB_Buf;
}

/**
	@warning 학생 정보를 여러명이 아닌 한 명 기준으로 저장한다
*/
 void FileIO::saveStudent_StudentList(string filePath, Student student) {
	string stringBuf;

	studentListFileOut.open(filePath, ios::app);

	for (int i = 1; i <= NUM_STUDENT_INFO; i++) {
		switch (i) {
		case NAME:
			studentListFileOut << student.getName() << DELIMITER;
			break;
		case ID:
			studentListFileOut << student.getId() << DELIMITER;
			break;
		case DEPARTMENT:
			studentListFileOut << student.getDepartment() << DELIMITER;
			break;
		case AGE:
			studentListFileOut << student.getAge() << DELIMITER;
			break;
		case TELEPHONE:
			studentListFileOut << student.getTelephone() << DELIMITER;
			break;
		}
	}
	studentListFileOut << endl;
	studentListFileOut.close();
}


 void FileIO::closeFile_StudentList(string filePath) {
	studentListFileIn.close();
}