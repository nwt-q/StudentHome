#include "AdminView.h"
#include "Student.h"


void StudentInfoDisplay()
{
	setbkmode(TRANSPARENT);
	IMAGE img;
	loadimage(&img, "../Photo/19.png", 1280, 720);/*������ַ��ͼƬ��ַ    ��Ե�ַ��./����Ŀ¼�µ��ļ����з���   ͼƬչʾ������pngҲ������jpg*/
	putimage(0, 0, &img);/*չʾͼƬ*/
	/*for (int i = 0; i < ReturnStudent().size(); i++) {*/
		outtextxy(250, 250, ReturnStudent()[0].ID.c_str());
	//}
		while(1);
}
