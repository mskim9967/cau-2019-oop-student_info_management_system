/**
	@file   Student.cpp
	@date   2019/10/01
	@author ����(mskim9967@gmail.com) �߾Ӵ��б� ����Ʈ�����к� 20186274
	@brief  �л� �� ���� ǥ��
*/
#include "Student.h"

bool Student::setName(string stringBuf) {
	regex regex_name(REGEX_NAME);

	if (!regex_match(stringBuf, regex_name)) {
		return false;
	}
	name = stringBuf;
	return true;
}

void Student::setName_Lowercase() {
	name_Lowercase.assign(name.length(), ' ');
	for (int i = 0; i < name.length(); i++) {
		if (name[i] >= 'A'&&name[i] <= 'Z')  name_Lowercase[i] = name[i] + 'a' - 'A';
		else name_Lowercase[i] = name[i];
	}
}

bool Student::setId(string stringBuf) {
	regex regex_id(REGEX_ID);

	if (!regex_match(stringBuf, regex_id)) {
		return false;
	}
	id = stringBuf;
	return true;
}

bool Student::setDepartment(string stringBuf) {
	regex regex_department(REGEX_DEPARTMENT);

	if (!regex_match(stringBuf, regex_department)) {
		return false;
	}
	department = stringBuf;
	return true;
}

bool Student::setTelephone(string stringBuf) {
	regex regex_telephone(REGEX_TELEPHONE);

	if (!regex_match(stringBuf, regex_telephone)) {
		return false;
	}
	telephone = stringBuf;
	return true;
}

bool Student::setAge(string stringBuf) {
	regex regex_age(REGEX_AGE);

	//-1�� ������ �ǹ�, ������ �������� ���̹Ƿ� true�� ��ȯ
	if (atoi(stringBuf.c_str()) == -1 || stringBuf.length() == 0) {
		age = -1;
		return true;
	}

	if (!regex_match(stringBuf, regex_age)) {
		return false;
	}
	age = atoi(stringBuf.c_str());
	//������ �����ϱ� ���� -1�� ��ȯ
	if (age == 0) age = -1;
	return true;
}


string Student::getName() {
	return name;
}
string Student::getName_Lowercase() {
	return name_Lowercase;
}
string Student::getDepartment() {
	return department;
}
string Student::getTelephone() {
	return telephone;
}
string Student::getId() {
	return id;
}
int Student::getAge() {
	return age;
}

void Student::print() {
	cout.setf(std::ios::left, std::ios::adjustfield);
	cout << setw(LENGTH_MAX_NAME) << name << " ";
	cout << setw(LENGTH_ID) << id << " ";
	if (department.length() == 0)
		cout << setw(LENGTH_MAX_DEPARTMENT) << "-" << " ";
	else
		cout << setw(LENGTH_MAX_DEPARTMENT) << department << " ";
	if (age == -1)
		cout << setw(LENGTH_MAX_AGE) << "-" << " ";
	else
		cout << setw(LENGTH_MAX_AGE) << age << " ";
	if (telephone.length() == 0)
		cout << setw(LENGTH_MAX_TELEPHONE) << "-" << endl;
	else
		cout << setw(LENGTH_MAX_TELEPHONE) << telephone << endl;
}

