#include "AdminView.h"
#include "Student.h"


void StudentInfoDisplay()
{
	setbkmode(TRANSPARENT);
	IMAGE img;
	loadimage(&img, "../Photo/19.png", 1280, 720);/*变量地址，图片地址    相对地址“./”本目录下的文件进行访问   图片展示可以是png也可以是jpg*/
	putimage(0, 0, &img);/*展示图片*/
	/*for (int i = 0; i < ReturnStudent().size(); i++) {*/
		outtextxy(250, 250, ReturnStudent()[0].ID.c_str());
	//}
		while(1);
}
