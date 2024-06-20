#pragma once
/*
 Copyright WU DE QUAN. All rights reserved.

 @Author: EvLast
 @Date: 2024/6/12 1:54:26

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


#ifndef _ALL_
#define _ALL_

// -------------------- 数据设计 --------------------
#include <graphics.h>
#include<iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include <cmath>
#include <random>
#include <windows.h>
using namespace std;
//------------------数据设计------------------


/*
	颜色：
		R,G,B：颜色的RGB属性
		随机颜色时，可以通过随机R，G，B来随机颜色
*/
struct Color
{
	byte R;
	byte G;
	byte B;
};


extern int aaa;

//------------------数据设计------------------

// -------------------- service --------------------

void init();



// -------------------- view --------------------


#endif // !_ALL_