/**
	@file	SystemMessage.h
	@date   2019/09/30
	@author ����(mskim9967@gmail.com) �߾Ӵ��б� ����Ʈ�����к� 20186274
	@brief  a.exe ���� �� �߻��ϴ� Event�� ���� ���ڿ����� ����� SystemMessage.cpp�� �������
*/
#ifndef SYSTEMMESSAGE
#define SYSTEMMESSAGE

#include <iostream>
#include "Constant.h"

using namespace std;
using namespace Constant;

/**
	@class	SystemMessage
	@date   2019/09/30
	@author ����(mskim9967@gmail.com) �߾Ӵ��б� ����Ʈ�����к� 20186274
	@brief  a.exe ���� �� �߻��ϴ� Event�� ���� ���ڿ����� ���
*/
class SystemMessage {
public:
	void print(int menuType, int dataType);
};

#endif