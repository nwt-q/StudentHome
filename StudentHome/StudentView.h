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

#include "Student.h"
// -------------------- ������� --------------------
/*
    �����ˣ�
    ���ܣ�����ı���ؼ�
*/
extern struct EasyTextBox
{
    int left = 0, top = 0, right = 0, bottom = 0; // �ؼ�����
    char* text = NULL;                         // �ؼ�����
    unsigned __int64 maxlen = 0;                 // �ı���������ݳ���
};

/*
    �����ˣ�
    ���ܣ�ʵ�ֹܿذ���
*/
extern struct EasyButton {
    int left = 0, top = 0, right = 0, bottom = 0;	// �ؼ�����
    char* text = NULL;							// �ؼ�����
    void (*userfunc)() = NULL;						// �ؼ���Ϣ
};




// -------------------- service --------------------


// --------------- ѧ��ҳ�����ע��ģ�鴰��----------------
/*
    �����ˣ�
    ���ܣ������û�����
    ������void
    ����ֵ��void
*/

void EasyTextBoxShow(EasyTextBox* NEW);

/*
    �����ˣ�
    ���ܣ����ڳ�ʼ������
    ������x1,y1,x2,y2, maxn
    ����ֵ��void
*/
EasyTextBox EasyTextBoxCreate(int x1, int y1, int x2, int y2, int maxn);

/*
    �����ˣ�
    ���ܣ�����Ƿ�Խ�糬��������볤��
    ������EasyTextBox* NEW, int x, int y
    ����ֵ��bool
*/
bool EasyTextBoxCheck(EasyTextBox* NEW, int x, int y);

/*
    �����ˣ�
    ���ܣ�ɾ��Ԫ������
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void EasyTextBoxDelete(EasyTextBox* NEW);

/*
    �����ˣ�
    ���ܣ����ƽ���
    ������EasyButton* NEW
    ����ֵ��void
*/
void EasyButtonShow(EasyButton* NEW);

/*
    �����ˣ�
    ���ܣ����ڳ�ʼ������
    ������x1,y1,x2,y2, title  (*func)()
    ����ֵ��void
*/
EasyButton EasyButtonCreate(int x1, int y1, int x2, int y2, const char* title, void (*func)());

/*
    �����ˣ�
    ���ܣ�ɾ��Ԫ������
    ������EasyTextBox* NEW
    ����ֵ��void
*/
void EasyButtonDelete(EasyButton* NEW);

/*
    �����ˣ�
    ���ܣ��鿴�Ƿ���������
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
bool EasyButtonCheck(EasyButton* NEW, int x, int y);

/*
    �����ˣ�
    ���ܣ����÷��غ���
    ������EasyTextBox* NEW
    ����ֵ��void
*/
void EasyButtonOnMessage(EasyButton* NEW);

/*
    �����ˣ�
    ���ܣ�ȷ���Ƿ����ɹ�,��ť btnOK �ĵ���¼�
    ������EasyTextBox* NEW
    ����ֵ��void
*/
void On_btnOk_Click();

void LoginView();


void StudentSendView();


//-----------------ѧ������ҳ��----------------------


/*
    �����ˣ�
    ���ܣ����ð�ť
    ������int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor
    ����ֵ��void
*/
void StudentshowButton(int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor);

// ��Ϸѡ��ҳ��
void GameSelect();
//ѧ��ҳ��
void StudentmenuView();

// ������Աչʾҳ��
void ProductionGroupView();

// ���ý���
void StudentSettingView();


void StopView();

// ˫�������������
void TimeViewFPS(IMAGE& img);

// ��ʱ����
//������Ϸ���ʵ����ϰ����
void TimeView();


// -------------------- view --------------------

#endif // !_STUDENT_