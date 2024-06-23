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

#ifndef _ADMIN_
#define _ADMIN_
#include<iostream>

// -------------------- 数据设计 --------------------



// -------------------- service --------------------

// https://blog.csdn.net/wangxun20081008/article/details/115033507 


// 注销学生账号账号
bool resign(std::string name, std::string power);

// 注册管理员账号账号
bool sign(std::string name, std::string power);

// 登入管理员账号账号
bool Login(std::string name, std::string power);

// 修改学生信息
void corrective(std::string name, std::string StudentID, std::string StudentClass);

// 统计模块, 统计学生作业完成情况
void statistics();

// 通知模块
void notice();

// 作业发布
void WorkSendUp();

// 登入页面菜单
void AdminMenu();


// -------------------- view --------------------

#endif // !_ADMIN_
