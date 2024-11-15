//
// Created by NWT on 2024/11/11.
//

#include "../include/UserView.h"
#include "../include/game.h"
#include "../include/CalculagraphModel.h"
#include <windows.h>
#define backGround "../resources/Photo/19.png"
#define Titel "Wecome icpac_Control"

WindowController::WindowController() {
    initgraph(1280, 720, SHOWCONSOLE);

    ControlPage();
    while(1) {
        switch(pageIndex){
            case 1:
                ControlPage(); break;
            case 2:
                ProductionGroupView(); break;
            case 3:
                gameQoQoView(); break;
        }
    }
}

WindowController::~WindowController() {
    // �ر�ͼ��ģʽ
    closegraph();
}

void WindowController::ControlPage() {
    IMAGE img;
    loadimage(&img, backGround, 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    setbkmode(TRANSPARENT); // ���ڽ����ɫ����ͼ
    settextcolor(WHITE);
    settextstyle(60, 0, _T("������κ"));//�����ֺš�����
    outtextxy(400, 100, _T(Titel));
    IMAGE imgs;
    loadimage(&imgs,"../resources/Photo/shujia.jpg", 70,70);

      int dsty = 250; int dstx = 250;
    for(int i = 0; i < 6; i++,dstx += 150) putimage(dstx,dsty,&imgs);
//    for(int j = 0 ; j < 4; j++, dsty += 100) {
//        dstx = 250;
//        for(int i = 0; i < 6; i++,dstx += 150) putimage(dstx,dsty,&imgs);
//    }

    ExMessage msgs;
    while (true) {
        Sleep(200);
        while (peekmessage(&msgs, EM_MOUSE))
        {
            //�ж��Ƿ���
            if (msgs.message == WM_LBUTTONDOWN && msgs.x > 250 && msgs.y > 250 && msgs.x < 250 + 70 && msgs.y < 250 + 70)
            {
                pageIndex = 2;
                return ;
            }
            if (msgs.message == WM_LBUTTONDOWN && msgs.x > 400 && msgs.y > 250 && msgs.x < 400 + 70 && msgs.y < 250 + 70)
            {
                pageIndex = 3;
                return ;
            }
        }
    }
}

void WindowController::ProductionGroupView() {
    const std::string kText = "��������Ϣ"; // ��Ҫ������ʾ���ı�����
    const std::string kTextArr[9] = { "��������12��","�鳤�����ȫ","��Ա��Ф˴��","��Ա��������",
                                 "��Ա������" };
    ExMessage m;

    int y = 720;
    IMAGE img;
    loadimage(&img, "../resources/Photo/19.png", 1280, 720, true);//����ͼƬ

    while (true) { // ѭ�����Ź����ı�
        Sleep(5);
        BeginBatchDraw();
        cleardevice(); // �����Ļ
        putimage(0, 0, &img);

        settextstyle(48, 0, "�����п�"); // ����������ʽ�ʹ�С
        settextcolor(RGB(238,238,9)); // �����ı���ɫ
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
                pageIndex = 1;
                break;
            }
        }
    }
    EndBatchDraw();
}

void WindowController::gameQoQoView() {
    gameqoqo::menuView();
    pageIndex = 1;
    return ;
}




