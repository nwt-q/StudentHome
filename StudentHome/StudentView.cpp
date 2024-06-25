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
#include "Star.h"
#include "AdminView.h"

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

// ����ѧ������ҳ��ؼ�
EasyTextBox txtName;
EasyTextBox txtPwd;
EasyButton btnOK;

//����ѧ��ע��ҳ��ؼ�



//-----------------����ҳ�����----------------


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


//----------------ʵ�ְ����ؼ�EasyButton-------------
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


/*
    �����ˣ�
    ���ܣ�ȷ���Ƿ����ɹ�,��ť btnOK �ĵ���¼�
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void On_btnOk_Click()
{
    User* user = ReturnUser();
    int Usernum = ReturnUserCount();
    for (int i = 0; i < Usernum; i++) {
        if (strcmp(user[i].power.c_str(), txtPwd.text) || strcmp(user[i].name.c_str(), txtName.text)) {
           if(i == Usernum - 1) MessageBox(GetHWnd(), "���������û���������", "����", MB_OK);
        }    
        else // �������ɹ�
        {
            MessageBox(GetHWnd(), txtName.text, "Hello", MB_OK); // ��Ϣ����
            StudentmenuView();
        }
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
                        clearrectangle(NEW->left + 10 + width, NEW->top + 1, NEW->right - 1, NEW->bottom - 1); //�����������
                    }
                    break;
                case '\r':		On_btnOk_Click();		// �û����س����������ı�����
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

/*
    �����ˣ�
    ���ܣ������ı�����ı�����м���
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void EasyPBoxOnMessage(EasyTextBox* NEW)
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
                        clearrectangle(NEW->left + 10 + width, NEW->top + 1, NEW->right - 1, NEW->bottom - 1); //�����������
                    }
                    break;
                case '\r':		On_btnOk_Click();		// �û����س����������ı�����
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
                        //��������м���
                        std::string P = "";
                        for (int i = 0; i < width / 15; i++) {
                            P +='*';
                        }

                        outtextxy(NEW->left + 10, NEW->top + 5, P.c_str());		// ����µ��ַ���
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

//-----------------����ҳ�����----------------

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
    loadimage(&img, "../Photo/II.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    settextcolor(WHITE);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(400, 200, "ѧ��Todo");
    settextstyle(40, 0, _T("������κ")); //�����ֺš�����
    outtextxy(280, 340, "�û�����");
    txtName = EasyTextBoxCreate(400, 330, 700, 375, 10);        // �����û����ı���ؼ�
    settextstyle(40, 0, _T("������κ"));//�����ֺš�����
    outtextxy(280, 400, "�ܡ��� ");
    txtPwd = EasyTextBoxCreate(400, 400, 700, 445, 10);	
    settextstyle(15, 0,"");//�����ֺš�����
    settextcolor(BLACK);
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
            if (EasyTextBoxCheck(&txtPwd,msg.x, msg.y))		EasyPBoxOnMessage(&txtPwd);

            // �жϿؼ�
            if (EasyButtonCheck(&btnOK,msg.x, msg.y))	EasyButtonOnMessage(&btnOK);
        }
    }
    return;
}

//---------------------------------------


//----------------ע��ҳ������---------------------

/*
    �����ˣ�
    ���ܣ�����չʾѧ��ע��ҳ��
    ������void
    ����ֵ��void
*/
void StudentSendView()
{

    IMAGE img;
    loadimage(&img, "../Photo/19.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    settextcolor(BLACK);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(400, 200, "ע��Todo");
    settextcolor(BLACK);
    settextstyle(40, 0, _T("������κ"));//�����ֺš�����
    outtextxy(280, 340, "�û�����");
    txtName = EasyTextBoxCreate(400, 330, 700, 375, 10);        // �����û����ı���ؼ�
    settextstyle(40, 0, _T("������κ"));//�����ֺš�����
    outtextxy(280, 400, "�ܡ��룺");
    txtPwd = EasyTextBoxCreate(400, 400, 700, 445, 10);
    settextstyle(15, 0, "");//�����ֺš�����
    btnOK = EasyButtonCreate(620, 470, 700, 495, "ע��", On_btnOk_Click);	// ������ť�ؼ�
    settextstyle(30, 0, "");//�����ֺš�����

    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);			// ��ȡ��Ϣ����

        if (msg.message == WM_LBUTTONDOWN)
        {
            // �жϿؼ�
            if (EasyTextBoxCheck(&txtName, msg.x, msg.y))	EasyTextBoxOnMessage(&txtName);

            // �жϿؼ�
            if (EasyTextBoxCheck(&txtPwd, msg.x, msg.y))		EasyTextBoxOnMessage(&txtPwd);

            // �жϿؼ�
            if (EasyButtonCheck(&btnOK, msg.x, msg.y))	EasyButtonOnMessage(&btnOK);
        }
    }

}


//------------------------------------------------
/*
    �����ˣ�
    ���ܣ����õ����Button
    ������void
    ����ֵ��void
*/
void StudentshowButton(int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor)			//Ĭ�Ϻڵף�����
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
    ���ܣ���Ϸѡ��
    ������void
    ����ֵ��void
*/
void GameSelect() {
    using namespace gxb;
    cleardevice();
    IMAGE img;
    loadimage(&img, "../Photo/V.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/


    StudentshowButton(BUTTONX, 100, BUTTONW, BUTTONH, "��ϷI", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "��ϷII", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 400, BUTTONW, BUTTONH, "��ϷIII", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "��ϷIV", 48, fillColor, textColor);

    /*����ҳ����ת*/
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //�ж��Ƿ���
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 100, BUTTONW, BUTTONH))
            {
                game();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 250, BUTTONW, BUTTONH))
            {
                game();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 400, BUTTONW, BUTTONH))
            {
                game();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 550, BUTTONW, BUTTONH))
            {
                game();
            }
        }
    }
}

// ������Ϣ�˵�
void PersonalInformation() {
    using namespace gxb;
    cleardevice();

    IMAGE img;
    loadimage(&img, "../Photo/VII.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    IMAGE duanxin;
    loadimage(&duanxin, "../Photo/duanxin.jpg", 100, 100);
    putimage(10, 610, &duanxin);
    IMAGE haoyou;
    loadimage(&haoyou, "../Photo/haoyou.jpg", 100, 100);
    putimage(120, 610, &haoyou);
    IMAGE zhinan;
    loadimage(&zhinan, "../Photo/zhinan.jpg", 100, 100);
    putimage(230, 610, &zhinan);
    IMAGE shujia;
    loadimage(&shujia, "../Photo/shujia.jpg", 100, 100);
    putimage(340, 610, &shujia);
    IMAGE touxiang;
    loadimage(&touxiang, "../Photo/touxiang.jpg", 130, 130);
    putimage(10, 10, &touxiang);

    StudentshowButton(1110, 10, 160, 80, "����", 48, { 1,1,1 }, { 255,255,255 });
    StudentshowButton(150, 60, 100, 20, txtName.text, 48, { 1,1,1 }, { 255,255,255 });
    StudentshowButton(150, 110, 200, 20, "ѧϰ������114514", 28, { 1,1,1 }, { 255,255,255 });




    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //�ж��Ƿ���
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 1110, 10, 160, 80))
            {
                StudentmenuView();
            }

        }
    }
}

/*
    �����ˣ�
    ���ܣ�ѧ��ҳ������ҳ���л�
    ������void
    ����ֵ��void
*/
void StudentmenuView() {
    using namespace gxb;
    cleardevice();
    IMAGE img;
    loadimage(&img, "../Photo/III.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/

    IMAGE touxiang;
    loadimage(&touxiang, "../Photo/touxiang.jpg", 130, 130);
    putimage(10, 10, &touxiang);

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
                GameSelect();
                StudentmenuView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 400, BUTTONW, BUTTONH))
            {
                StudentSettingView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 550, BUTTONW, BUTTONH))
            {
                LoginView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 10, 10, 200, 100))
            {
                
                PersonalInformation();
            }
        }
    }
}


void ProductionGroupView()
{
    const string kText = "��������Ϣ"; // ��Ҫ������ʾ���ı�����
    const string kTextArr[9] = { "��������12��","�鳤�����ȫ","��Ա��Ф˴��","��Ա��������",
                            "��Ա������" };
    ExMessage m;

    int y = 720;
    IMAGE img;
    loadimage(&img, "../Photo/19.png", 1280, 720, true);//����ͼƬ
    Color fillColor1 = { 135, 206, 250 };
    Color textColor1 = { 0,0,0 };
    Color textColor2 = { 238,238,9 };
    while (true) { // ѭ�����Ź����ı�
        Sleep(5);
        BeginBatchDraw();
        cleardevice(); // �����Ļ
        putimage(0, 0, &img);
        StudentshowButton(1080, 670, 200, 50, "�����Ļ����", 30, fillColor1, textColor1);
        settextstyle(48, 0, "�����п�"); // ����������ʽ�ʹ�С
        settextcolor(RGB(textColor2.R, textColor2.G, textColor2.B)); // �����ı���ɫ
        setbkmode(TRANSPARENT);

        for (int i = 0; i < 9; i++)
        {
            int w = (1280 - textwidth(kTextArr[i].c_str())) / 2;
            outtextxy(w, i * 100 + y, kTextArr[i].c_str()); // ��ָ��λ������ı�
        }

        // ��ʾ�����ı�
        y -= 2; // ÿ�������ƶ� 1 ������

        if (y < -700) { // ����ı��ƶ�����Ļ�������¿�ʼ����
            y = 720;
        }

        // �ȴ�һ��ʱ�䣬�Կ��ƹ����ٶ�
        FlushBatchDraw();
        if (peekmessage(&m, EM_MOUSE)) {
            if (m.message == WM_LBUTTONDOWN) {
                cleardevice();
                EndBatchDraw();
                break;
            }
        }
    }
    EndBatchDraw();
    StudentSettingView();
}



//ѧ������ҳ��
void StudentSettingView() {
    using namespace gxb;
    cleardevice();
    IMAGE img;
    loadimage(&img, "../Photo/IV.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/

    StudentshowButton(BUTTONX, 100, BUTTONW, BUTTONH, "������Ա", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "������", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 400, BUTTONW, BUTTONH, "�ر�����", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "���ز˵�", 48, fillColor, textColor);
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //�ж��Ƿ���
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 100, BUTTONW, BUTTONH))
            {
                ProductionGroupView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 250, BUTTONW, BUTTONH))
            {
                OpenMusic();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 400, BUTTONW, BUTTONH))
            {
                CloseMusic();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 550, BUTTONW, BUTTONH))
            {
                StudentmenuView();
            }
        }
    }
}

void StopView() {
    using namespace gxb;
    IMAGE img;
    loadimage(&img, "../Photo/I.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/

    StudentshowButton(350, 500, 200, 100, "���ز˵�", 48, { 92,235,89 }, { 255,255,255 });
    StudentshowButton(750, 500, 200, 100, "��Ϸ�ռ�", 48, { 92,235,89 }, { 255,255,255 });
    settextstyle(40, 0, _T("������κ"));//�����ֺš�����
    FlushBatchDraw();   // ������Ļ��ʾ
    TimePrint();
    outtextxy(550, 150, "���Ѿ���ϰ��") ;
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 350, 500, 200, 100))
            {
                StudentmenuView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 750, 500, 200, 100))
            {
                game();
            }
        }
    }
}


void StudentPage()
{
    using namespace gxb;
    IMAGE img;
    loadimage(&img, "../Photo/I.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    settextcolor(WHITE);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(400, 100, "Wecome ѧ��Todo");
    StudentshowButton(350, 500, 200, 100, "ѧ������", 48, { 92,235,89 }, { 255,255,255 });
    StudentshowButton(750, 500, 200, 100, "ѧ��ע��", 48, { 92,235,89 }, { 255,255,255 });
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 350, 500, 200, 100))
            {
                LoginView();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 750, 500, 200, 100))
            {
                StudentSendView();
            }
        }
    }
}

// Ӧ�õ�һҳ
void FistPage()
{
    using namespace gxb;
    IMAGE img;
    loadimage(&img, "../Photo/I.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    settextcolor(WHITE);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(400, 100, "Wecome ѧ��Todo");
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "ѧ������", 48, { 92,235,89 }, { 255,255,255 });
    StudentshowButton(BUTTONX - 50, 450, BUTTONW + 100, BUTTONH, "����Ա����", 48, { 92,235,89 }, { 255,255,255 });
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 250, BUTTONW, BUTTONH))
            {
                StudentPage();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX - 50, 450, BUTTONW + 100, BUTTONH))
            {
                AdminPage();
            }
        }
    }
}

void TimeViewFPS(IMAGE &img) {
    BeginBatchDraw();
    putimage(0, 0, &img);/*չʾͼƬ*/

    TimePrint();
    setbkmode(TRANSPARENT);
    settextstyle(48, 0, _T("�����п�"));
    settextcolor(RGB(255,255,255));
    outtextxy(580, 120, "��ϰ��");

    StudentshowButton(250, 500, 200, 100, "��ͣ", 48, { 92,235,89 }, { 255,255,255 });
    StudentshowButton(550, 500, 200, 100, "��ʼ", 48, { 92,235,89 }, { 255,255,255 });
    StudentshowButton(850, 500, 200, 100, "����", 48, { 92,235,89 }, { 255,255,255 });
    EndBatchDraw();
}

// ѧ����ʱרעҳ��
void TimeView() {
    using namespace gxb;
    IMAGE img;
    cleardevice();
    loadimage(&img, "../Photo/I.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    Timeinit();
    TimePrint();
    Start(); // ����㿪ʼ��ϰ
    setbkmode(TRANSPARENT);
    settextstyle(48, 0, _T("�����п�"));
    settextcolor(RGB(255, 255, 255));
    outtextxy(580, 120, "��ϰ��");
    StudentshowButton(250, 500, 200, 100, "��ͣ", 48, { 92,235,89 }, { 255,255,255 });
    StudentshowButton(550, 500, 200, 100, "��ʼ", 48, { 92,235,89 }, { 255,255,255 });
    StudentshowButton(850, 500, 200, 100, "����", 48, { 92,235,89 }, { 255,255,255 });
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 550, 500, 200, 100))
            {
                Start();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 250, 500, 200, 100))
            {
                Pause();
            }
            if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 850, 500, 200, 100))
            {
                Stop();
                StopView();
            }
        }
        // ˫����ˢ��
        TimeViewFPS(img);
    }
}

