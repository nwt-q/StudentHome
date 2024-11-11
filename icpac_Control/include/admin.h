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

#ifndef _ADMIN_
#define _ADMIN_

#include "LoginRegisterModule.h"
// -------------------- ������� --------------------


// -------------------- service --------------------

// https://blog.csdn.net/wangxun20081008/article/details/115033507

class LoginRegisterModule;

class Admin : public LoginRegisterModule{
public:

    /*
        ���ܣ� ע��ѧ���˺��˺�
        ������void
        ����ֵ��void
    */
    bool resign(std::string name, std::string power) override;

    /*
        ���ܣ� ע�����Ա�˺��˺�
        ������void
        ����ֵ��void
    */
    bool sign(std::string name, std::string power) override;

    /*
        ���ܣ� �������Ա�˺��˺�
        ������void
        ����ֵ��void
    */
    bool Login(std::string name, std::string power) override;

    /*
        ���ܣ�  ֪ͨģ��
        ������void
        ����ֵ��void
    */
    void notice();

    /*
        ���ܣ�ģ�黯���� �ڲ�Ӱ�������������������
        ������void
        ����ֵ��void
    */
    void adminmodel();

};
/*
    �����ˣ�
    ����: ����ҳ��˵�
    ������void
    ����ֵ��void
*/
//void AdminMenu();

// -------------------- view --------------------

#endif // !_ADMIN_
