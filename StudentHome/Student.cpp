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
std::string Header; // ��ʾ��(��ʾ��ͷ��)
std::vector<Student> StudentM; //(��������)
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
	�����ˣ�
	���ܣ����ڳ�ʼ��������Ϣ
	������std::string ID,std::string Name,std::string Class,std::string Grade,Student* NEWStudent
	����ֵ��Student*
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
	�����ˣ�
	���ܣ���ʽ�������������ݵĸ�ʽ��
	������void
	����ֵ��void
*/
std::string FormatInfo(Student* Stu) {
	std::stringstream ss;
	ss << Stu->ID << "\t" << "\t" << Stu->Name << "\t" << "\t" << Stu->Class << "\t" << " " << Stu->Grade << "\t" << "\t" << Stu->Power;
	return ss.str();
}


/*
	�����ˣ�
	���ܣ����ڽ�ע����Ϣд���ļ������ݽ��г־û�����
	������const std::string& FileName : �ļ���
	����ֵ��void
*/
void StudentFilein(const std::string& FileName)
{
	fstream write(FileName, ios::out | ios::trunc);  // FileName : �򿪲���   ios::out | ios::trunc : ��ģʽ

	if (!write.is_open())
	{
		cerr << "Unable to open file." << std::endl; // δ�򿪳ɹ�
		return;
	}
	// д��ͷ������
	Header += "\n";
	write.write(Header.c_str(), Header.size());
	// д������
	for (int i = 0; i < StudentM.size(); i++) 
	{
		/*cout << FormatInfo(&StudentM[i]) << endl;*/  // ����
		write.write(FormatInfo(&StudentM[i]).c_str(), FormatInfo(&StudentM[i]).size()); // д������
	}
	write.close();
}


/*
	�����ˣ�
	���ܣ������ļ���Ϣ
	������const std::string& FileName : �ļ���
	����ֵ��void
*/
void StudentFilenout(const std::string& FileName)
{
	// ע������ͷ�ļ� : #include <fstream>
	fstream read(FileName, ios::in);
	if (!read.is_open()) {
		std::cerr << "Unable to open file." << std::endl; // δ�򿪳ɹ�
		return;
	}
	char Buf[1024] = { 0 };
	read.getline(Buf, 1024);
	Header= std::string(Buf);
	cout << Header << endl;
	
	//��ȡ����
	while (!read.eof()) 
	{
		char data[1024] = { 0 };
		read.getline(data, 1024);// ��ȡһ������

		Student Limit;
		stringstream ss(data); // �����ݽ��н���

		//���ļ��н�������
		ss >> Limit.ID;
		ss >> Limit.Name;
		ss >> Limit.Class;
		ss >> Limit.Grade;
		ss >> Limit.Power;

		student[UserCount].name = (std::string)Limit.Name;
		student[UserCount].power = (std::string)Limit.Power;

		UserCount++;

		//���ڴ���ѧ����Ϣ
		StudentM.push_back(Limit);

		std::cout <<  Limit.ID << " " << Limit.Name << " " << Limit.Class << " " << Limit.Grade << " " << Limit.Power; // ����
	}

	read.close();
}


//ʵ���û��������
bool Login(std::string name, std::string power) {
	for (int i = 0; i < UserCount; i++) {
		if (student[i].name == name && student[i].power == power) {
			return true;
		}
	}
	return false;
}


bool resign(std::string ID, std::string Name, std::string Class, std::string Grade, std::string Power) {
	// ������ҵ��û����û���Ϣ�ÿ�
	for (int i = 0; i < UserCount; i++) { // ��ʱ����BUG�޷��������������
		if (student[i].name == Name && student[i].power == Power) {
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
	if(is_stop) start_time = time(0);   // �����ֹ��ʱ�򽫳�ʼʱ������
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
void WorkSendown() 
{
	
}

//������ҵ�ݽ�. ������ҵ״̬
void WorkSendTo() {

}

//�û�ע��ģ��
bool Sign(std::string name, std::string power) 
{
	student[UserCount].name = name;
	student[UserCount].power = power;
	UserCount++;
	return true;
}
