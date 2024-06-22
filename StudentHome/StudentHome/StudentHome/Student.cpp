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

//��ʱ�Դ���
struct User {
	// �û���
	std::string name;
	//�û�����
	std::string power;
};


User student[MAXN];

// ��ǰ�û�����
extern int UserCount = 0;
//����ʱ��ͳ��
extern int tim = 0;


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
	printf("//              ���汣��       ����崻�      ����BUG               //");
	printf("\n");
	printf("////////////////////////////////////////////////////////////////////");
	printf("\n");
	return ;
}


//���ڼ�ʱ
//ϵͳ��ʱΪ1000ms
double timer() {	// ר������ʱ��
	double start = clock();
	char a[10];
	InputBox(a, 10, "����רעʱ��");
	tim = atoi(a);
	std::cout << tim << "\n";
	Sleep(tim*1000);
	double end = clock();
	std::cout << start << " " << end << "\n";
	double last = end - start;
	std::cout << last / 1000 << "s";
	return last;
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