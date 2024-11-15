//
// Created by NWT on 2024/11/11.
//

#include "../include/UserView.h"
#include "../include/game.h"
#include "../include/CalculagraphModel.h"
#include <windows.h>
#define backGround "../resources/Photo/19.png"
#define Titel "Wecome icpac_Control"

WindowController::WindowController() {
    initgraph(1280, 720, SHOWCONSOLE);

    ControlPage();
    while(1) {
        switch(pageIndex){
            case 1:
                ControlPage(); break;
            case 2:
                ProductionGroupView(); break;
            case 3:
                gameQoQoView(); break;
        }
    }
}

WindowController::~WindowController() {
    // 关闭图形模式
    closegraph();
}

void WindowController::ControlPage() {
    IMAGE img;
    loadimage(&img, backGround, 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    setbkmode(TRANSPARENT); // 用于解决黑色背景图
    settextcolor(WHITE);
    settextstyle(60, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(400, 100, _T(Titel));
    IMAGE imgs;
    loadimage(&imgs,"../resources/Photo/shujia.jpg", 70,70);

      int dsty = 250; int dstx = 250;
    for(int i = 0; i < 6; i++,dstx += 150) putimage(dstx,dsty,&imgs);
//    for(int j = 0 ; j < 4; j++, dsty += 100) {
//        dstx = 250;
//        for(int i = 0; i < 6; i++,dstx += 150) putimage(dstx,dsty,&imgs);
//    }

    ExMessage msgs;
    while (true) {
        Sleep(200);
        while (peekmessage(&msgs, EM_MOUSE))
        {
            //判断是否点击
            if (msgs.message == WM_LBUTTONDOWN && msgs.x > 250 && msgs.y > 250 && msgs.x < 250 + 70 && msgs.y < 250 + 70)
            {
                pageIndex = 2;
                return ;
            }
            if (msgs.message == WM_LBUTTONDOWN && msgs.x > 400 && msgs.y > 250 && msgs.x < 400 + 70 && msgs.y < 250 + 70)
            {
                pageIndex = 3;
                return ;
            }
        }
    }
}

void WindowController::ProductionGroupView() {
    const std::string kText = "制作组信息"; // 需要滚动显示的文本内容
    const std::string kTextArr[9] = { "组名：第12组","组长：吴德全","组员：肖舜昌","组员：于在熙",
                                 "组员：钟欣" };
    ExMessage m;

    int y = 720;
    IMAGE img;
    loadimage(&img, "../resources/Photo/19.png", 1280, 720, true);//背景图片

    while (true) { // 循环播放滚动文本
        Sleep(5);
        BeginBatchDraw();
        cleardevice(); // 清空屏幕
        putimage(0, 0, &img);

        settextstyle(48, 0, "华文行楷"); // 设置字体样式和大小
        settextcolor(RGB(238,238,9)); // 设置文本颜色
        setbkmode(TRANSPARENT);

        for (int i = 0; i < 9; i++)
        {
            int w = (1280 - textwidth(kTextArr[i].c_str())) / 2;
            outtextxy(w, i * 100 + y, kTextArr[i].c_str()); // 在指定位置输出文本
        }

        // 显示滚动文本
        y -= 2; // 每次向上移动 1 个像素

        if (y < -700) { // 如果文本移动出屏幕，则重新开始滚动
            y = 720;
        }

        // 等待一定时间，以控制滚动速度
        FlushBatchDraw();
        if (peekmessage(&m, EM_MOUSE)) {
            if (m.message == WM_LBUTTONDOWN) {
                cleardevice();
                EndBatchDraw();
                pageIndex = 1;
                break;
            }
        }
    }
    EndBatchDraw();
}

void WindowController::gameQoQoView() {
    gameqoqo::menuView();
    pageIndex = 1;
    return ;
}




