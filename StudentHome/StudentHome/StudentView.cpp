#include "StudentView.h"
#include "Student.h"


//学生登入视图
void LoginView() {
    // 初始化图形模式
    initgraph(680, 480);
    IMAGE img;/*声明一个IMAGE变量*/
    loadimage(&img, "../../../Photo/18.png",680,480);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
    putimage(0, 0, &img);/*展示图片*/
    /*cleardevice();*/
    //setbkcolor(RED);
    //cleardevice();

    // 设置文本样式
    settextstyle(30, 0, _T("黑体"));
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
    //Login();
    
    // 等待用户按键
   /* _getch();*/
    while (true);
    // 关闭图形模式
    closegraph();
    return ;


}