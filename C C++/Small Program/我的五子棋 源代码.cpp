#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define max 15

#define black 1
#define white 2
#define topleft 3
#define topright 4
#define bottomleft 5
#define bottomright 6
#define topbottom 7
#define leftright 8
#define topbottomleftright 9
#define leftrightbottom	10
#define leftrighttop 11
#define topbottomleft 12
#define topbottomright 13


char buff[2*max+1][2*max+1];
int X=max+1,Y=max+1;
int now=2;
int count=0;

//函数定义
void restart();

//初始化



void initialize()
{
	for(int i=0;i<max;i++)
		for(int j=0;j<max;j++)
			buff[i][j]=0;
}

//棋盘落子
void ininitalizebuff()
{	
	for(int i=0;i<2*max+1;i+=2)
		for(int j=0;j<2*max+1;j++)
			buff[i][j]=leftright;

	for(int j=0;j<2*max+1;j+=2)
		for(int i=0;i<2*max+1;i++)
			buff[i][j]=topbottom;

	for(int i=2;i<2*max;i+=2)
		for(int j=2;j<2*max;j+=2)
			buff[i][j]=topbottomleftright;

	for(int j=0;j<2*max;j+=2)
	{
		buff[0][j]=leftrightbottom;
		buff[2*max][j]=leftrighttop;
	}

	for(int i=0;i<2*max;i+=2)
	{
		buff[i][0]=topbottomright;
		buff[i][2*max]=topbottomleft;
	}


	buff[0][0]=topleft;
	buff[0][2*max]=topright;
	buff[2*max][0]=bottomleft;
	buff[2*max][2*max]=bottomright;
}

//画棋盘
void print(int i)
{
	if(i==0)
	{
		for(int i=0;i<2*max+1;i++)
		{
			for(int j=0;j<2*max+1;j++)
			{
				switch(buff[i][j])
				{
					case 0: printf("%s","  ");break;
					case 1: printf("%s","●");break;
					case 2: printf("%s","○");break;
					case 3: printf("%s","┌");break;
					case 4: printf("%s","┐");break;
					case 5: printf("%s","└");break;
					case 6: printf("%s","┘");break;
					case 7: printf("%s","│");break;
					case 8: printf("%s","─");break;
					case 9: printf("%s","┼");break;
					case 10: printf("%s","┬");break;
					case 11: printf("%s","┴");break;
					case 12: printf("%s","┤");break;
					case 13: printf("%s","├");break;
				}
			}
			printf("\n");
		}
	}
	else if(i==1)
	{
		printf("黑棋胜利,回车重开\n");
		print(0);
		restart();
	}
	else if(i==2)
	{
		printf("白棋胜利,回车重开\n");
		print(0);
		restart();
	}
	else if(i==3)
	{
		printf("平局,回车重开\n");
		print(0);
		restart();
	}
}

void curse(int x,int y)
{
	if(x>1 && x<2*max-1 && y>1 && y<2*max-1)
	{
		buff[x+1][y+1]=bottomright;
		buff[x-1][y+1]=topright;
		buff[x-1][y-1]=topleft;
		buff[x+1][y-1]=bottomleft;
	}
}

void freecurse(int x,int y)
{
		buff[x+1][y+1]=0;
		buff[x-1][y+1]=0;
		buff[x-1][y-1]=0;
		buff[x+1][y-1]=0;
}

void move(int c)
{
	freecurse(X,Y);
	if(c==0x48) //表示 上
		if(X==2)
			X=2*max-2;
		else
			X-=2;
	if(c==0x50) //表示 下
		if(X==2*max-2)
			X=2;
		else
			X+=2;
	if(c==0x4b) //表示 左
		if(Y==2)
			Y=2*max-2;
		else
			Y-=2;
	if(c==0x4d) //表示 右
		if(Y==2*max-2)
			Y=2;
		else
			Y+=2;
	
	curse(X,Y);
}

int putable()
{
	if(buff[X][Y]==1 || buff[X][Y]==2)
		return 0;
	else
		return 1;
}

void putchess(int X,int Y)
{
	if(putable())
	{
	now=3-now;
	buff[X][Y]=now;
	}
}

int victory()
{
	int w=1,x=1,y=1,z=1;
	for(int i=1;i<5;i++)
		if((X-2*i)>2 && buff[X-2*i][Y] == now)w++;else break; //向上检查
	for(int i=1;i<5;i++)
		if((X+2*i)<2*max && buff[X+2*i][Y] == now)w++;else break; //向下检查
	if(w>=5) return now;

	for(int i=1;i<5;i++)
		if((Y-2*i)>2 && buff[X][Y-2*i] == buff[X][Y])x++;else break; //向左检查
	for(int i=1;i<5;i++)
		if((Y+2*i)<2*max && buff[X][Y+2*i] == buff[X][Y])x++;else break; //向右检查
	if(x>=5) return now;

	for(int i=1;i<=5;i++)
		if((X-2*i)>2 && (Y-2*i)>2 && buff[X-2*i][Y-2*i] == buff[X][Y])y++;else break; //向左上上检查
	for(int i=1;i<5;i++)
		if((X+2*i)<2*max &&	(Y+2*i)<2*max && buff[X+2*i][Y+2*i] == buff[X][Y])y++;else break; //向右下检查
	if(y>=5) return now;

	for(int i=1;i<5;i++)
		if((X-2*i)>2 && (Y+2*i)>2 && buff[X-2*i][Y+2*i] == buff[X][Y])z++;else break; //向右上检查
	for(int i=1;i<5;i++)
		if((X+2*i)<2*max && (Y-2*i)<2*max && buff[X+2*i][Y-2*i] == buff[X][Y])z++;else break; //向左下检查
	if(z>=5) return now;
	
	if(count==(max-1)*(max))
		return 3;
	return 0;
}

		 

void RunGame()
{
	int c1,v1=0;
	c1=getch();

	if(c1==0x20) //上下左右
		{
				putchess(X,Y);
				count++;
				v1=victory();
		}
	else
	{
		c1=getch();
		if(c1==0x4b || c1==0x48 || c1==0x4d || c1==0x50)
		{
			move(c1);
		}
	}
		
	
	system("cls");
	print(v1);
}

void restart()
{
	int c;
		c=getchar();
	if(c!=NULL)
		{
			initialize();
			ininitalizebuff();
			system("cls");
			print(0);
			RunGame();
		}
}

int main()
{
	system("mode con cols=63 lines=34");//设置窗口大小 宽 高
	system("color E0");//设置颜色 背景 前景
	
	initialize();
	ininitalizebuff();
	printf("两下回车键开始\n");
	print(0);
	while(1)
	{
	RunGame();
	}
	/*for(int i=0;i<2*max;i++)
	{
		for(int j=0;j<2*max;j++)
		{
			printf("%d",buff[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}