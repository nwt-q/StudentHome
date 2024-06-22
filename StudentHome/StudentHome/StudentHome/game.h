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
//------------------�������------------------
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
	static double mapDeltaX = 0;			//��ͼX����ƫ����
	static double mapDeltaY = 0;

	const string voiceSRC = "../../../Music/backgroundMusic.mp3";				//�������ֵ��ļ�·��
	const string BackGround = "../../../background/2.jpg";			//��ʼ����(�˵�)�������ļ�·��
	const int skinCount = 6;								//Ƥ������
	string gamerSkins[skinCount] =
	{ "../../../Skins/Ƥ��һ.png","../../../Skins/Ƥ����.png","../../../Skins/Ƥ����.png",
		"../../../Skins/Ƥ����.png","../../../Skins/Ƥ����.png","../../../Skins/Ƥ����.png" };	//���Ƥ�����ļ�·��

	int gamerSkinIndex = 0;							//��ҵ�ǰƤ���������е�������Ĭ��Ϊ��һ��

	const int windowsWidth = 1280;					//���ڿ��(��λ�����ص�)
	const int windowsHeight = 720;					//���ڸ߶�
	const int mapWidth = windowsWidth * 4;			//��ͼ���
	const int mapHeight = windowsHeight * 4;		//��ͼ�߶�

	const int AICount = 20;			//��ʼAI����
	const int initAIMaxR = 30;			//AI��ʼ���뾶
	const int initAIMinR = 20;			//AI��ʼ��С�뾶
	const double attackRFactor = 2.5;		//AI׷����ҵľ������ӣ���Ҿ���AI attackRFactor���뾶ʱAI��ʼ׷����

	const int foodMinR = 3;				//ʳ����С�뾶
	const int foodMaxR = 9;			//ʳ�����뾶

	const int initGamerR = 15;			//��ʼ����Ҵ�С
	const int speedFactor = 1800;		//�ٶ�����		�ٶ� = speedFactor / pow(ball.r, 2)
	const int minFoodNumber = 800;		//ʳ����С����

	double minSpeed = 3;
	int eatAI = 0;						//��ҳԵ�AI������
	bool music = false;					//��������״̬����/�رգ�	true: ��ʾ���������Ѵ�
	double scaleFactor = 1;					//�������ӣ�������ű���Ϊ��scaleFactor��ƽ��

	/*
		��ɫ��
			R,G,B����ɫ��RGB����
			�����ɫʱ������ͨ�����R��G��B�������ɫ
	*/
	struct Color
	{
		byte R;
		byte G;
		byte B;
	};

	/*
		��
			ͨ�ýṹ�塣���Ա�ʾ����ң�AI������ʳ��

		���һ���򱻳Ե��ˣ���ô�����İ뾶��Ϊ0��֮�󲻲���Ի��߱��ԡ�
	*/
	struct Ball
	{
		int x;							//x���꣬����
		int y;							//y���꣬����
		int r;							//�뾶

		double deltaX;					//X �ı仯����|deltaX| < 1 ʱ��x����; deltaX > 1ʱ��x++,ͬʱ deltaX -= 1; deltaX < -1: X--,ͬʱdeltaX+=1;
		double deltaY;					//Y �ı仯����|deltaY| < 1 ʱ��y����; deltaY > 1ʱ��y++,ͬʱ deltaY -= 1; deltaY < -1; Y--,ͬʱdeltaY+=1;

		string* imagesrc = nullptr;			//ָ��Ƥ���ַ���·����ָ�룻ֻ������У�AI��ʳ��� imagesrc = nullptr;
		Color RGB{ 0,0,0 };				//�������Ĭ����ɫΪ��ɫ	����Ϸ����Ϊ��ɫ��
	};

	Ball Gamer;						//��ҿ��Ƶ���
	Ball AI[AICount];				//AI
	Ball food[2 * minFoodNumber];		//ʳ��
	//------------------�������------------------



	//--------------------------service--------------------------

	/*
		�����ˣ�
		���ܣ���ʼ����Ϸ����
				��ʼ�����		��ʼ��ʳ����λ�ã�ȫ�ֱ������г�ʼ��������		��ʼ��AI�������
				Ҫ��ʼ����ֵ���������Ƥ��������ٶȡ����꣬�뾶����ɫ����ҳ��⣩��
		��������
		����ֵ��void
	*/
	void Gameinit();

	/*
		�����ˣ�
		���ܣ�ʵ����ball���ƶ��� ���磺���Ҫʵ����ҵ��ƶ����ͽ������Ϊ��������ȥ
			ʵ��˼·��
				�����ٶȣ��޸�deltaX��deltaY, ����deltaX �� deltaY ��ֵ���ٿ����Ƿ���Ҫ�޸����ڵ�ͼ�е����ꡣ

			���ע�⣺
				1.��Ҫ�ж��Ƿ�����÷����ƶ���
					���磺�����ƶ���Ҫ��֤ Gamer.y-Gamer.r-getSpeed(Gamer) ʼ�� > 0
				2.��Ҫ�ж� deltaX �� deltaY �ľ���ֵ�Ƿ� > 1
				2.����Ҫ�����û����롣
					survice�㲻�����û�����
		������Ball���ͱ���ball������Ҫ�ƶ�����ע�������ô���
		����ֵ��void
	*/
	bool goDown(Ball& ball);
	bool goUp(Ball& ball);
	bool goLeft(Ball& ball);
	bool goRight(Ball& ball);

	/*
		������:
		���ܣ�ʵ������AI���ƶ�
				��AI�������Լ������ʳ���ƶ��������Ҿ����Լ���������ô׷�����
				�ƶ����Ե���goDown() goUp()��,��Ҫ�ƶ�������Ϊ��������ȥ

				�ƶ�����	����ÿһ��AI
					�ж�����Ƿ���׷����Χ�ڣ�
					����ڣ�����delta_x �� delta_y .����׷����׷������߼� �� �������ʳ���߼�һ��
							ע�⣺��Ball�ڲ���deltaX���岻һ����
					������ڣ�
						1.�ҵ������Լ������ʳ�����delta_x��delta_y,
						2.�Ƚ϶��ߴ�С��˭�󣬾�����˭�ķ����ƶ���
							���磺delta_x > delta_y ��ô������X���ƶ�������ʳ������ٶ�speed��
						3.��Ҫ�����������delta_x (�� delta_y) >0 ���� <0��������Ҫ x+=speed ���� x-=speed
						4.��AI�ƶ���ɺ���һ��AI�ƶ�
		��������
		����ֵ��void
	*/
	void AIMove();

	/*
		�����ˣ�
		���ܣ�����������֮��Ľ��������뱻�ԣ�
			��������ҳ�ʳ�
				  ��ҳ�AI��
				  AI��ʳ��

				  ����ѭ�����ж������ÿ��ʳ������ÿ��AI��ÿ��AI��ÿ��ʳ�� ֮��ĳ��뱻�Թ�ϵ��
					����ԵĹ�ϵ���ȸ��´����������İ뾶�� ��Ҫ��ε���getArea() ��
									�ٽ����Ե�����İ뾶��Ϊ0
					�������뱻�Ե�������
							С����ȫ�����������		Բ�ľ��� + С��뾶 <= ����뾶
		��������
		����ֵ��void
	*/
	void ballEat();

	/*
		�����ˣ�
		���ܣ���������ٶ�
			���ݴ����������������ٶȡ�
				speed = speedFactor / pow(ball.r, 2)

		������Ball���ͱ���ball������ʱ����Ҫ���ٶȵ���
		����ֵ��double��������������ٶ�
	*/
	double getSpeed(const Ball& ball);

	/*
		�����ˣ�
		���ܣ������� ball_1 �� ball_2 ��Բ��֮�����
		������
			Ball ball_1: Ҫ����������1
			Ball ball_2: Ҫ����������2
		����ֵ��double	��������֮��ľ���
	*/
	double getDistance(const Ball& ball_1, const Ball& ball_2);

	/*
		������:
		���ܣ�ʤ���ж�
				�Ե�AI���� = ��ʼ��AI����
		������void
		����ֵ��bool
		`			true: ��ʾʤ��
					false����ʾ��δʤ��
	*/
	bool isWin();

	/*
		�����ˣ�
		���ܣ�ʧ���ж�
				��ұ��Ե����뾶Ϊ0��
		��������
		����ֵ��bool
					true����ʾ��Ϸʧ�ܣ���ұ��Ե��ˣ�
					false����ʾ��δʧ��
	*/
	bool isFail();

	/*
		�����ˣ�
		���ܣ���ȡһ�������
				ʵ��Ҫ�󣺵õ����������������Ҷ��Ǳ����䡣
					���磺int temp = getRandom(1,10)	��ô��temp�Ŀ���ֵһ��Ҫ���� 1 �� 10
		������
				int min���������Χ��Сֵ
				int max���������Χ���ֵ
		����ֵ��int�����صõ��������
	*/
	int getRandom(int min, int max);

	/*
		�����ˣ�
		���ܣ�֡������
		������int fps��������ʱ����ֵ����λΪms������������Ϸ����ˢ���ٶȡ����ν����ӡ֮�������ʱ�䲻��С��fps ms
		����ֵ��bool��
					true����ʾ��������ʱ��������һ�δ�ӡ�����ʱ�����fps ms��
					false����ʾ��������ʱ��������һ�δ�ӡ�����ʱ�䲻��fps ms
	*/
	bool FPS();


	/*
		������:
		���ܣ����ʳ�������Ƿ����
				�������顣��¼ r>0��ʳ��������
		��������
		����ֵ��bool
					true����ʾʳ����������
					false: ��ʾʳ�����������������������
	*/
	bool foodEnough();

	/*
		�����ˣ�
		���ܣ���������ʳ���Ҫ�����ֵ���뾶��x,y���꣩
				����ʱ����ʳ����������ʱ
				ʵ��Ҫ�󣺽�ʳ��������������ʹ������ÿ��Ԫ�صİ뾶r������0��
					ȫ�ֱ������У�ʳ������뾶��ʳ�����С�뾶��ʳ�����С����
		��������
		����ֵ��void
	*/
	void creatFood();

	/*
		�����ˣ�
		���ܣ��鿴��������״̬���򿪻��ǹرգ�
				����ȫ�ֱ���music��ֵ�����ر�������״̬
		��������
		����ֵ��bool
				true: ��ʾ�������ִ�
				false: ��ʾ�������ֹر�
	*/
	bool musicState();

	/*
		�����ˣ�
		���ܣ���/�ر�������
				��musicȡ����Ȼ���������򿪻�ر�����
		��������
		����ֵ��void
	*/
	void changeMusic();

	/*
		�����ˣ�
		���ܣ����ݴ����index������gamerSkinIndex��ֵ
		������int index:	����Ҫѡ���Ƥ����Ƥ�������е��±�
		����ֵ��void
	*/
	void skinChange(int index);

	/*
		�����ˣ�
		���ܣ���������ǰ�����꣬�������ź������
		������int x������ǰ�����꣬���Դ���x��Ҳ���Դ���y
		����ֵ��double	��ʾ���ź��X��Y����
	*/
	double getScale(int x);

	//--------------------------service--------------------------


	//---------------------view---------------------

	/*
		�����ˣ�
		���ܣ�չʾ��ʼ����
				��ӡ��ʼ���档ͬʱ�������û������жϽ�������ǰ���ĸ�����
				��Ҫ������ť����ʼ��Ϸ��Ƥ��ѡ�����ã�������Ϸ
		��������
		����ֵ��void
	*/
	void menuView();

	/*
		�����ˣ�
		���ܣ�չʾ��Ϸ����
			��Ҫչʾ���У�
					��ң�ʳ�AI
		��������
		����ֵ��void
	*/
	void gameView();

	/*
		�����ˣ�
		���ܣ���Ϸ��������
				while(1)
				{
					��ӡ��Ϸ����(���� gameView())
						��ӡ��ң�AI��ʳ�	�����Ҫ��ӡƤ��
					if(!foodEnough())		���ʳ�ﲻ��
						�������ʳ����ã�creatFood()��
					��ȡ�û�����
						W/�ϣ������ƶ������������ƶ��ĺ�����goUp(Ball &ball)�����ƶ���������service��ʵ�֣�
						A/�������ƶ������������ƶ��ĺ�����
						S/�£������ƶ������������ƶ��ĺ�����
						D/�ң������ƶ������������ƶ��ĺ�����
						�ո�/ESC����ͣ��	����pauseView()
					AI�ƶ�( ���� AIMove() )
					������֮�佻�����򻥳ԣ� ���� ballEat() ��

					ʤ�������ж�( ���� isWin() )
						���ʤ����
							չʾʤ������ ( ����winView() )
					ʧ�������ж�( ���� isFail() )
						���ʧ�ܣ�
							չʾʧ�ܽ��� ( ����failView() )
				}

		��������
		����ֵ��void
	*/
	void gameStart();

	/*
		�����ˣ�
		���ܣ�չʾ��ͣ����
				��Ҫ������ť��
						������Ϸ��
						���ؿ�ʼ�˵���
						��/�ر���Ч������changeMusic()ʵ�ֿ�/����Ч������musicChangeView()չʾ��ǰ��Ч״̬����
		��������
		����ֵ��void
	*/
	void pauseView();

	/*
		�����ˣ�
		���ܣ�չʾ���ý���
				������ť����/�ر���Ч������changeMusic()ʵ�ֿ�/����Ч������musicChangeView()չʾ��ǰ��Ч״̬����
				��������Ϣ��
				���ؿ�ʼ���档
		��������
		����ֵ��void
	*/
	void settingView();

	/*
		�����ˣ�
		���ܣ�չʾ��������Ϣҳ��
				��������������Ϣ�ı��򣬷������ý��档
		��������
		����ֵ��void
	*/
	void productionGroupView();

	/*
		�����ˣ�
		���ܣ���ʾ��ť�������߱��������Ĺ��ܣ�Ҳ�Ͳ��߱����º������ز�����������
				��ť���ǳ�����
		������
			int x����ť�����Ͻ�x����
			int y����ť�����Ͻ�y����
			int width����ť���
			int height����ť�߶�
			string str����ť��ʾ����
			int textSize����ť�����ִ�С
			Color fillColor	�����ɫ ������ɫ��
			Color textColor	������ɫ
		����ֵ��
	*/
	void showButton(int x, int y, int width, int height, string str, int textSize,
		Color fillColor = { 0,0,0 }, Color textColor = { 255,255,255 });	//Ĭ�Ϻڵף�����

	/*
		�����ˣ�
		���ܣ�չʾʤ������
				��Ҫ��ť������һ�飬���ؿ�ʼ����
		��������
		����ֵ��void
	*/
	void winView();

	/*
		�����ˣ�
		���ܣ�չʾʧ�ܽ���
				��Ҫ��ť�����¿�ʼ�����ؿ�ʼ����
		��������
		����ֵ��void
	*/
	void failView();

	/*
		�����ˣ�
		���ܣ�չʾƤ��ѡ�����
				�����û�����
				��Ҫչʾ��Ƥ����ȫ�ֱ������� Ƥ�������� �� ·������͸����ͼ������transparentImage(****)����
							ÿ��Ƥ����Ӧ�İ�ť�����ؿ�ʼ����İ�ť
					�û�ѡ��Ƥ��֮��Ӧ����ѡ��ɹ�����ʾ��
		��������
		����ֵ��void
	*/
	void skinChoiceView();

	/*
		�����ˣ�
		���ܣ�͸����ͼ
				�������ͼƬ�ı���͸�����������ͼƬ��	ע�⣺�ú�����Ҫʵ�����	������AlphaBlend()������
		������
			int x:ͼƬ���ʱ������
			int y:ͼƬ���ʱ������
			IMAGE* src:	ԴͼƬָ��
		����ֵ��void
	*/
	void transparentImage(int x, int y, IMAGE* srcimg);

	/*
		�����ˣ�
		���ܣ������ı���Ч����ʾ����	�ο�������MessageBox()����
				���ú���musicState()���ݷ���ֵ��������Ӧ��ʾ����
		��������
		����ֵ��void
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

		//������Ϣ�ṹ�����
		ExMessage msg;
		//����Ƿ��ھ�����
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
		//�򿪱����֣�
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
		//��ʼ�����

		int Number_Food = minFoodNumber * 2;

		for (int i = 0; i < Number_Food; ++i) {//��ʼ��ʳ��
			food[i].x = rand() % (mapWidth - 2 * initGamerR + 5) + initGamerR;	//x
			food[i].y = rand() % (mapHeight - 2 * initGamerR + 5) + initGamerR;	//y
			food[i].r = rand() % (foodMaxR - foodMinR + 1) + foodMinR;			//�뾶

			//��ɫ
			food[i].RGB.R = rand() % (256);
			food[i].RGB.G = rand() % (256);
			food[i].RGB.B = rand() % (256);
		}

		for (int i = 0; i < AICount; ++i) {//��ʼ��AI
			AI[i].x = rand() % (mapWidth - 2 * initGamerR + 1) + initGamerR;//x
			AI[i].y = rand() % (mapHeight - 2 * initGamerR + 1) + initGamerR;//y
			AI[i].r = rand() % (initAIMaxR - initAIMinR + 1) + initAIMinR;//r

			//��ɫ
			AI[i].RGB.R = rand() % (256);
			AI[i].RGB.G = rand() % (256);
			AI[i].RGB.B = rand() % (256);
		}

		//��ʼ�����ű���
		scaleFactor = 1;

		//��ʼ���Ե�AI����
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
			if (AI[i].r == 0)		//�Ѿ����Ե�
			{
				continue;
			}
			if (getDistance(AI[i], Gamer) < attackRFactor * AI[i].r)		//��Ҵ���AIһ���뾶������Χ֮��
			{
				int deltaX = AI[i].x - Gamer.x;			//X�����ֵ
				int deltaY = AI[i].y - Gamer.y;			//Y�����ֵ
				if (Gamer.r <= AI[i].r)						//��ұ�AIС��׷��
				{
					if (abs(deltaX) > abs(deltaY))			//X�᷽������Զ
					{
						if (deltaX > 0)
						{
							goLeft(AI[i]);					//�����AI���,AI������
						}
						else
						{
							goRight(AI[i]);
						}
					}
					else									//Y�᷽���Ͼ����Զ
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
				else						//AI����
				{
					if (abs(deltaX) > abs(deltaY))			//X�᷽������Զ
					{
						if (deltaX > 0)
						{
							goRight(AI[i]);					//�����AI���,AI������
						}
						else
						{
							goLeft(AI[i]);
						}
					}
					else									//Y�᷽���Ͼ����Զ
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
				Ball* temp = nullptr;				//��¼���������ʳ��
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
					cout << "�����ˣ�û���ҵ����������ʳ��" << endl;
					exit(-1);
				}

				int deltaX = AI[i].x - (*temp).x;
				int deltaY = AI[i].y - (*temp).y;
				if (abs(deltaX) > abs(deltaY))			//X�᷽������Զ
				{
					if (deltaX > 0)
					{
						if (!goLeft(AI[i])) 					//�����ʳ����AI���,AI������
						{
							//�����߲��������������ʳ��Բ�����ǿ������ʳ�
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
				else									//Y�᷽���Ͼ����Զ
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
		for (int i = 0; i < AICount; i++)				//ѭ������AI
		{
			if (AI[i].r)
			{
				if (getDistance(Gamer, AI[i]) <= AI[i].r)			//AI�����
				{
					AI[i].r += Gamer.r / 4;
					Gamer.r = 0;
					continue;
				}
				if (getDistance(Gamer, AI[i]) <= Gamer.r)			//��ҳ�AI
				{
					Gamer.r += AI[i].r / 4;
					++eatAI;
					AI[i].r = 0;
				}
				for (int j = 0; j < 2 * minFoodNumber; j++)			//ѭ������ʳ��
				{
					if (food[j].r)
					{
						if (getDistance(Gamer, food[j]) <= Gamer.r)			//��ҳ�ʳ��
						{
							Gamer.r += food[j].r / 4;
							food[j].r = 0;
							if (Gamer.r > 820)
							{
								Gamer.r -= 5;
							}
							continue;
						}
						if (getDistance(AI[i], food[j]) <= AI[i].r)			//AI��ʳ��
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
		loadimage(&img, BackGround.c_str(), windowsWidth, windowsHeight, true);//����ͼƬ
		putimage(0, 0, &img);
		showButton(BUTTONX, 100, BUTTONW, BUTTONH, "��ʼ��Ϸ", 48, fillColor, textColor);
		showButton(BUTTONX, 250, BUTTONW, BUTTONH, "Ƥ��ѡ��", 48, fillColor, textColor);
		showButton(BUTTONX, 400, BUTTONW, BUTTONH, "��������", 48, fillColor, textColor);
		showButton(BUTTONX, 550, BUTTONW, BUTTONH, "�˳���Ϸ", 48, fillColor, textColor);

		while (1)
		{
			Sleep(200);
			while (peekmessage(&msg, EM_MOUSE))
			{
				//�ж��Ƿ���
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
		//˫����
		BeginBatchDraw();
		setbkcolor(BLACK);
		cleardevice();

		//ʳ��
		for (int i = 0; i < minFoodNumber * 2; i++)
		{
			if (food[i].r)
			{
				setfillcolor(RGB(food[i].RGB.R, food[i].RGB.G, food[i].RGB.B));
				solidcircle(getScale(food[i].x), getScale(food[i].y), food[i].r / scaleFactor);
			}
		}
		if (Gamer.r)			//�����Ҵ��ڣ���ô������ҡ�����ұ��Ե���ʧ�ܽ�����Ҫ1����ܵ�����
		{
			//�������
			setfillcolor(BLUE);
			solidcircle(getScale(Gamer.x), getScale(Gamer.y), Gamer.r / scaleFactor);
			double skinScaleFactor = (Gamer.r / scaleFactor) / 54.0;						//54��Ƥ������������£����ĵ�Բ�İ뾶
			IMAGE Skin;
			loadimage(&Skin, Gamer.imagesrc->c_str(), 500 * skinScaleFactor, 281 * skinScaleFactor);					//������״̬����İ뾶��С
			transparentImage(getScale(Gamer.x) - 250 * skinScaleFactor, getScale(Gamer.y) - 140 * skinScaleFactor, &Skin);
		}
		//����ai
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
		mapDeltaX = windowsWidth / 2.0 - getScale(Gamer.x);			//��ͼX����ƫ����
		mapDeltaY = windowsHeight / 2.0 - getScale(Gamer.y);

		cleardevice();
		settextstyle(50, 0, "�����п�");//���ô�С������
		settextcolor(WHITE);
		outtextxy(400, 300, "��ͣ���ո��");
		outtextxy(400, 500, "�ƶ���WASD�����������ң�");
		Sleep(3000);


		BeginBatchDraw();
		cleardevice();
		int count = 0;

		while (1)
		{
			int startTime = clock();			//��ȡѭ����ʼ��ʱ��
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
		//����ͼƬ����
		IMAGE img_tp;
		//����ͼƬ
		loadimage(&img_tp, BackGround.c_str(), windowsWidth, windowsHeight);
		putimage(0, 0, &img_tp);
		showButton(BUTTONX, 100, BUTTONW, BUTTONH, "������Ϸ", 48, fillColor, textColor);
		showButton(BUTTONX, 250, BUTTONW, BUTTONH, "���ز˵�", 48, fillColor, textColor);
		showButton(BUTTONX - 40, 400, BUTTONW + 80, BUTTONH, "��/�ر���Ч", 48, fillColor, textColor);
		showButton(BUTTONX, 550, BUTTONW, BUTTONH, "�˳���Ϸ", 48, fillColor, textColor);
		while (1)
		{
			Sleep(250);
			while (peekmessage(&msg, EM_MOUSE))
			{
				//�ж��Ƿ���
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 100, BUTTONW, BUTTONH))			//������Ϸ
				{
					return;
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 250, BUTTONW, BUTTONH))			//���ز˵�
				{
					menuView();
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX - 40, 400, BUTTONW + 80, BUTTONH))			//������Ч
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
		loadimage(&img, BackGround.c_str(), windowsWidth, windowsHeight, true);//����ͼƬ
		putimage(0, 0, &img);
		settextstyle(96, 0, "�����п�");//���ô�С������
		settextcolor(RGB(255, 255, 96));   //����������ɫ
		setbkmode(TRANSPARENT);    //͸���ף������ǵ�ͼ
		outtextxy(100, 70, "���ý���");  // �� (100, 100) ��λ������ı�
		//��֮ǰ��ť����ɫ
		Color fillColor1 = { 238,238,9 };
		//��֮��ť����ɫ
		Color fillColor2 = { 200,200,0 };
		//������ɫ
		Color textColor1 = { 0,0,0 };
		showButton(490, 170, 300, 100, "��/�ر���Ч", 48, fillColor1, textColor1);
		showButton(490, 340, 300, 100, "��������Ϣ", 48, fillColor1, textColor1);
		showButton(490, 510, 300, 100, "���ؿ�ʼ����", 48, fillColor1, textColor1);
		ExMessage m;
		while (true) {
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					if (m.x >= 490 && m.x <= 790 && m.y >= 170 && m.y <= 270) {
						changeMusic();
						showButton(490, 170, 300, 100, "��/�ر���Ч", 48, fillColor2, textColor1);
						Sleep(200);
						showButton(490, 170, 300, 100, "��/�ر���Ч", 48, fillColor1, textColor1);
						musicChangeView();
					}
					else if (m.x >= 490 && m.x <= 790 && m.y >= 340 && m.y <= 440) {
						showButton(490, 340, 300, 100, "��������Ϣ", 48, fillColor2, textColor1);
						Sleep(200);
						showButton(490, 340, 300, 100, "��������Ϣ", 48, fillColor1, textColor1);

						productionGroupView();

						cleardevice();
						putimage(0, 0, &img);
						settextstyle(96, 0, "�����п�");//���ô�С������
						settextcolor(RGB(255, 255, 96));   //����������ɫ
						setbkmode(TRANSPARENT);    //͸���ף������ǵ�ͼ
						outtextxy(100, 70, "���ý���");  // �� (100, 100) ��λ������ı�
						//��֮ǰ��ť����ɫ
						Color fillColor1 = { 238,238,9 };
						//��֮��ť����ɫ
						Color fillColor2 = { 200,200,0 };
						//������ɫ
						Color textColor1 = { 0,0,0 };
						showButton(490, 170, 300, 100, "��/�ر���Ч", 48, fillColor1, textColor1);
						showButton(490, 340, 300, 100, "��������Ϣ", 48, fillColor1, textColor1);
						showButton(490, 510, 300, 100, "���ؿ�ʼ����", 48, fillColor1, textColor1);
					}
					else if (m.x >= 490 && m.x <= 790 && m.y >= 510 && m.y <= 610) {
						showButton(490, 510, 300, 100, "���ؿ�ʼ����", 48, fillColor2, textColor1);
						Sleep(200);
						showButton(490, 510, 300, 100, "���ؿ�ʼ����", 48, fillColor1, textColor1);
						menuView();
					}
				}
			}
		}
	}

	void productionGroupView()
	{
		const string kText = "��������Ϣ"; // ��Ҫ������ʾ���ı�����
		const string kTextArr[9] = { "��������12��","�鳤����ɽ","��Ʒ������ɽ","�����٣���ɽ",
								"���֣���ɽ","Ƥ�����棺��ɽ" };
		ExMessage m;

		int y = windowsHeight;
		IMAGE img;
		loadimage(&img, BackGround.c_str(), windowsWidth, windowsHeight, true);//����ͼƬ
		Color fillColor1 = { 135, 206, 250 };
		Color textColor1 = { 0,0,0 };
		Color textColor2 = { 238,238,9 };
		while (true) { // ѭ�����Ź����ı�
			Sleep(5);
			BeginBatchDraw();
			cleardevice(); // �����Ļ
			putimage(0, 0, &img);
			showButton(1080, 670, 200, 50, "�����Ļ����", 30, fillColor1, textColor1);
			settextstyle(48, 0, "�����п�"); // ����������ʽ�ʹ�С
			settextcolor(RGB(textColor2.R, textColor2.G, textColor2.B)); // �����ı���ɫ
			setbkmode(TRANSPARENT);

			for (int i = 0; i < 9; i++)
			{
				int w = (windowsWidth - textwidth(kTextArr[i].c_str())) / 2;
				outtextxy(w, i * 100 + y, kTextArr[i].c_str()); // ��ָ��λ������ı�
			}

			// ��ʾ�����ı�
			y -= 2; // ÿ�������ƶ� 1 ������

			if (y < -700) { // ����ı��ƶ�����Ļ�������¿�ʼ����
				y = windowsHeight;
			}

			// �ȴ�һ��ʱ�䣬�Կ��ƹ����ٶ�
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
		Color fillColor, Color textColor)			//Ĭ�Ϻڵף�����
	{
		setfillcolor(RGB(fillColor.R, fillColor.G, fillColor.B));
		fillroundrect(x, y, x + width, y + height, width / 10, width / 10);
		setbkmode(TRANSPARENT);
		settextstyle(textSize, 0, _T("�����п�"));
		int w = (width - textwidth(str.c_str())) / 2;
		int h = (height - textheight(str.c_str())) / 2;
		settextcolor(RGB(textColor.R, textColor.G, textColor.B));
		outtextxy(x + w, y + h, str.c_str());
	}

	void winView()
	{
		setorigin(0, 0);
		IMAGE img;
		loadimage(&img, BackGround.c_str(), windowsWidth, windowsHeight, true);//����ͼƬ
		putimage(0, 0, &img);
		settextstyle(96, 0, "�����п�");//���ô�С������
		settextcolor(RGB(255, 255, 96));   //����������ɫ
		setbkmode(TRANSPARENT);    //͸���ף������ǵ�ͼ
		outtextxy(200, 80, "��ϲʤ��");  // �� (100, 100) ��λ������ı�

		//����һ�εİ�ť��ɫ
		Color fillColor1 = { 238,238,9 };
		//���ؿ�ʼ����İ�ť��ɫ
		Color fillColor2 = { 200,200,0 };
		//����һ�ε�������ɫ
		Color textColor1 = { 0,0,0 };
		//���ؿ�ʼ�����������ɫ
		Color textColor2 = { 0,0,0 };

		showButton(240, 350, 300, 100, "����һ��", 48, fillColor1, textColor1);
		showButton(740, 350, 300, 100, "���ؿ�ʼ����", 48, fillColor1, textColor1);
		ExMessage m;
		while (true) {
			Sleep(100);
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					if (m.x >= 240 && m.x <= 540 && m.y >= 350 && m.y <= 450) {
						showButton(240, 350, 300, 100, "����һ��", 48, fillColor2, textColor1);
						Sleep(250);
						showButton(240, 350, 300, 100, "����һ��", 48, fillColor1, textColor1);
						gameStart();
					}
					else if (m.x >= 740 && m.x <= 1040 && m.y >= 350 && m.y <= 450) {
						showButton(740, 350, 300, 100, "���ؿ�ʼ����", 48, fillColor2, textColor1);
						Sleep(250);
						showButton(740, 350, 300, 100, "���ؿ�ʼ����", 48, fillColor1, textColor1);
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
		//����ͼƬ����
		IMAGE img_tp;
		//����ͼƬ
		loadimage(&img_tp, BackGround.c_str(), windowsWidth, windowsHeight);
		putimage(0, 0, &img_tp);

		settextstyle(96, 0, "�����п�");//���ô�С������
		settextcolor(RGB(255, 255, 96));   //����������ɫ
		setbkmode(TRANSPARENT);    //͸���ף������ǵ�ͼ
		outtextxy(200, 80, "��Ϸʧ�ܣ��㱻�Ե���");  // �� (100, 100) ��λ������ı�

		showButton(BUTTONX, 200, BUTTONW, BUTTONH, "���ز˵�", 48, fillColor, textColor);
		showButton(BUTTONX, 400, BUTTONW, BUTTONH, "����һ��", 48, fillColor, textColor);
		while (1)
		{
			Sleep(100);
			while (peekmessage(&msg, EM_MOUSE))
			{
				//�ж��Ƿ���
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 200, BUTTONW, BUTTONH))		//���ز˵�
				{
					menuView();
				}
				if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, BUTTONX, 400, BUTTONW, BUTTONH))		//����һ��
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
		showButton(200, 200, 100, 40, "Ƥ��һ", 20);
		showButton(600, 200, 100, 40, "Ƥ����", 20);
		showButton(1000, 200, 100, 40, "Ƥ����", 20);
		showButton(200, 500, 100, 40, "Ƥ����", 20);
		showButton(600, 500, 100, 40, "Ƥ����", 20);
		showButton(1000, 500, 100, 40, "Ƥ����", 20);

		showButton(600, 600, 100, 40, "����", 20);
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
						MessageBox(hwnd, "�����ɹ�", "Ƥ��", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 600 && msg.x <= 600 + 100 && msg.y >= 200 && msg.y <= 200 + 40)
					{
						skinChange(1);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "�����ɹ�", "Ƥ��", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 1000 && msg.x <= 1000 + 100 && msg.y >= 200 && msg.y <= 200 + 40)
					{
						skinChange(2);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "�����ɹ�", "Ƥ��", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 200 && msg.x <= 200 + 100 && msg.y >= 500 && msg.y <= 500 + 40)
					{
						skinChange(3);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "�����ɹ�", "Ƥ��", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 600 && msg.x <= 600 + 100 && msg.y >= 500 && msg.y <= 500 + 40)
					{
						skinChange(4);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "�����ɹ�", "Ƥ��", MB_OK | MB_ICONEXCLAMATION);
					}
					if (msg.x >= 1000 && msg.x <= 1000 + 100 && msg.y >= 500 && msg.y <= 500 + 40)
					{
						skinChange(5);
						HWND hwnd = GetHWnd();
						MessageBox(hwnd, "�����ɹ�", "Ƥ��", MB_OK | MB_ICONEXCLAMATION);
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
			MessageBox(hwnd, "���������ѹر�", "BGM", MB_OK | MB_ICONEXCLAMATION);
		}
		else
		{
			HWND hwnd = GetHWnd();
			MessageBox(hwnd, "���������Ѵ�", "BGM", MB_OK | MB_ICONEXCLAMATION);
		}
	}
}

#endif // !_GAME_