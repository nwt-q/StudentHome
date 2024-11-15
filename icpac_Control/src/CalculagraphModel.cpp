//
// Created by NWT on 2024/11/10.
//

#include <ctime>
#include <iostream>
#include <easyx.h>
#include "../include/CalculagraphModel.h"

/*
    功能：对计时器进行初始化
    参数：void
    返回值：void
*/
void CalculagraphModel::Timeinit() {
    is_pause = false; //一开始并不是暂停所以为false
    is_stop = true;
    start_time = time(0); // 开始时间设置为系统时间的初始值
}

bool CalculagraphModel::isPause() {

    if (is_pause) return true;
    return false;
}

bool CalculagraphModel::isStop() {
    if (is_stop) return true;
    return false;
}

void CalculagraphModel::Start() {
    if (is_stop) {
        is_stop = false;
    }
    else if (is_pause) { // 如果是暂停
        is_pause = false; // 将暂停状态取消
        start_time += time(0) - pause_time;  // 更新开始时间: 用此来计算时间
    }
}

void CalculagraphModel::Pause() {
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

void CalculagraphModel::Stop() {
    if (is_stop) return; //如果已经在停止状态不做处理
    else if (is_pause) {  // 如果是在暂停状态下停止计时
        is_pause = false; // 关闭暂停状态
        is_stop = true; //设置为停止状态
    }
    else if (!is_stop) {
        is_stop = true;
    }
}

long CalculagraphModel::getStartTime() {
    return start_time;
}

void CalculagraphModel::TimePrint() {

    long t = time(0) - start_time;  // 开始时间
    if (isPause()) { // 如果是暂停状态
        t = pauseT; // 存储暂停时候的时间
    }
    char s[20]; // long -> string
    std::cout << t << std::endl;

    sprintf_s(s, sizeof(s),"%02d:%02d:%02d", t / 60 / 60, t / 60 % 60, t % 60); // 格式化输出
    FlushBatchDraw();   // 更新屏幕显示
    outtextxy(572, 332, _T(s));
    if(is_stop) start_time = time(0);   // 如果终止计时则将初始时间清零
    return ;
}
