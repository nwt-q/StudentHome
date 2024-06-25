#include "AdminView.h"
#include "StudentView.h"
#define fillColor { 92, 235, 89 }
#define textColor { 255,255,255 }


//������Ϣ�ṹ�����
ExMessage msg = {};

void StudentInfoDisplay()
{
    setbkmode(TRANSPARENT);
    IMAGE img;
    loadimage(&img, "../Photo/20.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT);
    StudentshowButton(1, 15, 100, 50, "���ز˵�", 20, fillColor, textColor);
    StudentshowButton(1145, 15, 100, 50, "��һҳ", 20, fillColor, textColor);
    settextcolor(BLACK);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
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
            //�ж��Ƿ���
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

void StudentInfoDisplay1()/*����*/
{
    setbkmode(TRANSPARENT);
    IMAGE img;
    loadimage(&img, "../Photo/20.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    StudentshowButton(25, 15, 100, 50, "��һҳ", 20, fillColor, textColor);
    StudentshowButton(1145, 15, 100, 50, "���ز˵�", 20, fillColor, textColor);
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //�ж��Ƿ���
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