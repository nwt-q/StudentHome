/*
 Copyright WU DE QUAN. All rights reserved.

 @Author: EvLast
 @Date: 2024/6/7 3:20:30

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

#include"Student.h"


//暂时性储存
struct User {
	// 用户名
	std::string name;
	//用户密码
	std::string power;
};

User student[MAXN];

// 当前用户数量
int UserCount = 0;

//登入模块,运行总模块
void Adminrun() {

	//程序总循环
	while (true) {
		LoginView(); // 登入页面
		/*if (!Login()) continue;*/
	}
}

//实现用户登入操作
bool Login(std::string name,std::string power) {
	for (int i = 0; i < UserCount; i++) {
		if (student[i].name == name && student[i].power == power) {
			return true;
		}
	}
	return false;
}


bool resign(std::string name, std::string power) {
	return true;
}

/// <summary>
/// 导入游戏模块
/// </summary>
void game() {

}