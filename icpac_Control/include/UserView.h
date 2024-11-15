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

#include "StudentModel.h"
#include "graphics.h"
//--------------------����ģ��--------------------------


struct  Color;



// -------------------- service --------------------
// �����ع��� QT
class WindowController {
public:
    WindowController();
    ~WindowController();

    /*
        ���ܣ� Ӧ�õ�һҳ
        ������void
        ����ֵ��void
    */
    void ControlPage();

    void ProductionGroupView();

    void gameQoQoView();

private:
    int pageIndex = 1;
};


/*
    ���ܣ�ȷ���Ƿ����ɹ�,��ť btnOK �ĵ���¼�
    ������EasyTextBox* NEW
    ����ֵ��void
*/
void On_btnOk_Click();

// -------------------- view --------------------

#endif // ! _STUDENTVIEW_