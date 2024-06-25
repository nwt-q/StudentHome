#include "AdminView.h"
#include "StudentView.h"
#define fillColor { 92, 235, 89 }
#define textColor { 255,255,255 }


//定义消息结构体变量
ExMessage msg = {};

void StudentInfoDisplay()
{
    setbkmode(TRANSPARENT);
    IMAGE img;
    loadimage(&img, "../Photo/20.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    setbkmode(TRANSPARENT);
    StudentshowButton(1, 15, 100, 50, "返回菜单", 20, fillColor, textColor);
    StudentshowButton(1145, 15, 100, 50, "下一页", 20, fillColor, textColor);
    settextcolor(BLACK);
    settextstyle(60, 0, _T("华文新魏"));//设置字号、字体
    for (int i = 0; i < ReturnStudent().size(); i++) {
        outtextxy(220, 220, ReturnStudent()[0].ID.c_str());
        outtextxy(220+ 100, 220 + 100, ReturnStudent()[0].Name.c_str());
        outtextxy(220 + 200, 220, ReturnStudent()[0].Class.c_str());
        outtextxy(220 + 300, 220, ReturnStudent()[0].Grade.c_str());
    }
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //判断是否点击
            if (msg.message == WM_LBUTTONDOWN && msg.x > 1145 && msg.y > 15 && msg.x < 1145 + 100 && msg.y < 15 + 100)
            {
                StudentInfoDisplay1();
                StudentInfoDisplay();
            }
            if (msg.message == WM_LBUTTONDOWN && msg.x > 25 && msg.y > 15 && msg.x < 25 + 100 && msg.y < 15 + 100)
            {
                StudentmenuView();
            }
        }
    }
}

void StudentInfoDisplay1()/*改名*/
{
    setbkmode(TRANSPARENT);
    IMAGE img;
    loadimage(&img, "../Photo/20.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    StudentshowButton(25, 15, 100, 50, "上一页", 20, fillColor, textColor);
    StudentshowButton(1145, 15, 100, 50, "返回菜单", 20, fillColor, textColor);
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //判断是否点击
            if (msg.message == WM_LBUTTONDOWN && msg.x > 25 && msg.y > 15 && msg.x < 25 + 100 && msg.y < 15 + 100)
            {
                StudentInfoDisplay();
                StudentInfoDisplay1();
            }
            if (msg.message == WM_LBUTTONDOWN && msg.x > 1145 && msg.y > 15 && msg.x < 1145 + 100 && msg.y < 15 + 100)
            {
                StudentmenuView();
            }
        }
    }
}