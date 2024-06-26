#include "AdminView.h"
#include "StudentView.h"
#define fillColor { 92, 235, 89 }
#define textColor { 255,255,255 }
#define IDX 220
#define NAMEX 358
#define CLASSX 570
#define GREADX 820

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
    StudentshowButton(1145, 15, 100, 50, "下一页", 20, fillColor, textColor);  //Header
    settextcolor(BLACK);
    settextstyle(60, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(IDX - 20, 120, _T("学号"));
    outtextxy(NAMEX - 10, 120, _T("姓名"));
    outtextxy(CLASSX - 10, 120, _T("班级"));
    outtextxy(GREADX - 10, 120, _T("成绩"));
    for (int i = 0; i < ReturnStudent().size() && i < 4; i++) {
        outtextxy(IDX, 220 + i * 100, ReturnStudent()[i].ID.c_str());
        outtextxy(NAMEX, 220 + i * 100, ReturnStudent()[i].Name.c_str());
        outtextxy(CLASSX, 220 + i * 100, ReturnStudent()[i].Class.c_str());
        outtextxy(GREADX, 220 + i * 100, ReturnStudent()[i].Grade.c_str());
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
                AdminView();
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
    settextcolor(BLACK);
    settextstyle(60, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(IDX - 20, 120, _T("学号"));
    outtextxy(NAMEX - 10, 120, _T("姓名"));
    outtextxy(CLASSX - 10, 120, _T("班级"));
    outtextxy(GREADX - 10, 120, _T("成绩"));
    for (int i = 4; i < ReturnStudent().size() && i < 8; i++) {
        outtextxy(IDX, 220 + (i % 4) * 100, ReturnStudent()[i].ID.c_str());
        outtextxy(NAMEX, 220 + (i % 4) * 100, ReturnStudent()[i].Name.c_str());
        outtextxy(CLASSX, 220 + (i % 4) * 100, ReturnStudent()[i].Class.c_str());
        outtextxy(GREADX, 220 + (i % 4 )* 100, ReturnStudent()[i].Grade.c_str());
    }
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
                AdminView();
            }
        }
    }
}


// 用于读取特定区域的鼠标信息(绿色)
namespace gx
{
    const int BUTTONX = 550;
    const int BUTTONY = 200;
    const int BUTTONW = 200;
    const int BUTTONH = 100;

    Color FillColor = { 92, 235, 89 }; // 按键颜色
    Color TextColor = { 255,255,255 }; // 文本颜色

    //定义消息结构体变量
    ExMessage mg;
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

// 定义学生登入页面控件
EasyTextBox TxtName;
EasyTextBox TxtPwd;
EasyTextBox TxtID;
EasyButton BtnOK;
EasyButton BtnOUT;

//定义学生注册页面控件



//-----------------登入页面设计----------------


/*
    负责人：
    功能：绘制用户界面
    参数：void
    返回值：void
*/

void AdminEasyTextBoxShow(EasyTextBox* NEW) {
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

EasyTextBox AdminEasyTextBoxCreate(int x1, int y1, int x2, int y2, int maxn) {   // 其中的x1, y1, x2, y2
    EasyTextBox NEW = { x1 , y1, x2, y2,NULL,maxn }; // 初始化坐标以及最大值
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
bool AdminEasyTextBoxCheck(EasyTextBox* NEW, int x, int y) {
    return (NEW->right >= x && NEW->left <= x && NEW->top <= y && NEW->bottom >= y);
}

/*
    负责人：
    功能：删除元素数据
    参数：EasyTextBox* NEW
    返回值：bool
*/
void AdminEasyTextBoxDelete(EasyTextBox* NEW) {
    if (NEW->text != NULL) {
        delete[] NEW->text;
    }
}


//----------------实现按键控件EasyButton-------------
/*
    负责人：
    功能：绘制界面
    参数：EasyButton* NEW
    返回值：void
*/
void AdminEasyButtonShow(EasyButton* NEW)
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
EasyButton AdminEasyButtonCreate(int x1, int y1, int x2, int y2, const char* title, void (*func)())
{
    EasyButton NEW = { x1,y1,x2,y2,NULL,NULL };
    NEW.text = new char[strlen(title) + 1];
    strcpy_s(NEW.text, strlen(title) + 1, title);
    NEW.left = x1, NEW.top = y1, NEW.right = x2, NEW.bottom = y2;
    NEW.userfunc = func;
    // 绘制管理员界面
    AdminEasyButtonShow(&NEW);
    return NEW;
}

/*
    负责人：
    功能：删除元素数据
    参数：EasyTextBox* NEW
    返回值：bool
*/
void AdminEasyButtonDelete(EasyButton* NEW)
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
bool AdminEasyButtonCheck(EasyButton* NEW, int x, int y)
{
    return (NEW->left <= x && x <= NEW->right && NEW->top <= y && y <= NEW->bottom);
}

/*
    负责人：
    功能：调用返回函数
    参数：EasyTextBox* NEW
    返回值：bool
*/
void AdminEasyButtonOnMessage(EasyButton* NEW)
{
    if (NEW->userfunc != NULL)
        NEW->userfunc();
}


/*
    负责人：
    功能：确定是否登入成功,按钮 btnOK 的点击事件
    参数：EasyTextBox* NEW
    返回值：bool
*/
void AdminOn_btnOk_Click()
{
    User* user = ReturnUser();
    int Usernum = ReturnUserCount();
    for (int i = 0; i < Usernum; i++) {
        if (strcmp(user[i].power.c_str(), TxtPwd.text) || strcmp(user[i].name.c_str(), TxtName.text)) {
            if (i == Usernum - 1) MessageBox(GetHWnd(), "密码错误或用户名不存在", "错误", MB_OK);
        }
        else // 如果登入成功
        {
            MessageBox(GetHWnd(), TxtName.text, "Hello 尊贵的管理员", MB_OK); // 消息弹窗
            AdminView();
        }
    }
}

void AdminOn_Delete_Click()
{
    corrective(TxtID.text);
}

/*
    负责人：
    功能：鼠标点击事件 & 光标定位
    参数：EasyTextBox* NEW
    返回值：bool
*/
void AdminEasyTextBoxOnMessage(EasyTextBox* NEW)
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
                        clearrectangle(NEW->left + 10 + width, NEW->top + 1, NEW->right - 1, NEW->bottom - 1); //清除矩形区域
                    }
                    break;
                case '\r':		AdminOn_btnOk_Click();		// 用户按回车键，结束文本输入
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

/*
    负责人：
    功能：密码文本框对文本框进行加密
    参数：EasyTextBox* NEW
    返回值：bool
*/
void AdminEasyPBoxOnMessage(EasyTextBox* NEW)
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
                        clearrectangle(NEW->left + 10 + width, NEW->top + 1, NEW->right - 1, NEW->bottom - 1); //清除矩形区域
                    }
                    break;
                case '\r':		AdminOn_btnOk_Click();		// 用户按回车键，结束文本输入
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
                        //对密码进行加密
                        std::string P = "";
                        for (int i = 0; i < width / 15; i++) {
                            P += '*';
                        }

                        outtextxy(NEW->left + 10, NEW->top + 5, P.c_str());		// 输出新的字符串
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

//-----------------登入页面设计----------------

/*
    负责人：
    功能：学生登入视图,绘制登录界面
    参数：void
    返回值：void
*/

void AdminPage()
{
    // 简单绘制界面
   //setbkcolor(0xeeeeee);
    cleardevice();  // 顺便可以消除鼠标
    IMAGE img;/*声明一个IMAGE变量*/
    loadimage(&img, "../Photo/II.jpg", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    setbkmode(TRANSPARENT); // 用于解决黑色背景图
    settextcolor(WHITE);
    settextstyle(60, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(400, 200, "Admin Wecome to");
    settextstyle(40, 0, _T("华文新魏")); //设置字号、字体
    outtextxy(280, 340, "用户名：");
    TxtName = AdminEasyTextBoxCreate(400, 330, 700, 375, 10);        // 创建用户名文本框控件
    settextstyle(40, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(280, 400, "密　码 ");
    TxtPwd = AdminEasyTextBoxCreate(400, 400, 700, 445, 10);
    settextstyle(15, 0, "");//设置字号、字体
    settextcolor(BLACK);
    BtnOK = AdminEasyButtonCreate(620, 470, 700, 495, "Login", AdminOn_btnOk_Click);	// 创建按钮控件
    settextstyle(30, 0, "");//设置字号、字体

    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);			// 获取消息输入

        if (msg.message == WM_LBUTTONDOWN)
        {
            // 判断控件
            if (EasyTextBoxCheck(&TxtName, msg.x, msg.y))	AdminEasyTextBoxOnMessage(&TxtName);

            // 判断控件
            if (EasyTextBoxCheck(&TxtPwd, msg.x, msg.y))		AdminEasyPBoxOnMessage(&TxtPwd);

            // 判断控件
            if (EasyButtonCheck(&BtnOK, msg.x, msg.y))	AdminEasyButtonOnMessage(&BtnOK);
        }
    }
    return;
}

/*
    负责人：
    功能：管控管理员登入页面
    参数：void
    返回值：void
*/
void AdminView()
{
    using namespace gx;
    cleardevice();
    IMAGE img;
    loadimage(&img, "../Photo/IV.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/

    StudentshowButton(BUTTONX, 100, BUTTONW, BUTTONH, "学生信息", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "信息删除", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 400, BUTTONW, BUTTONH, "关闭音乐", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "退出登入", 48, fillColor, textColor);
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //判断是否点击
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 100, BUTTONW, BUTTONH))
            {
                StudentInfoDisplay();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 250, BUTTONW, BUTTONH))
            {
                CorrectiveView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 400, BUTTONW, BUTTONH))
            {
                CloseMusic();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 550, BUTTONW, BUTTONH))
            {
                AdminPage();
            }
        }
    }
}

//学生信息删除页面
void CorrectiveView() {
    using namespace gx;
    cleardevice();
    setbkcolor(0xeeeeee);
    IMAGE img;
    loadimage(&img, "../Photo/IV.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    settextstyle(40, 0, _T("华文新魏")); //设置字号、字体
    settextcolor(RED);
    outtextxy(260, 335, "学生ID：");
    setbkmode(TRANSPARENT); // 用于解决黑色背景图
    settextcolor(BLACK);
    settextstyle(60, 0, _T("华文新魏"));//设置字号、字体
    outtextxy(400, 200, "Admin to Delete Student");


    TxtID = AdminEasyTextBoxCreate(400, 330, 700, 375, 10);        // 创建用户名文本框控件

    settextcolor(BLACK);
    settextstyle(15, 0, "");//设置字号、字体
    BtnOK = AdminEasyButtonCreate(620, 470, 700, 495, "Delete", AdminOn_Delete_Click);	// 创建按钮控件
    BtnOUT = AdminEasyButtonCreate(420, 470, 500, 495, "OUT", AdminView);	// 创建按钮控件
    settextstyle(30, 0, "");//设置字号、字体

    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);			// 获取消息输入

        if (msg.message == WM_LBUTTONDOWN)
        {
            // 判断控件
            if (EasyTextBoxCheck(&TxtID, msg.x, msg.y))	AdminEasyTextBoxOnMessage(&TxtID);

            // 判断控件
            if (EasyButtonCheck(&BtnOK, msg.x, msg.y))	AdminEasyButtonOnMessage(&BtnOK);

            //判断控件
            if (EasyButtonCheck(&BtnOUT, msg.x, msg.y))	AdminEasyButtonOnMessage(&BtnOUT);

        }
    }
}