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

#ifndef _STUDENTVIEW_
#define _STUDENTVIEW_

#include "StudentModel.h"

//--------------------����ģ��--------------------------
/*
    ���ܣ�ʵ�ֹܿذ���
*/
struct EasyButton;
/*
    ���ܣ�����ı���ؼ�
*/
struct EasyTextBox;

struct Color;

// -------------------- service --------------------
// �����ع��� QT
class WindowController {
public:
    /*
        ���ܣ������û�����
        ������void
        ����ֵ��void
    */
    void EasyTextBoxShow(EasyTextBox* NEW);

    /*
        ���ܣ����ڳ�ʼ������
        ������x1,y1,x2,y2, maxn
        ����ֵ��void
    */
    EasyTextBox EasyTextBoxCreate(int x1, int y1, int x2, int y2, int maxn);

    /*
        ���ܣ�����Ƿ�Խ�糬��������볤��
        ������EasyTextBox* NEW, int x, int y
        ����ֵ��bool
    */
    bool EasyTextBoxCheck(EasyTextBox* NEW, int x, int y);

    /*
        ���ܣ�ɾ��Ԫ������
        ������EasyTextBox* NEW
        ����ֵ��bool
    */
    void EasyTextBoxDelete(EasyTextBox* NEW);

    /*
        ���ܣ����ư���
        ������EasyButton* NEW
        ����ֵ��void
    */
    void EasyButtonShow(EasyButton* NEW);

    /*
        ���ܣ����ڳ�ʼ������
        ������x1,y1,x2,y2, title  (*func)()
        ����ֵ��void
    */
    EasyButton EasyButtonCreate(int x1, int y1, int x2, int y2, const char* title, void (*func)());

    /*
        ���ܣ�ɾ��Ԫ������
        ������EasyTextBox* NEW
        ����ֵ��void
    */
    void EasyButtonDelete(EasyButton* NEW);

    /*
        ���ܣ��鿴�Ƿ���������
        ������EasyTextBox* NEW
        ����ֵ��bool
    */
    bool EasyButtonCheck(EasyButton* NEW, int x, int y);

    /*
        ���ܣ����÷��غ���
        ������EasyTextBox* NEW
        ����ֵ��void
    */
    void EasyButtonOnMessage(EasyButton* NEW);

    /*
        ���ܣ�ȷ���Ƿ����ɹ�,��ť btnOK �ĵ���¼�
        ������EasyTextBox* NEW
        ����ֵ��void
    */
    int On_btnOk_Click();

    /*
        ���ܣ�ȷ���Ƿ�ע��ɹ�,��ť btnOK �ĵ���¼�
        ������EasyTextBox* NEW
        ����ֵ��void
    */
    int On_SendOk_Click();

    /*
        ���ܣ�������¼� & ��궨λ
        ������EasyTextBox* NEW
        ����ֵ��bool
    */
    void EasyTextBoxOnMessage(EasyTextBox* NEW);

    /*
        ���ܣ������ı�����ı�����м���
        ������EasyTextBox* NEW
        ����ֵ��bool
    */
    void EasyPBoxOnMessage(EasyTextBox* NEW);

    /*
        ���ܣ�������洰����ͼ
        ������void
        ����ֵ��void
    */
    void LoginView();

    /*
        ���ܣ�ѧ��ע��ģ����ͼ
        ������void
        ����ֵ��void
    */
    void StudentSendView();


    /*
        ���ܣ����ð�ť
        ������int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor
        ����ֵ��void
    */
    void StudentshowButton(int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor);

    /*
        ���ܣ���Ϸѡ��ҳ��
        ������void
        ����ֵ��void
    */
    void GameSelect();

    /*
        ���ܣ����˲˵�ҳ��
        ������void
        ����ֵ��void
    */
    void PersonalInformation();

    /*
        ���ܣ�ѧ��ҳ��
        ������void
        ����ֵ��void
    */
    void StudentmenuView();

    /*
        ���ܣ�������Աչʾҳ��
        ������void
        ����ֵ��void
    */
    void ProductionGroupView();

    /*
        ���ܣ����ý���
        ������void
        ����ֵ��void
    */
    void StudentSettingView();

    /*
        ���ܣ���ʱֹͣҳ��
        ������void
        ����ֵ��void
    */
    void StopView();

    /*
        �����ˣ�
        ���ܣ��ܿ�ѧ������ע��
        ������void
        ����ֵ��void
    */
    void StudentPage();

    /*
        ���ܣ� Ӧ�õ�һҳ
        ������void
        ����ֵ��void
    */
    int FistPage();

    /*
        ���ܣ� ˫�������������
        ������void
        ����ֵ��void
    */
    void TimeViewFPS(IMAGE& img);

    /// ��ʱ����
    /*
        �����ˣ�
        ���ܣ� ������Ϸ���ʵ����ϰ����
        ������void
        ����ֵ��void
    */
    void TimeView();

private:

};


// -------------------- view --------------------

#endif // ! _STUDENTVIEW_