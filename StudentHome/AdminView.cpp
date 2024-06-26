#include "AdminView.h"
#include "StudentView.h"
#define fillColor { 92, 235, 89 }
#define textColor { 255,255,255 }
#define IDX 220
#define NAMEX 358
#define CLASSX 570
#define GREADX 820

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
    StudentshowButton(1145, 15, 100, 50, "��һҳ", 20, fillColor, textColor);  //Header
    settextcolor(BLACK);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(IDX - 20, 120, _T("ѧ��"));
    outtextxy(NAMEX - 10, 120, _T("����"));
    outtextxy(CLASSX - 10, 120, _T("�༶"));
    outtextxy(GREADX - 10, 120, _T("�ɼ�"));
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
            //�ж��Ƿ���
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

void StudentInfoDisplay1()/*����*/
{
    setbkmode(TRANSPARENT);
    IMAGE img;
    loadimage(&img, "../Photo/20.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    StudentshowButton(25, 15, 100, 50, "��һҳ", 20, fillColor, textColor);
    StudentshowButton(1145, 15, 100, 50, "���ز˵�", 20, fillColor, textColor);
    settextcolor(BLACK);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(IDX - 20, 120, _T("ѧ��"));
    outtextxy(NAMEX - 10, 120, _T("����"));
    outtextxy(CLASSX - 10, 120, _T("�༶"));
    outtextxy(GREADX - 10, 120, _T("�ɼ�"));
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
            //�ж��Ƿ���
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


// ���ڶ�ȡ�ض�����������Ϣ(��ɫ)
namespace gx
{
    const int BUTTONX = 550;
    const int BUTTONY = 200;
    const int BUTTONW = 200;
    const int BUTTONH = 100;

    Color FillColor = { 92, 235, 89 }; // ������ɫ
    Color TextColor = { 255,255,255 }; // �ı���ɫ

    //������Ϣ�ṹ�����
    ExMessage mg;
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
EasyTextBox TxtName;
EasyTextBox TxtPwd;
EasyTextBox TxtID;
EasyButton BtnOK;
EasyButton BtnOUT;

//����ѧ��ע��ҳ��ؼ�



//-----------------����ҳ�����----------------


/*
    �����ˣ�
    ���ܣ������û�����
    ������void
    ����ֵ��void
*/

void AdminEasyTextBoxShow(EasyTextBox* NEW) {
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

EasyTextBox AdminEasyTextBoxCreate(int x1, int y1, int x2, int y2, int maxn) {   // ���е�x1, y1, x2, y2
    EasyTextBox NEW = { x1 , y1, x2, y2,NULL,maxn }; // ��ʼ�������Լ����ֵ
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
bool AdminEasyTextBoxCheck(EasyTextBox* NEW, int x, int y) {
    return (NEW->right >= x && NEW->left <= x && NEW->top <= y && NEW->bottom >= y);
}

/*
    �����ˣ�
    ���ܣ�ɾ��Ԫ������
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void AdminEasyTextBoxDelete(EasyTextBox* NEW) {
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
void AdminEasyButtonShow(EasyButton* NEW)
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
EasyButton AdminEasyButtonCreate(int x1, int y1, int x2, int y2, const char* title, void (*func)())
{
    EasyButton NEW = { x1,y1,x2,y2,NULL,NULL };
    NEW.text = new char[strlen(title) + 1];
    strcpy_s(NEW.text, strlen(title) + 1, title);
    NEW.left = x1, NEW.top = y1, NEW.right = x2, NEW.bottom = y2;
    NEW.userfunc = func;
    // ���ƹ���Ա����
    AdminEasyButtonShow(&NEW);
    return NEW;
}

/*
    �����ˣ�
    ���ܣ�ɾ��Ԫ������
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void AdminEasyButtonDelete(EasyButton* NEW)
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
bool AdminEasyButtonCheck(EasyButton* NEW, int x, int y)
{
    return (NEW->left <= x && x <= NEW->right && NEW->top <= y && y <= NEW->bottom);
}

/*
    �����ˣ�
    ���ܣ����÷��غ���
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void AdminEasyButtonOnMessage(EasyButton* NEW)
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
void AdminOn_btnOk_Click()
{
    User* user = ReturnUser();
    int Usernum = ReturnUserCount();
    for (int i = 0; i < Usernum; i++) {
        if (strcmp(user[i].power.c_str(), TxtPwd.text) || strcmp(user[i].name.c_str(), TxtName.text)) {
            if (i == Usernum - 1) MessageBox(GetHWnd(), "���������û���������", "����", MB_OK);
        }
        else // �������ɹ�
        {
            MessageBox(GetHWnd(), TxtName.text, "Hello ���Ĺ���Ա", MB_OK); // ��Ϣ����
            AdminView();
        }
    }
}

void AdminOn_Delete_Click()
{
    corrective(TxtID.text);
}

/*
    �����ˣ�
    ���ܣ�������¼� & ��궨λ
    ������EasyTextBox* NEW
    ����ֵ��bool
*/
void AdminEasyTextBoxOnMessage(EasyTextBox* NEW)
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
                case '\r':		AdminOn_btnOk_Click();		// �û����س����������ı�����
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
void AdminEasyPBoxOnMessage(EasyTextBox* NEW)
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
                case '\r':		AdminOn_btnOk_Click();		// �û����س����������ı�����
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
                            P += '*';
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

void AdminPage()
{
    // �򵥻��ƽ���
   //setbkcolor(0xeeeeee);
    cleardevice();  // ˳������������
    IMAGE img;/*����һ��IMAGE����*/
    loadimage(&img, "../Photo/II.jpg", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    settextcolor(WHITE);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(400, 200, "Admin Wecome to");
    settextstyle(40, 0, _T("������κ")); //�����ֺš�����
    outtextxy(280, 340, "�û�����");
    TxtName = AdminEasyTextBoxCreate(400, 330, 700, 375, 10);        // �����û����ı���ؼ�
    settextstyle(40, 0, _T("������κ"));//�����ֺš�����
    outtextxy(280, 400, "�ܡ��� ");
    TxtPwd = AdminEasyTextBoxCreate(400, 400, 700, 445, 10);
    settextstyle(15, 0, "");//�����ֺš�����
    settextcolor(BLACK);
    BtnOK = AdminEasyButtonCreate(620, 470, 700, 495, "Login", AdminOn_btnOk_Click);	// ������ť�ؼ�
    settextstyle(30, 0, "");//�����ֺš�����

    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);			// ��ȡ��Ϣ����

        if (msg.message == WM_LBUTTONDOWN)
        {
            // �жϿؼ�
            if (EasyTextBoxCheck(&TxtName, msg.x, msg.y))	AdminEasyTextBoxOnMessage(&TxtName);

            // �жϿؼ�
            if (EasyTextBoxCheck(&TxtPwd, msg.x, msg.y))		AdminEasyPBoxOnMessage(&TxtPwd);

            // �жϿؼ�
            if (EasyButtonCheck(&BtnOK, msg.x, msg.y))	AdminEasyButtonOnMessage(&BtnOK);
        }
    }
    return;
}

/*
    �����ˣ�
    ���ܣ��ܿع���Ա����ҳ��
    ������void
    ����ֵ��void
*/
void AdminView()
{
    using namespace gx;
    cleardevice();
    IMAGE img;
    loadimage(&img, "../Photo/IV.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/

    StudentshowButton(BUTTONX, 100, BUTTONW, BUTTONH, "ѧ����Ϣ", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 250, BUTTONW, BUTTONH, "��Ϣɾ��", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 400, BUTTONW, BUTTONH, "�ر�����", 48, fillColor, textColor);
    StudentshowButton(BUTTONX, 550, BUTTONW, BUTTONH, "�˳�����", 48, fillColor, textColor);
    while (true) {
        Sleep(200);
        while (peekmessage(&msg, EM_MOUSE))
        {
            //�ж��Ƿ���
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

//ѧ����Ϣɾ��ҳ��
void CorrectiveView() {
    using namespace gx;
    cleardevice();
    setbkcolor(0xeeeeee);
    IMAGE img;
    loadimage(&img, "../Photo/IV.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    settextstyle(40, 0, _T("������κ")); //�����ֺš�����
    settextcolor(RED);
    outtextxy(260, 335, "ѧ��ID��");
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    settextcolor(BLACK);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(400, 200, "Admin to Delete Student");


    TxtID = AdminEasyTextBoxCreate(400, 330, 700, 375, 10);        // �����û����ı���ؼ�

    settextcolor(BLACK);
    settextstyle(15, 0, "");//�����ֺš�����
    BtnOK = AdminEasyButtonCreate(620, 470, 700, 495, "Delete", AdminOn_Delete_Click);	// ������ť�ؼ�
    BtnOUT = AdminEasyButtonCreate(420, 470, 500, 495, "OUT", AdminView);	// ������ť�ؼ�
    settextstyle(30, 0, "");//�����ֺš�����

    ExMessage msg;
    while (true)
    {
        msg = getmessage(EX_MOUSE);			// ��ȡ��Ϣ����

        if (msg.message == WM_LBUTTONDOWN)
        {
            // �жϿؼ�
            if (EasyTextBoxCheck(&TxtID, msg.x, msg.y))	AdminEasyTextBoxOnMessage(&TxtID);

            // �жϿؼ�
            if (EasyButtonCheck(&BtnOK, msg.x, msg.y))	AdminEasyButtonOnMessage(&BtnOK);

            //�жϿؼ�
            if (EasyButtonCheck(&BtnOUT, msg.x, msg.y))	AdminEasyButtonOnMessage(&BtnOUT);

        }
    }
}