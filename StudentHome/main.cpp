/*
 Copyright WU DE QUAN. All rights reserved.

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

#include "AdminView.h"
#include"StudentView.h"
#include"Star.h"
#undef UNICODE
#undef _UNICODE

/*
* 创建者 : 书山(EvLast)
* 创建时间 : 2024/6/6 12:10:55
*/

int main() {
	initgraph(1280, 720, SHOWCONSOLE);
	T();
	//mciSendString(_T("open su.mp3 alias ../Music/backgroundMusic.mp3"), NULL, 0, NULL);//播放音乐
	//mciSendString(_T("play ../Music/backgroundMusic.mp3 repeat"), NULL, 0, NULL);//循环播放
	StudentFilenout("../Data/StudentData.txt");
	/*LoginView();*/
	FistPage();
	/*CorrectiveView();*/
	/*StudentSendView();*/
	StudentFilein("../Data/test.txt");
	// 关闭图形模式
	closegraph();
    return 0;
}
