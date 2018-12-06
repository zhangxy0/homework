        
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SNAKE_MAX_LENGTH 50
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'


char map[12][13] ={
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
"************" };
//全局变量：初始状态表
int food = 0;//定义开始时食物数量为0
int x = 0, y = 0;//定义食物的坐标（x，y）
int snake_x[SNAKE_MAX_LENGTH] = { 5, 4, 3, 2, 1 };//蛇身的横坐标
int snake_y[SNAKE_MAX_LENGTH] = { 1, 1, 1, 1, 1 };//蛇身的纵坐标
int last_X = 1, last_Y = 1;//表示蛇尾部的坐标
int length = 5;//定义初始长度，在该变量完成蛇长的变化
void move(int x, int y);//蛇移动函数
void output(void);//蛇移动效果打印函数
void clear(void);//蛇移动前的蛇图像清空
void printmap(void);//打印
int gameover(void);//判定游戏结束（碰到身子或边界）
void snakefood(void);//用来生成食物
void eatfood(void);//蛇吃食物后身体增长

int main() {
    int i;
    printmap();//打印初始状态图
    char c;
    int a = 0, b = 0;
    while ((scanf("%c", &c)) != EOF)//输入字母W,A,S,D
    {
        switch (c){//进行移动
        case 'a'://左移时
            a = 1;
            b = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 'd'://右移
            b = 1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 's'://上移
            a = -1;
            b = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 'w'://下移
            b = -1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        }
    }//判定贪吃蛇的移动（通过move函数实现）并通过output函数实现map上的变化
    return 0;
}

void snakefood(void){
    srand(time(NULL));

    if (food == 0)
    {   
        x = rand() % 10 + 1;
        y = rand() % 10 + 1;
        if (map[x][y] == ' ')//确保在空白位置出现食物
        {
            map[x][y] = SNAKE_FOOD;//在地图可到达位置上随机生成食物
            food++;//确保每次只出现一个食物
        }

    }
}

void eatfood(void){
    if (snake_y[0] == x && snake_x[0] == y)//判断蛇是否吃到食物
    {
        length++;
        food = 0;//食物已经被吃掉，清空
        snake_x[length - 1] = last_X;
        snake_y[length - 1] = last_Y;//蛇长增加一个
    }
} 
