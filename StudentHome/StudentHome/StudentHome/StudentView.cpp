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

    Color fillColor = { 92, 235, 89 }; // ������ɫ
    Color textColor = { 255,255,255 }; // �ı���ɫ

    //������Ϣ�ṹ�����
    ExMessage msg;
    //����Ƿ��ھ����� 
    bool inArea(int mx, int my, int x, int y, int w, int h) //���ڲ���������¼�
    {
        if (mx > x && my > y && mx < x + w && my < y + h)
        {
            return true;
        }
        return false;
    }
}

//ѧ��������ͼ
void LoginView() {
    // ��ʼ��ͼ��ģʽ
    initgraph(1280, 720);
    IMAGE img;/*����һ��IMAGE����*/
    loadimage(&img, "../../../Photo/18.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    // �����ı���ʽ
    setbkmode(TRANSPARENT);  // ���ڽ����ɫ����ͼ
    settextstyle(30, 0, _T("����")); // TRANSPARENT
    settextcolor(BLACK);
    outtextxy(240, 100, _T("ѧ����¼"));
    settextstyle(20, 0, _T("����"));

    // ���������
    rectangle(320, 190, 580, 220);
    rectangle(320, 250, 580, 280);

    // �����û������������
    char username[20] = "";
    char password[20] = "";

    // �����û���
    settextstyle(20, 0, _T("����"));
    outtextxy(180, 200, _T("�û�����"));
    // ��������
    settextstyle(20, 0, _T("����"));
    outtextxy(180, 260, _T("���룺"));
    //  ѧ������ģ��
    char s[10];
    while (true);
    // �ر�ͼ��ģʽ
    closegraph();
    return;

}

void StudentshowButton(int x, int y, int width, int height, std::string str, int textSize,Color fillColor, Color textColor)			//Ĭ�Ϻڵף�����
{
    setfillcolor(RGB(fillColor.R, fillColor.G, fillColor.B));
    fillroundrect(x, y, x + width, y + height, width / 10, width / 10);
    setbkmode(TRANSPARENT);
    settextstyle(textSize, 0, _T("�����п�"));
    int w = (width - textwidth(str.c_str())) / 2;
    int h = (height - textheight(str.c_str())) / 2;
    settextcolor(RGB(textColor.R, textColor.G, textColor.B));
    outtextxy(x + w, y + h, str.c_str());
}

//ѧ��ҳ������ҳ���л�
void StudentmenuView() {
    using namespace gxb;
    //initgraph(1280, 720);
    cleardevice();
    IMAGE img;
    loadimage(&img, "../../../Photo/19.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/

    StudentshowButton(BUTTONX, 100, BUTTONW, BUTTONH, "��ʼ��ϰ", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "��Ϸ�ռ�", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 400, BUTTONW, BUTTONH, "ȫ������", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "�˳�����", 48, fillColor, textColor);

    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //�ж��Ƿ���
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
    // �ر�ͼ��ģʽ
    closegraph();
}


//ѧ������ҳ��
void StudentSettingView() {
    using namespace gxb;
    cleardevice();
    IMAGE img;
    loadimage(&img, "../../../Photo/18.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/

    StudentshowButton(BUTTONX, 100, BUTTONW, BUTTONH, "������Ա", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "��������", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 400, BUTTONW, BUTTONH, "������", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "�˳�", 48, fillColor, textColor);
}

// ѧ����ʱרעҳ��
void TimeView() {
    cleardevice();
    IMAGE img;
    loadimage(&img, "../../../Photo/19.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    StudentshowButton(550, 100, 200, 100, "��ϰ��", 48, {92,235,89}, {255,255,255});
    timer();
}