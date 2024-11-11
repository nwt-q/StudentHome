//
// Created by NWT on 2024/11/10.
//

#include "../include/Teacher.h"
#include "../include/StudentView.h"
#include <vector>
#include <algorithm> // 包含 std::sort


void Teacher::corrective(std::string StudentID) {
    for (int i = 0; i < ReturnStudent().size(); i++) {
        if (ReturnStudent()[i].ID == StudentID) {
            std::swap(ReturnStudent()[i], ReturnStudent().back()); // 将第8个元素和最后一个元素交换
            ReturnStudent().pop_back(); // 删除最后一个元素（现在是原来的第8个元素
            std::sort(ReturnStudent().begin(), ReturnStudent().end(),[=](const Student x, const Student y) {
                if (x.ID > y.ID) return true;
                else return false;
            });  // 自定义排序规则
        }
    }
}
