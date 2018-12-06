    
    #include <stdio.h>
#include <stdlib.h>
#include<time.h>
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
int snakex[SNAKE_MAX_LENGTH] = { 5, 4, 3, 2, 1 };//蛇身的横坐标
int snakey[SNAKE_MAX_LENGTH] = { 1, 1, 1, 1, 1 };//蛇身的纵坐标
int lastX = 1, lastY = 1;//表示蛇尾部的坐标
int length = 5;//定义初始长度，在该变量完成蛇长的变化
void move(int x, int y);//蛇移动函数
void output(void);//蛇移动效果打印函数
void clear(void);//蛇移动前的蛇图像清空
void printmap(void);//打印
int gameover(void);//判定游戏结束（碰到身子或边界）
void snakefood(void);//用来生成食物
void eatfood(void);//蛇吃食物后身体增长
