#pragma once

/*
 Copyright WU DE QUAN. All rights reserved.

 @Author: EvLast
 @Date: 2024/6/7 0:20:30

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

#ifndef _STUDENTVIEW_
#define _STUDENTVIEW_

#include "Student.h"
// -------------------- ������� --------------------

// -------------------- service --------------------


// ------ ѧ��ҳ�����ע��ģ�鴰��------------------
void LoginView();


//-------------------------------------------------

//���ð�ť
void StudentshowButton(int x, int y, int width, int height, std::string str, int textSize, Color fillColor, Color textColor);

//ѧ��ҳ��
void StudentmenuView();

// ���ý���
void StudentSettingView();

// ��ʱ����
void TimeView();


// -------------------- view --------------------

#endif // !_STUDENT_