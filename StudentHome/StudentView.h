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
// -------------------- 数据设计 --------------------
/*
    负责人：
    功能：设计文本框控件
*/
extern struct EasyTextBox
{
    int left = 0, top = 0, right = 0, bottom = 0; // 控件坐标
    char* text = NULL;                         // 控件内容
    UINT64 maxlen = 0;                 // 文本框最大内容长度
};

/*
    负责人：
    功能：实现管控按键
*/
extern struct EasyButton {
    int left = 0, top = 0, right = 0, bottom = 0;	// 控件坐标
    char* text = NULL;							// 控件内容
    void (*userfunc)() = NULL;						// 控件消息
};




// -------------------- service --------------------


// --------------- 学生页面登入注册模块窗口----------------
/*
    负责人：
    功能：绘制用户界面
    参数：void
    返回值：void
*/

void EasyTextBoxShow(EasyTextBox* NEW);

/*
    负责人：
    功能：用于初始化数据
    参数：x1,y1,x2,y2, maxn
    返回值：void
*/
EasyTextBox EasyTextBoxCreate(int x1, int y1, int x2, int y2, int maxn);

/*
    负责人：
    功能：检查是否越界超过最大输入长度
    参数：EasyTextBox* NEW, int x, int y
    返回值：bool
*/
bool EasyTextBoxCheck(EasyTextBox* NEW, int x, int y);

/*
    负责人：
    功能：删除元素数据
    参数：EasyTextBox* NEW
    返回值：bool
*/
void EasyTextBoxDelete(EasyTextBox* NEW);

/*
    负责人：
    功能：绘制界面
    参数：EasyButton* NEW
    返回值：void
*/
void EasyButtonShow(EasyButton* NEW);

/*
    负责人：
    功能：用于初始化数据
    参数：x1,y1,x2,y2, title  (*func)()
    返回值：void
*/
EasyButton EasyButtonCreate(int x1, int y1, int x2, int y2, const char* title, void (*func)());

/*
    负责人：
    功能：删除元素数据
    参数：EasyTextBox* NEW
    返回值：void
*/
void EasyButtonDelete(EasyButton* NEW);

/*
    负责人：
    功能：查看是否在区域内
    参数：EasyTextBox* NEW
    返回值：bool
*/
bool EasyButtonCheck(EasyButton* NEW, int x, int y);

/*
    负责人：
    功能：调用返回函数
    参数：EasyTextBox* NEW
    返回值：void
*/
void EasyButtonOnMessage(EasyButton* NEW);

/*
    负责人：
    功能：确定是否登入成功,按钮 btnOK 的点击事件
    参数：EasyTextBox* NEW
    返回值：void
*/
void On_btnOk_Click();

/*
    负责人：
    功能：确定是否注册成功,按钮 btnOK 的点击事件
    参数：EasyTextBox* NEW
    返回值：void
*/
void On_SendOk_Click();

/*
    负责人：
    功能：鼠标点击事件 & 光标定位
    参数：EasyTextBox* NEW
    返回值：bool
*/

void EasyTextBoxOnMessage(EasyTextBox* NEW);

/*
    负责人：
    功能：密码文本框对文本框进行加密
    参数：EasyTextBox* NEW
    返回值：bool
*/
void EasyPBoxOnMessage(EasyTextBox* NEW);

/*
    负责人：
    功能：登入界面窗口视图
    参数：void
    返回值：void
*/
void LoginView();


/*
    负责人：
    功能：学生注册模块视图
    参数：void
    返回值：void
*/
void StudentSendView();


//-----------------学生登入页面----------------------


/*
    负责人：
    功能：放置按钮
    参数：int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor
    返回值：void
*/
void StudentshowButton(int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor);


/*
    负责人：
    功能：游戏选择页面
    参数：void
    返回值：void
*/
void GameSelect();

/*
    负责人：
    功能：个人菜单页面
    参数：void
    返回值：void
*/
void PersonalInformation();

/*
    负责人：
    功能：学生页面
    参数：void
    返回值：void
*/
void StudentmenuView();

/*
    负责人：
    功能：技术人员展示页面
    参数：void
    返回值：void
*/
void ProductionGroupView();

/*
    负责人：
    功能：设置界面
    参数：void
    返回值：void
*/
void StudentSettingView();

/*
    负责人：
    功能：计时停止页面
    参数：void
    返回值：void
*/
void StopView();

/*
    负责人：
    功能：管控学生登入注册
    参数：void
    返回值：void
*/
void StudentPage();

/*
    负责人：
    功能： 应用第一页
    参数：void
    返回值：void
*/
void FistPage();

/*
    负责人：
    功能： 双缓冲防闪屏技术
    参数：void
    返回值：void
*/
void TimeViewFPS(IMAGE& img);

/// 计时界面  
/*
    负责人：
    功能： 设置耦合返回实现自习功能
    参数：void
    返回值：void
*/
void TimeView();


// -------------------- view --------------------

#endif // !_STUDENT_