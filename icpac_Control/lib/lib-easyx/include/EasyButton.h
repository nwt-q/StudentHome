//
// Created by NWT on 2024/11/10.
//

#ifndef ICPAC_CONTROL_EASYBUTTON_H
#define ICPAC_CONTROL_EASYBUTTON_H

#include <graphics.h>
#include <string>

struct Color
{
    cs_byte R;
    cs_byte G;
    cs_byte B;
};

/*
    功能：设计文本框控件
*/
struct EasyTextBox
{
    int left = 0, top = 0, right = 0, bottom = 0; // 控件坐标
    char* text = NULL;                         // 控件内容
    UINT64 maxlen = 0;                 // 文本框最大内容长度
};


class EasyButton {
public:
    EasyButton();
    EasyButton(int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor);
    EasyButton(int x, int y, int width, int height);
    EasyButton(int x, int y, int width, int height, std::string str,  void (*userfunc)() = NULL);

    EasyButton(int i, int i1, int i2, int i3, const char string[4], int n);

    bool EasyTextBoxCheck(EasyTextBox* NEW, int x, int y);

    void EasyButtonShow();

    void (*userfunc)() = NULL;
    int left = 0, top = 0, right = 0, bottom = 0; // 控件坐标
    LPCTSTR text;
};
#endif //ICPAC_CONTROL_EASYBUTTON_H
