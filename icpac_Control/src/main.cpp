/*
 Copyright Wu DeQuan. All rights reserved.

 @Author: EvLast
 @Date: 2024/6/6 12:10:55

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
#pragma comment(lib,"WINMM.LIB")
#include "../include/AdminView.h"
#include "../include/StudentView.h"
#include "../include/Star.h"
#include "../include/game.h"
using namespace gameqoqo;

#undef UNICODE
#undef _UNICODE

/*
* 创建者 : 书山(EvLast)
* 创建时间 : 2024/6/6 12:10:55
*/
int main() {
	initgraph(1280, 720, SHOWCONSOLE);
	T();

    auto Window = new WindowController();

    Window->FistPage();

    //mciSendString("open Summer.mp3 alias ../resources/Music/backgroundMusic.mp3",NULL,0,NULL);

//    StudentFilenout("../resources/Data/StudentData.txt");
//    WindowController* w  = new WindowController();
//    w->FistPage();
//	StudentFilein("../resources/Data/test.txt");
    /*initgraph(windowsWidth, windowsHeight, EX_MOUSE);*/
    //打开背景乐：
    //changeMusic();
//    menuView();
//	// 关闭图形模式
   closegraph();
    return 0;
}
