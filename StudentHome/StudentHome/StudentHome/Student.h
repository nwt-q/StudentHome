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
// -------------------- 数据设计 --------------------



// -------------------- service --------------------


// 注销账号
bool resign(std::string name, std::string power);

// 注册账号
bool Sign(std::string name, std::string power);

// 登入账号
bool Login(std::string name, std::string power);

// 设置专注时间, 定时计时
double timer();

// 游戏模块
void game();

// 作业接收
void WorkSendown();

//作业提交
void WorkSendTo();

//void TextBox(int x, int y, int width, int height, int maxWord);//构造函数
//const wstring& getText();  //查看private成员text
//bool getSelect();          //查看private成员isSelected
//bool isEmpty();            //检查输入内容是否为空
//void clear();              //清空输入
//void setText(const wstring& newText);
//void draw();               //显示用户输入的字符以及光标
//bool checkClick(int mouseX, int mouseY);  //在鼠标已点击的前提下，检查鼠标是否在文本框范围内
//void keyInput(wchar_t ch); //输入字符
//void updateCursor();       //光标显示状态

void T();
// -------------------- view --------------------

#endif // !_STUDENT_