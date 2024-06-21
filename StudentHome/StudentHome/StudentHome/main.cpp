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
//#include"game.h"
#include "AdminView.h"
#include"StudentView.h"
#include"Star.h"
#undef UNICODE
#undef _UNICODE
/*
* ´«½¨Õß : ÊéÉ½(EvLast)
* ´´½¨Ê±¼ä : 2024/6/6 12:10:55
*/


int main() {
	initgraph(1280, 720, SHOWCONSOLE);
	T();
	LoginView();
	//StudentmenuView();
	// �ر�ͼ��ģʽ
	closegraph();
	//LoginView();
	StudentmenuView();
    return 0;
}
