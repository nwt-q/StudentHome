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


//��ʱ�Դ���
struct User {
	// �û���
	std::string name;
	//�û�����
	std::string power;
};

User student[MAXN];

// ��ǰ�û�����
int UserCount = 0;

//����ģ��,������ģ��
void Adminrun() {

	//������ѭ��
	while (true) {
		LoginView(); // ����ҳ��
		/*if (!Login()) continue;*/
	}
}

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
	return true;
}

/// <summary>
/// ������Ϸģ��
/// </summary>
void game() {

}