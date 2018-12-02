# 贪吃蛇实验报告

## 任务一：实现蛇的移动

```C
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SNAKE_MAX_LENGTH 20		/*		声明符号常量 蛇的最大长度     	*/
#define SNAKE_HEAD 'H'			/*		声明符号常量 蛇头的字符    		*/
#define SNAKE_BODY 'X'			/*		声明符号常量 蛇身的字符     	*/
#define SNAKE_CELL ' '			/*		声明符号常量 地图字符   		*/
#define SNAKE_FOOD '$'			/*		声明符号常量 食物的字符    		*/
#define WALL_CELL '*'			/*		声明符号常量 地图边界的字符  	*/

void snakeMove(int,int);		/*		声明移动函数     	*/
void put_money(void);		    /*		声明生产食物函数 	*/
void output(void);				/*		声明输出函数     	*/
void gameover(void);			/*		声明游戏结束函数 	*/

char map[13][13] =				/*		     	*/
{
	/*		     	*/
	"************",				/*		     	*/
	"*XXXXH     *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/* 建立初始地图 */
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"************"				/*		     	*/
};								/*		     	*/

int snakeLength = 5;		//声明蛇的初始长度
int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};		//用数组表示蛇的X坐标
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};		//用数组表示蛇的Y坐标
int counter1 = 1;		//声明计数器1，用于判断游戏是否结束，并初始化为1，即游戏开始
int counter2 = 1;		//声明计数器2，用于判断地图上是否有食物，并初始化为1，即一开始有一个食物

int randNumX,randNumY;		//声明随机数变量，用于生成食物

int main(void)
{
	char ch;

	put_money();		//游戏开始时有一个食物

	for(int i = 0; i < 12; i++)		//输出最初的全地图
		printf("%s\n",map[i]);

	while(counter1 == 1)
	{
		scanf("%c",&ch);		//获取用户输入的方向

		switch(ch)		//判断用户输入的方向并作出相应的动作
		{
			case 'A':		//向左走，给坐标改变量的参数到snakeMove()函数中，并输出改变后的地图
				snakeMove(-1,0);
				output();
				break;
			case 'D':		//向右走，给坐标改变量的参数到snakeMove()函数中，并输出改变后的地图
				snakeMove(1,0);
				output();
				break;
			case 'W':		//向上走，给坐标改变量的参数到snakeMove()函数中，并输出改变后的地图
				snakeMove(0,-1);
				output();
				break;
			case 'S':		//向下走，给坐标改变量的参数到snakeMove()函数中，并输出改变后的地图
				snakeMove(0,1);
				output();
				break;
		}

	}

}

void snakeMove(int a,int b)
{
	map[snakeY[0]][snakeX[0]] = SNAKE_CELL;											/*	   				 	*/
																					/*	   				 	*/
	for(int i = 0; i < snakeLength - 1; i++)										/*	  蛇身整体平移 		*/
	{																				/*	   				 	*/
		snakeX[i] = snakeX[i + 1];													/*	   				 	*/
		snakeY[i] = snakeY[i + 1];													/*	   				 	*/
	}																				/*	   				 	*/
	snakeX[snakeLength - 1] = snakeX[snakeLength - 1] + a;							/*	  改变蛇头坐标 		*/
	snakeY[snakeLength - 1] = snakeY[snakeLength - 1] + b;							/*	  改变蛇头坐标 		*/

	if(snakeX[snakeLength - 1] >= 11 || snakeX[snakeLength - 1] <= 0 || snakeY[snakeLength - 1] >= 11 || snakeY[snakeLength - 1] <= 0)		//判断蛇是否出了边界，若是则结束游戏 
		gameover();
	for(int i = 0; i < snakeLength - 1; i++)		//判断蛇是否吃到身体，若是则结束游戏 
	{
		if(snakeX[snakeLength - 1] == snakeX[i] && snakeY[snakeLength - 1] == snakeY[i])
			gameover();
	}

	map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;			/*	对应坐标的蛇头打上字符 SNAKE_HEAD   	*/
																				/*	                                    	*/
	for(int i = 0 ; i < snakeLength - 1; i++)									/*	对应坐标的蛇身打上字符 SNAKE_BODY   	*/
		map[snakeY[i]][snakeX[i]] = SNAKE_BODY;									/*	                                    	*/
}

void gameover(void)		//游戏结束函数的实现
{
	printf("GAME OVER!!!\n");
	counter1 = 0;
	exit(0);		//结束程序
}

void output(void)		//输出函数的实现
{
	for(int i = 0; i < 12; i++)
		printf("%s\n",map[i]);
}

void put_money(void)	//生成食物函数实现暂不要求
{
}
```

## 任务二：实现蛇吃食物增长


```C
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SNAKE_MAX_LENGTH 20		/*		声明符号常量 蛇的最大长度     	*/
#define SNAKE_HEAD 'H'			/*		声明符号常量 蛇头的字符    		*/
#define SNAKE_BODY 'X'			/*		声明符号常量 蛇身的字符     	*/
#define SNAKE_CELL ' '			/*		声明符号常量 地图字符   		*/
#define SNAKE_FOOD '$'			/*		声明符号常量 食物的字符    		*/
#define WALL_CELL '*'			/*		声明符号常量 地图边界的字符  	*/

void snakeMove(int,int);		/*		声明移动函数     	*/ 
void put_money(void);		    /*		声明生产食物函数 	*/
void output(void);				/*		声明输出函数     	*/
void gameover(void);			/*		声明游戏结束函数 	*/				

char map[13][13] =				/*		     	*/
{								/*		     	*/
	"************",				/*		     	*/
	"*XXXXH     *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/* 建立初始地图 */
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"*          *",				/*		     	*/
	"************"				/*		     	*/
};								/*		     	*/

int snakeLength = 5;		//声明蛇的初始长度 
int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};		//用数组表示蛇的X坐标 
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};		//用数组表示蛇的Y坐标 
int counter1 = 1;		//声明计数器1，用于判断游戏是否结束，并初始化为1，即游戏开始 
int counter2 = 1;		//声明计数器2，用于判断地图上是否有食物，并初始化为1，即一开始有一个食物 

int randNumX,randNumY;		//声明随机数变量，用于生成食物 

int main(void)
{
	char ch;

	put_money();					//游戏开始时需要一个食物

	for(int i = 0; i < 12; i++)		//输出最初的全地图
		printf("%s\n",map[i]);

	while(counter1 == 1)
	{
		scanf("%c",&ch);			//获取用户输入的方向
		
		if(counter2 == 0)			//如果地图上没有食物了就放一个食物 
			put_money();

		switch(ch)					//判断用户输入的方向并作出相应的动作 
		{
			case 'A':				//向左走，给坐标改变量的参数到snakeMove()函数中，并输出改变后的地图 
				snakeMove(-1,0);
				output();
				break;
			case 'D':				//向右走，给坐标改变量的参数到snakeMove()函数中，并输出改变后的地图 
				snakeMove(1,0);
				output();
				break;
			case 'W':				//向上走，给坐标改变量的参数到snakeMove()函数中，并输出改变后的地图 
				snakeMove(0,-1);
				output();
				break;
			case 'S':				//向下走，给坐标改变量的参数到snakeMove()函数中，并输出改变后的地图 
				snakeMove(0,1);
				output();
				break;
		}

	}

}

void snakeMove(int a,int b)		//移动函数的实现 
{
	if(snakeY[snakeLength - 1] == randNumY && snakeX[snakeLength - 1] == randNumX)		//判断蛇是否吃到了食物 
	{		
		snakeLength++;																	/*	  蛇长增加一	 	*/
		snakeX[snakeLength - 1] = snakeX[snakeLength - 2] + a;							/*	  改变蛇头坐标 		*/
		snakeY[snakeLength - 1] = snakeY[snakeLength - 2] + b;							/*	  改变蛇头坐标 		*/
		counter2 = 0;																	/*	  将食物计数器归零	*/
	}
	else
	{
		map[snakeY[0]][snakeX[0]] = SNAKE_CELL;											/*	   				 	*/ 
		for(int i = 0; i < snakeLength - 1; i++)										/*	  蛇身整体平移 		*/
		{																				/*	   				 	*/
			snakeX[i] = snakeX[i + 1];													/*	   				 	*/
			snakeY[i] = snakeY[i + 1];													/*	   				 	*/
		}																				/*	   				 	*/
		snakeX[snakeLength - 1] = snakeX[snakeLength - 1] + a;							/*	  改变蛇头坐标 		*/
		snakeY[snakeLength - 1] = snakeY[snakeLength - 1] + b;							/*	  改变蛇头坐标 		*/
	}

	if(snakeX[snakeLength - 1] >= 11 || snakeX[snakeLength - 1] <= 0 || snakeY[snakeLength - 1] >= 11 || snakeY[snakeLength - 1] <= 0)		//判断蛇是否出了边界，若是则结束游戏 
		gameover();
	for(int i = 0; i < snakeLength - 1; i++)		//判断蛇是否吃到身体，若是则结束游戏 
	{
		if(snakeX[snakeLength - 1] == snakeX[i] && snakeY[snakeLength - 1] == snakeY[i])
			gameover();
	}

	map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = SNAKE_HEAD;			/*	对应坐标的蛇头打上字符 SNAKE_HEAD   	*/
																				/*	                                    	*/
	for(int i = 0 ; i < snakeLength - 1; i++)									/*	对应坐标的蛇身打上字符 SNAKE_BODY   	*/
		map[snakeY[i]][snakeX[i]] = SNAKE_BODY;									/*	                                    	*/
}

void gameover(void)		//游戏结束函数的实现 
{
	printf("GAME OVER!!!\n");
	counter1 = 0;
	exit(0);		//结束程序 
}

void output(void)		//输出函数的实现 
{
	for(int i = 0; i < 12; i++)
		printf("%s\n",map[i]);
}

void put_money(void)		//生产食物函数的实现 
{
	int counter = 0;		//声明计数器，用于判断生成的随机数坐标是否和蛇重合 

	while(counter == 0)
	{
		srand(time(NULL));											/*	   				 	*/
		randNumX = rand()%10 + 1;									/*	   生成随机数		*/
		randNumY = rand()%10 + 1;									/*	   				 	*/
		counter++;													/*	   计数器加一		*/
		for(int i = 0; i < snakeLength; i++)							
		{															/*	   				 	*/
			if(randNumX == snakeX[i] && randNumY == snakeY[i])		/* 判断是否和蛇重合 	*/
				counter = 0;										/* 若是则计数器归零  	*/
		}															/*	   				 	*/
	}																/*	   				 	*/
	counter2 = 1;													/* 更新食物计数器		*/
	map[randNumY][randNumX] = SNAKE_FOOD;							/* 在对应坐标下放置食物 */
}
```

