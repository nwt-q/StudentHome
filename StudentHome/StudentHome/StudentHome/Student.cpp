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
#include "game.h"
#include <sstream>
#include <iomanip>

//暂时性储存
struct User {
	// 用户名
	std::string name;
	//用户密码
	std::string power;
};


User student[MAXN];

// 当前用户数量
extern int UserCount = 0;
//用于时间统计
extern int tim = 0;


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
	// 如果查找到用户将用户信息置空
	for (int i = 0; i < UserCount; i++) { // 暂时存在BUG无法解决连续性问题
		if (student[i].name == name && student[i].power == power) {
			student[i].name = "";
			student[i].power = "";
			UserCount--;
			return true;
		}
	}
	//未查找到用户, 返回失败
	return false;
}

/// <summary>
/// 导入游戏模块
/// </summary>

void game() {
	using namespace gameqoqo;
	/*initgraph(windowsWidth, windowsHeight, EX_MOUSE);*/
	//打开背景乐：
	changeMusic();
	menuView();
}

void T() {
	printf("////////////////////////////////////////////////////////////////////");
	printf("\n");
	printf("//                          _ooOoo_                               //");
	printf("\n");
	printf("//                         o8888888o                              //");
	printf("\n");
	printf("//                         88\" . \"88                              //");
	printf("\n");
	printf("//                         (| ^_^ |)                              //");
	printf("\n");
	printf("//                         O\\  =  /O                              //");
	printf("\n");
	printf("//                      ____/`---'\\____                           //");
	printf("\n");
	printf("//                    .'  \\\\|     |//  `.                         //");
	printf("\n");
	printf("//                   /  \\\\|||  :  |||//  \\                        //");
	printf("\n");
	printf("//                  /  _||||| -:- |||||-  \\                       //");
	printf("\n");
	printf("//                  |   | \\\\\\  -  /// |   |                       //");
	printf("\n");
	printf("//                  | \\_|  ''\\---/''  |   |                       //");
	printf("\n");
	printf("//                  \\  .-\\__  `-`  ___/-. /                       //");
	printf("\n");
	printf("//                ___`. .'  /--.--\\  `. . ___                     //");
	printf("\n");
	printf("//              .\"\" '<  `.___\\_<|>_/___.'  >'\"\".                  //");
	printf("\n");
	printf("//            | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |                 //");
	printf("\n");
	printf("//            \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /                 //");
	printf("\n");
	printf("//      ========`-.____`-.___\\_____/___.-`____.-'========         //");
	printf("\n");
	printf("//                           `=---='                              //");
	printf("\n");
	printf("//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //");
	printf("\n");
	printf("//              佛祖保佑       永不宕机      永无BUG               //");
	printf("\n");
	printf("////////////////////////////////////////////////////////////////////");
	printf("\n");
	return ;
}


//用于计时
//系统计时为1000ms
double timer() {	// 专门设置时间
	double start = clock();
	char a[10];
	InputBox(a, 10, "输入专注时间");
	tim = atoi(a);
	std::cout << tim << "\n";
	Sleep(tim*1000);
	double end = clock();
	std::cout << start << " " << end << "\n";
	double last = end - start;
	std::cout << last / 1000 << "s";
	return last;
}

//用于作业接收,需要查询作业发送的地方,看看存不存在作业,如果存在则将作业显示于用户,如果没有则不显示
void WorkSendown() {
	
}

//用于作业递交. 更改作业状态
void WorkSendTo() {

}

//用户注册模块
bool Sign(std::string name, std::string power) {
	student[UserCount].name = name;
	student[UserCount].power = power;
	UserCount++;
	return true;
}