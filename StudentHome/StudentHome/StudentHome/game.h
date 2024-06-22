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


#ifndef _GAME_
#define _GAME_
#pragma comment( lib, "MSIMG32.LIB")
//------------------数据设计------------------
#include <graphics.h>
#include<iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include <cmath>
#include <random>
#include <windows.h>
using namespace std;
#pragma comment(lib,"winmm.lib")

namespace gameqoqo {
	static double mapDeltaX = 0;			//地图X方向偏移量
	static double mapDeltaY = 0;

	const string voiceSRC = "../../../Music/backgroundMusic.mp3";				//背景音乐的文件路径
	const string BackGround = "../../../background/2.jpg";			//开始界面(菜单)背景的文件路径
	const int skinCount = 6;								//皮肤数量
	string gamerSkins[skinCount] =
	{ "../../../Skins/皮肤一.png","../../../Skins/皮肤二.png","../../../Skins/皮肤三.png",
		"../../../Skins/皮肤四.png","../../../Skins/皮肤五.png","../../../Skins/皮肤六.png" };	//玩家皮肤的文件路径

	int gamerSkinIndex = 0;							//玩家当前皮肤在数组中的索引，默认为第一个

	const int windowsWidth = 1280;					//窗口宽度(单位：像素点)
	const int windowsHeight = 720;					//窗口高度
	const int mapWidth = windowsWidth * 4;			//地图宽度
	const int mapHeight = windowsHeight * 4;		//地图高度

	const int AICount = 20;			//初始AI数量
	const int initAIMaxR = 30;			//AI初始最大半径
	const int initAIMinR = 20;			//AI初始最小半径
	const double attackRFactor = 2.5;		//AI追击玩家的距离因子（玩家距离AI attackRFactor倍半径时AI开始追击）

	const int foodMinR = 3;				//食物最小半径
	const int foodMaxR = 9;			//食物最大半径

	const int initGamerR = 15;			//初始化玩家大小
	const int speedFactor = 1800;		//速度因子		速度 = speedFactor / pow(ball.r, 2)
	const int minFoodNumber = 800;		//食物最小数量

	double minSpeed = 3;
	int eatAI = 0;						//玩家吃掉AI的数量
	bool music = false;					//背景音乐状态（打开/关闭）	true: 表示背景音乐已打开
	double scaleFactor = 1;					//缩放因子，面积缩放比例为：scaleFactor的平方

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

	/*
		球：
			通用结构体。可以表示：玩家，AI，或者食物

		如果一个球被吃掉了，那么将他的半径置为0；之后不参与吃或者被吃。
	*/
	struct Ball
	{
		int x;							//x坐标，横向
		int y;							//y坐标，纵向
		int r;							//半径

		double deltaX;					//X 的变化量，|deltaX| < 1 时，x不变; deltaX > 1时：x++,同时 deltaX -= 1; deltaX < -1: X--,同时deltaX+=1;
		double deltaY;					//Y 的变化量，|deltaY| < 1 时，y不变; deltaY > 1时：y++,同时 deltaY -= 1; deltaY < -1; Y--,同时deltaY+=1;

		string* imagesrc = nullptr;			//指向皮肤字符串路径的指针；只有玩家有，AI和食物的 imagesrc = nullptr;
		Color RGB{ 0,0,0 };				//所有球的默认颜色为黑色	（游戏背景为白色）
	};

	Ball Gamer;						//玩家控制的球
	Ball AI[AICount];				//AI
	Ball food[2 * minFoodNumber];		//食物
	//------------------数据设计------------------



	//--------------------------service--------------------------

	/*
		负责人：
		功能：初始化游戏数据
				初始化玩家		初始化食物（随机位置，全局变量中有初始化数量）		初始化AI（随机）
				要初始化的值包括：玩家皮肤，玩家速度。坐标，半径，颜色（玩家除外），
		参数：无
		返回值：void
	*/
	void Gameinit();

	/*
		负责人：
		功能：实现球ball的移动。 例如：如果要实现玩家的移动，就将玩家作为参数传进去
			实现思路：
				根据速度，修改deltaX和deltaY, 根据deltaX 和 deltaY 的值。再考虑是否需要修改球在地图中的坐标。

			设计注意：
				1.需要判断是否能向该方向移动。
					例如：向上移动需要保证 Gamer.y-Gamer.r-getSpeed(Gamer) 始终 > 0
				2.需要判断 deltaX 和 deltaY 的绝对值是否 > 1
				2.不需要接收用户输入。
					survice层不接受用户输入
		参数：Ball类型变量ball，传入要移动的球，注意是引用传递
		返回值：void
	*/
	bool goDown(Ball& ball);
	bool goUp(Ball& ball);
	bool goLeft(Ball& ball);
	bool goRight(Ball& ball);

	/*
		负责人:
		功能：实现所有AI的移动
				令AI朝距离自己最近的食物移动，如果玩家距离自己够近，那么追击玩家
				移动可以调用goDown() goUp()等,将要移动的球作为参数传进去

				移动规则：	对于每一个AI
					判断玩家是否在追击范围内，
					如果在，计算delta_x 和 delta_y .进行追击，追击玩家逻辑 与 吃最近的食物逻辑一样
							注意：根Ball内部的deltaX含义不一样。
					如果不在：
						1.找到距离自己最近的食物，计算delta_x和delta_y,
						2.比较二者大小，谁大，就沿着谁的方向移动。
							例如：delta_x > delta_y 那么就沿着X轴移动，靠近食物（按照速度speed）
						3.需要根据情况，看delta_x (或 delta_y) >0 还是 <0，决定需要 x+=speed 还是 x-=speed
						4.该AI移动完成后，下一个AI移动
		参数：无
		返回值：void
	*/
	void AIMove();

	/*
		负责人：
		功能：进行球与球之间的交互（吃与被吃）
			包括：玩家吃食物，
				  玩家吃AI，
				  AI吃食物

				  利用循环，判断玩家与每个食物，玩家与每个AI，每个AI与每个食物 之间的吃与被吃关系。
					满足吃的关系后：先更新存活下来的球的半径（ 需要多次调用getArea() ）
									再将被吃掉的球的半径置为0
					触发吃与被吃的条件，
							小球完全被大球包裹。		圆心距离 + 小球半径 <= 大球半径
		参数：无
		返回值：void
	*/
	void ballEat();

	/*
		负责人：
		功能：计算球的速度
			根据传入球的面积计算其速度。
				speed = speedFactor / pow(ball.r, 2)

		参数：Ball类型变量ball，调用时传入要求速度的球
		返回值：double：返回求出来的速度
	*/
	double getSpeed(const Ball& ball);

	/*
		负责人：
		功能：计算球 ball_1 和 ball_2 的圆心之间距离
		参数：
			Ball ball_1: 要计算距离的球1
			Ball ball_2: 要计算距离的球2
		返回值：double	返回两球之间的距离
	*/
	double getDistance(const Ball& ball_1, const Ball& ball_2);

	/*
		负责人:
		功能：胜利判断
				吃掉AI数量 = 初始化AI数量
		参数：void
		返回值：bool
		`			true: 表示胜利
					false：表示还未胜利
	*/
	bool isWin();

	/*
		负责人：
		功能：失败判断
				玩家被吃掉（半径为0）
		参数：无
		返回值：bool
					true：表示游戏失败（玩家被吃掉了）
					false：表示还未失败
	*/
	bool isFail();

	/*
		负责人：
		功能：获取一个随机数
				实现要求：得到的随机数区间的左右都是闭区间。
					例如：int temp = getRandom(1,10)	那么，temp的可能值一定要包含 1 和 10
		参数：
				int min：随机数范围最小值
				int max：随机数范围最大值
		返回值：int，返回得到的随机数
	*/
	int getRandom(int min, int max);

	/*
		负责人：
		功能：帧数控制
		参数：int fps：给定的时间阈值，单位为ms，用来控制游戏界面刷新速度。两次界面打印之间相隔的时间不得小于fps ms
		返回值：bool：
					true：表示函数调用时，距离上一次打印界面的时间大于fps ms，
					false：表示函数调用时，距离上一次打印界面的时间不足fps ms
	*/
	bool FPS();


	/*
		负责人:
		功能：检查食物数量是否充足
				遍历数组。记录 r>0的食物数量，
		参数：无
		返回值：bool
					true：表示食物数量充足
					false: 表示食物数量不够，低于最低数量
	*/
	bool foodEnough();

	/*
		负责人：
		功能：补充生成食物（需要随机的值：半径；x,y坐标）
				调用时机：食物数量不够时
				实现要求：将食物数组中填满（使数组中每个元素的半径r都大于0）
					全局变量中有：食物的最大半径，食物的最小半径，食物的最小数量
		参数：无
		返回值：void
	*/
	void creatFood();

	/*
		负责人：
		功能：查看背景音乐状态（打开还是关闭）
				根据全局变量music的值，返回背景音乐状态
		参数：无
		返回值：bool
				true: 表示背景音乐打开
				false: 表示背景音乐关闭
	*/
	bool musicState();

	/*
		负责人：
		功能：开/关背景音乐
				对music取反，然后根据情况打开或关闭音乐
		参数：无
		返回值：void
	*/
	void changeMusic();

	/*
		负责人：
		功能：根据传入的index，更改gamerSkinIndex的值
		参数：int index:	传入要选择的皮肤在皮肤数组中的下标
		返回值：void
	*/
	void skinChange(int index);

	/*
		负责人：
		功能：传入缩放前的坐标，计算缩放后的坐标
		参数：int x：缩放前的坐标，可以传入x，也可以传入y
		返回值：double	表示缩放后的X或Y坐标
	*/
	double getScale(int x);

	//--------------------------service--------------------------


	//---------------------view---------------------

	/*
		负责人：
		功能：展示开始界面
				打印开始界面。同时：根据用户输入判断接下来该前往哪个界面
				需要包含按钮：开始游戏，皮肤选择，设置，结束游戏
		参数：无
		返回值：void
	*/
	void menuView();

	/*
		负责人：
		功能：展示游戏界面
			需要展示的有：
					玩家，食物，AI
		参数：无
		返回值：void
	*/
	void gameView();

	/*
		负责人：
		功能：游戏界面整合
				while(1)
				{
					打印游戏界面(调用 gameView())
						打印玩家，AI，食物。	玩家需要打印皮肤
					if(!foodEnough())		如果食物不够
						随机生成食物（调用：creatFood()）
					获取用户输入
						W/上：向上移动（调用向上移动的函数：goUp(Ball &ball)）（移动函数是由service层实现）
						A/左：向左移动（调用向左移动的函数）
						S/下：向下移动（调用向下移动的函数）
						D/右：向右移动（调用向右移动的函数）
						空格/ESC：暂停。	调用pauseView()
					AI移动( 调用 AIMove() )
					球与球之间交互，球互吃（ 调用 ballEat() ）

					胜利条件判断( 调用 isWin() )
						如果胜利：
							展示胜利界面 ( 调用winView() )
					失败条件判断( 调用 isFail() )
						如果失败：
							展示失败界面 ( 调用failView() )
				}

		参数：无
		返回值：void
	*/
	void gameStart();

	/*
		负责人：
		功能：展示暂停界面
				需要包含按钮：
						继续游戏，
						返回开始菜单，
						打开/关闭音效（调用changeMusic()实现开/关音效，调用musicChangeView()展示当前音效状态）。
		参数：无
		返回值：void
	*/
	void pauseView();

	/*
		负责人：
		功能：展示设置界面
				包含按钮：打开/关闭音效（调用changeMusic()实现开/关音效，调用musicChangeView()展示当前音效状态）。
				制作组信息。
				返回开始界面。
		参数：无
		返回值：void
	*/
	void settingView();

	/*
		负责人：
		功能：展示制作组信息页面
				包含：制作组信息文本框，返回设置界面。
		参数：无
		返回值：void
	*/
	void productionGroupView();

	/*
		负责人：
		功能：显示按钮（并不具备监听鼠标的功能，也就不具备按下后进行相关操作的能力）
				按钮都是长方形
		参数：
			int x：按钮的左上角x坐标
			int y：按钮的左上角y坐标
			int width：按钮宽度
			int height：按钮高度
			string str：按钮显示内容
			int textSize：按钮中文字大小
			Color fillColor	填充颜色 （背景色）
			Color textColor	字体颜色
		返回值：
	*/
	void showButton(int x, int y, int width, int height, string str, int textSize,
		Color fillColor = { 0,0,0 }, Color textColor = { 255,255,255 });	//默认黑底，白字

	/*
		负责人：
		功能：展示胜利界面
				需要按钮：再来一遍，返回开始界面
		参数：无
		返回值：void
	*/
	void winView();

	/*
		负责人：
		功能：展示失败界面
				需要按钮：重新开始，返回开始界面
		参数：无
		返回值：void
	*/
	void failView();

	/*
		负责人：
		功能：展示皮肤选择界面
				根据用户输入
				需要展示：皮肤（全局变量中有 皮肤总数量 和 路径）（透明贴图：调用transparentImage(****)），
							每个皮肤对应的按钮，返回开始界面的按钮
					用户选择皮肤之后应该有选择成功的提示。
		参数：无
		返回值：void
	*/
	void skinChoiceView();

	/*
		负责人：
		功能：透明贴图
				将传入的图片的背景透明化并且输出图片。	注意：该函数需要实现输出	（调用AlphaBlend()函数）
		参数：
			int x:图片输出时横坐标
			int y:图片输出时纵坐标
			IMAGE* src:	源图片指针
		返回值：void
	*/
	void transparentImage(int x, int y, IMAGE* srcimg);

	/*
		负责人：
		功能：弹出改变音效的提示窗口	参考：调用MessageBox()函数
				调用函数musicState()根据返回值，弹出相应提示窗口
		参数：无
		返回值：void
	*/
	void musicChangeView();

	//---------------------view---------------------




	namespace ldk
	{
		const int VK_W = 0x57;
		const int VK_A = 0x41;
		const int VK_S = 0x53;
		const int VK_D = 0x44;
	}

	namespace gxb
	{
		const int BUTTONX = 550;
		const int BUTTONY = 200;
		const int BUTTONW = 200;
		const int BUTTONH = 100;

		Color fillColor = { 92, 235, 89 };
		Color textColor = { 255,255,255 };

		//定义消息结构体变量
		ExMessage msg;
		//鼠标是否在矩形内
		bool inArea(int mx, int my, int x, int y, int w, int h)
		{
			if (mx > x && my > y && mx < x + w && my < y + h)
			{
				return true;
			}
			return false;
		}
	}

	int main()
	{
		initgraph(windowsWidth, windowsHeight, EX_MOUSE);
		//打开背景乐：
		changeMusic();
		menuView();

		return 0;
	}

	//--------------------------service--------------------------

	void Gameinit() {
		srand(int(time(0)));
		Gamer.x = rand() % (mapWidth - 2 * initGamerR + 1) + initGamerR;
		Gamer.y = rand() % (mapHeight - 2 * initGamerR + 1) + initGamerR;
		Gamer.r = initGamerR;
		Gamer.imagesrc = &gamerSkins[gamerSkinIndex];
		//初始化玩家

		int Number_Food = minFoodNumber * 2;

		for (int i = 0; i < Number_Food; ++i) {//初始化食物
			food[i].x = rand() % (mapWidth - 2 * initGamerR + 5) + initGamerR;	//x
			food[i].y = rand() % (mapHeight - 2 * initGamerR + 5) + initGamerR;	//y
			food[i].r = rand() % (foodMaxR - foodMinR + 1) + foodMinR;			//半径

			//颜色
			food[i].RGB.R = rand() % (256);
			food[i].RGB.G = rand() % (256);
			food[i].RGB.B = rand() % (256);
		}

		for (int i = 0; i < AICount; ++i) {//初始化AI
			AI[i].x = rand() % (mapWidth - 2 * initGamerR + 1) + initGamerR;//x
			AI[i].y = rand() % (mapHeight - 2 * initGamerR + 1) + initGamerR;//y
			AI[i].r = rand() % (initAIMaxR - initAIMinR + 1) + initAIMinR;//r

			//颜色
			AI[i].RGB.R = rand() % (256);
			AI[i].RGB.G = rand() % (256);
			AI[i].RGB.B = rand() % (256);
		}

		//初始化缩放比例
		scaleFactor = 1;

		//初始化吃掉AI数量
		eatAI = 0;
	}

	bool goDown(Ball& ball)
	{
		double vy = getSpeed(ball);
		if (ball.y + ball.r + vy < mapHeight)
		{
			ball.deltaY += vy;
			while (ball.deltaY > 1)
			{
				ball.y += 1;
				ball.deltaY -= 1;
			}
			return true;
		}
		return false;
	}
	bool goUp(Ball& ball)
	{
		double vy = getSpeed(ball);
		if (ball.y - ball.r - vy > 0)
		{
			ball.deltaY += vy;
			while (ball.deltaY > 1)
			{
				ball.y -= 1;
				ball.deltaY -= 1;
			}
			return true;
		}
		return false;
	}
	bool goLeft(Ball& ball)
	{
		double vx = getSpeed(ball);
		if (ball.x - ball.r - vx > 0)
		{
			ball.deltaX += vx;
			while (ball.deltaX > 1)
			{
				ball.x -= 1;
				--ball.deltaX;
			}
			return true;
		}
		return false;
	}
	bool goRight(Ball& ball)
	{
		double vx = getSpeed(ball);
		if (ball.x + ball.r + vx < mapWidth)
		{
			ball.deltaX += vx;
			while (ball.deltaX > 1)
			{
				ball.x += 1;
				--ball.deltaX;
			}
			return true;
		}
		return false;
	}

	void AIMove()
	{
		for (int i = 0; i < AICount; i++)
		{
			if (AI[i].r == 0)		//已经被吃掉
			{
				continue;
			}
			if (getDistance(AI[i], Gamer) < attackRFactor * AI[i].r)		//玩家处于AI一定半径倍数范围之内
			{
				int deltaX = AI[i].x - Gamer.x;			//X方向差值
				int deltaY = AI[i].y - Gamer.y;			//Y方向差值
				if (Gamer.r <= AI[i].r)						//玩家比AI小，追击
				{
					if (abs(deltaX) > abs(deltaY))			//X轴方向距离更远
					{
						if (deltaX > 0)
						{
							goLeft(AI[i]);					//玩家在AI左边,AI向左走
						}
						else
						{
							goRight(AI[i]);
						}
					}
					else									//Y轴方向上距离更远
					{
						if (deltaY > 0)
						{
							goUp(AI[i]);
						}
						else
						{
							goDown(AI[i]);
						}
					}
				}
				else						//AI逃跑
				{
					if (abs(deltaX) > abs(deltaY))			//X轴方向距离更远
					{
						if (deltaX > 0)
						{
							goRight(AI[i]);					//玩家在AI左边,AI向右走
						}
						else
						{
							goLeft(AI[i]);
						}
					}
					else									//Y轴方向上距离更远
					{
						if (deltaY > 0)
						{
							goDown(AI[i]);
						}
						else
						{
							goUp(AI[i]);
						}
					}
				}
			}
			else
			{
				double minFoodDistance = INT_MAX;
				Ball* temp = nullptr;				//记录距离最近的食物
				for (int j = 0; j < minFoodNumber * 2; j++)
				{
					if (food[j].r > 0)
					{
						int distance = getDistance(AI[i], food[j]);
						if (distance < minFoodDistance)
						{
							temp = &food[j];
							minFoodDistance = distance;
						}
					}
				}
				if (!temp)
				{
					cout << "出错了，没有找到距离最近的食物" << endl;
					exit(-1);
				}

				int deltaX = AI[i].x - (*temp).x;
				int deltaY = AI[i].y - (*temp).y;
				if (abs(deltaX) > abs(deltaY))			//X轴方向距离更远
				{
					if (deltaX > 0)
					{
						if (!goLeft(AI[i])) 					//最近的食物在AI左边,AI向左走
						{
							//向左走不动：特殊情况：食物吃不到，强制消灭食物。
							temp->r = 0;
						}
					}
					else
					{
						if (!goRight(AI[i]))
						{
							temp->r = 0;
						}
					}
				}
				else									//Y轴方向上距离更远
				{
					if (deltaY > 0)
					{
						if (!goUp(AI[i]))
						{
							temp->r = 0;
						}
					}
					else
					{
						if (!goDown(AI[i]))
						{
							temp->r = 0;
						}
					}
				}
			}
		}
	}

	void ballEat()
	{
		for (int i = 0; i < AICount; i++)				//循环遍历AI
		{
			if (AI[i].r)
			{
				if (getDistance(Gamer, AI[i]) <= AI[i].r)			//AI吃玩家
				{
					AI[i].r += Gamer.r / 4;
					Gamer.r = 0;
					continue;
				}
				if (getDistance(Gamer, AI[i]) <= Gamer.r)			//玩家吃AI
				{
					Gamer.r += AI[i].r / 4;
					++eatAI;
					AI[i].r = 0;
				}
				for (int j = 0; j < 2 * minFoodNumber; j++)			//循环遍历食物
				{
					if (food[j].r)
					{
						if (getDistance(Gamer, food[j]) <= Gamer.r)			//玩家吃食物
						{
							Gamer.r += food[j].r / 4;
							food[j].r = 0;
							if (Gamer.r > 820)
							{
								Gamer.r -= 5;
							}
							continue;
						}
						if (getDistance(AI[i], food[j]) <= AI[i].r)			//AI吃食物
						{
							AI[i].r += food[j].r / 4;
							food[j].r = 0;
							if (AI[i].r > 790)
							{
								AI[i].r -= 7;
							}
						}
					}
				}
			}
		}
	}

	double getSpeed(const Ball& ball)
	{
		return max(speedFactor / pow(ball.r, 2), minSpeed);
	}

	double getDistance(const Ball& ball_1, const Ball& ball_2)
	{
		return sqrt(pow(ball_1.x - ball_2.x, 2) + pow(ball_1.y - ball_2.y, 2));
	}

	bool isWin()
	{
		return eatAI == AICount;
	}

	bool isFail()
	{
		return(Gamer.r == 0);
	}

	int getRandom(int min, int max)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(min, max);

		return(distrib(gen));
	}

	bool FPS()
	{
		const int const  Chick = 1000 / 60;
		static int startTime;
		int endTime = clock();
		if (endTime - startTime > Chick) {
			startTime = endTime;
			return true;
		}
		return false;
	}

	bool foodEnough()
	{
		int foodCount = 0;
		for (int i = 0; i < 2 * minFoodNumber; i++)
		{
			if (food[i].r != 0)
			{
				foodCount++;
			}
		}
		return foodCount >= minFoodNumber;
	}
	void creatFood()
	{
		for (int i = 0; i < 2 * minFoodNumber; i++)
		{
			if (food[i].r == 0)
			{
				food[i].r = getRandom(foodMinR, foodMaxR);
				food[i].x = getRandom(foodMaxR + 10, mapWidth - foodMaxR - 10);
				food[i].y = getRandom(foodMaxR + 10, mapHeight - foodMaxR - 10);

				food->RGB.R = static_cast<byte>(getRandom(0, 255));
				food->RGB.G = static_cast<byte>(getRandom(0, 255));
				food->RGB.B = static_cast<byte>(getRandom(0, 255));
			}
		}
	}

	bool musicState()
	{
		return music;
	}

	void changeMusic()
	{
		music = !music;
		if (music == true) {
			mciSendString(("open \"" + voiceSRC + "\" ").c_str(), NULL, 0, NULL);
			mciSendString(("play \"" + voiceSRC + "\" repeat").c_str(), NULL, 0, NULL);
			mciSendString(("setaudio \"" + voiceSRC + "\" volume to 100").c_str(), NULL, 0, NULL);
		}
		else {
			mciSendString(("stop \"" + voiceSRC + "\" ").c_str(), NULL, 0, NULL);
			mciSendString(("Close \"" + voiceSRC + "\" ").c_str(), NULL, 0, NULL);
		}
	}

	void skinChange(int index)
	{
		gamerSkinIndex = index;
	}

	double getScale(int x)
	{
		return x / scaleFactor - mapWidth / (2 * scaleFactor) + mapWidth / 2.0;
	}

	//---------------------view---------------------
	void menuView()
	{
		using namespace gxb;
		cleardevice();
		IMAGE img;
		loadimage(&img, BackGround.c_str(), windowsWidth, windowsHeight, true);//背景图片
		putimage(0, 0, &img);
		showButton(BUTTONX, 100, BUTTONW, BUTTONH, "开始游戏", 48, fillColor, textColor);
		showButton(BUTTONX, 250, BUTTONW, BUTTONH, "皮肤选择", 48, fillColor, textColor);
		showButton(BUTTONX, 400, BUTTONW, BUTTONH, "进入设置", 48, fillColor, textColor);
		showButton(BUTTONX, 550, BUTTONW, BUTTONH, "退出游戏", 48, fillColor, textColor);

		while (1)
		{
			Sleep(200);
			while (peekmessage(&msg, EM_MOUSE))
			{
				//判断是否点击
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 100, BUTTONW, BUTTONH))
				{
					gameStart();
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 250, BUTTONW, BUTTONH))
				{
					skinChoiceView();
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 400, BUTTONW, BUTTONH))
				{
					settingView();
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 550, BUTTONW, BUTTONH))
				{
					exit(0);
				}
			}
		}
	}

	void gameView()
	{
		//双缓冲
		BeginBatchDraw();
		setbkcolor(BLACK);
		cleardevice();

		//食物
		for (int i = 0; i < minFoodNumber * 2; i++)
		{
			if (food[i].r)
			{
				setfillcolor(RGB(food[i].RGB.R, food[i].RGB.G, food[i].RGB.B));
				solidcircle(getScale(food[i].x), getScale(food[i].y), food[i].r / scaleFactor);
			}
		}
		if (Gamer.r)			//如果玩家存在，那么绘制玩家。（玩家被吃掉后，失败界面需要1秒才能弹出）
		{
			//绘制玩家
			setfillcolor(BLUE);
			solidcircle(getScale(Gamer.x), getScale(Gamer.y), Gamer.r / scaleFactor);
			double skinScaleFactor = (Gamer.r / scaleFactor) / 54.0;						//54是皮肤无缩放情况下，中心的圆的半径
			IMAGE Skin;
			loadimage(&Skin, Gamer.imagesrc->c_str(), 500 * skinScaleFactor, 281 * skinScaleFactor);					//无缩放状态下球的半径大小
			transparentImage(getScale(Gamer.x) - 250 * skinScaleFactor, getScale(Gamer.y) - 140 * skinScaleFactor, &Skin);
		}
		//绘制ai
		for (int i = 0; i < AICount; i++)
		{
			if (AI[i].r)
			{
				setfillcolor(RGB(AI[i].RGB.R, AI[i].RGB.G, AI[i].RGB.B));
				solidcircle(getScale(AI[i].x), getScale(AI[i].y), AI[i].r / scaleFactor);
			}
		}

		EndBatchDraw();
	}

	void gameStart()
	{
		using namespace ldk;
		Gameinit();
		mapDeltaX = windowsWidth / 2.0 - getScale(Gamer.x);			//地图X方向偏移量
		mapDeltaY = windowsHeight / 2.0 - getScale(Gamer.y);

		cleardevice();
		settextstyle(50, 0, "华文行楷");//设置大小，字体
		settextcolor(WHITE);
		outtextxy(400, 300, "暂停：空格键");
		outtextxy(400, 500, "移动：WASD（或上下左右）");
		Sleep(3000);


		BeginBatchDraw();
		cleardevice();
		int count = 0;

		while (1)
		{
			int startTime = clock();			//获取循环开始的时间
			if (!foodEnough())
			{
				creatFood();
			}
			if (windowsHeight / (Gamer.r * 2 / scaleFactor) < 2)
			{
				scaleFactor++;
				mapDeltaX = windowsWidth / 2.0 - getScale(Gamer.x);
				mapDeltaY = windowsHeight / 2.0 - getScale(Gamer.y);
			}
			gameView();
			if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_W))
			{
				if (goUp(Gamer))
				{
					double speed = getSpeed(Gamer);
					mapDeltaY += speed / scaleFactor;
				}
			}
			if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_S))
			{
				if (goDown(Gamer))
				{
					double speed = getSpeed(Gamer);
					mapDeltaY -= speed / scaleFactor;
				}
			}
			if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_A))
			{
				if (goLeft(Gamer))
				{
					double speed = getSpeed(Gamer);
					mapDeltaX += speed / scaleFactor;
				}
			}
			if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_D))
			{
				if (goRight(Gamer))
				{
					double speed = getSpeed(Gamer);
					mapDeltaX -= speed / scaleFactor;
				}
			}
			if (GetAsyncKeyState(VK_SPACE))
			{
				pauseView();
			}
			setorigin(mapDeltaX, mapDeltaY);

			AIMove();
			ballEat();

			if (isWin())
			{
				++count;
				if (count == 100)
				{
					winView();
				}
			}
			if (isFail())
			{
				++count;
				if (count == 100)
				{
					failView();
				}
			}
			if (FPS())
			{
				continue;
			}
		}

		FlushBatchDraw();
	}

	void pauseView()
	{
		setorigin(0, 0);
		using namespace gxb;
		cleardevice();
		//定义图片变量
		IMAGE img_tp;
		//加载图片
		loadimage(&img_tp, BackGround.c_str(), windowsWidth, windowsHeight);
		putimage(0, 0, &img_tp);
		showButton(BUTTONX, 100, BUTTONW, BUTTONH, "继续游戏", 48, fillColor, textColor);
		showButton(BUTTONX, 250, BUTTONW, BUTTONH, "返回菜单", 48, fillColor, textColor);
		showButton(BUTTONX - 40, 400, BUTTONW + 80, BUTTONH, "打开/关闭音效", 48, fillColor, textColor);
		showButton(BUTTONX, 550, BUTTONW, BUTTONH, "退出游戏", 48, fillColor, textColor);
		while (1)
		{
			Sleep(250);
			while (peekmessage(&msg, EM_MOUSE))
			{
				//判断是否点击
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 100, BUTTONW, BUTTONH))			//继续游戏
				{
					return;
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 250, BUTTONW, BUTTONH))			//返回菜单
				{
					menuView();
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX - 40, 400, BUTTONW + 80, BUTTONH))			//设置音效
				{
					changeMusic();
					musicChangeView();
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 550, BUTTONW, BUTTONH))
				{
					exit(0);
				}
			}
		}
	}

	void settingView() {
		IMAGE img;
		loadimage(&img, BackGround.c_str(), windowsWidth, windowsHeight, true);//背景图片
		putimage(0, 0, &img);
		settextstyle(96, 0, "华文行楷");//设置大小，字体
		settextcolor(RGB(255, 255, 96));   //设置字体颜色
		setbkmode(TRANSPARENT);    //透明底，不覆盖底图
		outtextxy(100, 70, "设置界面");  // 在 (100, 100) 的位置输出文本
		//按之前按钮的颜色
		Color fillColor1 = { 238,238,9 };
		//按之后按钮的颜色
		Color fillColor2 = { 200,200,0 };
		//字体颜色
		Color textColor1 = { 0,0,0 };
		showButton(490, 170, 300, 100, "打开/关闭音效", 48, fillColor1, textColor1);
		showButton(490, 340, 300, 100, "制作组信息", 48, fillColor1, textColor1);
		showButton(490, 510, 300, 100, "返回开始界面", 48, fillColor1, textColor1);
		ExMessage m;
		while (true) {
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					if (m.x >= 490 && m.x <= 790 && m.y >= 170 && m.y <= 270) {
						changeMusic();
						showButton(490, 170, 300, 100, "打开/关闭音效", 48, fillColor2, textColor1);
						Sleep(200);
						showButton(490, 170, 300, 100, "打开/关闭音效", 48, fillColor1, textColor1);
						musicChangeView();
					}
					else if (m.x >= 490 && m.x <= 790 && m.y >= 340 && m.y <= 440) {
						showButton(490, 340, 300, 100, "制作组信息", 48, fillColor2, textColor1);
						Sleep(200);
						showButton(490, 340, 300, 100, "制作组信息", 48, fillColor1, textColor1);

						productionGroupView();

						cleardevice();
						putimage(0, 0, &img);
						settextstyle(96, 0, "华文行楷");//设置大小，字体
						settextcolor(RGB(255, 255, 96));   //设置字体颜色
						setbkmode(TRANSPARENT);    //透明底，不覆盖底图
						outtextxy(100, 70, "设置界面");  // 在 (100, 100) 的位置输出文本
						//按之前按钮的颜色
						Color fillColor1 = { 238,238,9 };
						//按之后按钮的颜色
						Color fillColor2 = { 200,200,0 };
						//字体颜色
						Color textColor1 = { 0,0,0 };
						showButton(490, 170, 300, 100, "打开/关闭音效", 48, fillColor1, textColor1);
						showButton(490, 340, 300, 100, "制作组信息", 48, fillColor1, textColor1);
						showButton(490, 510, 300, 100, "返回开始界面", 48, fillColor1, textColor1);
					}
					else if (m.x >= 490 && m.x <= 790 && m.y >= 510 && m.y <= 610) {
						showButton(490, 510, 300, 100, "返回开始界面", 48, fillColor2, textColor1);
						Sleep(200);
						showButton(490, 510, 300, 100, "返回开始界面", 48, fillColor1, textColor1);
						menuView();
					}
				}
			}
		}
	}

	void productionGroupView()
	{
		const string kText = "制作组信息"; // 需要滚动显示的文本内容
		const string kTextArr[9] = { "组名：第12组","组长：书山","产品经理：书山","技术官：书山",
								"音乐：书山","皮肤界面：书山" };
		ExMessage m;

		int y = windowsHeight;
		IMAGE img;
		loadimage(&img, BackGround.c_str(), windowsWidth, windowsHeight, true);//背景图片
		Color fillColor1 = { 135, 206, 250 };
		Color textColor1 = { 0,0,0 };
		Color textColor2 = { 238,238,9 };
		while (true) { // 循环播放滚动文本
			Sleep(5);
			BeginBatchDraw();
			cleardevice(); // 清空屏幕
			putimage(0, 0, &img);
			showButton(1080, 670, 200, 50, "点击屏幕返回", 30, fillColor1, textColor1);
			settextstyle(48, 0, "华文行楷"); // 设置字体样式和大小
			settextcolor(RGB(textColor2.R, textColor2.G, textColor2.B)); // 设置文本颜色
			setbkmode(TRANSPARENT);

			for (int i = 0; i < 9; i++)
			{
				int w = (windowsWidth - textwidth(kTextArr[i].c_str())) / 2;
				outtextxy(w, i * 100 + y, kTextArr[i].c_str()); // 在指定位置输出文本
			}

			// 显示滚动文本
			y -= 2; // 每次向上移动 1 个像素

			if (y < -700) { // 如果文本移动出屏幕，则重新开始滚动
				y = windowsHeight;
			}

			// 等待一定时间，以控制滚动速度
			FlushBatchDraw();
			if (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					cleardevice();
					EndBatchDraw();
					break;
				}
			}
		}
		EndBatchDraw();
	}

	void showButton(int x, int y, int width, int height, string str, int textSize,
		Color fillColor, Color textColor)			//默认黑底，白字
	{
		setfillcolor(RGB(fillColor.R, fillColor.G, fillColor.B));
		fillroundrect(x, y, x + width, y + height, width / 10, width / 10);
		setbkmode(TRANSPARENT);
		settextstyle(textSize, 0, _T("华文行楷"));
		int w = (width - textwidth(str.c_str())) / 2;
		int h = (height - textheight(str.c_str())) / 2;
		settextcolor(RGB(textColor.R, textColor.G, textColor.B));
		outtextxy(x + w, y + h, str.c_str());
	}

	void winView()
	{
		setorigin(0, 0);
		IMAGE img;
		loadimage(&img, BackGround.c_str(), windowsWidth, windowsHeight, true);//背景图片
		putimage(0, 0, &img);
		settextstyle(96, 0, "华文行楷");//设置大小，字体
		settextcolor(RGB(255, 255, 96));   //设置字体颜色
		setbkmode(TRANSPARENT);    //透明底，不覆盖底图
		outtextxy(200, 80, "恭喜胜利");  // 在 (100, 100) 的位置输出文本

		//再来一次的按钮颜色
		Color fillColor1 = { 238,238,9 };
		//返回开始界面的按钮颜色
		Color fillColor2 = { 200,200,0 };
		//再来一次的字体颜色
		Color textColor1 = { 0,0,0 };
		//返回开始界面的字体颜色
		Color textColor2 = { 0,0,0 };

		showButton(240, 350, 300, 100, "再来一次", 48, fillColor1, textColor1);
		showButton(740, 350, 300, 100, "返回开始界面", 48, fillColor1, textColor1);
		ExMessage m;
		while (true) {
			Sleep(100);
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					if (m.x >= 240 && m.x <= 540 && m.y >= 350 && m.y <= 450) {
						showButton(240, 350, 300, 100, "再来一次", 48, fillColor2, textColor1);
						Sleep(250);
						showButton(240, 350, 300, 100, "再来一次", 48, fillColor1, textColor1);
						gameStart();
					}
					else if (m.x >= 740 && m.x <= 1040 && m.y >= 350 && m.y <= 450) {
						showButton(740, 350, 300, 100, "返回开始界面", 48, fillColor2, textColor1);
						Sleep(250);
						showButton(740, 350, 300, 100, "返回开始界面", 48, fillColor1, textColor1);
						menuView();
					}
				}
			}
		}
	}

	void failView()
	{
		setorigin(0, 0);
		using namespace gxb;
		cleardevice();
		//定义图片变量
		IMAGE img_tp;
		//加载图片
		loadimage(&img_tp, BackGround.c_str(), windowsWidth, windowsHeight);
		putimage(0, 0, &img_tp);

		settextstyle(96, 0, "华文行楷");//设置大小，字体
		settextcolor(RGB(255, 255, 96));   //设置字体颜色
		setbkmode(TRANSPARENT);    //透明底，不覆盖底图
		outtextxy(200, 80, "游戏失败，你被吃掉了");  // 在 (100, 100) 的位置输出文本

		showButton(BUTTONX, 200, BUTTONW, BUTTONH, "返回菜单", 48, fillColor, textColor);
		showButton(BUTTONX, 400, BUTTONW, BUTTONH, "再来一次", 48, fillColor, textColor);
		while (1)
		{
			Sleep(100);
			while (peekmessage(&msg, EM_MOUSE))
			{
				//判断是否点击
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 200, BUTTONW, BUTTONH))		//返回菜单
				{
					menuView();
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 400, BUTTONW, BUTTONH))		//再来一次
				{

					gameStart();
				}
			}
		}
	}

	void skinChoiceView() {
		setbkcolor(GREEN);
		cleardevice();
		IMAGE Png;
		for (int i = 0; i < skinCount; ++i) {
			loadimage(&Png, gamerSkins[i].c_str());
			switch (i)
			{
			case 0:transparentImage(0, 0, &Png); break;
			case 1:transparentImage(400, 0, &Png); break;
			case 2:transparentImage(800, 0, &Png); break;
			case 3:transparentImage(0, 300, &Png); break;
			case 4:transparentImage(400, 300, &Png); break;
			case 5:transparentImage(800, 300, &Png); break;
			default:
				break;
			}

		}
		showButton(200, 200, 100, 40, "皮肤一", 20);
		showButton(600, 200, 100, 40, "皮肤二", 20);
		showButton(1000, 200, 100, 40, "皮肤三", 20);
		showButton(200, 500, 100, 40, "皮肤四", 20);
		showButton(600, 500, 100, 40, "皮肤五", 20);
		showButton(1000, 500, 100, 40, "皮肤六", 20);

		showButton(600, 600, 100, 40, "返回", 20);
		ExMessage msg;
		//msg = getmessage(EM_MOUSE);
		while (true)
		{
			Sleep(10);
			if (peekmessage(&msg, EM_MOUSE))
			{
				if (msg.message == WM_LBUTTONDOWN)
				{
					if (msg.x >= 200 && msg.x <= 200 + 100 && msg.y >= 200 && msg.y <= 200 + 40)
					{
						skinChange(0);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "更换成功", "皮肤", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 600 && msg.x <= 600 + 100 && msg.y >= 200 && msg.y <= 200 + 40)
					{
						skinChange(1);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "更换成功", "皮肤", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 1000 && msg.x <= 1000 + 100 && msg.y >= 200 && msg.y <= 200 + 40)
					{
						skinChange(2);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "更换成功", "皮肤", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 200 && msg.x <= 200 + 100 && msg.y >= 500 && msg.y <= 500 + 40)
					{
						skinChange(3);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "更换成功", "皮肤", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 600 && msg.x <= 600 + 100 && msg.y >= 500 && msg.y <= 500 + 40)
					{
						skinChange(4);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "更换成功", "皮肤", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 1000 && msg.x <= 1000 + 100 && msg.y >= 500 && msg.y <= 500 + 40)
					{
						skinChange(5);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "更换成功", "皮肤", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 600 && msg.x <= 600 + 100 && msg.y >= 600 && msg.y <= 600 + 40)
					{
						menuView();
					}
				}
			}
		}
	}


	void transparentImage(int x, int y, IMAGE* srcimg)
	{
		HDC dstDC = GetImageHDC(nullptr);
		HDC srcDC = GetImageHDC(srcimg);
		int width = srcimg->getwidth();
		int height = srcimg->getheight();
		BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
		AlphaBlend(dstDC, x, y, width, height, srcDC, 0, 0, width, height, bf);
	}

	void musicChangeView()
	{
		if (musicState() == false)
		{
			HWND hwnd = GetHWnd();
			MessageBox(hwnd, "背景音乐已关闭", "BGM", MB_OK | MB_ICONEXCLAMATION);
		}
		else
		{
			HWND hwnd = GetHWnd();
			MessageBox(hwnd, "背景音乐已打开", "BGM", MB_OK | MB_ICONEXCLAMATION);
		}
	}
}

#endif // !_GAME_