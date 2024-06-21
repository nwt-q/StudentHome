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



// -------------------- service --------------------


// ע���˺�
bool resign(std::string name, std::string power);

// ע���˺�
bool Sign(std::string name, std::string power);

// �����˺�
bool Login(std::string name, std::string power);

// ����רעʱ��, ��ʱ��ʱ
double timer();

// ��Ϸģ��
void game();

// ��ҵ����
void WorkSendown();

//��ҵ�ύ
void WorkSendTo();

//void TextBox(int x, int y, int width, int height, int maxWord);//���캯��
//const wstring& getText();  //�鿴private��Աtext
//bool getSelect();          //�鿴private��ԱisSelected
//bool isEmpty();            //������������Ƿ�Ϊ��
//void clear();              //�������
//void setText(const wstring& newText);
//void draw();               //��ʾ�û�������ַ��Լ����
//bool checkClick(int mouseX, int mouseY);  //������ѵ����ǰ���£��������Ƿ����ı���Χ��
//void keyInput(wchar_t ch); //�����ַ�
//void updateCursor();       //�����ʾ״̬

void T();
// -------------------- view --------------------

#endif // !_STUDENT_