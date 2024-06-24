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
//---------------�������----------------------

long start_time;  // ���濪ʼʱ��
long pause_time; //������ͣʱ���Ѿ�רע��ʱ��

//����boolֵ�������״̬ 
bool is_pause; //��¼��ʱ����״̬ ���Ƿ�����ͣ״̬��
bool is_stop;//�Ƿ���ֹͣ״̬ 
long pauseT; //��ͣʱʱ��




// ��ǰ�û�����
extern int UserCount = 1;

User student[MAXN];


User* ReturnUser() {
	student[0].name = "root";
	student[0].power = "123456";
	return student;
}

int ReturnUserCount() {
	return UserCount;
}

// ---------------service-----------------


//ʵ���û��������
bool Login(std::string name,std::string power) {
	for (int i = 0; i < UserCount; i++) {
		if (student[i].name == name && student[i].power == power) {
			return true;
		}
	}
	return false;
}


bool resign(std::string name, std::string power) {
	// ������ҵ��û����û���Ϣ�ÿ�
	for (int i = 0; i < UserCount; i++) { // ��ʱ����BUG�޷��������������
		if (student[i].name == name && student[i].power == power) {
			student[i].name = "";
			student[i].power = "";
			UserCount--;
			return true;
		}
	}
	//δ���ҵ��û�, ����ʧ��
	return false;
}


// -----------------------��ʱ����ģ��------------------------------


void Timeinit()
{
	is_pause = false; //һ��ʼ��������ͣ����Ϊfalse
	is_stop = true;
	start_time = time(0); // ��ʼʱ������Ϊϵͳʱ��ĳ�ʼֵ
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
		start_time = time(0); // �����ֹ��ʱ�򽫳�ʼʱ������
		is_stop = false;
	}
	else if (is_pause) { // �������ͣ
		is_pause = false; // ����ͣ״̬ȡ��
		start_time += time(0) - pause_time;  // ���¿�ʼʱ��: �ô�������ʱ��
	}
}

void Pause() // ��ͣ״̬
{
	if (is_stop || is_pause)
	{
		return;
	}
	else {
		pause_time = time(0);
		is_pause = true;
		pauseT = time(0) - start_time;  // ����ǰ���Ѿ�������ʱ��
	}
}

void Stop()
{
	if (is_stop) return; //����Ѿ���ֹͣ״̬��������
	else if (is_pause) {  // ���������ͣ״̬��ֹͣ��ʱ
		is_pause = false; // �ر���ͣ״̬
		is_stop = true; //����Ϊֹͣ״̬
	}
	else if (!is_stop) {
		is_stop = true;
		start_time = time(0);   // �����ֹ��ʱ�򽫳�ʼʱ������
	}
}

/*
	�����ˣ�
	���ܣ�ʵ��ʱ��Ķ�ȡ
	������void
	����ֵ��inline long
*/
inline long getStartTime()
{
	return start_time;
}

//���ڼ�ʱ
//ϵͳ��ʱΪ1000m

/*
	�����ˣ�
	���ܣ�ʵ����ϰ���ܵľۺ�
	������void
	����ֵ��void
*/
void TimePrint() {	// ר������ʱ��
	long t = time(0) - start_time;  // ��ʼʱ��
	if (isPause()) { // �������ͣ״̬
		t = pauseT; // �洢��ͣʱ���ʱ��
	}
	char s[20]; // long -> string
	std::cout << t << endl;
	/*clearrectangle(572, 332,200,100);*/
	sprintf_s(s, sizeof(s),"%02d:%02d:%02d", t / 60 / 60, t / 60 % 60, t % 60); // ��ʽ�����
	FlushBatchDraw();   // ������Ļ��ʾ
	outtextxy(572, 332, _T(s));
	return ;
}

//---------------------------------------------------------------


/// <summary>
/// ������Ϸģ��
/// </summary>

void game() {
	using namespace gameqoqo;
	/*initgraph(windowsWidth, windowsHeight, EX_MOUSE);*/
	//�򿪱����֣�
	changeMusic();
	menuView();
}

/*
	�����ˣ�
	���ܣ�������
	��������
	����ֵ��void
*/
void OpenMusic() {
	mciSendString(_T("open su.mp3 alias ../Music/backgroundMusic.mp3"), NULL, 0, NULL);//��������
	mciSendString(_T("play ../Music/backgroundMusic.mp3 repeat"), NULL, 0, NULL);//ѭ������
}

/*
	�����ˣ�
	���ܣ��ر�����
	��������
	����ֵ��void
*/
void CloseMusic() {
	mciSendString(_T("close  ../Music/backgroundMusic.mp3"), NULL, 0, NULL);//�ر�����
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
	printf("//              ���汣��       ����崻�      ����BUG               //");
	printf("\n");
	printf("////////////////////////////////////////////////////////////////////");
	printf("\n");
	return ;
}



//������ҵ����,��Ҫ��ѯ��ҵ���͵ĵط�,�����治������ҵ,�����������ҵ��ʾ���û�,���û������ʾ
void WorkSendown() {
	
}

//������ҵ�ݽ�. ������ҵ״̬
void WorkSendTo() {

}

//�û�ע��ģ��
bool Sign(std::string name, std::string power) {
	student[UserCount].name = name;
	student[UserCount].power = power;
	UserCount++;
	return true;
}