#pragma once

/*
 Copyright WU DE QUAN. All rights reserved.

 @Author: EvLast
 @Date: 2024/6/6 12:34:36

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _STUDENT_
#define _STUDENT_
#include "All.h"
#define MAXN 10
// -------------------- ������� --------------------

//��ʱ�Դ���
extern struct User {
	// �û���
	std::string name;
	//�û�����
	std::string power;
};


// -------------------- service --------------------

User* ReturnUser();
int ReturnUserCount();

// ע���˺�
bool resign(std::string name, std::string power);

// ע���˺�
bool Sign(std::string name, std::string power);

// �����˺�
bool Login(std::string name, std::string power);

//-------------��ʱģ��-----------------

// �Լ�ʱ�����г�ʼ��
void Timeinit();

// ���ؼ�ʱ��״̬
bool isPause();
 
bool isStop();

// ��ʱ�������߹���
void Start(); // ��ʼרע
void Pause(); // ����רערע
void Stop();  // ֹͣ1רע

// ��ȡʱ�� ��Ϊʱ����һ���ܴ�����������ʹ��long

inline long getStartTime();

// ����רעʱ��, ��ʱ��ʱ, ��ʱҳ��,�߼�����ʵ��
void TimePrint();

//-------------------------------------

// ��Ϸģ��
void game();

// ��ҵ����
void WorkSendown();

//��ҵ�ύ
void WorkSendTo();

/*
	�����ˣ�
	���ܣ�������
	��������
	����ֵ��void
*/
void OpenMusic();

void CloseMusic();

void T();
// -------------------- view --------------------

#endif // !_STUDENT_