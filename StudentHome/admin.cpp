/*
 Copyright WU DE QUAN. All rights reserved.

 @Author: EvLast
 @Date: 2024/6/7 1:20:30

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


#include "admin.h"
#include "StudentView.h"
/*
    �����ˣ�
    ���ܣ� �޸�ѧ����Ϣ
    ������void
    ����ֵ��void
*/
bool resign(std::string name, std::string power)
{
    return 0;
}

/*
    �����ˣ�
    ���ܣ� �޸�ѧ����Ϣ
    ������ReturnStudent() ���ڻ�ȡѧ����Ϣ std::string name,  std::string StudentClass
    ����ֵ��void
*/
void corrective(std::string StudentID) {
    auto& AllStudents = ReturnStudent();

    auto cmp = [&](const Student x, const Student y) {return x.ID <= y.ID; };

    for (int i = 0; i < AllStudents.size(); i++) {
        if (AllStudents[i].ID == StudentID) {
            std::swap(AllStudents[i], AllStudents.back()); // ����8��Ԫ�غ����һ��Ԫ�ؽ���  
            AllStudents.pop_back(); // ɾ�����һ��Ԫ�أ�������ԭ���ĵ�8��Ԫ��
            sort(AllStudents.begin(), AllStudents.end(),cmp);  // �Զ����������
            MessageBox(GetHWnd(), "ѧ����Ϣ�Ѿ�ɾ���ɹ�", "���Ĺ���Ա", MB_OK); // ��Ϣ����
            return;
        }
    }
    MessageBox(GetHWnd(), "ѧ����Ϣɾ��ʧ��", "���Ĺ���Ա", MB_OK); // ��Ϣ����
}