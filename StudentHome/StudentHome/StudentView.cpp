#include "StudentView.h"
#include "Student.h"


//ѧ��������ͼ
void LoginView() {
    // ��ʼ��ͼ��ģʽ
    initgraph(680, 480);
    IMAGE img;/*����һ��IMAGE����*/
    loadimage(&img, "../../../Photo/18.png",680,480);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
    putimage(0, 0, &img);/*չʾͼƬ*/
    /*cleardevice();*/
    //setbkcolor(RED);
    //cleardevice();

    // �����ı���ʽ
    settextstyle(30, 0, _T("����"));
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
    //Login();
    
    // �ȴ��û�����
   /* _getch();*/
    while (true);
    // �ر�ͼ��ģʽ
    closegraph();
    return ;


}