/*
 Copyright WU DE QUAN. All rights reserved.

 @Author: EvLast
 @Date: 2024/6/7 3:29:51

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

#include "StudentView.h"

namespace gxb
{
    const int BUTTONX = 550;
    const int BUTTONY = 200;
    const int BUTTONW = 200;
    const int BUTTONH = 100;

    Color fillColor = { 92, 235, 89 }; // 按键颜色
    Color textColor = { 255,255,255 }; // 文本颜色

    //定义消息结构体变量
    ExMessage msg;
    //鼠标是否在矩形内 
    bool inArea(int mx, int my, int x, int y, int w, int h) //用于捕获鼠标点击事件
    {
        if (mx > x && my > y && mx < x + w && my < y + h)
        {
            return true;
        }
        return false;
    }
}

//学生登入视图
void LoginView() {
    // 初始化图形模式
    initgraph(1280, 720);
    IMAGE img;/*声明一个IMAGE变量*/
    loadimage(&img, "../../../Photo/18.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    // 设置文本样式
    setbkmode(TRANSPARENT);  // 用于解决黑色背景图
    settextstyle(30, 0, _T("黑体")); // TRANSPARENT
    settextcolor(BLACK);
    outtextxy(240, 100, _T("学生登录"));
    settextstyle(20, 0, _T("宋体"));

    // 绘制输入框
    rectangle(320, 190, 580, 220);
    rectangle(320, 250, 580, 280);

    // 定义用户名和密码变量
    char username[20] = "";
    char password[20] = "";

    // 输入用户名
    settextstyle(20, 0, _T("宋体"));
    outtextxy(180, 200, _T("用户名："));
    // 输入密码
    settextstyle(20, 0, _T("宋体"));
    outtextxy(180, 260, _T("密码："));
    //  学生登入模块
    char s[10];
    while (true);
    // 关闭图形模式
    closegraph();
    return;

}

void StudentshowButton(int x, int y, int width, int height, std::string str, int textSize,Color fillColor, Color textColor)			//默认黑底，白字
{
    setfillcolor(RGB(fillColor.R, fillColor.G, fillColor.B));
    fillroundrect(x, y, x + width, y + height, width / 10, width / 10);
    setbkmode(TRANSPARENT);
    settextstyle(textSize, 0, _T("华文行楷"));
    int w = (width - textwidth(str.c_str())) / 2;
    int h = (height - textheight(str.c_str())) / 2;
    settextcolor(RGB(textColor.R, textColor.G, textColor.B));
    outtextxy(x + w, y + h, str.c_str());
}

//学生页面用于页面切换
void StudentmenuView() {
    using namespace gxb;
    //initgraph(1280, 720);
    cleardevice();
    IMAGE img;
    loadimage(&img, "../../../Photo/19.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/

    StudentshowButton(BUTTONX, 100, BUTTONW, BUTTONH, "开始自习", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "游戏空间", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 400, BUTTONW, BUTTONH, "全局设置", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "退出登入", 48, fillColor, textColor);

    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //判断是否点击
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 100, BUTTONW, BUTTONH))
            {
                TimeView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 250, BUTTONW, BUTTONH))
            {
                game();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 400, BUTTONW, BUTTONH))
            {
                StudentSettingView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 550, BUTTONW, BUTTONH))
            {
                exit(0);
            }
        }
    }
    // 关闭图形模式
    closegraph();
}


//学生设置页面
void StudentSettingView() {
    using namespace gxb;
    cleardevice();
    IMAGE img;
    loadimage(&img, "../../../Photo/18.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/

    StudentshowButton(BUTTONX, 100, BUTTONW, BUTTONH, "技术人员", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "背景设置", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 400, BUTTONW, BUTTONH, "打开音乐", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "退出", 48, fillColor, textColor);
}

// 学生计时专注页面
void TimeView() {
    cleardevice();
    IMAGE img;
    loadimage(&img, "../../../Photo/19.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    StudentshowButton(550, 100, 200, 100, "自习中", 48, {92,235,89}, {255,255,255});
    timer();
}