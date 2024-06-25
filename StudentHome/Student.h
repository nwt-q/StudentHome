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

//暂时性储存(管理员)
extern struct User {
	// 用户名
	std::string name;
	//用户密码
	std::string power;
};

/*
	负责人：
	功能：学生信息存储
*/
extern struct Student {
	std::string ID;// 学号 
	std::string Name;//姓名
	std::string Class;// 班级
	std::string Grade;//成绩
	std::string Power;//成绩
};

// -------------------- service --------------------

User* ReturnUser();

int ReturnUserCount();

vector<Student> ReturnStudent();

/*
	负责人：
	功能：用于初始化数据信息
	参数：std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
	返回值：Student*
*/
Student* StudentIn(Student* NEWStudent, std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power);

/*
	负责人：
	功能：格式化数据用于数据的格式化
	参数：void
	返回值：void
*/
std::string FormatInfo(Student* Stu);

/*
	负责人：
	功能：用于将注册信息写入文件对数据进行持久化储存
	参数：const std::string& FileName
	返回值：void
*/
void StudentFilein(const std::string& FileName);

/*
	负责人：
	功能：读入文件信息
	参数：无
	返回值：void
*/
void StudentFilenout(const std::string& FileName);

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