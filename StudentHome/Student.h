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

//暂时性储存
extern struct User {
	// 用户名
	std::string name;
	//用户密码
	std::string power;
};


// -------------------- service --------------------

User* ReturnUser();
int ReturnUserCount();

// 注销账号
bool resign(std::string name, std::string power);

// 注册账号
bool Sign(std::string name, std::string power);

// 登入账号
bool Login(std::string name, std::string power);

//-------------计时模块-----------------

// 对计时器进行初始化
void Timeinit();

// 返回计时器状态
bool isPause();
 
bool isStop();

// 计时器的三者功能
void Start(); // 开始专注
void Pause(); // 暂替专注专注
void Stop();  // 停止1专注

// 获取时间 因为时间是一个很大是数据所以使用long

inline long getStartTime();

// 设置专注时间, 定时计时, 暂时页面,逻辑功能实现
void TimePrint();

//-------------------------------------

// 游戏模块
void game();

// 作业接收
void WorkSendown();

//作业提交
void WorkSendTo();

/*
	负责人：
	功能：打开音乐
	参数：无
	返回值：void
*/
void OpenMusic();

void CloseMusic();

void T();
// -------------------- view --------------------

#endif // !_STUDENT_