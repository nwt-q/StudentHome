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

std::string inputUser = "";  // 存储输入文本的变量

// 用于读取特定区域的鼠标信息(绿色)
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

//-----------------登入页面设计----------------

/*
    负责人：
    功能：设计文本框控件
*/
struct EasyTextBox 
{
    int left = 0, top = 0, right = 0, bottom = 0; // 控件坐标
    char* text = NULL;                         // 控件内容
    unsigned __int64 maxlen = 0;                 // 文本框最大内容长度
};

/*
    负责人：
    功能：绘制用户界面
    参数：void
    返回值：void
*/

void EasyTextBoxShow(EasyTextBox* NEW) {
    // 备份环境值
    int oldlinecolor = getlinecolor();
    int oldbkcolor = getbkcolor();
    int oldfillcolor = getfillcolor();

    setlinecolor(LIGHTGRAY);		// 设置画线颜色
    setbkcolor(0xeeeeee);			// 设置背景颜色
    setfillcolor(0xeeeeee);			// 设置填充颜色
    fillrectangle(NEW->left, NEW->top, NEW->right, NEW->bottom);  // 绘制矩形 
    outtextxy(NEW->left + 10, NEW->top + 5, _T(NEW->text)); // 显示文本

    // 恢复环境值
    setlinecolor(oldlinecolor);
    setbkcolor(oldbkcolor);
    setfillcolor(oldfillcolor);
}


/*
    负责人：
    功能：用于初始化数据
    参数：x1,y1,x2,y2, maxn
    返回值：void
*/

EasyTextBox EasyTextBoxCreate(int x1, int y1, int x2, int y2, int maxn) {   // 其中的x1, y1, x2, y2
    EasyTextBox NEW = { x1 , y1, x2, y2,NULL,maxn}; // 初始化坐标以及最大值
    NEW.text = new char[NEW.maxlen];  // 创建一个最大长度数组, 函数销毁时可能出现问题
    NEW.text[0] = 0; // 将文本放置于 0
    // 绘制用户界面
    EasyTextBoxShow(&NEW);
    return NEW;
}

/*
    负责人：
    功能：检查是否越界超过最大输入长度
    参数：EasyTextBox* NEW, int x, int y
    返回值：bool
*/
bool EasyTextBoxCheck(EasyTextBox* NEW, int x, int y) {
    return (NEW->right >= x && NEW->left <= x && NEW->top <= y && NEW->bottom >= y);
}

/*
    负责人：
    功能：删除元素数据
    参数：EasyTextBox* NEW
    返回值：bool
*/
void EasyTextBoxDelete(EasyTextBox* NEW) {
    if (NEW->text != NULL) {
        delete[] NEW->text;
    }
}

/*
    负责人：
    功能：鼠标点击事件 & 光标定位
    参数：EasyTextBox* NEW
    返回值：bool
*/
void EasyTextBoxOnMessage(EasyTextBox* NEW)
{
    // 备份环境值
    int oldlinecolor = getlinecolor();
    int oldbkcolor = getbkcolor();
    int oldfillcolor = getfillcolor();

    setlinecolor(BLACK);			// 设置画线颜色
    setbkcolor(WHITE);				// 设置背景颜色
    setfillcolor(WHITE);			// 设置填充颜色
    fillrectangle(NEW->left, NEW->top, NEW->right, NEW->bottom);
    outtextxy(NEW->left + 20, NEW->top + 15, NEW->text);

    int width = textwidth(NEW->text);	// 字符串总宽度
    int counter = 0;				// 光标闪烁计数器
    bool binput = true;				// 是否输入中

    ExMessage msg; // 检查鼠标点击事件
    while (binput)
    {
        while (binput && peekmessage(&msg, EX_MOUSE | EX_CHAR, false))	// 获取消息，但不从消息队列拿出
        {
            if (msg.message == WM_LBUTTONDOWN)
            {
                // 如果鼠标点击文本框外面，结束文本输入
                if (msg.x < NEW->left || msg.x > NEW->right || msg.y < NEW->top || msg.y > NEW->bottom)
                {
                    binput = false;
                    break;
                }
            }
            else if (msg.message == WM_CHAR)
            {
                size_t len = strlen(NEW->text);
                switch (msg.ch)
                {
                case '\b':				// 用户按退格键，删掉一个字符
                    if (len > 0)
                    {
                        NEW->text[len - 1] = 0;
                        width = textwidth(NEW->text);
                        counter = 0;
                        clearrectangle(NEW->left + 10 + width, NEW->top + 1, NEW->right - 1, NEW->bottom - 1);
                    }
                    break;
                case '\r':				// 用户按回车键，结束文本输入
                case '\n':
                    binput = false;
                    break;
                default:				// 用户按其它键，接受文本输入
                    if (len < NEW->maxlen - 1)
                    {
                        NEW->text[len++] = msg.ch;
                        NEW->text[len] = 0;

                        clearrectangle(NEW->left + 10 + width + 1, NEW->top + 3, NEW->left + 10 + width + 1, NEW->bottom - 3);	// 清除画的光标
                        width = textwidth(NEW->text);				// 重新计算文本框宽度
                        counter = 0;
                        outtextxy(NEW->left + 10, NEW->top + 5, NEW->text);		// 输出新的字符串
                    }
                }
            }
            peekmessage(NULL, EX_MOUSE | EX_CHAR);				// 从消息队列抛弃刚刚处理过的一个消息
        }

        // 绘制光标（光标闪烁周期为 20ms * 32）
        counter = (counter + 1) % 32;
        if (counter < 16)
            line(NEW->left + 10 + width + 1, NEW->top + 3, NEW->left + 10 + width + 1, NEW->bottom - 3);				// 画光标
        else
            clearrectangle(NEW->left + 10 + width + 1, NEW->top + 3, NEW->left + 10 + width + 1, NEW->bottom - 3);		// 擦光标

        // 延时 20ms
        Sleep(20);
    }
}

//----------------实现按键控件EasyButton-------------
struct EasyButton {
    int left = 0, top = 0, right = 0, bottom = 0;	// 控件坐标
    char* text = NULL;							// 控件内容
    void (*userfunc)() = NULL;						// 控件消息
};

/*
    负责人：
    功能：绘制界面
    参数：EasyButton* NEW
    返回值：void
*/
void EasyButtonShow(EasyButton* NEW)
{
    // 备份环境
    int oldlinecolor = getlinecolor();
    int oldbkcolor = getbkcolor();
    int oldfillcolor = getfillcolor();

    setlinecolor(BLACK);			// 设置画线颜色
    setbkcolor(WHITE);				// 设置背景颜色
    setfillcolor(WHITE);			// 设置填充颜色
    fillrectangle(NEW->left, NEW->top, NEW->right, NEW->bottom);
    outtextxy(NEW->left + (NEW->right - NEW->left - textwidth(NEW->text) + 1) / 2, NEW->top + (NEW->bottom - NEW->top - textheight(NEW->text) + 1) / 2, NEW->text);
    //恢复环境
    setlinecolor(oldlinecolor);
    setbkcolor(oldbkcolor);
    setfillcolor(oldfillcolor);
}

/*
    负责人：
    功能：用于初始化数据
    参数：x1,y1,x2,y2, title  (*func)()
    返回值：void
*/
EasyButton EasyButtonCreate(int x1, int y1, int x2, int y2, const char* title, void (*func)())
{
    EasyButton NEW = {x1,y1,x2,y2,NULL,NULL};
    NEW.text = new char[strlen(title) + 1];
    strcpy_s(NEW.text, strlen(title) + 1, title);
    NEW.left = x1, NEW.top = y1, NEW.right = x2, NEW.bottom = y2;
    NEW.userfunc = func;
    // 绘制用户界面
    EasyButtonShow(&NEW);
    return NEW;
}

/*
    负责人：
    功能：删除元素数据
    参数：EasyTextBox* NEW
    返回值：bool
*/
void EasyButtonDelete(EasyButton* NEW)
{
    if (NEW->text != NULL)
        delete[] NEW->text;
}

/*
    负责人：
    功能：查看是否在区域内
    参数：EasyTextBox* NEW
    返回值：bool
*/
bool EasyButtonCheck(EasyButton* NEW ,int x, int y)
{
    return (NEW->left <= x && x <= NEW->right && NEW->top <= y && y <= NEW->bottom);
}

/*
    负责人：
    功能：调用返回函数
    参数：EasyTextBox* NEW
    返回值：bool
*/
void EasyButtonOnMessage(EasyButton* NEW)
{
    if (NEW->userfunc != NULL)
        NEW->userfunc();
}

// 定义控件
EasyTextBox txtName;
EasyTextBox txtPwd;
EasyButton btnOK;
int Page = 1;

/*
    负责人：
    功能：确定是否登入成功,按钮 btnOK 的点击事件
    参数：EasyTextBox* NEW
    返回值：bool
*/
void On_btnOk_Click()
{
    if (strcmp("123456", txtPwd.text))
        MessageBox(GetHWnd(), "密码错误", "错误", MB_OK);
    else // 如果登入成功
    {
        MessageBox(GetHWnd(),txtName.text, "Hello", MB_OK); // 消息弹窗
        StudentmenuView();
    }
}
// ------------------------------------------------

/*
    负责人：
    功能：学生登入视图,绘制登录界面
    参数：void
    返回值：void
*/
void LoginView() {

    // 简单绘制界面
    //setbkcolor(0xeeeeee);
    cleardevice();  // 顺便可以消除鼠标
    IMAGE img;/*声明一个IMAGE变量*/
    loadimage(&img, "../../../Photo/18.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    setbkmode(TRANSPARENT); // 用于解决黑色背景图
    settextcolor(BLACK);
    settextstyle(60, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(400, 200, "6月26日课设项目");
    settextstyle(40, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(280, 340, "用户名：");
    txtName = EasyTextBoxCreate(400, 330, 700, 375, 10);        // 创建用户名文本框控件
    settextstyle(40, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(280, 400, "密　码：");
    txtPwd = EasyTextBoxCreate(400, 400, 700, 445, 10);						// 创建密码文本框控件
    settextstyle(15, 0,"");//设置字号、字体
    btnOK = EasyButtonCreate(620, 470, 700, 495, "Login", On_btnOk_Click);	// 创建按钮控件
    settextstyle(30, 0, "");//设置字号、字体

    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);			// 获取消息输入

        if (msg.message == WM_LBUTTONDOWN)
        {
            // 判断控件
            if (EasyTextBoxCheck(&txtName,msg.x, msg.y))	EasyTextBoxOnMessage(&txtName);

            // 判断控件
            if (EasyTextBoxCheck(&txtPwd,msg.x, msg.y))		EasyTextBoxOnMessage(&txtPwd);

            // 判断控件
            if (EasyButtonCheck(&btnOK,msg.x, msg.y))	EasyButtonOnMessage(&btnOK);
        }
    }
    return;
}

//-----------------登入页面设计----------------

/*
    负责人：
    功能：放置点击的Button
    参数：void
    返回值：void
*/
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

/*
    负责人：
    功能：学生页面用于页面切换
    参数：void
    返回值：void
*/


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
    /*用于页面跳转*/
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
                Page = 0;
                LoginView();
            }
        }
        //switch (Page) {
        //case 0: exit(0); break;
        //case 1: StudentmenuView(); break;
        //case 2: TimeView(); break;
        //}
    }
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
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "返回菜单", 48, fillColor, textColor);
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
                Page = 0;
                StudentmenuView();
            }
        }
    }
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

