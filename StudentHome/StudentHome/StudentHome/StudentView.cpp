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

std::string inputUser = "";  // �洢�����ı��ı���

// ���ڶ�ȡ�ض�����������Ϣ(��ɫ)
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

//-----------------����ҳ�����----------------

/*
    �����ˣ�
    ���ܣ�����ı���ؼ�
*/
struct EasyTextBox 
{
    int left = 0, top = 0, right = 0, bottom = 0; // �ؼ�����
    char* text = NULL;                         // �ؼ�����
    unsigned __int64 maxlen = 0;                 // �ı���������ݳ���
};

/*
    �����ˣ�
    ���ܣ������û�����
    ������void
    ����ֵ��void
*/

void EasyTextBoxShow(EasyTextBox* NEW) {
    // ���ݻ���ֵ
    int oldlinecolor = getlinecolor();
    int oldbkcolor = getbkcolor();
    int oldfillcolor = getfillcolor();

    setlinecolor(LIGHTGRAY);		// ���û�����ɫ
    setbkcolor(0xeeeeee);			// ���ñ�����ɫ
    setfillcolor(0xeeeeee);			// ���������ɫ
    fillrectangle(NEW->left, NEW->top, NEW->right, NEW->bottom);  // ���ƾ��� 
    outtextxy(NEW->left + 10, NEW->top + 5, _T(NEW->text)); // ��ʾ�ı�

    // �ָ�����ֵ
    setlinecolor(oldlinecolor);
    setbkcolor(oldbkcolor);
    setfillcolor(oldfillcolor);
}


/*
    �����ˣ�
    ���ܣ����ڳ�ʼ������
    ������x1,y1,x2,y2, maxn
    ����ֵ��void
*/

EasyTextBox EasyTextBoxCreate(int x1, int y1, int x2, int y2, int maxn) {   // ���е�x1, y1, x2, y2
    EasyTextBox NEW = { x1 , y1, x2, y2,NULL,maxn}; // ��ʼ�������Լ����ֵ
    NEW.text = new char[NEW.maxlen];  // ����һ����󳤶�����, ��������ʱ���ܳ�������
    NEW.text[0] = 0; // ���ı������� 0
    // �����û�����
    EasyTextBoxShow(&NEW);
    return NEW;
}

/*
    �����ˣ�
    ���ܣ�����Ƿ�Խ�糬��������볤��
    ������EasyTextBox* NEW, int x, int y
    ����ֵ��bool
*/
bool EasyTextBoxCheck(EasyTextBox* NEW, int x, int y) {
    return (NEW->right >= x && NEW->left <= x && NEW->top <= y && NEW->bottom >= y);
}

/*
    �����ˣ�
    ���ܣ�ɾ��Ԫ������
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void EasyTextBoxDelete(EasyTextBox* NEW) {
    if (NEW->text != NULL) {
        delete[] NEW->text;
    }
}

/*
    �����ˣ�
    ���ܣ�������¼� & ��궨λ
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void EasyTextBoxOnMessage(EasyTextBox* NEW)
{
    // ���ݻ���ֵ
    int oldlinecolor = getlinecolor();
    int oldbkcolor = getbkcolor();
    int oldfillcolor = getfillcolor();

    setlinecolor(BLACK);			// ���û�����ɫ
    setbkcolor(WHITE);				// ���ñ�����ɫ
    setfillcolor(WHITE);			// ���������ɫ
    fillrectangle(NEW->left, NEW->top, NEW->right, NEW->bottom);
    outtextxy(NEW->left + 20, NEW->top + 15, NEW->text);

    int width = textwidth(NEW->text);	// �ַ����ܿ��
    int counter = 0;				// �����˸������
    bool binput = true;				// �Ƿ�������

    ExMessage msg; // ���������¼�
    while (binput)
    {
        while (binput && peekmessage(&msg, EX_MOUSE | EX_CHAR, false))	// ��ȡ��Ϣ����������Ϣ�����ó�
        {
            if (msg.message == WM_LBUTTONDOWN)
            {
                // ���������ı������棬�����ı�����
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
                case '\b':				// �û����˸����ɾ��һ���ַ�
                    if (len > 0)
                    {
                        NEW->text[len - 1] = 0;
                        width = textwidth(NEW->text);
                        counter = 0;
                        clearrectangle(NEW->left + 10 + width, NEW->top + 1, NEW->right - 1, NEW->bottom - 1);
                    }
                    break;
                case '\r':				// �û����س����������ı�����
                case '\n':
                    binput = false;
                    break;
                default:				// �û����������������ı�����
                    if (len < NEW->maxlen - 1)
                    {
                        NEW->text[len++] = msg.ch;
                        NEW->text[len] = 0;

                        clearrectangle(NEW->left + 10 + width + 1, NEW->top + 3, NEW->left + 10 + width + 1, NEW->bottom - 3);	// ������Ĺ��
                        width = textwidth(NEW->text);				// ���¼����ı�����
                        counter = 0;
                        outtextxy(NEW->left + 10, NEW->top + 5, NEW->text);		// ����µ��ַ���
                    }
                }
            }
            peekmessage(NULL, EX_MOUSE | EX_CHAR);				// ����Ϣ���������ոմ������һ����Ϣ
        }

        // ���ƹ�꣨�����˸����Ϊ 20ms * 32��
        counter = (counter + 1) % 32;
        if (counter < 16)
            line(NEW->left + 10 + width + 1, NEW->top + 3, NEW->left + 10 + width + 1, NEW->bottom - 3);				// �����
        else
            clearrectangle(NEW->left + 10 + width + 1, NEW->top + 3, NEW->left + 10 + width + 1, NEW->bottom - 3);		// �����

        // ��ʱ 20ms
        Sleep(20);
    }
}

//----------------ʵ�ְ����ؼ�EasyButton-------------
struct EasyButton {
    int left = 0, top = 0, right = 0, bottom = 0;	// �ؼ�����
    char* text = NULL;							// �ؼ�����
    void (*userfunc)() = NULL;						// �ؼ���Ϣ
};

/*
    �����ˣ�
    ���ܣ����ƽ���
    ������EasyButton* NEW
    ����ֵ��void
*/
void EasyButtonShow(EasyButton* NEW)
{
    // ���ݻ���
    int oldlinecolor = getlinecolor();
    int oldbkcolor = getbkcolor();
    int oldfillcolor = getfillcolor();

    setlinecolor(BLACK);			// ���û�����ɫ
    setbkcolor(WHITE);				// ���ñ�����ɫ
    setfillcolor(WHITE);			// ���������ɫ
    fillrectangle(NEW->left, NEW->top, NEW->right, NEW->bottom);
    outtextxy(NEW->left + (NEW->right - NEW->left - textwidth(NEW->text) + 1) / 2, NEW->top + (NEW->bottom - NEW->top - textheight(NEW->text) + 1) / 2, NEW->text);
    //�ָ�����
    setlinecolor(oldlinecolor);
    setbkcolor(oldbkcolor);
    setfillcolor(oldfillcolor);
}

/*
    �����ˣ�
    ���ܣ����ڳ�ʼ������
    ������x1,y1,x2,y2, title  (*func)()
    ����ֵ��void
*/
EasyButton EasyButtonCreate(int x1, int y1, int x2, int y2, const char* title, void (*func)())
{
    EasyButton NEW = {x1,y1,x2,y2,NULL,NULL};
    NEW.text = new char[strlen(title) + 1];
    strcpy_s(NEW.text, strlen(title) + 1, title);
    NEW.left = x1, NEW.top = y1, NEW.right = x2, NEW.bottom = y2;
    NEW.userfunc = func;
    // �����û�����
    EasyButtonShow(&NEW);
    return NEW;
}

/*
    �����ˣ�
    ���ܣ�ɾ��Ԫ������
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void EasyButtonDelete(EasyButton* NEW)
{
    if (NEW->text != NULL)
        delete[] NEW->text;
}

/*
    �����ˣ�
    ���ܣ��鿴�Ƿ���������
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
bool EasyButtonCheck(EasyButton* NEW ,int x, int y)
{
    return (NEW->left <= x && x <= NEW->right && NEW->top <= y && y <= NEW->bottom);
}

/*
    �����ˣ�
    ���ܣ����÷��غ���
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void EasyButtonOnMessage(EasyButton* NEW)
{
    if (NEW->userfunc != NULL)
        NEW->userfunc();
}

// ����ؼ�
EasyTextBox txtName;
EasyTextBox txtPwd;
EasyButton btnOK;
int Page = 1;

/*
    �����ˣ�
    ���ܣ�ȷ���Ƿ����ɹ�,��ť btnOK �ĵ���¼�
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void On_btnOk_Click()
{
    if (strcmp("123456", txtPwd.text))
        MessageBox(GetHWnd(), "�������", "����", MB_OK);
    else // �������ɹ�
    {
        MessageBox(GetHWnd(),txtName.text, "Hello", MB_OK); // ��Ϣ����
        StudentmenuView();
    }
}
// ------------------------------------------------

/*
    �����ˣ�
    ���ܣ�ѧ��������ͼ,���Ƶ�¼����
    ������void
    ����ֵ��void
*/
void LoginView() {

    // �򵥻��ƽ���
    //setbkcolor(0xeeeeee);
    cleardevice();  // ˳������������
    IMAGE img;/*����һ��IMAGE����*/
    loadimage(&img, "../../../Photo/18.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    settextcolor(BLACK);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(400, 200, "6��26�տ�����Ŀ");
    settextstyle(40, 0, _T("������κ"));//�����ֺš�����
    outtextxy(280, 340, "�û�����");
    txtName = EasyTextBoxCreate(400, 330, 700, 375, 10);        // �����û����ı���ؼ�
    settextstyle(40, 0, _T("������κ"));//�����ֺš�����
    outtextxy(280, 400, "�ܡ��룺");
    txtPwd = EasyTextBoxCreate(400, 400, 700, 445, 10);						// ���������ı���ؼ�
    settextstyle(15, 0,"");//�����ֺš�����
    btnOK = EasyButtonCreate(620, 470, 700, 495, "Login", On_btnOk_Click);	// ������ť�ؼ�
    settextstyle(30, 0, "");//�����ֺš�����

    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);			// ��ȡ��Ϣ����

        if (msg.message == WM_LBUTTONDOWN)
        {
            // �жϿؼ�
            if (EasyTextBoxCheck(&txtName,msg.x, msg.y))	EasyTextBoxOnMessage(&txtName);

            // �жϿؼ�
            if (EasyTextBoxCheck(&txtPwd,msg.x, msg.y))		EasyTextBoxOnMessage(&txtPwd);

            // �жϿؼ�
            if (EasyButtonCheck(&btnOK,msg.x, msg.y))	EasyButtonOnMessage(&btnOK);
        }
    }
    return;
}

//-----------------����ҳ�����----------------

/*
    �����ˣ�
    ���ܣ����õ����Button
    ������void
    ����ֵ��void
*/
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

/*
    �����ˣ�
    ���ܣ�ѧ��ҳ������ҳ���л�
    ������void
    ����ֵ��void
*/


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
    /*����ҳ����ת*/
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
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "���ز˵�", 48, fillColor, textColor);
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
                Page = 0;
                StudentmenuView();
            }
        }
    }
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

