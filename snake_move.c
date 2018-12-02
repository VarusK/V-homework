#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define SNAKE_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snakeMove(int,int);
void put_money(void);
void output(void);
void gameover(void);

char map[13][13] =
{
	"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"
};
int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};
int snakeLength = 5;
int counter1 = 1;
int counter2 = 0;

int main(void)
{
	char ch;

	put_money();

	for(int i = 0; i < 12; i++)
		printf("%s\n",map[i]);

	while(counter1 == 1)
	{
		scanf("%c",&ch);

		switch(ch)
		{
			case 'A':
				snakeMove(-1,0);
				output();
				break;
			case 'D':
				snakeMove(1,0);
				output();
				break;
			case 'W':
				snakeMove(0,-1);
				output();
				break;
			case 'S':
				snakeMove(0,1);
				output();
				break;
		}
	}
}

void snakeMove(int a,int b)
{
	map[snakeY[0]][snakeX[0]] = ' ';

	for(int i = 0; i < snakeLength - 1; i++)
	{
		snakeX[i] = snakeX[i + 1];
		snakeY[i] = snakeY[i + 1];
	}
	snakeX[snakeLength - 1] = snakeX[snakeLength - 1] + a;
	snakeY[snakeLength - 1] = snakeY[snakeLength - 1] + b;

	if(snakeX[snakeLength - 1] >= 11 || snakeX[snakeLength - 1] <= 0 || snakeY[snakeLength - 1] >= 11 || snakeY[snakeLength - 1] <= 0)
		gameover();
	for(int i = 0; i < snakeLength - 1; i++)
		if(snakeX[snakeLength - 1] == snakeX[i] && snakeY[snakeLength - 1] == snakeY[i])
			gameover();

	map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'H';

	for(int i = 0; i < snakeLength - 1; i++)
		map[snakeY[i]][snakeX[i]] = 'X';
}

void gameover(void)
{
	printf("GAME OVER!!!\n");
	counter1 = 0;
	exit(0);
}

void output(void)
{
	for(int i = 0; i < 12; i++)
		printf("%s\n",map[i]);
}

void put_money(void)
{
}
