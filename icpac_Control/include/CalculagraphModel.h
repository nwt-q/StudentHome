//
// Created by NWT on 2024/11/10.
//

/// <summary>
/// 计时器模块
/// </summary>

#ifndef ICPAC_CONTROL_CALCULAGRAPHMODEL_H
#define ICPAC_CONTROL_CALCULAGRAPHMODEL_H


class CalculagraphModel {
public:
    /*
        功能：对计时器进行初始化
        参数：void
        返回值：void
    */
    void Timeinit();

    /*
        功能：返回计时器状态
        参数：bool
        返回值：bool
    */
    bool isPause();

    /*
        功能：返回计时器状态
        参数：bool
        返回值：bool
    */
    bool isStop();

    /*
        负责人：
        功能：开始专注,返回计时器状态
        参数：void
        返回值：bool
    */
    void Start();

    /*
        功能：暂停专注专注
        参数：void
        返回值：void
    */
    void Pause();

    /*
        功能：停止专注
        参数：void
        返回值：void
    */
    void Stop();

    /*
        功能：获取时间 因为时间是一个很大是数据所以使用long
        参数：void
        返回值：inline
    */
    inline long getStartTime();

    /*
        功能：设置专注时间, 定时计时, 暂时页面,逻辑功能实现
        参数：void
        返回值：inline
    */
    void TimePrint();

private:
    long start_time;  // 储存开始时间
    long pause_time; //储存暂停时候已经专注的时间

    //两个bool值标记四种状态
    bool is_pause; //记录计时器的状态 （是否处于暂停状态）
    bool is_stop;//是否处于停止状态
    long pauseT; //暂停时时间
};


#endif //ICPAC_CONTROL_CALCULAGRAPHMODEL_H
