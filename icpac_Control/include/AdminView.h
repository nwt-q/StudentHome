#pragma once

/*
 Copyright WU DE QUAN. All rights reserved.

 @Author: EvLast
 @Date: 2024/6/7 0:20:30

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

#ifndef _ADMINVIEW_
#define _ADMINVIEW_
#include"admin.h"
#include "../lib/lib-easyx/include/EasyButton.h"
// -------------------- service --------------------
class AdminViews {
public:

    /*
        ����: ����ҳ��˵�
        ������void
        ����ֵ��void
    */
    void AdminMenu();
    /*
        ���ܣ� ѧ����Ϣ��ʾ (��ҳ)
        ������void
        ����ֵ��void
    */
    void StudentInfoDisplay();

    /*
        ���ܣ��ܿع���Ա����ҳ��
        ������void
        ����ֵ��void
    */
    [[maybe_unused]] void AdminPage();

    /*
        ���ܣ�����Աҳ��
        ������void
        ����ֵ��void
    */
    int AdminView();

    /*
        ���ܣ�����Աҳ��
        ������void
        ����ֵ��void
    */
    void CorrectiveView();
public: // �ź���� => �¼�����
    int AdminOn_btnOk_Click();
private:
    EasyButton * Button;
};

// -------------------- view --------------------

#endif // !_STUDENT_