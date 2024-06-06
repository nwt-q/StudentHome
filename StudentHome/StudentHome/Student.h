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
#include<iostream>

// -------------------- 数据设计 --------------------



// -------------------- service --------------------

// 注销账号
bool resign(std::string name, std::string power);

// 注册账号
bool sign(std::string name, std::string power);

// 登入账号
bool Login(std::string name, std::string power);

// 设置专注时间, 定时计时
void timer();

// 游戏模块
void game();

// 作业接收
void WorkSendown();

//作业提交
void WorkSendTo();

// -------------------- view --------------------

#endif // !_STUDENT_