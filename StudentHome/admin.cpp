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
    负责人：
    功能： 修改学生信息
    参数：void
    返回值：void
*/
bool resign(std::string name, std::string power)
{
    return 0;
}

/*
    负责人：
    功能： 修改学生信息
    参数：ReturnStudent() 用于获取学生信息 std::string name,  std::string StudentClass
    返回值：void
*/
void corrective(std::string StudentID) {
    auto& AllStudents = ReturnStudent();

    auto cmp = [&](const Student x, const Student y) {return x.ID <= y.ID; };

    for (int i = 0; i < AllStudents.size(); i++) {
        if (AllStudents[i].ID == StudentID) {
            std::swap(AllStudents[i], AllStudents.back()); // 将第8个元素和最后一个元素交换  
            AllStudents.pop_back(); // 删除最后一个元素（现在是原来的第8个元素
            sort(AllStudents.begin(), AllStudents.end(),cmp);  // 自定义排序规则
            MessageBox(GetHWnd(), "学生信息已经删除成功", "尊贵的管理员", MB_OK); // 消息弹窗
            return;
        }
    }
    MessageBox(GetHWnd(), "学生信息删除失败", "尊贵的管理员", MB_OK); // 消息弹窗
}