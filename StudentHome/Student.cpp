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
#define _CRT_SECURE_NO_WARNINGS 1
//---------------数据设计----------------------

long start_time;  // 储存开始时间
long pause_time; //储存暂停时候已经专注的时间

//两个bool值标记四种状态 
bool is_pause; //记录计时器的状态 （是否处于暂停状态）
bool is_stop;//是否处于停止状态 
long pauseT; //暂停时时间




// 当前用户数量
extern int UserCount = 1;
std::string Header; // 显示项(显示的头部)
std::vector<Student> StudentM; //(保存数据)
User student[MAXN];


User* ReturnUser() {
	student[0].name = "root";
	student[0].power = "123456";
	return student;
}

int ReturnUserCount() {
	return UserCount;
}

/*
	负责人：
	功能：用于初始化数据信息
	参数：std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
	返回值：Student*
*/
Student* StudentIn(Student* NEWStudent, std::string ID, std::string Name, std::string Class, std::string Grade,std::string Power) {
	NEWStudent->ID = ID;
	NEWStudent->Name = Name;
	NEWStudent->Class = Class;
	NEWStudent->Grade = Grade;
	NEWStudent->Power = Power;
	return  NEWStudent;
}


// ---------------service-----------------

vector<Student> ReturnStudent() {
	return StudentM;
}


/*
	负责人：
	功能：格式化数据用于数据的格式化
	参数：void
	返回值：void
*/
std::string FormatInfo(Student* Stu) {
	std::stringstream ss;
	ss << Stu->ID << "\t" << "\t" << Stu->Name << "\t" << "\t" << Stu->Class << "\t" << " " << Stu->Grade << "\t" << "\t" << Stu->Power;
	return ss.str();
}


/*
	负责人：
	功能：用于将注册信息写入文件对数据进行持久化储存
	参数：const std::string& FileName : 文件名
	返回值：void
*/
void StudentFilein(const std::string& FileName)
{
	fstream write(FileName, ios::out | ios::trunc);  // FileName : 打开参数   ios::out | ios::trunc : 打开模式

	if (!write.is_open())
	{
		cerr << "Unable to open file." << std::endl; // 未打开成功
		return;
	}
	// 写入头部数据
	Header += "\n";
	write.write(Header.c_str(), Header.size());
	// 写入数据
	for (int i = 0; i < StudentM.size(); i++) 
	{
		/*cout << FormatInfo(&StudentM[i]) << endl;*/  // 测试
		write.write(FormatInfo(&StudentM[i]).c_str(), FormatInfo(&StudentM[i]).size()); // 写入数据
	}
	write.close();
}


/*
	负责人：
	功能：读入文件信息
	参数：const std::string& FileName : 文件名
	返回值：void
*/
void StudentFilenout(const std::string& FileName)
{
	// 注意引入头文件 : #include <fstream>
	fstream read(FileName, ios::in);
	if (!read.is_open()) {
		std::cerr << "Unable to open file." << std::endl; // 未打开成功
		return;
	}
	char Buf[1024] = { 0 };
	read.getline(Buf, 1024);
	Header= std::string(Buf);
	cout << Header << endl;
	
	//读取数据
	while (!read.eof()) 
	{
		char data[1024] = { 0 };
		read.getline(data, 1024);// 读取一行数据

		Student Limit;
		stringstream ss(data); // 对数据进行解析

		//从文件中解析数据
		ss >> Limit.ID;
		ss >> Limit.Name;
		ss >> Limit.Class;
		ss >> Limit.Grade;
		ss >> Limit.Power;

		student[UserCount].name = (std::string)Limit.Name;
		student[UserCount].power = (std::string)Limit.Power;

		UserCount++;

		//用于储存学生信息
		StudentM.push_back(Limit);

		std::cout <<  Limit.ID << " " << Limit.Name << " " << Limit.Class << " " << Limit.Grade << " " << Limit.Power; // 测试
	}

	read.close();
}


//实现用户登入操作
bool Login(std::string name, std::string power) {
	for (int i = 0; i < UserCount; i++) {
		if (student[i].name == name && student[i].power == power) {
			return true;
		}
	}
	return false;
}


bool resign(std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power) {
	// 如果查找到用户将用户信息置空
	for (int i = 0; i < UserCount; i++) { // 暂时存在BUG无法解决连续性问题
		if (student[i].name == Name && student[i].power == Power) {
			student[i].name = "";
			student[i].power = "";
			UserCount--;
			return true;
		}
	}

	//未查找到用户, 返回失败
	return false;
}


// -----------------------计时功能模块------------------------------


void Timeinit()
{
	is_pause = false; //一开始并不是暂停所以为false
	is_stop = true;
	start_time = time(0); // 开始时间设置为系统时间的初始值
}

bool isPause()
{
	if (is_pause) return true;

	return false;
}

bool isStop()
{
	if (is_stop) return true;
	return false;
}

void Start()
{
	if (is_stop) {
		is_stop = false;
	}
	else if (is_pause) { // 如果是暂停
		is_pause = false; // 将暂停状态取消
		start_time += time(0) - pause_time;  // 更新开始时间: 用此来计算时间
	}
}

void Pause() // 暂停状态
{
	if (is_stop || is_pause)
	{
		return;
	}
	else {
		pause_time = time(0);
		is_pause = true;
		pauseT = time(0) - start_time;  // 储存前面已经经过的时间
	}
}

void Stop()
{
	if (is_stop) return; //如果已经在停止状态不做处理
	else if (is_pause) {  // 如果是在暂停状态下停止计时
		is_pause = false; // 关闭暂停状态
		is_stop = true; //设置为停止状态
	}
	else if (!is_stop) {
		is_stop = true;
	}
}

/*
	负责人：
	功能：实现时间的读取
	参数：void
	返回值：inline long
*/
inline long getStartTime()
{
	return start_time;
}

//用于计时
//系统计时为1000m

/*
	负责人：
	功能：实现自习功能的聚合
	参数：void
	返回值：void
*/
void TimePrint() {	// 专门设置时间
	long t = time(0) - start_time;  // 开始时间
	if (isPause()) { // 如果是暂停状态
		t = pauseT; // 存储暂停时候的时间
	}
	char s[20]; // long -> string
	std::cout << t << endl;
	/*clearrectangle(572, 332,200,100);*/
	sprintf_s(s, sizeof(s),"%02d:%02d:%02d", t / 60 / 60, t / 60 % 60, t % 60); // 格式化输出
	FlushBatchDraw();   // 更新屏幕显示
	outtextxy(572, 332, _T(s));
	if(is_stop) start_time = time(0);   // 如果终止计时则将初始时间清零
	return ;
}

//---------------------------------------------------------------


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

/*
	负责人：
	功能：打开音乐
	参数：无
	返回值：void
*/
void OpenMusic() {
	mciSendString(_T("open su.mp3 alias ../Music/backgroundMusic.mp3"), NULL, 0, NULL);//播放音乐
	mciSendString(_T("play ../Music/backgroundMusic.mp3 repeat"), NULL, 0, NULL);//循环播放
}

/*
	负责人：
	功能：关闭音乐
	参数：无
	返回值：void
*/
void CloseMusic() {
	mciSendString(_T("close  ../Music/backgroundMusic.mp3"), NULL, 0, NULL);//关闭音乐
}


void T() {
	printf("////////////////////////////////////////////////////////////////////\n");
	printf("//                          _ooOoo_                               //\n");
	printf("//                         o8888888o                              //\n");
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



//用于作业接收,需要查询作业发送的地方,看看存不存在作业,如果存在则将作业显示于用户,如果没有则不显示
void WorkSendown() 
{
	
}

//用于作业递交. 更改作业状态
void WorkSendTo() {

}

//用户注册模块
bool Sign(std::string name, std::string power) 
{
	student[UserCount].name = name;
	student[UserCount].power = power;
	UserCount++;
	return true;
}
