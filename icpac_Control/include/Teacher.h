//
// Created by NWT on 2024/11/10.
//

#ifndef ICPAC_CONTROL_TEACHER_H
#define ICPAC_CONTROL_TEACHER_H
#include "admin.h"

class Teacher : public Admin{
public:
    /*
        功能： 修改学生信息
        参数：void
        返回值：void
    */
    void corrective(std::string StudentID);

    /*
        功能：  作业发布
        参数：void
        返回值：void
    */
    void WorkSendUp();


    /*
        功能： 统计模块, 统计学生作业完成情况
        参数：void
        返回值：void
    */
    void statistics();
};


#endif //ICPAC_CONTROL_TEACHER_H
