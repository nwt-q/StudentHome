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
#include "LoginRegisterModule.h"

#define MAXN 10
// -------------------- ������� --------------------

//��ʱ�Դ���(����Ա)
struct User {
	// �û���
	std::string name;
	//�û�����
	std::string power;
};

/*
	�����ˣ�
	���ܣ�ѧ����Ϣ�洢
*/
struct Student {
	std::string ID;// ѧ�� 
	std::string Name;//����
	std::string Class;// �༶
	std::string Grade;//�ɼ�
	std::string Power;//�ɼ�
};

// -------------------- service --------------------

class StudentModel : public LoginRegisterModule {
public:
    /*
        ���ܣ����ڳ�ʼ��������Ϣ
        ������std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
        ����ֵ��Student*
    */
    Student* StudentIn(Student* NEWStudent, std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power);

    /*
        ���ܣ�ע���˺�
        ������std::string name, std::string power
        ����ֵ��void
    */
    bool resign(std::string name, std::string power) override;

    /*
        ���ܣ�ע���˺�
        ������std::string name, std::string power
        ����ֵ��void
    */
    bool sign(std::string name, std::string power) override;

    /*
        �����ˣ�
        ���ܣ������˺�
        ������std::string name, std::string power
        ����ֵ��void
    */
    bool Login(std::string name, std::string power) override;

private:
    std::string name; //�û���
    std::string power; //����
    std::string ID;// ѧ��
    std::string Name;//����
    std::string Class;// �༶
    std::string Grade;//�ɼ�
    std::string Power;//�ɼ�
};

/*
	�����ˣ�
	���ܣ����ع���Ա��Ϣ
	������void
	����ֵ��void
*/
User* ReturnUser();

/*
	�����ˣ�
	���ܣ������û�����
	������void
	����ֵ��void
*/
int* ReturnUserCount();

/*
	�����ˣ�
	���ܣ�����Student˽������
	������void
	����ֵ��void
*/
vector<Student>& ReturnStudent();

/*
	�����ˣ�
	���ܣ�����Header˽������
	������void
	����ֵ��void
*/
std::string ReturnHeader();


/*
	�����ˣ�
	���ܣ���ʽ�������������ݵĸ�ʽ��
	������void
	����ֵ��void
*/
std::string FormatInfo(Student* Stu);

/*
	�����ˣ�
	���ܣ����ڽ�ע����Ϣд���ļ������ݽ��г־û�����
	������const std::string& FileName
	����ֵ��void
*/
void StudentFilein(const std::string& FileName);

/*
	�����ˣ�
	���ܣ������ļ���Ϣ
	������const std::string& FileName
	����ֵ��void
*/
void StudentFilenout(const std::string& FileName);


/*
    �����ˣ�
    ���ܣ����ڳ�ʼ��������Ϣ
    ������std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
    ����ֵ��Student*
*/
Student* StudentIn(Student* NEWStudent, std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power);


//-------------��ʱģ��-----------------


/*
	�����ˣ�
	���ܣ��Լ�ʱ�����г�ʼ��
	������void
	����ֵ��void
*/
void Timeinit();


/*
	�����ˣ�
	���ܣ����ؼ�ʱ��״̬
	������bool
	����ֵ��bool
*/
bool isPause();

/*
	�����ˣ�
	���ܣ����ؼ�ʱ��״̬
	������bool
	����ֵ��bool
*/
bool isStop();

/// ��ʱ�������߹���


/*
	�����ˣ�
	���ܣ���ʼרע,���ؼ�ʱ��״̬
	������void
	����ֵ��bool
*/
void Start(); 

/*
	�����ˣ�
	���ܣ���ͣרערע
	������void
	����ֵ��void
*/
void Pause();

/*
	�����ˣ�
	���ܣ�ֹͣרע
	������void
	����ֵ��void
*/
void Stop(); 


/*
	�����ˣ�
	���ܣ���ȡʱ�� ��Ϊʱ����һ���ܴ�����������ʹ��long
	������void
	����ֵ��inline
*/

inline long getStartTime();

/*
	�����ˣ�
	���ܣ�����רעʱ��, ��ʱ��ʱ, ��ʱҳ��,�߼�����ʵ��
	������void
	����ֵ��inline
*/
void TimePrint();

//-------------------------------------

/*
	�����ˣ�
	���ܣ� ��Ϸģ��
	������void
	����ֵ��void
*/
void game();

/*
	�����ˣ�
	���ܣ� ��ҵ����
	������ void
	����ֵ��void
*/
void WorkSendown();

//��ҵ�ύ
/*
	�����ˣ�
	���ܣ� ��ҵ�ύ
	������ void
	����ֵ��void
*/
void WorkSendTo();

/*
	�����ˣ�
	���ܣ�������
	������void
	����ֵ��void
*/
void OpenMusic();

/*
	�����ˣ�
	���ܣ��ر�����
	������void
	����ֵ��void
*/
void CloseMusic();

/*
	�����ˣ�
	���ܣ������ӡ
	������void
	����ֵ��void
*/
void T();
// -------------------- view --------------------

#endif // !_STUDENT_