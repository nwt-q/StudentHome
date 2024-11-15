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
/// struct �ṹ��ת��ΪStudentModel�е���

///*
//	�����ˣ�
//	���ܣ�ѧ����Ϣ�洢
//*/
//struct Student {
//	std::string ID;// ѧ��
//	std::string Name;//����
//	std::string Class;// �༶
//	std::string Grade;//�ɼ�
//	std::string Power;//�ɼ�
//};

// -------------------- service --------------------

class StudentModel : public LoginRegisterModule {
public:
    /*
        ���ܣ����ڳ�ʼ��������Ϣ
        ������std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
        ����ֵ��Student*
    */
    StudentModel(std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power);

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
	���ܣ������ӡ
	������void
	����ֵ��void
*/
void T();
// -------------------- view --------------------

#endif // !_STUDENT_