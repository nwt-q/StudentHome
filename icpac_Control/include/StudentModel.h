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
/// struct 结构体转换为StudentModel中的类

///*
//	负责人：
//	功能：学生信息存储
//*/
//struct Student {
//	std::string ID;// 学号
//	std::string Name;//姓名
//	std::string Class;// 班级
//	std::string Grade;//成绩
//	std::string Power;//成绩
//};

// -------------------- service --------------------

class StudentModel : public LoginRegisterModule {
public:
    /*
        功能：用于初始化数据信息
        参数：std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
        返回值：Student*
    */
    StudentModel(std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power);

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
	功能：神像打印
	参数：void
	返回值：void
*/
void T();
// -------------------- view --------------------

#endif // !_STUDENT_