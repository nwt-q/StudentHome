//
// Created by NWT on 2024/11/10.
//

#include "../include/EasyButton.h"

EasyxxButton::EasyxxButton(int x, int y, int width, int height, std::string str, int textSize, Color fillColor,
                       Color textColor) {
    setfillcolor(RGB(fillColor.R, fillColor.G, fillColor.B));
    fillroundrect(x, y, x + width, y + height, width / 10, width / 10);
    setbkmode(TRANSPARENT);
    settextstyle(textSize, 0, _T("华文行楷"));
    int w = (width - textwidth(str.c_str())) / 2;
    int h = (height - textheight(str.c_str())) / 2;
    settextcolor(RGB(textColor.R, textColor.G, textColor.B));
    outtextxy(x + w, y + h, str.c_str());
}

void EasyxxButton::EasyButtonShow()
{
    // 备份环境
    int oldlinecolor = getlinecolor();
    int oldbkcolor = getbkcolor();
    int oldfillcolor = getfillcolor();

    setlinecolor(BLACK);			// 设置画线颜色
    setbkcolor(WHITE);				// 设置背景颜色
    setfillcolor(WHITE);			// 设置填充颜色
    fillrectangle(this->left, this->top, this->right, this->bottom);
    outtextxy(this->left + (this->right - this->left - textwidth(this->text) + 1) / 2, this->top + (this->bottom - this->top - textheight(this->text) + 1) / 2, this->text);
    //恢复环境
    setlinecolor(oldlinecolor);
    setbkcolor(oldbkcolor);
    setfillcolor(oldfillcolor);
}


//bool EasyxxButton::EasyTextBoxCheck(EasyTextBox *NEW, int x, int y)
//{
//    return (NEW->right >= x && NEW->left <= x && NEW->top <= y && NEW->bottom >= y);
//}

EasyxxButton::EasyxxButton() {

}

EasyxxButton::EasyxxButton(int x, int y, int width, int height) {

}

EasyxxButton::EasyxxButton(int x, int y, int width, int height, std::string str, void (*userfunc)()) {

}

EasyxxButton::EasyxxButton(int i, int i1, int i2, int i3, const char *string, int n) {

}
