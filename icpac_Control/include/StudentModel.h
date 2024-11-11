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
#include "LoginRegisterModule.h"

#define MAXN 10
// -------------------- 数据设计 --------------------

//暂时性储存(管理员)
struct User {
	// 用户名
	std::string name;
	//用户密码
	std::string power;
};

/*
	负责人：
	功能：学生信息存储
*/
struct Student {
	std::string ID;// 学号 
	std::string Name;//姓名
	std::string Class;// 班级
	std::string Grade;//成绩
	std::string Power;//成绩
};

// -------------------- service --------------------

class StudentModel : public LoginRegisterModule {
public:
    /*
        功能：用于初始化数据信息
        参数：std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
        返回值：Student*
    */
    Student* StudentIn(Student* NEWStudent, std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power);

    /*
        功能：注销账号
        参数：std::string name, std::string power
        返回值：void
    */
    bool resign(std::string name, std::string power) override;

    /*
        功能：注册账号
        参数：std::string name, std::string power
        返回值：void
    */
    bool sign(std::string name, std::string power) override;

    /*
        负责人：
        功能：登入账号
        参数：std::string name, std::string power
        返回值：void
    */
    bool Login(std::string name, std::string power) override;

private:
    std::string name; //用户名
    std::string power; //密码
    std::string ID;// 学号
    std::string Name;//姓名
    std::string Class;// 班级
    std::string Grade;//成绩
    std::string Power;//成绩
};

/*
	负责人：
	功能：返回管理员信息
	参数：void
	返回值：void
*/
User* ReturnUser();

/*
	负责人：
	功能：返回用户数量
	参数：void
	返回值：void
*/
int* ReturnUserCount();

/*
	负责人：
	功能：返回Student私有属性
	参数：void
	返回值：void
*/
vector<Student>& ReturnStudent();

/*
	负责人：
	功能：返回Header私有属性
	参数：void
	返回值：void
*/
std::string ReturnHeader();


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
	参数：const std::string& FileName
	返回值：void
*/
void StudentFilenout(const std::string& FileName);


/*
    负责人：
    功能：用于初始化数据信息
    参数：std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
    返回值：Student*
*/
Student* StudentIn(Student* NEWStudent, std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power);


//-------------计时模块-----------------


/*
	负责人：
	功能：对计时器进行初始化
	参数：void
	返回值：void
*/
void Timeinit();


/*
	负责人：
	功能：返回计时器状态
	参数：bool
	返回值：bool
*/
bool isPause();

/*
	负责人：
	功能：返回计时器状态
	参数：bool
	返回值：bool
*/
bool isStop();

/// 计时器的三者功能


/*
	负责人：
	功能：开始专注,返回计时器状态
	参数：void
	返回值：bool
*/
void Start(); 

/*
	负责人：
	功能：暂停专注专注
	参数：void
	返回值：void
*/
void Pause();

/*
	负责人：
	功能：停止专注
	参数：void
	返回值：void
*/
void Stop(); 


/*
	负责人：
	功能：获取时间 因为时间是一个很大是数据所以使用long
	参数：void
	返回值：inline
*/

inline long getStartTime();

/*
	负责人：
	功能：设置专注时间, 定时计时, 暂时页面,逻辑功能实现
	参数：void
	返回值：inline
*/
void TimePrint();

//-------------------------------------

/*
	负责人：
	功能： 游戏模块
	参数：void
	返回值：void
*/
void game();

/*
	负责人：
	功能： 作业接收
	参数： void
	返回值：void
*/
void WorkSendown();

//作业提交
/*
	负责人：
	功能： 作业提交
	参数： void
	返回值：void
*/
void WorkSendTo();

/*
	负责人：
	功能：打开音乐
	参数：void
	返回值：void
*/
void OpenMusic();

/*
	负责人：
	功能：关闭音乐
	参数：void
	返回值：void
*/
void CloseMusic();

/*
	负责人：
	功能：神像打印
	参数：void
	返回值：void
*/
void T();
// -------------------- view --------------------

#endif // !_STUDENT_